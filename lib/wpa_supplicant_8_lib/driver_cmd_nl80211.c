/*
 * Driver interaction with extended Linux CFG8021
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 */
/*
 * Portions of this file are copyright (c) 2020 Amazon.com, Inc. or its affiliates.  All rights reserved.
 *
 * PORTIONS OF THIS FILE ARE AMAZON PROPRIETARY/CONFIDENTIAL.  USE IS SUBJECT TO LICENSE TERMS.
 *
 * Amazon modifications are indicated by [fosmod_* comments].
 */

#include "includes.h"
#include "common.h"
#include <net/if.h>
#include <fcntl.h>
#include <unistd.h>
#include "driver_nl80211.h"
#include "wpa_supplicant_i.h"
#include "config.h"
#include "driver_i.h"
#include "linux_ioctl.h"
#include "bss.h"

#ifdef ANDROID
#include "android_drv.h"
#endif

#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/wireless.h>

// fosmod_wifi_thermal_policy begin
#define GETCNM_STAMODE_KEYWORD "[NetType1]"
#define GETCNM_BW_KEYWORD      "[BW "
#define GETCNM_CH_KEYWORD      "[CH "
#define GETCNM_MIN_BW          0
#define GETCNM_MAX_BW          2
#define GETCNM_DEFAULT_BW      GETCNM_MAX_BW
#define REATTATCH_5G_LOWEST_FREQ      5180
#define REATTATCH_THROTTLE_DISABLE_BW 80
#define REATTATCH_THROTTLE_ENABLE_BW  20

int wpa_driver_check_reattach_allow(void *priv)
{
	struct i802_bss *bss = priv;
	struct wpa_supplicant *wpa_s = bss->ctx;
	struct wpa_bss *cur_bss = NULL;

	if (wpa_s == NULL)
		return 1;

	cur_bss = wpa_s->current_bss;
	if (cur_bss == NULL) {
		wpa_printf(MSG_INFO, "[wpa_driver_check_reattach_allow] not connected!");
		return 0;
	}
	wpa_printf(MSG_INFO, "[wpa_driver_check_reattach_allow] freq %d", cur_bss->freq);

	if (cur_bss->freq < REATTATCH_5G_LOWEST_FREQ) {
		return 0;
	}

	return 1;
}
// fosmod_wifi_thermal_policy end

int wpa_driver_set_act_intv(void *priv, char *cmd, char *buf, size_t buf_len)
{
        struct iwreq wrq;
        int skfd = -1;
        struct i802_bss *bss = priv;
        struct wpa_driver_nl80211_data *drv = bss->drv;
        int ret = -1;

        wpa_printf(MSG_DEBUG, "[ACT_INTV] command %s", cmd);

        /* zeroize */
        memset(&wrq, 0, sizeof(struct iwreq));

        /* initialize skfd */
        skfd = socket(PF_INET, SOCK_DGRAM, 0);
        if (skfd < 0) {
                wpa_printf(MSG_ERROR,
                        "[%s] : failed to opern net socket in %s\n",
                        strerror(errno), __func__);
                ret = -1;
                return ret;
        }

        /* configure struct iwreq */
        wrq.u.data.pointer = cmd;
        wrq.u.data.length = os_strlen(cmd) + 1; //add terminator '\0' as driver needs it.
        wrq.u.data.flags = 15; /* PRIV_CMD_OID (TBD) */
        /* Set device name */
        strncpy(wrq.ifr_name, bss->ifname, (IFNAMSIZ - 1));

        /* IOCTL_GET_DRIVER */
        ret = ioctl(skfd, SIOCIWFIRSTPRIV + 15, &wrq);
        if (ret < 0) {
                wpa_printf(MSG_ERROR,
                "[ANT_DIV] ioctl failed and returned errno %s\n",
                strerror(errno));
        }

        ret = snprintf(buf, buf_len, "%s\n", cmd);
        wpa_printf(MSG_DEBUG, "[ACT_INTV] ret=%d", ret);

        close(skfd);
        return 0;
}

int wpa_driver_enforce_power_mode(void *priv, char *cmd)
{
        struct iwreq wrq;
        int skfd = -1;
        struct i802_bss *bss = priv;
        struct wpa_driver_nl80211_data *drv = bss->drv;
        int ret = -1;

        wpa_printf(MSG_DEBUG, "command: %s", cmd);

        /* zeroize */
        memset(&wrq, 0, sizeof(struct iwreq));

        /* initialize skfd */
        skfd = socket(PF_INET, SOCK_DGRAM, 0);
        if (skfd < 0) {
                wpa_printf(MSG_ERROR,
                        "[%s] : failed to opern net socket in %s\n",
                        strerror(errno), __func__);
                ret = -1;
                return ret;
        }
        /* configure struct iwreq */
        wrq.u.data.pointer = cmd;
        wrq.u.data.length = os_strlen(cmd) + 1; //add terminator '\0' as driver needs it.

        /* Set device name */
        strncpy(wrq.ifr_name, bss->ifname, (IFNAMSIZ - 1));

        /* IOCTL_GET_DRIVER */
        ret = ioctl(skfd, SIOCIWFIRSTPRIV + 15 , &wrq);
        if (ret < 0) {
                wpa_printf(MSG_ERROR,
                "[ENFORCE_POWER_MODE] ioctl failed and returned errno %s\n",
                strerror(errno));
        }

        wpa_printf(MSG_DEBUG, "[ENFORCE_POWER_MODE] ret=%d", ret);

        close(skfd);
        return 0;
}

int wpa_driver_set_cmd_common(void *priv, char *cmd, char *buf, size_t buf_len)
{
	struct iwreq wrq;
	int skfd = -1;
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;
	int ret = -1;

	wpa_printf(MSG_DEBUG, "command: %s", cmd);

	/* zeroize */
	memset(&wrq, 0, sizeof(struct iwreq));

	/* initialize skfd */
	skfd = socket(PF_INET, SOCK_DGRAM, 0);
	if (skfd < 0) {
			wpa_printf(MSG_ERROR,
					"[%s] : failed to opern net socket in %s\n",
					strerror(errno), __func__);
			ret = -1;
			return ret;
	}

	/* configure struct iwreq */
	wrq.u.data.pointer = cmd;
	wrq.u.data.length = os_strlen(cmd) + 1; //add terminator '\0' as driver needs it.
	wrq.u.data.flags = 15; /* PRIV_CMD_OID (TBD) */
	/* Set device name */
	strncpy(wrq.ifr_name, bss->ifname, (IFNAMSIZ - 1));

	/* IOCTL_GET_DRIVER */
	ret = ioctl(skfd, SIOCIWFIRSTPRIV + 15, &wrq);
	if (ret < 0) {
			wpa_printf(MSG_ERROR,
			"ioctl failed and returned errno %s\n",
			strerror(errno));
	}

	ret = snprintf(buf, buf_len, "%s\n", cmd);
	wpa_printf(MSG_DEBUG, "%s ret=%d", cmd, ret);

	close(skfd);
	return 0;
}

// fosmod_wifi_thermal_policy begin
/*
 * cmd: "DYN_MODE 1" (enable) or "DYN_MODE 0" (disable).
 */
static int wpa_set_dyn_mode(void *priv, char *cmd, char *buf, size_t buf_len)
{
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;
	int ret = -1;

	/* "1" means enable bw throttling */
	if (os_strstr(cmd, "1") != NULL) {
		os_memset(cmd, 0, 20);
		strlcpy(cmd, "SET_CFG Sta5gBw 0", 18);
		ret = wpa_driver_set_cmd_common(priv, cmd, buf, buf_len);
	/* "0" means disable bw throttling */
	} else if (os_strstr(cmd, "0") != NULL) {
		os_memset(cmd, 0, 20);
		strlcpy(cmd, "SET_CFG Sta5gBw 2", 18);
		ret = wpa_driver_set_cmd_common(priv, cmd, buf, buf_len);
	} else {
		wpa_printf(MSG_ERROR,"DYN_BW_MODE cmd failed due to wrong parameter %s.\n", cmd);
		return ret;
	}
	wpa_printf(MSG_INFO,"DYN_BW_MODE cmd done %s.\n", cmd);

	usleep(200);
	os_memset(cmd, 0, 20);
	os_memcpy(cmd, "SET_CFG reload", 14);
	ret = wpa_driver_set_cmd_common(priv, cmd, buf, buf_len);
	usleep(200);

	/* Call back to wpa_supplicant to trigger "wpa_cli reattach" */
	if (wpa_driver_check_reattach_allow(priv))
		wpa_driver_nl80211_reattach(drv);

	return ret;
}

/*
 * cmd: "driver get_cnm".
*/
int wpa_get_cnm_cmd(void *priv, char *cmd, char *buf, size_t buf_len)
{
    int ret = -1;
    char *ret_buf = NULL;

    ret = wpa_driver_set_cmd_common(priv, cmd, buf, buf_len);
    if (ret < 0) {
            wpa_printf(MSG_ERROR, "wpa_get_cnm_cmd %s %d\n", cmd, ret);
            return -1;
    }
    wpa_printf(MSG_DEBUG, "%d get_cnm %s ret=%d", __LINE__, cmd, ret);

    snprintf(buf, buf_len, "%s\n", cmd);

    ret_buf = strstr(cmd, GETCNM_STAMODE_KEYWORD);
    if (ret_buf == NULL) {
        cmd[0] = 0;
        return -1;
    }
    ret_buf = strstr(ret_buf, GETCNM_BW_KEYWORD);
    if (ret_buf == NULL) {
        cmd[0] = 0;
        return -1;
    }
    ret_buf += strlen(GETCNM_BW_KEYWORD);
    ret = atoi(ret_buf);
    wpa_printf(MSG_DEBUG, "%d get_cnm %s ret=%d", __LINE__, ret_buf, ret);
    if (ret <= 0 || (ret % 20) || ret > 80) {
        /* make sure return value are 20, 40 or 80 and there is no reminder divided by 20. */
        cmd[0] = 0;
        return -1;
    }

    sprintf(cmd, "%d\n", ret);

    return ret;
}

/*
 * cmd: "driver get_cfg Sta5gBw".
*/
static int wpa_get_sta5gbw_cmd(void *priv, char *cmd, char *buf, size_t buf_len)
{
    struct i802_bss *bss = priv;
    struct wpa_driver_nl80211_data *drv = bss->drv;
    int ret = -1;

    ret = wpa_driver_set_cmd_common(priv, cmd, buf, buf_len);
    if (ret < 0) {
        wpa_printf(MSG_ERROR, "wpa_get_sta5gbw_cmd: getBw(): cmd %s return invalid %d",
                    cmd, ret);
        return -1;
    }

    /* If iwpriv get_cfg can't get value, it means no entry in wifi.cfg and can overwrite */
    if (strlen(cmd) == 0) {
        ret = 0;
    } else {
        ret = atoi(cmd);
        if (ret < GETCNM_MIN_BW || ret > GETCNM_MAX_BW) {
            wpa_printf(MSG_ERROR, "wpa_get_sta5gbw_cmd: getBw(): cmd %s atoi error %d",
                        cmd, ret);
            return -1;
        }
        /* return value is 0-2, so 1 << ret will be 1-4. Times 20 to produce 20/40/80  */
        ret = (1 << ret) * 20;
    }
    sprintf(buf, "%d", ret);
    return ret;
}

int wpa_driver_get_bw_cmd(void *priv, char *cmd_str, char *buf, size_t buf_len)
{
    char get_cfg_bw_str[] = "GET_CFG Sta5gBw";

    /* translate GET_BW to GET_CFG Sta5gBw */
    strcpy(cmd_str, get_cfg_bw_str);

    return wpa_get_sta5gbw_cmd(priv, cmd_str, buf, buf_len);
}
// fosmod_wifi_thermal_policy end

int wpa_driver_nl80211_driver_cmd(void *priv, char *cmd, char *buf,
				  size_t buf_len )
{
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;
	int ret = -1;

	if (drv == NULL) {
		wpa_printf(MSG_ERROR, "%s: drv is NULL. Exiting", __func__);
		return -1;
	}
	if (drv->ctx == NULL) {
		wpa_printf(MSG_ERROR, "%s: drv->ctx is NULL. Exiting", __func__);
		return -1;
	}

	wpa_printf(MSG_DEBUG, "iface %s ifindex=%d recv cmd: %s len %d rt %d buf_len %d", bss->ifname, drv->ifindex, 
				cmd, os_strlen("GET_CFG"), os_strncasecmp(cmd, "GET_CFG", os_strlen("GET_CFG")), os_strlen(cmd));

	if (os_strncasecmp(cmd, "POWERMODE ", 10) == 0) {
		int state;
		state = atoi(cmd + 10);
		wpa_printf(MSG_DEBUG, "POWERMODE=%d", state);
	}  else if (os_strncasecmp(cmd, "GET_STA_STATISTICS ", 19) == 0) {
		ret = 0;
	} else if (os_strncasecmp(cmd, "SETSUSPENDMODE ", 15) == 0) {
		ret = 0;
	}  else if (os_strncmp(cmd, "MACADDR", os_strlen("MACADDR"))==0) {
		u8 macaddr[ETH_ALEN] = {};
		ret = linux_get_ifhwaddr(drv->global->ioctl_sock, bss->ifname, macaddr);
		if (!ret)
			ret = os_snprintf(buf, buf_len, "Macaddr = " MACSTR "\n", MAC2STR(macaddr));
	} else if(os_strncasecmp(cmd, "COUNTRY", os_strlen("COUNTRY"))==0) {
		if (os_strlen(cmd) != os_strlen("COUNTRY") + 3) {
			wpa_printf(MSG_DEBUG, "Ignore COUNTRY cmd %s", cmd);
			ret = 0;
		} else {
			wpa_printf(MSG_INFO, "Set country: %s", cmd + 8);
			ret = wpa_driver_nl80211_set_country(priv, cmd + 8);
		}
	} else if (os_strcasecmp(cmd, "start") == 0) {
		ret = 0;
	} else if (os_strcasecmp(cmd, "stop") == 0) {
		ret = 0;
	} else if (os_strncasecmp(cmd, "getpower", 8) == 0) {
		ret = 0;
	} else if (os_strncasecmp(cmd, "get-rts-threshold", 17) == 0) {
		ret = 0;
	} else if (os_strncasecmp(cmd, "set-rts-threshold", 17) == 0) {
		ret = 0;
	} else if (os_strncasecmp(cmd, "rxfilter-add", 12) == 0 ) {
		ret = 0;
	} else if (os_strncasecmp(cmd, "rxfilter-remove", 15) == 0 ) {
		ret = 0;
	} else if (os_strncasecmp(cmd, "rxfilter-stop", 13) == 0 ) {
		ret = 0;
	} else if (os_strncasecmp(cmd, "rxfilter-start", 14) == 0 ) {
		ret = 0;
	} else if (os_strncasecmp(cmd, "btcoexscan-start", 16) == 0) {
		ret = 0;
	} else if (os_strncasecmp(cmd, "btcoexscan-stop", 15) == 0) {
		ret = 0;
	} else if( os_strncasecmp(cmd, "btcoexmode", 10) == 0 ) {
		ret = 0;
	} else if (os_strncasecmp(cmd, "ANT_DIV",
		os_strlen("ANT_DIV")) == 0) {

		struct iwreq wrq;
		int skfd = -1;

		wpa_printf(MSG_DEBUG, "[ANT_DIV] command %s", cmd);

		/* zeroize */
		memset(&wrq, 0, sizeof(struct iwreq));

		/* initialize skfd */
		skfd = socket(PF_INET, SOCK_DGRAM, 0);
		if (skfd < 0) {
			wpa_printf(MSG_ERROR,
				"[%s] : failed to opern net socket in %s\n",
				strerror(errno), __func__);
			ret = -1;
			return ret;
		}

		/* configure struct iwreq */
		wrq.u.data.pointer = cmd;
		wrq.u.data.length = 15;
		wrq.u.data.flags = 15; /* PRIV_CMD_OID (TBD) */

		/* Set device name */
		strncpy(wrq.ifr_name, "wlan0", (IFNAMSIZ - 1));

		/* IOCTL_GET_DRIVER */
		ret = ioctl(skfd, SIOCIWFIRSTPRIV + 15, &wrq);
		if (ret < 0) {
			wpa_printf(MSG_ERROR,
			"[ANT_DIV] ioctl failed and returned errno %s\n",
			strerror(errno));
		}
		wpa_printf(MSG_DEBUG, "[ANT_DIV] res=%s", cmd);

		ret = snprintf(buf, buf_len, "%s\n", cmd);
		wpa_printf(MSG_DEBUG, "[ANT_DIV] ret=%d", ret);

		close(skfd);
	} else if (os_strncasecmp(cmd, "SET_ACT_INTV", os_strlen("SET_ACT_INTV")) == 0 ) {
		ret = wpa_driver_set_act_intv(priv, cmd, buf, buf_len);
	} else if (os_strncasecmp(cmd, "ENFORCE_POWER_MODE", os_strlen("ENFORCE_POWER_MODE")) == 0 ) {
		ret = wpa_driver_enforce_power_mode(priv, cmd);
	} else if (os_strncasecmp(cmd, "SET_1RPD", os_strlen("SET_1RPD")) == 0 ) {
		ret = wpa_driver_set_cmd_common(priv, cmd, buf, buf_len);
	} else if (os_strncasecmp(cmd, "SET_MMPS", os_strlen("SET_MMPS")) == 0 ) {
		ret = wpa_driver_set_cmd_common(priv, cmd, buf, buf_len);
	} else if (os_strncasecmp(cmd, "SET_CFG", os_strlen("SET_CFG")) == 0 ) {
		ret = wpa_driver_set_cmd_common(priv, cmd, buf, buf_len);
// fosmod_wifi_thermal_policy begin
	} else if (os_strncasecmp(cmd, "GET_CFG", os_strlen("GET_CFG")) == 0 ) {
		ret = wpa_driver_set_cmd_common(priv, cmd, buf, buf_len);
// fosmod_wifi_thermal_policy end
	} else if (os_strncasecmp(cmd, "SET_ADM", os_strlen("SET_ADM")) == 0 ) {
		ret = wpa_driver_set_cmd_common(priv, cmd, buf, buf_len);
	} else if (os_strncasecmp(cmd, "GET_ADM", os_strlen("GET_ADM")) == 0 ) {
		ret = wpa_driver_set_cmd_common(priv, cmd, buf, buf_len);
	} else if (os_strncasecmp(cmd, "ADMINCTRL", os_strlen("ADMINCTRL")) == 0 ) {
		ret = wpa_driver_set_cmd_common(priv, cmd, buf, buf_len);
// fosmod_wifi_thermal_policy begin
	} else if (os_strncasecmp(cmd, "GET_BW", os_strlen("GET_BW")) == 0 ) {
		ret = wpa_driver_get_bw_cmd(priv, cmd, buf, buf_len);
	} else if (os_strncasecmp(cmd, "DYN_BW_MODE", os_strlen("DYN_BW_MODE"))==0) {
		ret = wpa_set_dyn_mode(priv, cmd, buf, buf_len);
// fosmod_wifi_thermal_policy end
	} else {
		if ( os_strlen(cmd) >= 15 ) cmd[15] = '\0'; // make sure cmd buffer not over-run in printf
		wpa_printf(MSG_WARNING,"Unsupported command %s", cmd);
	}
	return ret;
}


int wpa_driver_set_p2p_noa(void *priv, u8 count, int start, int duration)
{
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;

	wpa_printf(MSG_DEBUG, "iface %s P2P_SET_NOA %d %d %d, ignored", bss->ifname, count, start, duration);
	return -1;
}

int wpa_driver_get_p2p_noa(void *priv, u8 *buf, size_t len)
{
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;

	wpa_printf(MSG_DEBUG, "iface %s P2P_GET_NOA, ignored", bss->ifname);
	return -1;
}

int wpa_driver_set_p2p_ps(void *priv, int legacy_ps, int opp_ps, int ctwindow)
{
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;

	wpa_printf(MSG_DEBUG, "iface %s P2P_SET_PS, ignored", bss->ifname);
	return -1;
}

int wpa_driver_set_ap_wps_p2p_ie(void *priv, const struct wpabuf *beacon,
				 const struct wpabuf *proberesp,
				 const struct wpabuf *assocresp)
{
	struct i802_bss *bss = priv;
	struct wpa_driver_nl80211_data *drv = bss->drv;

	wpa_printf(MSG_DEBUG, "iface %s set_ap_wps_p2p_ie, ignored", bss->ifname);
	return 0;
}
