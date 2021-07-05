/*
** EPITECH PROJECT, 2020
** bsminishell
** File description:
** include.h
*/

#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include "include2.h"

typedef struct var
{
    pid_t child;
    size_t len;
    int check;
}var_;

typedef struct {
    char **env;
    int child;
    int nbr;
} reduct_pipe_t;

test_env *my_unsetenv(test_env **test, char *search, int len);

bool ifsetenv(test_env *list, char **av);

int reduct_main(env_tab_and_chained *env, char *str, var_ *var);

void reduc_main_pipe(int child, char *str, char **env, int nbr);

void reduct_pipe(int *piped, int i, int nbr);

void check_recallmain(int ac, char **av, env_tab_and_chained envv, var_ var);

bool or_or(char *str, char **env, int child);

int as_double(char *str, char const *comp);

char **create_tab_from_list(env_tab_and_chained *env);

test_env *modif_path(test_env **test, char *search, int len, char *new_var);

char **get_path(test_env *test, char *search, int len);

int my_getline(char **str, size_t len);

char **set_tab(char **dest, char *src, int *size, char const *sep);

int ma(char const *str, char const *sep, int *size);

int match(char const *str, char const *sep, int size);

char **my_str_t_w_a(char *str, char const *sep);

void my_scanf(char *str, ...);

test_env *my_cd(char *path, test_env *env);

char *my_str_copie(char *str);

void free_tab(char **tab);

int my_strcmp(char *str_to_comp, char *comp);

test_env *is_indirect(char **tab, test_env *env);

void find_lunch(char **av, char **env);

int ms_len_re(char *str);

int my_printf(char *str, ...);

bool and_funct(char *argv, char **env, int child);

int main(int ac, char **av, char **env);

bool redirect(char *str, char **env, pid_t child);

int my_getnbr(char const *str);

int my_strlen(char const *str);

bool pipe_funct(char *str, char **env, int child);

void *my_malloc(size_t size);

bool and_and(char *str, char **env, int child);

#endif