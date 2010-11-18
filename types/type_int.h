
#ifndef __TYPE_INT_H

#define __TYPE_INT_H 1

#define TYPE_INT 0

#include "type.h"

type_t* type_int_init();

void type_int_print(void*);

type_value_t* type_int_convert(int, void*);

void* type_int_construct(void*);

#endif
