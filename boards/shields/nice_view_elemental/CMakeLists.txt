if(CONFIG_ZMK_DISPLAY AND CONFIG_NICE_VIEW_WIDGET_STATUS)
  zephyr_library_include_directories(${CMAKE_SOURCE_DIR}/include)

  zephyr_library_sources(
    ./src/main.c
    ./src/fonts/custom_font_22.c
    ./src/images/art.c
    ./src/images/bluetooth_logo_outlined.c
    ./src/images/bluetooth_logo.c
    ./src/images/bluetooth_searching.c
    ./src/images/usb_logo.c
    ./src/utils/draw_art.c
    ./src/utils/draw_battery.c
    ./src/utils/draw_bluetooth_logo_outlined.c
    ./src/utils/draw_bluetooth_logo.c
    ./src/utils/draw_bluetooth_searching.c
    ./src/utils/draw_usb_logo.c
    ./src/utils/rotate_connectivity_canvas.c
  )

  if(NOT CONFIG_ZMK_SPLIT OR CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    zephyr_library_sources(
      ./src/central/initialize_listeners.c
      ./src/central/render.c
      # These are not included on the peripheral since they are only used for
      # displaying the layer name.
      ./src/fonts/custom_font_44.c
      ./src/fonts/custom_font_shadow.c
      ./src/fonts/custom_font_outline.c
    )
  else()
    zephyr_library_sources(
      ./src/peripheral/initialize_listeners.c
      ./src/peripheral/render.c
    )
  endif()
endif()
