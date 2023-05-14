# CMakeList.txt: проект CMake для Lecture; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project (Vector)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Vector  "Headers/Vector.hpp" "Source/test.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
