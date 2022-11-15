cmake_minimum_required(VERSION 3.21)
project(Projet_Algo_L2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(std_tree)
include_directories("conjugated forms")
include_directories("misc")
include_directories("files")

add_executable(Projet_Algo_L2
        "conjugated forms/form_cell.c"
        "conjugated forms/form_cell.h"
        "conjugated forms/form_list.c"
        "conjugated forms/form_list.h"
        std_tree/node.c
        std_tree/node.h
        std_tree/tree.c
        std_tree/tree.h
        files.c
        files.h
        function.c
        function.h
        misc/menu.c
        misc/menu.h
        dictionnaire_non_accentue.txt
        main.c "conjugated forms/conjugated_form.c" "conjugated forms/conjugated_form.h" misc/str.c misc/str.h misc/model.c misc/model.h)