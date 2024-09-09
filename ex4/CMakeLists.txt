cmake_minimum_required(VERSION 3.22.1)

project(
	random_num_generator
	VERSION 1.4
	DESCRIPTION "Random Number Generator"
	LANGUAGES C)

add_executable(
	random_number_generator
	inc/function.h
	src/function.c
	src/main.c)

target_compile_features(random_num_generator PRIVATE C17)

target_compile_options(random_num_generator PRIVATE "-Wextra -Wfatal-errors -Wpedantic")
