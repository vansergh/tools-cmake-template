Template for new C++ project

Project name will be generated from name of root dir. Cmake will search all .c .cpp .cxx 
sources and .h .hpp headers within all dirs recursively, starting from current dir. 
You can setup exclude mask/files/dirs in CMakeLists.txt:

```
# Include list of files to be built
set(SOURCES_INCLUDE_PATH *.cpp *.c *.cxx)
set(HEADERS_INCLUDE_PATH *.hpp *.h)

# Exclude list of files (regxp)
set(EXCLUDE_PATH "(/out|/opt|/res)")
```

You can set C++ Standart there

```
# Set C++ Standart
set(CMAKE_CXX_STANDARD 17)
```

Cmake will display all files included in project before build:

```
[cmake] -- Found headers:
[cmake] -- 		C:/Users/user/source/repos/cmake-template/lib/class1/class.hpp
[cmake] 		C:/Users/user/source/repos/cmake-template/lib/class2/header_for_class.hpp
[cmake] 		C:/Users/user/source/repos/cmake-template/lib/lib.hpp
[cmake] 		C:/Users/user/source/repos/cmake-template/lib/source_file1.hpp
[cmake] -- Found sources:
[cmake] -- 		C:/Users/user/source/repos/cmake-template/lib/class1/class.hpp
[cmake] 		C:/Users/user/source/repos/cmake-template/lib/class2/header_for_class.hpp
[cmake] 		C:/Users/user/source/repos/cmake-template/lib/lib.hpp
[cmake] 		C:/Users/user/source/repos/cmake-template/lib/source_file1.hpp
```

Dirs:

lib - for libraries, includes, heades of your project (you can delete all inside this dir.)
opt - for external libs
out - ignored in .gitignore this is output dir of cmake
res - resources dir
src - your sources (main.cpp if you want)
