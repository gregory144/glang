
#ifndef __TYPE_LIST_H

#define __TYPE_LIST_H 1

#define TYPE_LIST 2

#include "type.h"

struct type_list {
    long size;
    type_value_t* content;
    struct type_list* next;
} type_list_t;

type_t* type_list_init();

void type_list_print(void*);

type_value_t* type_list_convert(int, void*);

void* type_list_construct(void*);

#endif
