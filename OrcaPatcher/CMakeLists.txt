# CMakeList.txt: проект CMake для OrcaPatcher; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

cmake_minimum_required(VERSION 3.20)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (OrcaPatcher "OrcaPatcher.cpp" "OrcaPatcher.h" "Patcher.cpp")
#target_link_libraries(OrcaPatcher stdc++fs)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OrcaPatcher PROPERTY CXX_STANDARD 20)
endif()

project ("OrcaPatcher")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
