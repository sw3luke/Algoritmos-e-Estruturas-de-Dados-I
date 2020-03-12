cmake_minimum_required(VERSION 3.10)
project(Voo C)

set(CMAKE_C_STANDARD 99)

add_executable(Voo main.c TADVoo.c TADLista.c Matriz_Voos.c Item_matriz.c)