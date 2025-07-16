# Register the ESP32-BLE-CompositeHID component
idf_component_register(
  SRCS
    "BleCompositeHID.cpp"
    "BaseCompositeDevice.cpp"
    "BleConnectionStatus.cpp"
    "BLEHostConfiguration.cpp"
    "GamepadConfiguration.cpp"
    "GamepadDevice.cpp"
    "XboxGamepadConfigurations.cpp"
    "XboxGamepadDevice.cpp"
  INCLUDE_DIRS
    "."
  REQUIRES
    bt
    esp-nimble-cpp  # NimBLE
    esp32-3.2.1     # Arduino
    Callback
  PRIV_REQUIRES
    nvs_flash
)