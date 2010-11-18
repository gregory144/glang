
#include "type.h"
#include <stdlib.h>
#include <stdio.h>

type_t* type_table;

void type_initialize_builtins() {
    type_add(type_int_init());
    type_add(type_float_init());
    type_add(type_list_init());
}

void type_add(type_t *type) {
    printf("Adding type: %d\n", type->type_id);
    type->next = type_table;
    type_table = type;
}

type_t* type_find(int type_id) {
    type_t *curr = type_table;
    while (curr != NULL) {
        if (type_id == curr->type_id) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void type_print(type_value_t* val) {
    type_t *type = type_find(val->type);
    if (type != NULL) {
        (type->print)(val->value);
    }
}

type_value_t* type_convert(int type_id, type_value_t *orig) {
    type_t *type = type_find(type_id);
    if (type != NULL) {
        printf("Found type: %d", type_id);
        return (type->convert)(type_id, orig->value);
    } else {
        printf("Didn't find type: %d", type_id);
        return NULL;
    }
}

int type_equals(type_value_t *v1, type_value_t *v2) {
    return v1->type == v2->type;
}

type_value_t* type_construct(int type_id, void* value) {
    type_value_t* val = malloc(sizeof(type_value_t));
    val->type = type_id;
    type_t *type = type_find(type_id);
    val->value = (type->construct)(value);
    return val;
}
