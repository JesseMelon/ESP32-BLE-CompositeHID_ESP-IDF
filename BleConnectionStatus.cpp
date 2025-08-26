#include "BleConnectionStatus.h"

BleConnectionStatus::BleConnectionStatus(void)
{
}

void BleConnectionStatus::onConnect(NimBLEServer *pServer, NimBLEConnInfo& connInfo)
{
    // Reject multiple simultaneous connections // TODO: favour new connection?
    if (pServer->getConnectedCount() > 1) {
        pServer->disconnect(connInfo.getConnHandle());
    }
    pServer->updateConnParams(connInfo.getConnHandle(), 6, 12, 0, 600);
}

void BleConnectionStatus::onDisconnect(NimBLEServer* pServer, NimBLEConnInfo& connInfo, int reason)
{
    this->connected = false;
}

bool BleConnectionStatus::isConnected(){
    return this->connected;
}

void BleConnectionStatus::onAuthenticationComplete(NimBLEConnInfo& connInfo)
{
    this->connected = true;
}