cmake_minimum_required (VERSION 3.12)

project (data_struct)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSION OFF)

file(MAKE_DIRECTORY bin)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)

# if compiler is Clang, link libc++, otherwise, link default libstdc++
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -fsanitize=signed-integer-overflow")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
endif()

include_directories (utils)

file (GLOB files *.cpp */*.cpp */*/*.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()

#add_subdirectory(target_target_to_the_offerto_the_offer)