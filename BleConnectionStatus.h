#ifndef ESP32_BLE_CONNECTION_STATUS_H
#define ESP32_BLE_CONNECTION_STATUS_H
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)
#ifdef ARDUINO
#include "nimconfig.h"
#else
#include <functional>
#endif
#if defined(CONFIG_BT_NIMBLE_ROLE_PERIPHERAL)

#include <NimBLEServer.h>
#include "NimBLECharacteristic.h"
#include "NimBLEConnInfo.h"

class BleConnectionStatus : public NimBLEServerCallbacks
{
public:
    BleConnectionStatus(void);
    void onConnect(NimBLEServer *pServer, NimBLEConnInfo& connInfo) override;
    void onDisconnect(NimBLEServer *pServer, NimBLEConnInfo& connInfo, int reason) override;
    void setOnConnectCallback(std::function<void(void*)> callback);
    void setOnDisconnectCallback(std::function<void(void*)> callback);
    //NimBLECharacteristic *inputGamepad;
    bool isConnected();
    void onAuthenticationComplete(NimBLEConnInfo& connInfo) override;
private:
    bool connected = false;
    std::function<void(void*)> onConnectCallback = nullptr;
    std::function<void(void*)> OnDisconnectCallback = nullptr;
};

#endif // CONFIG_BT_NIMBLE_ROLE_PERIPHERAL
#endif // CONFIG_BT_ENABLED
#endif // ESP32_BLE_CONNECTION_STATUS_H
