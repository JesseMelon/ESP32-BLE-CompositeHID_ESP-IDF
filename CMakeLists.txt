# Register the ESP32-BLE-CompositeHID component

idf_component_register(
  SRCS
    "BleCompositeHID.cpp"
  INCLUDE_DIRS
    "."
  REQUIRES
    bt
    esp-nimble-cpp
    esp32-3.2.1
  PRIV_REQUIRES
    nvs_flash
)