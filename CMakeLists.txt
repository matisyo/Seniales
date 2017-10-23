cmake_minimum_required(VERSION 3.8)
project(JustSignals)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        SIGINT_Handler.h
        SIGINT_Handler_Partidos.h
        EventHandler.h
        SignalHandler.cpp
        SignalHandler.h
        Partido.cpp Partido.h)
add_executable(JustSignals ${SOURCE_FILES})