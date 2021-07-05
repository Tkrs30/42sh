/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-42sh-samuel.nadal
** File description:
** recall_main.c
*/

#include <include.h>

void check_return_recall(var_ var)
{
    int gevaudant = 0;
    gevaudant = WEXITSTATUS(var.check);
    if (gevaudant != 0) {
        exit(84);
    }
    exit(0);
}

void check_recallmain(int ac, char **av, env_tab_and_chained envv, var_ var)
{
    if (ac == 999) {
        reduct_main(&envv, av[0], &var);
        if (WIFEXITED(var.check)) {
            check_return_recall(var);
        }
        exit(84);
    }
}