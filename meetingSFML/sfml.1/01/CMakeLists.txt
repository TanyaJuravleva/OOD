# Этот текст — скрипт сборки на языке CMake. В этом скрипте мы подключаем три модуля SFML (window, graphics, system), 
# устанавливаем версию языка (C++2017), настраиваем зависимости SFML (библиотеки libjpeg и freetype). 
# Если бы мы напрямую вызывали g++, нам бы пришлось писать очень длинные команды — скрипт позволяет такого избежать.

# set(CMAKE_CXX_STANDARD 26)
# set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")

add_executable(01 main.cpp)
set(SFML_STATIC_LIBRARIES TRUE)

# set(SFML_DIR "C:\\Program Files\\SFML-2.5.1\\lib\\cmake\\SFML")

#find_package(Freetype)
#find_package(JPEG)
#set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2 COMPONENTS window graphics system) 

# COMPONENTS
target_compile_features(01 PUBLIC cxx_std_17)
target_compile_definitions(01 PRIVATE SFML_STATIC)


# target_link_libraries(01 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
target_link_libraries(01 sfml-graphics sfml-window sfml-system)

# set(SFML_DIR "include/sfml/lib/cmake/SFML")

# target_link_libraries(GammaEngine 
#     PUBLIC sfml-graphics 
#     PUBLIC sfml-window 
#     PUBLIC sfml-system)