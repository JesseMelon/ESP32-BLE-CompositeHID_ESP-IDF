# Register the ESP32-BLE-CompositeHID component

if(__COMPONENT_TARGETS MATCHES "___idf_esp-nimble-component")
    list(APPEND ESP_NIMBLE_PRIV_REQUIRES
        esp-nimble-component
    )
elseif(__COMPONENT_TARGETS MATCHES "__idf_nimble")
    list(APPEND ESP_NIMBLE_PRIV_REQUIRES
        nimble
    )
endif()

idf_component_register(
  SRCS
    "XboxDescriptors.cpp"
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
    esp-nimble-cpp
    Callback
  # esp32-3.2.1     # Arduino
  PRIV_REQUIRES
    bt
    nvs_flash
)