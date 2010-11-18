
#ifndef __TYPE_H

#define __TYPE_H 1

#define CAST(T,P) (*(T*)(P))

typedef struct type_value {
    int type;
    void* value;
} type_value_t;

typedef struct type {
    int type_id;
    void (*print)(void*);
    type_value_t* (*convert)(int,void*);
    void* (*construct)(void*);
    struct type *next;
} type_t;

void type_initialize_builtins();

void type_add(type_t*);

type_t* type_find(int);

void type_print(type_value_t*);

type_value_t* type_convert(int, type_value_t*);

int type_equals(type_value_t*, type_value_t*);

type_value_t* type_construct(int, void*);

#include "type_int.h"
#include "type_float.h"
#include "type_list.h"

#endif
