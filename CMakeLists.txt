#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 2.6)

#Name your project here
project(BT)

add_executable(BT BT.cpp BT.h csv_writer.cpp csv_writer.h functions.h  random.h random.cpp main.cpp)