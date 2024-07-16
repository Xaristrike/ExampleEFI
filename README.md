# ExampleEFI Application

This repository contains an EFI (Extensible Firmware Interface) application written in C.

## Prerequisites

### This application is made to run in a Linux environment

Before running this application, ensure you have the following tools and dependencies installed:

- `clang` for compiling.
- `mkfs.vfat` utility for creating the file system needed.
- `make` for building.
- `qemu-system` for running.

## Installing prerequisites

Install all the packages needed:
```bash
sudo apt install make clang dosfstools qemu-system
```

## Building

To build the EFI application:

1. **Clone Repository:**
```bash
git clone https://github.com/Xaristrike/ExampleEFI
```
```bash
cd ExampleEfi
```
2. **Compile the Application:**
```bash
make
```

## Running with QEMU
To run the EFI application using QEMU:
```bash
make qemu
```

## Running in Text Mode with QEMU
To run the EFI application in text mode, where QEMU outputs to the terminal:
```bash
make qemunographic
```

## Cleaning Up
To clean up build files and other temporary files:
```bash
make clean
```

## About the name

"ExampleEFI" is a temporary name.

During development, I was planning

to name this application "AugerXenith"

after one of my favorite Doom WADs.

Maybe this will happen in the future.