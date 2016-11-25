cmake_minimum_required(VERSION 2.8) # проверка версии CMake
project(executable) # название проекта
set(CMAKE_VERBOSE_MAKEFILE ON) # печатать вывод make

# Выставить warning'и
if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
else()
	message(SEND_ERROR "Warning flags are unset" )
endif()

# CMAKE_CURRENT_LIST_DIR -- директория, переданная CMake как корневая
set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(LIB_DIR ${SOURCE_DIR}/libdemo) # инициализировать переменную
message("LIB_DIR == ${LIB_DIR}") # вывести на экран сообщение

# Найти все файлы с расширением ".cpp" в ${LIB_DIR}
file(GLOB_RECURSE LIBDEMO_SOURCES "${LIB_DIR}/*.cpp")

include_directories("${SOURCE_DIR}") # добавить путь для поиска include'ов

add_library(demo SHARED ${LIBDEMO_SOURCES}) # создать динамическую библиотеку
add_executable(executable ${SOURCE_DIR}/main.cpp) # создать исполняемый файл
target_link_libraries(executable demo) # произвести линковку
