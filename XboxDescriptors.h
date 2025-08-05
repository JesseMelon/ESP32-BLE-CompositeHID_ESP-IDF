
#ifndef XBOX_DESCRIPTORS_H
#define XBOX_DESCRIPTORS_H

#include <stdint.h>

#define XBOX_VENDOR_ID 0x045E

// Product: Xbox Wireless controller
#define XBOX_1708_ALT_PRODUCT_ID 0x02e0 

// Product: Xbox One S controller (supports linux kernel < 6.5)
// Menu/select button replaces share button
#define XBOX_1708_PRODUCT_ID 0x02fd
#define XBOX_1708_BCD_DEVICE_ID 0x0408
#define XBOX_1708_SERIAL "3033363030343037323136373239"

// Product: latest Xbox series X wireless controller
// Share button valid
#define XBOX_1914_PRODUCT_ID 0x0B13
#define XBOX_1914_BCD_DEVICE_ID 0x0509
#define XBOX_1914_SERIAL "3039373130303637313034303231"

#define XBOX_INPUT_REPORT_ID 0x01
#define XBOX_EXTRA_INPUT_REPORT_ID 0x02 // Unnecessary for 1914 model
#define XBOX_OUTPUT_REPORT_ID 0x03
#define XBOX_EXTRA_OUTPUT_REPORT_ID 0x04

extern const uint8_t XboxOneS_1914_HIDDescriptor[283];

// Descriptor adapted from:
    // https://github.com/DJm00n/ControllersInfo/blob/master/xboxone/xboxone_model_1708_bluetooth_hid_report_descriptor.txt
extern const uint8_t XboxOneS_1708_HIDDescriptor[334];

#endif