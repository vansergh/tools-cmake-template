Template for new C++ project

Project name will be generated from name of root dir. Cmake will search all .c .cpp .cxx 
sources and .h .hpp headers within all dirs recursively, starting from current dir. 
You can setup exclude mask/files/dirs in CMakeLists.txt:

```
# Include directory to use with #include <...>
set(INCLUDE_DIRS "include")

# Include list of files to be built
set(SOURCES_INCLUDE_PATH *.cpp *.c *.cxx)
set(HEADERS_INCLUDE_PATH *.hpp *.h)

# Exclude list of files (regxp)
set(EXCLUDE_PATH "(/out|/opt|/res)")
```

You can set C++ Standart there and compiler params

```
# Set C++ Standart
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-Werror)
add_compile_options(-Wfatal-errors)
add_compile_options(-pedantic)
add_compile_options(-pedantic-errors)
#add_compile_options(-Wno-unused-variable)
#add_compile_options(-Wno-unused-parameter)
```

Cmake will display all files included in project before build:

```
[cmake] -- Found headers:
[cmake] -- 		C:/Users/user/source/repos/cmake-template/include/class1/class.hpp
[cmake] 		C:/Users/user/source/repos/cmake-template/include/class2/header_for_class.hpp
[cmake] 		C:/Users/user/source/repos/cmake-template/include/lib.hpp
[cmake] 		C:/Users/user/source/repos/cmake-template/include/source_file1.hpp
[cmake] -- Found sources:
[cmake] -- 		C:/Users/user/source/repos/cmake-template/include/class1/class.hpp
[cmake] 		C:/Users/user/source/repos/cmake-template/include/class2/header_for_class.hpp
[cmake] 		C:/Users/user/source/repos/cmake-template/include/lib.hpp
[cmake] 		C:/Users/user/source/repos/cmake-template/include/source_file1.hpp
```

Dirs:

include - for libraries, includes, heades of your project (you can delete all inside this dir.)
opt     - for external libs
out     - ignored in .gitignore this is output dir of cmake
res     - resources dir
src     - your sources (main.cpp if you want)

Boost and Openssl (find_package in cmake/boost.cmake and cmake/openssl.cmake)

```
#include boost lib
include(cmake/boost.cmake)

#include boost lib
include(cmake/openssl.cmake)

...

# Build executable with boost
TARGET_LINK_LIBRARIES(${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES})

# Build executable with openssl
TARGET_LINK_LIBRARIES(${PROJECT_NAME} LINK_PUBLIC ${OPENSSL_LIBRARIES})
```
