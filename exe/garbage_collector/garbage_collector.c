/*
** EPITECH PROJECT, 2020
** garbage colector
** File description:
** garbage_collector.c
*/

#include "garbage_collector.h"

garbage_collector_t *add_ptr_to_garbage_collector_t \
(garbage_collector_t *garbage_collector, void *ptr)
{
    garbage_collector_t *node = malloc(sizeof(garbage_collector_t));
    garbage_collector_t **save = &garbage_collector;
    if (!garbage_collector) {
        garbage_collector = malloc(sizeof(garbage_collector_t));
        garbage_collector->list = ptr;
        garbage_collector->next = NULL;
        free(node);
    } else {
        while (garbage_collector->next)
            garbage_collector = garbage_collector->next;
        node->list = ptr;
        node->next = NULL;
        garbage_collector->next = node;
        garbage_collector = *save;
    }
    return (garbage_collector);
}

void *stat_save(void)
{
    static garbage_collector_t *garbage = NULL;
    if (garbage == NULL)
        garbage = add_ptr_to_garbage_collector_t\
        (garbage, malloc(sizeof(short int)));
    return (garbage);
}

void __attribute__((destructor)) destroygc(void)
{
    garbage_collector_t *garbage_collector = stat_save();
    void *next = garbage_collector->next;
    while (garbage_collector->next) {
        free(garbage_collector->list);
        free(garbage_collector);
        garbage_collector = next;
        next = garbage_collector->next;
    }
    free(garbage_collector->list);
    free(garbage_collector);
}

void *my_malloc(size_t size)
{
    garbage_collector_t *garbage_collector = stat_save();
    void *address = malloc(size);
    garbage_collector = \
    add_ptr_to_garbage_collector_t(garbage_collector, address);
    return (address);
}