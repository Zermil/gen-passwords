@echo off

set CXX=g++
set FLAGS=-Wall -Wextra -pedantic -std=c++17
set FILES=main.cpp

call %CXX% %FLAGS% %FILES% -o genpass
