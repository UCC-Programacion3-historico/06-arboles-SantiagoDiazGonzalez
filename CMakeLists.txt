cmake_minimum_required(VERSION 3.2)
project(06_Arboles)

set(CMAKE_CXX_STANDARD 14)

# Agrego todos los test.
add_subdirectory(test)

set(SOURCE_FILES_01 Ej-01/main.cpp ArbolBinario/ArbolBinario.h ArbolBinario/NodoArbol.h prueba/main.cpp)
add_executable(Ej-01 ${SOURCE_FILES_01})

set(SOURCE_FILES_03 Ej-03/main.cpp)
add_executable(Ej-03 ${SOURCE_FILES_03})

set(SOURCE_FILES_04 Ej-04/main.cpp)
add_executable(Ej-04 ${SOURCE_FILES_04})

set(SOURCE_FILES_05 prueba/main.cpp)
add_executable(prueba ${SOURCE_FILES_05})
