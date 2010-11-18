
#ifndef __OPERATION_H

#define __OPERATION_H 1

#define OP_ADD 0
#define OP_SUBTRACT 1
#define OP_MULTIPLY 2
#define OP_DIVIDE 3
#define OP_MODULUS 4

#include "type.h"

int operation_validate(int, int, int);

int operation_binary_arith_validate(int,int);
int operation_binary_int_arith_validate(int,int);

type_value_t* operation(int, type_value_t*, type_value_t*);

type_value_t* operation_add(type_value_t*,type_value_t*);
type_value_t* operation_subtract(type_value_t*,type_value_t*);
type_value_t* operation_multiply(type_value_t*,type_value_t*);
type_value_t* operation_divide(type_value_t*,type_value_t*);
type_value_t* operation_modulus(type_value_t*,type_value_t*);

typedef int (*op_valid_table_t)(int,int);

typedef type_value_t* (*op_table_t) (type_value_t*, type_value_t*);

#endif
