#include "BleConnectionStatus.h"

BleConnectionStatus::BleConnectionStatus(void)
{
}

void BleConnectionStatus::setOnConnectCallback(std::function<void(void*)> callback)
{
    onConnectCallback = callback;
}

void BleConnectionStatus::onConnect(NimBLEServer *pServer, NimBLEConnInfo& connInfo)
{
    // Reject multiple simultaneous connections // TODO: favour new connection?
    if (pServer->getConnectedCount() > 1) {
        pServer->disconnect(connInfo.getConnHandle());
    }
    pServer->updateConnParams(connInfo.getConnHandle(), 6, 7, 0, 600);  // this line has 6, 12, 0, 600 as a previous revision

    if (onConnectCallback != nullptr) onConnectCallback(nullptr);
}

void BleConnectionStatus::setOnDisconnectCallback(std::function<void(void*)> callback)
{
    OnDisconnectCallback = callback;
}

void BleConnectionStatus::onDisconnect(NimBLEServer* pServer, NimBLEConnInfo& connInfo, int reason)
{
    this->connected = false;
    if (OnDisconnectCallback != nullptr) OnDisconnectCallback(nullptr);
}

bool BleConnectionStatus::isConnected(){
    return this->connected;
}

void BleConnectionStatus::onAuthenticationComplete(NimBLEConnInfo& connInfo)
{
    this->connected = true;
}