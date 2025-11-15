# DateCompare
**DateCompare** is a program that compares two input days of the week to see if they are the same.<br>
<img width="409" height="363" alt="image" src="https://github.com/user-attachments/assets/b1bcc13e-24ea-408b-aa15-d17afc35fd77" />

# Features
* Cross-platform support for Windows, macOS, Linux
* Works with only the C++ standard library

# How to use
1. Enter the date you want to compare.
1. Enter another date you want to compare.
1. The results will be displayed.

# Build Instructions
Please note that operation has not been confirmed on any operating system other than Windows.

## Windows
_You will need to have **Visual Studio Developer Command Prompt** or **CMake** installed._

```
cl /std:c++17 /EHsc day_of_week.cpp
```

```
mkdir build
cd build

cmake ..
cmake --build .
```
## macOS
_Compatible with Intel and Apple Silicon Mac._

**Install Xcode Command Line Tools**
```
xcode-select --install
```

**Install CMake (Homebrew is recommended)**
```
brew install cmake
```

**Build**
```
mkdir build
cd build

cmake ..
cmake --build .
```

(Optional) You can specify which one to build for with the following command:
* Build for Intel Mac: `cmake .. -DCMAKE_OSX_ARCHITECTURES=x86_64`
* Build for Apple Silicon Mac: `cmake .. -DCMAKE_OSX_ARCHITECTURES=arm64`

## Linux
_The following commands are based on an example for Ubuntu._

**Install required packages**
```
sudo apt update
sudo apt install build-essential cmake
```

**Build**
```
mkdir build
cd build

cmake ..
cmake --build .
```
