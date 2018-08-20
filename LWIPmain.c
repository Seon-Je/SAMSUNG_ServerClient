/****************************************************************************
*
* Copyright 2018 Primesoft All Rights Reserved.
*
* Filename: 522_LWIPmain.c
* Author: enj.park, yr.kim
* Release date: 2018/05/02
* Version: 2.0
*
****************************************************************************/

#include <stdio.h>
#include <apps/shell/tash.h>
#define WIFI_SSID "[85110]Primesoft"
#define WIFI_PASSPHRASE "Primesoft85110"


static void show_usage(FAR const char *program)
{
	printf("USAGE:\n");
	printf(" %s wifi	   : connect to wifi [lwiptest wifi SSID PASSWORD]\n", program);
	printf(" %s client     : client program test [lwiptest client serverIP PORT]\n", program);
	printf(" %s server     : server program test [lwiptest server PORT]\n", program);
}

#ifdef CONFIG_BUILD_KERNEL
int main(int argc, FAR char *argv[])
#else
int lwip_main(int argc, FAR char *argv[])
#endif
{
	int ret = 0;

	// lwiptest wifi SSID PASSWORD -> argc 4
	// lwiptest server PORT -> argc 3
	// lwiptest client serverIP PORT -> argc 4
	switch (argc) {
	case 3: // server
		if (strcmp(argv[1], "server") == 0) {
			server_main(argc, argv);
		}	else {
			show_usage(argv[0]);
		}
		break;
	case 4: // wifi, client
		if (strcmp(argv[1], "client") == 0)
		{
			client_main(argc, argv);
		}
		else if (strcmp(argv[1], "server") == 0)
		{
			server_main(argc, argv);
		}
		else if (strcmp(argv[1], "wifi") == 0)
		{
			wifi_main(argc, argv);
		}
		else
		{
			show_usage(argv[0]);
		}
		break;
	default:
		show_usage(argv[0]);
		break;
	}

	return ret;
}

int main(int argc, FAR char *argv[])
{
		tash_cmd_install("lwiptest", lwip_main, TASH_EXECMD_SYNC);
	return 0;
}
