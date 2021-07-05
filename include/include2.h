/*
** EPITECH PROJECT, 2020
** AtelierCode-Minishell1
** File description:
** include.h
*/

#ifndef include2_h
#define include2_h

typedef struct test_env
{
    char *var_env;
    int size;
    struct test_env *next;
}test_env;

typedef struct env_tab_and_chained
{
    char **env;
    test_env *envv;
}env_tab_and_chained;

test_env *push_back(char *str, test_env *struc_init);

int nmatch(char *str_to_comp, char *str_comp, int n);

test_env *fill(char **env);

char **my_str_t_w_a(char *str, char const *sep);

char *concat_strings(char *dest, char const *src);

void *my_malloc(size_t size);

#endif