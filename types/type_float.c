
#include "type_float.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>

type_t* type_float_init() {
    type_t* type = malloc(sizeof(type_t));
    type->type_id = TYPE_FLOAT;
    type->print = type_float_print;
    type->convert = type_float_convert;
    type->construct = type_float_construct;
    return type;
}

void type_float_print(void* value) {
    printf("%lf", CAST(double, value));
}

type_value_t* type_float_convert(int type_id, void *val) {
    type_value_t *new_type = malloc(sizeof(type_value_t));
    new_type->type = type_id;
    if (type_id == TYPE_INT) {
        new_type->value = &CAST(double, val);
    }
    return new_type;
}

void* type_float_construct(void* val) {
    double* value_ptr = malloc(sizeof(double));
    *value_ptr = CAST(double, val);
    return value_ptr;
}
