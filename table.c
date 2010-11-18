
#include "table.h"
#include <stdlib.h>

sym_t* table_get(char *id) {
    sym_t *curr = sym_table;
    while (curr != NULL) {
        if (strcmp(id, curr->id) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

int table_exists(char *id) {
    return table_get(id) == NULL;
}

type_value_t* table_val(char *id) {
    return table_get(id)->val;
}

void table_set(char *id, type_value_t *val) {
    sym_t *var = malloc(sizeof(sym_t));
    var->id = id;
    var->val = val;
    if (sym_table == NULL) {
        sym_table = var;
    } else {
        var->next = sym_table;
        sym_table = var;
    }
}


