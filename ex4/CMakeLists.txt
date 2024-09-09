cmake_minimum_required(VERSION 3.22.1)

project(
	random_num_generator
	VERSION 1.4
	DESCRIPTION "Random Number Generator"
	LANGUAGES C)

add_executable(
	${PROJECT_NAME}
	src/function.c
	src/main.c)

set (CMAKE_CXX_STANDARD 17)

add_compile_options(
	-Wall
	-Wextra 
	-Wfatal-errors 
	-Wpedantic
	)
