
#include "type_list.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>

type_t* type_list_init() {
    type_t* type = malloc(sizeof(type_t));
    type->type_id = TYPE_LIST;
    type->print = type_list_print;
    type->convert = type_list_convert;
    type->construct = type_list_construct;
    return type;
}

void type_list_print(void* v) {
    struct type_list* curr = (struct type_list*)v;
    while (curr != NULL) {
        type_print(curr->content);
        curr = curr->next;
    }
}

type_value_t* type_list_convert(int type_id, void *val) {
    return NULL;
}

void* type_list_construct(void* val) {
    long* value_ptr = malloc(sizeof(long));
    *value_ptr = *(long*)val;
    return value_ptr;
}
