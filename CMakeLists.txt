cmake_minimum_required(VERSION 3.17)
SET(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_STANDARD 99)

# TODO: Change name to your project name
project(asuro_template C)

# MCU name and CPU
set(MCU atmega8)
set(F_CPU 8000000UL)

# Optimization level, can be [0, 1, 2, 3, s]. 0 turns off optimization.
# (Note: 3 is not always the best optimization level. See avr-libc FAQ.)
set(OPT s)

# Asuro library path
set(LIBPATH ./lib)
set(INCPATH ${LIBPATH}/inc)

# Main executable
set(TARGET src/main.c)

# AVR commands
# TODO: Change path to your local AVR directory
set(AVR C:/WinAVR)
SET(AVRBIN ${AVR}/bin)
SET(AVROBJCOPY avr-objcopy)
SET(AVRSIZE avr-size)

# Include header files
include_directories(${AVR}/avr/include ${LIBPATH} ${INCPATH})

# All source files
# TODO: Add your other source files here
set(SOURCES ${TARGET}
        ${LIBPATH}/asuro.c ${LIBPATH}/adc.c ${LIBPATH}/adc_low.c ${LIBPATH}/encoder.c
        ${LIBPATH}/encoder_low.c ${LIBPATH}/globals.c ${LIBPATH}/i2c.c ${LIBPATH}/lcd.c
        ${LIBPATH}/leds.c ${LIBPATH}/motor.c ${LIBPATH}/motor_low.c ${LIBPATH}/my_motor_low.c
        ${LIBPATH}/print.c ${LIBPATH}/printf.c ${LIBPATH}/rc5.c ${LIBPATH}/sound.c
        ${LIBPATH}/switches.c ${LIBPATH}/time.c ${LIBPATH}/uart.c ${LIBPATH}/ultrasonic.c ${LIBPATH}/version.c)

# Compiler settings and flags
SET(CMAKE_C_COMPILER ${AVRBIN}/avr-gcc)

SET(CMAKE_C_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -I. -g -O${OPT} -I${INCPATH} \
	-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums \
	-ffunction-sections -fdata-sections \
	-Wall -Wstrict-prototypes")

set(CMAKE_EXE_LINKER_FLAGS -Wl,--gc-sections,-Map=${TARGET}.map,--cref,-L${LIBPATH},-lm)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_PREFIX_PATH ${AVR}/avr)
set(CMAKE_EXECUTABLE_SUFFIX ".elf")

set_property(DIRECTORY PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_PROJECT_NAME}.hex"
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_PROJECT_NAME}.eep"
        )

# Source files and executables
SET(SOURCE_FILES ${SOURCES})
ADD_EXECUTABLE(${CMAKE_PROJECT_NAME} ${SOURCES})

# Commands to compile and build hex file
ADD_CUSTOM_COMMAND(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD COMMAND ${AVRBIN}/${AVROBJCOPY} -O ihex -R .eeprom ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_PROJECT_NAME}.elf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_PROJECT_NAME}.hex)
ADD_CUSTOM_COMMAND(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD COMMAND ${AVRBIN}/${AVRSIZE} --target=ihex ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_PROJECT_NAME}.hex)