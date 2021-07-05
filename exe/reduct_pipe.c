/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-42sh-samuel.nadal
** File description:
** reduct_pipe.c
*/

#include <include.h>

void reduc_main_pipe(int child, char *str, char **env, int nbr)
{
    int piped[nbr * 2];
    char **tab = NULL;
    pid_t pid = 0;
    tab = my_str_t_w_a(str, "|");
    for (int i = 0, p = 0; i < nbr; i++, p += 2)
        pipe(&piped[p]);
    for (int i = 0; !child && tab[i]; i++) {
        pid = fork();
        if (pid == 0) {
            reduct_pipe(piped, i, nbr);
            main(999, &tab[i], env);
            exit(0);
        }
    }
    for (int o = 0; o < nbr * 2; o++)
        close(piped[o]);
}