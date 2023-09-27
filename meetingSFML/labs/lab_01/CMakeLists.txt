set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")

add_executable(lab_01 main.cpp)
set(SFML_STATIC_LIBRARIES TRUE)

# find_package(Freetype)
# find_package(JPEG)
find_package(SFML 2 COMPONENTS window graphics system)

target_compile_features(lab_01 PUBLIC cxx_std_17)
target_compile_definitions(lab_01 PRIVATE SFML_STATIC)

# target_link_libraries(02 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
target_link_libraries(lab_01 sfml-graphics sfml-window sfml-system)