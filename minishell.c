/*
** EPITECH PROJECT, 2020
** bsminishell
** File description:
** exo3.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/include.h"
#include "include/include2.h"

char **my_str_t_w_a(char *str, char const *sep);

int nb_arg(char **tab)
{
    int size = 0;
    for (; tab[size]; size++);
    return (size);
}

int match_re(char *str, char *str_to_comp)
{
    if (ms_len_re(str) != ms_len_re(str_to_comp))
        return (0);
    for (int u = 0; str[u]; u++)
        if (str[u] != str_to_comp[u])
            return (0);
    return (1);
}

int reduct(char *str, char **tab, env_tab_and_chained *env, int child)
{
    env->env = create_tab_from_list(env);
    if (str[0] != '/' && !child) {
        find_lunch(tab, env->env);
    }
    else if (str[0] == '/' && !child) {
        execve(tab[0], &tab[0], env->env);
    }
    if (!child)
        return (1);
    return (0);
}

int reduct_main(env_tab_and_chained *env, char *str, var_ *var)
{
    char **tab;

    if (str[0] == 'c' && str[1] == 'd')
        (*env).envv = my_cd(str, env->envv);
    else {
        tab = my_str_t_w_a(str, " \n");
        if (match_re(tab[0], "setenv"))
            return (ifsetenv(env->envv, tab));
        if (match_re(tab[0], "unsetenv")) {
            env->envv = my_unsetenv(&env->envv, tab[1], strlen(tab[1]));
            return (true);
        }
        var->child = fork();
        waitpid(var->child, &var->check, 0);
        env->env = create_tab_from_list(env);
        if (pipe_funct(str, env->env, var->child) || \
        and_funct(str, env->env, var->child) || \
        redirect(str, env->env, var->child) || \
        reduct(str, tab, env, var->child))
            return (0);
        var->child = 0;
    }
    return (1);
}

int main(int ac, char **av, char **env)
{
    var_ var = (var_){0, 0};
    char *str = NULL;
    env_tab_and_chained envv;

    if (!env || (ac != 1 && ac != 999))
        return (84);
    envv.envv = fill(env);
    envv.env = env;
    check_recallmain(ac, av, envv, var);
    while (my_getline(&str, var.len) != -1 && !match_re(str, "exit\n"))
        reduct_main(&envv, str, &var);
    if (isatty(STDIN_FILENO) == 1)
        write(1, "exit\n", 5);
    free(str);
    return (84);
}