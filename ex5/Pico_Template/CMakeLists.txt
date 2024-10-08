cmake_minimum_required(VERSION 3.12)

# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# set(PICO_BOARD pico_w)

# Set name of project (as PROJECT_NAME) and C/C standards
project(LED_PRO C CXX ASM) # Replace <Project Name> with the name of your project
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

add_compile_options(-Wall
  -Wno-format # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
  -Wno-unused-function # we have some for the docs that aren’t called
  -Wno-maybe-uninitialized
)

# Create a variable for your C source files contained in src directory

# Tell CMake where to find the executable source file
add_executable(${PROJECT_NAME}
  # use variable for your C files
  src/led.c
  inc/led.h
  )

# Add target for custom header files
target_include_directories(
	${PROJECT_NAME}
  	PRIVATE
  	${CMAKE_CURRENT_SOURCE_DIR}/inc	
	)
# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(${PROJECT_NAME}
  pico_stdlib
)

# Enable USB output, disable UART output
pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 1)
