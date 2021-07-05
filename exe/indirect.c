/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-42sh-samuel.nadal
** File description:
** indirect.c
*/

#include <include.h>

test_env *is_indirect(char **tab, test_env *env)
{
    char f[999] = "PWD=";
    char f2[999] = "OLDPWD=";
    char *t = NULL;
    char *tb = NULL;
    char *save = my_str_copie(tab[1]);
    tab = get_path(env, "PWD=", 4);
    t = my_str_copie(tab[1]);
    tb = my_str_copie(tab[1]);
    chdir(concat_strings(concat_strings(tb, "/"), save));
    tab = get_path(env, "PWD=", 4);
    env = modif_path(&env, "PWD=", 4, my_str_copie(concat_strings(f, tab[1])));
    env = modif_path(&env, "OLDPWD=", 4, my_str_copie(concat_strings(f2, t)));
    return (env);
}