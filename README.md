GravNet OS

GravNet OS is a small 16-bit bootable operating system made in C and Assembly for CpE 3106 - Operating Systems (First Semester, AY 2026 - 2027) at the University of San Carlos, Department of Computer Engineering.
Instead of running on Windows or Linux, this project boots on its own to show how an operating system handles keyboard input, memory, and files directly.


What It Does

1. Bootloader and Basic Kernel
  Reads the kernel from the bootable disk image and starts the OS.
  Opens a GravNet> command prompt with system time and basic commands.

2. I/O Management (Keyboard Interrupts)
  Replaces the default BIOS keyboard handler (INT 09h) with a custom Interrupt Service Routine (ISR).
  Reads keystrokes directly from keyboard port 0x60 and stores them in a buffer for the prompt.

3. Memory Management (First-Fit)
  Uses a 4,096-byte static array as the memory pool.
  Uses the First-Fit method to allocate memory (alloc), free blocks and combine nearby free spaces (free), and show the current memory list (mem).

4. File Management (RAM Virtual Disk)
  Uses a struct array in RAM as a virtual disk (up to 16 files, 128 bytes per file) so it works without a real disk filesystem.
  Supports creating, writing, reading, listing, and deleting files.
