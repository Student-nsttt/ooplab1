cmake_minimum_required(VERSION 3.14)
project(ArrayOpsConsole CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

# 1. СБОРКА ОСНОВНОЙ ПРОГРАММЫ
add_executable(array_program 
    src/main.cpp 
    src/array_ops.cpp 
    src/array_ops.h
)

# 2. ПОДКЛЮЧЕНИЕ СКАЧАННОГО ЛОКАЛЬНО GOOGLE TEST
# Указываем компилятору собрать gtest из нашей локальной папки
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest)

# 3. СБОРКА ТЕСТОВ
add_executable(array_tests 
    tests/test_variant.cpp 
    src/array_ops.cpp
)

# Связываем тесты с локально собранным gtest
target_link_libraries(array_tests gtest_main)


