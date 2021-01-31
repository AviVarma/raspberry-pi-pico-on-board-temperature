cmake_minimum_required(VERSION 3.12)

# Change your executable name to something creative!
set(NAME OnBoardTemp) # <-- Name your project/executable here!

include(pico_sdk_import.cmake)

# Gooey boilerplate
project(OnBoardTemp C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Add your source files
add_executable(OnBoardTemp
    main.cpp # <-- Add source files here!
)

# Include required libraries
# This assumes `pimoroni-pico` is stored alongside your project
# include(../pimoroni-pico/libraries/pico_explorer/pico_explorer.cmake)
# include(../pimoroni-pico/libraries/pico_display/pico_display.cmake)

# Don't forget to link the libraries you need!
target_link_libraries(OnBoardTemp
    pico_stdlib # <-- List libraries here!
    hardware_adc
    hardware_gpio
)

# create map/bin/hex file etc.
pico_enable_stdio_usb(OnBoardTemp 1)
pico_enable_stdio_uart(OnBoardTemp 0)
pico_add_extra_outputs(OnBoardTemp)

# Set up files for the release packages
# install(FILES
#     ${CMAKE_CURRENT_BINARY_DIR}/OnBoardTemp.uf2
#     ${CMAKE_CURRENT_LIST_DIR}/README.md
#     DESTINATION .
# )

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)
