/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-hugo.gardes
** File description:
** my_cd.c
*/

#include <unistd.h>
#include "../include/include2.h"
#include "../include/include.h"

char *my_str_copie(char *str)
{
    int u = 0;
    char *str_cop = my_malloc(sizeof(char) * (ms_len_re(str) + 1));
    for (; str[u]; u++)
        str_cop[u] = str[u];
    str_cop[u] = 0;
    return (str_cop);
}

void is_empty(char **tab, test_env *env)
{
    char final[999] = "PWD=";
    char final2[999] = "OLDPWD=";
    char *temp = NULL;
    tab = get_path(env, "PWD=", 4);
    temp = my_str_copie(tab[1]);
    tab = get_path(env, "HOME=", 5);
    chdir(tab[1]);
    tab = get_path(env, "PWD=", 4);
    modif_path(&env, "PWD=", 4, my_str_copie(concat_strings(final, tab[1])));
    modif_path(&env, "OLDPWD=", 4, my_str_copie(concat_strings(final2, temp)));
}

void is_minus(char **tab, test_env *env)
{
    char final[999] = "PWD=";
    char final2[999] = "OLDPWD=";
    char *temp = NULL;
    tab = get_path(env, "PWD=", 4);
    temp = my_str_copie(tab[1]);
    tab = get_path(env, "OLDPWD=", 7);
    chdir(tab[1]);
    tab = get_path(env, "PWD=", 4);
    modif_path(&env, "PWD=", 4, my_str_copie(concat_strings(final, tab[1])));
    modif_path(&env, "OLDPWD=", 4, my_str_copie(concat_strings(final2, temp)));
}

test_env *is_slash(char **tab, test_env *env)
{
    char f[999] = "PWD=";
    char f2[999] = "OLDPWD=";
    char *t = NULL;
    chdir(tab[1]);
    tab = get_path(env, "PWD=", 4);
    t = my_str_copie(tab[1]);
    tab = get_path(env, "PWD=", 4);
    env = modif_path(&env, "PWD=", 4, my_str_copie(concat_strings(f, tab[1])));
    env = modif_path(&env, "OLDPWD=", 4, my_str_copie(concat_strings(f2, t)));
    return (env);
}

test_env *my_cd(char *path, test_env *env)
{
    char **tab = my_str_t_w_a(path, " \n");
    if (tab[1] == NULL) {
        is_empty(tab, env);
    } else if (my_strcmp(tab[1], "-") == 0) {
        is_minus(tab, env);
    } else if (tab[1][0] == '/') {
        env = is_slash(tab, env);
    } else {
        is_indirect(tab, env);
    }
    return (env);
}