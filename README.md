# Build-System-for-MSP432-Coursera-Assignment

In this Project, I have written a Makefile to compile and build all the source and header files into a single executable that can be downloaded or flashed on the MSP432P401R. The makefile consists of various architecture specific flags and compile time switches. It aslo, has various targets like creating a dependency file from a .c file, creating a .i file from its corresponding .c file, the 'build' target, etc.

This was done to fulfill an assignment requirement for the 'Introduction to Embedded Systems Sotware and Development Environment' Course on Coursera provided by UC Boulder. Some of the source files are written by the course instructors, as they were provided to us as a part of the assignment. Our task was to write a makefile that achieved the various course objectives. The final Makefile is placed under 'src' folder.

- To compile this code on Arch-Linux:
  - Download ```arm-none-eabi-gcc-9``` : [gcc-arm-none-eabi-9-2019-q4-major-aarch64-linux.tar.bz2](https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2019q4/gcc-arm-none-eabi-9-2019-q4-major-aarch64-linux.tar.bz2?revision=4583ce78-e7e7-459a-ad9f-bff8e94839f1&hash=EE4BA674F815B508E1986A0B6790E4B329DCF1DC)
  - Or From &#8594; https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads
  - Download ```ncurses5``` for ```arm-none-eabi-gdb``` with your AUR Helper : ```$ <AUR_Helper> -S ncurses5-compat-libs``` 
