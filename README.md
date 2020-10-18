asuro-template
---
This repository is a template project for coding on the [ASURO roboter](https://de.wikipedia.org/wiki/ASURO) with CMake.

## Information
This repository contains the ASURO C library, a sample program and a CMake build file to build the program.
I wanted to use CLion, so I copied and edited the `CMakeLists.txt` file to build the program using CLion and CMake.

An alternative is [Atmel Studio 7](https://www.microchip.com/mplab/avr-support/atmel-studio-7).
Atmel Studio has an embedded AVR toolchain, a build tool and a (semi-clever) IDE.
Therefore, no further installations are required to start developing.

*Note: Most of the mentioned resources will be mirrored in the release as they may become unavailable.* 

### General procedure with ASURO
1. Build your ASURO (soldering and that stuff).
2. Connect the programmer via USB to your PC.
3. Open the ASURO flash program and flash a sample program.
4. The sample program will test your sensors, lights and motor.
5. Start developing your own projects, for instance moving straight forward (it's not that simple tho).

## Prerequisites 
The template was tested on Windows 10 using WinAVR and CLion (MinGW toolchain).
However, the template should work on Unix systems as well.
Just change the paths in `CMakeLists.txt`

### IDE and CMake
I recommend [CLion](https://www.jetbrains.com/de-de/clion/) as IDE, however, every other IDE should be fine.
You have to choose a general toolchain like WSL or MinGW.
I installed MinGW to use commands like `make` on Windows.
Make sure to add it to your PATH variable.

In order to build the project, you need [CMake](https://cmake.org).
CLion has an embedded version of CMake.
Otherwise install it manually.
Once again, don't forget to add it to your PATH variable to use the commands in the console.

### AVR toolchain
You will need an AVR toolchain.
Meanwhile, there exists some different implementations of it.
I tested some toolchains (Atmel AVR, Prebuilt Windows Toolchain by Sysprogs, WinAVR and AVR-GCC by ZAK) and [WinAVR]() works best for me.
However, if you use WinAVR you have to overwrite `utils/bin/msys-1.0.dll` with a modified version (cf. [Uni Regensburg](https://homepages.uni-regensburg.de/~erc24492/WINAVR_unter_WIN10/WINAVR_unter_WIN10.html)).
Once again, don't forget to add the `bin/` directory to your PATH variable.

## Usage
1. Click on `Use this template`.
2. Clone your project.
3. Mark `src/` and `lib/` as `Project sources and headers` by right-click on the directory.
4. Edit and configure `CMakeLists.txt`.
Note the `# TODO: ` comments.
5. Code your stuff.
6. Build it (cf. [Build it](#build-it)).

## Build it
The ASURO flash tool requires a `.hex` file.
Run `cmake` and then `make`.
The `.hex` file will be built into `bin/`.

If you are using Windows and MinGW, the command `cmake -G "MinGW Makefiles" & mingw32-make` will build the file.

## Resources
All the resources are mirrored in the [release]().

- *asuro-lib*. [http://sourceforge.net/projects/asuro/](http://sourceforge.net/projects/asuro/)
- *WinAVR*. [https://sourceforge.net/projects/winavr/](https://sourceforge.net/projects/winavr/)
- *fixed WinAVR file*. [Uni Regensburg](http://homepages.uni-regensburg.de/~erc24492/ELFORT_KURS/WINAVR%20Win10%20Problem/msys-1.0-vista64/msys-1.0.dll) 
- *COM-Port driver*. [http://www.ftdichip.com/Drivers/VCP.htm](http://www.ftdichip.com/Drivers/VCP.htm)
- *ASURO manual*. [http://www.arexx.com/downloads/asuro/asuro_manual_de.pdf](http://www.arexx.com/downloads/asuro/asuro_manual_de.pdf)
- *flash tool*. _(not public)_

## Helpful repositories
- CMake and AVR - https://github.com/toni55/Clion-AVR
- Asuro Makefile - https://gist.github.com/bradfordbarr/9182992

