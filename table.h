
#ifndef __TABLE_H

#define __TABLE_H 1

#include "type.h"

typedef struct sym {
    char *id;
    type_value_t *val; 
    struct sym *next;
} sym_t;

sym_t *sym_table;

sym_t* table_get(char*);
int table_exists(char*);
type_value_t* table_val(char*);
void table_set(char*, type_value_t*);

#endif
