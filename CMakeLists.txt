cmake_minimum_required(VERSION 3.27)
project(Eva00 C)

set(CMAKE_C_STANDARD 99)

add_executable(Eva00 main.c
        Cliente.c
        Cliente.h
        Restaurante.c
        Restaurante.h
        Pratos.c
        Pratos.h
        Pedidos.c
        Pedidos.h)
