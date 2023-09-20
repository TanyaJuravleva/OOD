# Минимальная версия CMake: 3.8
cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

# Имя проекта: sfml-lab-1
project( sfml-lab-1)

# Подкаталог 00 содержит ещё один CMakeLists.txt
add_subdirectory(00)
add_subdirectory(01)
add_subdirectory(02)