/****************************************************************************
*
* Copyright 2018 Primesoft All Rights Reserved.
*
* Filename: 522_wifi.h
* Author: enj.park, yr.kim
* Release date: 2018/05/02
* Version: 2.0
*
****************************************************************************/

#ifndef WIFI_H_
#define WIFI_H_

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <artik_module.h>
#include <artik_wifi.h>
#include <artik_network.h>

#define WIFI_SCAN_TIMEOUT       15
#define WIFI_CONNECT_TIMEOUT    30
#define WIFI_DISCONNECT_TIMEOUT 10

struct callback_result {
	sem_t sem;
	artik_wifi_connection_info info;
	artik_error error;
};

void wifi_connect_callback(void *result, void *user_data);
int wifi_connect(const char* ssid, const char* passphrase);
int start_dhcp_client(void);

#endif /* WIFI_H_ */
