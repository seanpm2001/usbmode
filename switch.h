#ifndef __USBMODE_SWITCH_H
#define __USBMODE_SWITCH_H

#include <libubox/blobmsg.h>
#include <libusb.h>

struct usbdev_data {
	struct libusb_device_descriptor desc;
	struct libusb_config_descriptor *config;
	libusb_device_handle *devh;
	struct blob_attr *info;
	int interface;
	int msg_endpoint;
	int response_endpoint;

	char idstr[10];
	char mfg[128], prod[128], serial[128];
};

extern struct blob_attr **messages;
extern int n_messages;

void handle_switch(struct usbdev_data *data);

#endif
