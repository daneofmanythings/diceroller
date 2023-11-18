cmake_minimum_required(VERSION 3.22)
project(diceroller)
add_executable(
    ${PROJECT_NAME} 
    main.cpp 
    lexer.cpp
    token.cpp
)
