cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME ETH)

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    C:/stm32/ETH/Core/Src/lan8742.c
    C:/stm32/ETH/Core/Src/parseSV.c
    C:/stm32/ETH/data/data.c

    C:/stm32/ETH/DSP/Source/TransformFunctions/arm_cfft_f32.c
    C:/stm32/ETH/DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.c
    C:/stm32/ETH/DSP/Source/TransformFunctions/arm_bitreversal2.c
    C:/stm32/ETH/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.c
    C:/stm32/ETH/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.c
    C:/stm32/ETH/DSP/Source/TransformFunctions/arm_rfft_fast_f32.c
    C:/stm32/ETH/DSP/Source/CommonTables/arm_common_tables.c

    C:/stm32/ETH/DSP/Source/SupportFunctions/arm_q31_to_float.c

    C:/stm32/ETH/FFT/fft.c

# Add user sources here
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    C:/stm32/ETH/DSP/Include
    C:/stm32/ETH/Drivers/CMSIS/Include
    C:/stm32/ETH/Drivers/CMSIS/Core/Include
    C:/stm32/ETH/FFT
    # Add user defined include paths
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)

set(CMAKE_C_FLAGS_DEBUG "-O0 -g3")
set(CMAKE_C_FLAGS_RELEASE "-O2")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -u _printf_float")



add_compile_options(
    -mcpu=cortex-m7
    -std=gnu11
    -DUSE_PWR_LDO_SUPPLY
    -DDEBUG
    -mfloat-abi=hard
    -mfpu=fpv5-d16
    -DARM_MATH_CM7
    -DUSE_HAL_DRIVER
    -DSTM32H750xx
)
