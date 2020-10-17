cmake_minimum_required(VERSION 3.17)
set(CMAKE_C_STANDARD 99)

# TODO: Change to project name
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
# TODO: Change to your local AVR directory
set(AVR C:/WinAVR)
SET(AVRBIN ${AVR}/bin)
SET(AVROBJCOPY avr-objcopy)
SET(AVRSIZE avr-size)


# Compiler settings and flags
SET(CMAKE_C_COMPILER ${AVRBIN}/avr-gcc)

SET(CMAKE_C_FLAGS  "-mmcu=${MCU} -DF_CPU=${F_CPU} -I. -g -O${OPT} -I${INCPATH} \
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

# All source files
# TODO: Add your other source files here
set(SOURCES ${TARGET} lib/asuro.c lib/adc.c lib/adc_low.c lib/encoder.c lib/encoder_low.c lib/globals.c
        lib/i2c.c lib/lcd.c lib/leds.c lib/motor.c lib/motor_low.c lib/my_motor_low.c
        lib/print.c lib/printf.c lib/rc5.c lib/sound.c lib/switches.c lib/time.c lib/uart.c
        lib/ultrasonic.c lib/version.c)


# Include header files
include_directories(${AVR}/avr/include ${LIBPATH} ${INCPATH})

SET(SOURCE_FILES src/main.c asuro.c adc.c adc_low.c encoder.c encoder_low.c globals.c
        i2c.c lcd.c leds.c motor.c motor_low.c my_motor_low.c
        print.c printf.c rc5.c sound.c switches.c time.c uart.c
        ultrasonic.c version.c)

ADD_EXECUTABLE(${CMAKE_PROJECT_NAME} ${SOURCES})


# Commands to compile and build hex file
ADD_CUSTOM_COMMAND(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD COMMAND ${AVRBIN}/${AVROBJCOPY} -O ihex -R .eeprom ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_PROJECT_NAME}.elf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_PROJECT_NAME}.hex)
ADD_CUSTOM_COMMAND(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD COMMAND ${AVRBIN}/${AVRSIZE} --target=ihex ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_PROJECT_NAME}.hex)