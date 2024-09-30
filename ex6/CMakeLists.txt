cmake_minimum_required(VERSION 3.12)

# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(blinky C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_compile_options(-Wall
	-Wno-format
	-Wno-unused-function
	-Wno-maybe-uninitialized
)

set(SOURCE_FILES src/led.c)

add_executable(blinky src/led.c)

target_include_directories(
	${PROJECT_NAME}
  	PRIVATE
  	${CMAKE_CURRENT_SOURCE_DIR}/inc	
	)

pico_add_extra_outputs(blinky)
target_link_libraries(blinky pico_stdlib)

pico_enable_stdio_usb(blinky 0)
pico_enable_stdio_uart(blinky 1)

