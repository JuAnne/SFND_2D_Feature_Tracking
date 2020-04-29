# WSL and VSCode Installation Instructions
__NOTE: this is the recommended way for Windows users to work on Udacity C++ projects (for SFND,SDCND, CPPND, etc)__

* _Windows Subsystem for Linux_ (WSL) allows us to easily use Ubuntu without the overhead commonly associated with VMs.
* _VSCode_ is a cross-platform IDE which can be easily configured for C++. It's very light, yet surprisingly powerful once configured.

## Install WSL 
1. install Ubuntu WSL by following [offical installation guide](https://docs.microsoft.com/en-us/windows/wsl/install-win10)
2. launch Ubuntu from inside Windows
3. run the following shell commands:
```shell
$ sudo apt-get update
$ sudo apt-get install build-essential
$ sudo apt-get install cmake
```

## Install VSCode
You can also follow the [offical instructions](https://code.visualstudio.com/docs/cpp/config-wsl)

1. install [VSCode for Windows](https://code.visualstudio.com/)
2. launch VSCode
3. install the C++ extension from the built-in _Extension Marketplace_
4. run the following Ubuntu shell commands:
```shell
$ cd ~
$ mkdir projects
$ cd projects
$ mkdir hello
$ cd hello
$ code .
```
5. you may need to install the C++ extension on the Ubuntu remote VSCode (via _Extensions_)
6. select _C\C++: Edit Configurations_ from the _Command Palette_ (`Ctrl+Shft+P`). set the compiler path as `/usr/bin/gcc` and IntelliSense configuration as `gcc-x64`
7. install the _CMake Tools_ extension
8. create a `hello.cpp` file  with the following contents:
```c++
#include <iostream>
#include <string>

int main()
{
   const std::string msg{"Hello World!"};
   std::cout << msg << std::endl;
   return EXIT_SUCCESS;
}
```
9. create a `CMakeLists.txt` file with the following contents:
```cmake
cmake_minimum_required(VERSION 3.10.2)
project(hello VERSION 0.0.1 LANGUAGES CXX)

add_executable(hello hello.cpp)
```
10. open `CMakeLists.txt` and then run _CMAKE: Build_ from the _Command Palette_ 

11. once the project has been built, run _CMAKE: Execute The Current Target Without a Debugger_ from the _Command Palette_


## Install PCL (SFND Students)

1. install PCL via the Ubuntu terminal:
```shell
$ sudo apt install libpcl-dev
```

2. clone, build, and run the lidar project
```shell
$ cd ~/projects
$ git clone https://github.com/udacity/SFND_Lidar_Obstacle_Detection.git
$ cd SFND_Lidar_Obstacle_Detection
$ mkdir build
$ cd build
$ cmake ..
$ make
$> ./environment
```

## Compile and Install OpenCV with Contrib modules (SFND Students)

0.  install pre-requisites
```shell 
$ sudo apt install build-essential cmake git pkg-config libgtk-3-dev
$ sudo apt install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev libx264-dev
$ sudo apt install libjpeg-dev libpng-dev libtiff-dev gfortran openexr libatlas-base-dev
$ sudo apt install python3-dev python3-numpy libtbb2 libtbb-dev libdc1394-22-dev
```

1. clone `opencv` and `opencv_contrib` repositories
```shell
$ cd ~
$ mkdir opencv_with_contrib
$ cd opencv_with_contrib
$ git clone https://github.com/opencv/opencv.git
$ git clone https://github.com/opencv/opencv_contrib.git
```

2. set `opencv` and `opencv_contrib` versions to be built
```shell
$ cd opencv
$ git checkout 4.1.1
$ cd ../opencv_contrib
$ git checkout 4.1.1
$ cd ..
```

3. build the project (_NOTE:_ this will take some time with heavy CPU usage) 
```shell
$ mkdir build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=RELEASE -DOPENCV_ENABLE_NONFREE=ON -DENABLE_PRECOMPILED_HEADERS=OFF -DOPENCV_EXTRA_MODULES_PATH=~/opencv_with_contrib/opencv_contrib/modules -DBUILD_opencv_legacy=OFF -DCMAKE_INSTALL_PREFIX=/usr/local ../opencv            
$ make -j5
$ make install
```
_NOTE:_ if errors emerge during the build step, such that their printout points to Windows system paths, consider disabling [WSL/Windows interop](https://docs.microsoft.com/en-us/windows/wsl/interop): 
```shell
$ sudo -s
$ echo 0 > /proc/sys/fs/binfmt_misc/WSLInterop
$ exit
```

4. validate installation by compiling the 2d camera feature tracking project
```shell
$ cd ~/projects
$ git clone https://github.com/udacity/SFND_2D_Feature_Tracking.git
$ cd SFND_2D_Feature_Tracking
$ mkdir build
$ cd build
$ cmake ..
$ make
```

__Credits:__ [linuxize.com](https://linuxize.com/post/how-to-install-opencv-on-ubuntu-18-04/), [opencv_contrib](https://github.com/opencv/opencv_contrib), [opencv docs](https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html)