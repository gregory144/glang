
#include "type_int.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>

type_t* type_int_init() {
    type_t* type = malloc(sizeof(type_t));
    type->type_id = TYPE_INT;
    type->print = type_int_print;
    type->convert = type_int_convert;
    type->construct = type_int_construct;
    return type;
}

void type_int_print(void* v) {
    printf("%ld", CAST(long, v));
}

type_value_t* type_int_convert(int type_id, void *val) {
    type_value_t *new_type = malloc(sizeof(type_value_t));
    new_type->type = type_id;
    if (type_id == TYPE_FLOAT) {
        new_type->value = &CAST(long, val);
    }
    return new_type;
}

void* type_int_construct(void* val) {
    long* value_ptr = malloc(sizeof(long));
    *value_ptr = CAST(long, val);
    return value_ptr;
}
