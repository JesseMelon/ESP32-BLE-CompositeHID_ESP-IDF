#ifndef ESP32_BLE_MULTI_HID_H
#define ESP32_BLE_MULTI_HID_H
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)

#ifdef ARDUINO
#include "nimconfig.h"
#endif
#if defined(CONFIG_BT_NIMBLE_ROLE_PERIPHERAL)

#include "BleConnectionStatus.h"
#include "NimBLEHIDDevice.h"
#include "NimBLECharacteristic.h"

#include "BLEHostConfiguration.h"
#include "BaseCompositeDevice.h"

#include <vector>
#include "SafeQueue.hpp"

struct BleCompositeHIDConfig {
    std::string deviceName = "ESP32 BLE Composite HID";
    std::string deviceManufacturer = "Espressif";
    uint8_t batteryLevel = 100;
    std::function<void(void*)> onConnect = nullptr;
    std::function<void(void*)> onDisconnect = nullptr;
    std::function<void(NimBLEAdvertising*)> onAdvertisingComplete = nullptr;
    int advertisingTimeoutMS = 0;
};

class BleCompositeHID
{
public:
    BleCompositeHID(BleCompositeHIDConfig conf);
    BleCompositeHID(std::string deviceName = "ESP32 BLE Composite HID", std::string deviceManufacturer = "Espressif", uint8_t batteryLevel = 100);
    ~BleCompositeHID();
    void begin();
    void begin(const BLEHostConfiguration& config);
    void end();
    void addDevice(BaseCompositeDevice* device);
    bool isConnected();
    static void onAdvertisingComplete(NimBLEAdvertising* pAdvertising);
    void queueDeviceDeferredReport(std::function<void()> && reportFunc);
    void sendDeferredReports();
    void beginAdvertising();
    void disconnect();
    void setOnAdvertisingCompleteCallback(std::function<void(NimBLEAdvertising*)> callback);
    void setOnConnectCallback(std::function<void(void*)> callback);
    void setOnDisconnectCallback(std::function<void(void*)> callback);
    void setBatteryLevel(uint8_t level);
    uint8_t batteryLevel;
    std::string deviceManufacturer;
    std::string deviceName;
    int advertisingTimeoutMS; // Set to 0 for no timeout

protected:
    virtual void onStarted(NimBLEServer *pServer){};

private:
    static void taskServer(void *pvParameter);
    static void timedSendDeferredReports(void *pvParameter);
    void setOnAdvertisingCompleteCallbackImpl();

    BLEHostConfiguration _configuration;
    BleConnectionStatus* _connectionStatus;
    NimBLEHIDDevice* _hid;

    std::function<void(NimBLEAdvertising*)> _advCompleteCallback;

    std::vector<BaseCompositeDevice*> _devices;
    SafeQueue<std::function<void()>> _deferredReports;
    TaskHandle_t _autoSendTaskHandle;
};

#endif // CONFIG_BT_NIMBLE_ROLE_PERIPHERAL
#endif // CONFIG_BT_ENABLED
#endif // ESP32_BLE_MULTI_HID_H
