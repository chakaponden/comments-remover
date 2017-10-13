cmake_minimum_required(VERSION 2.8)

project(comments-remover)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++0x")

file(GLOB SOURCES
	main.cpp
    CommentRemover.h
    CommentRemover.cpp
)

add_executable(comments-remover ${SOURCES})