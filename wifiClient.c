/****************************************************************************
*
* Copyright 2018 Primesoft All Rights Reserved.
*
* Filename: 521_wifiClient.c
* Author: enj.park, yr.kim
* Release date: 2018/05/02
* Version: 2.0
*
****************************************************************************/

#include <stdio.h>
#include <apps/shell/tash.h>
#include "wifi.h"

int wifi_main(int argc, char *argv[]) {

	if (argc != 4) {
		printf("usage: lwiptest wifi SSID PASSWORD\n");
		return -1;
	}

	printf("============= WiFi Test Start =============\n");

	if (wifi_connect(argv[2], argv[3]) != 0) {
		return -1;
	}

	start_dhcp_client();

	printf("============== WiFi Test End ==============\n");
	return 0;
}
/*
int main(int argc, FAR char *argv[]){
	tash_cmd_install("wifitest", wifi_main, TASH_EXECMD_SYNC);
	return 0;
}
*/
