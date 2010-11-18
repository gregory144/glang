
#ifndef __TYPE_FLOAT_H

#define __TYPE_FLOAT_H 1

#define TYPE_FLOAT 1

#include "type.h"

type_t* type_float_init();

void type_float_print(void*);

type_value_t* type_float_convert(int, void*);

void* type_float_construct(void*);

#endif
