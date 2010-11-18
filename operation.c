
#include "operation.h"
#include "type.h"
#include <stdlib.h>
#include <stdio.h>

op_valid_table_t op_valid_table[] = {
    operation_binary_arith_validate,
    operation_binary_arith_validate,
    operation_binary_arith_validate,
    operation_binary_arith_validate,
    operation_binary_int_arith_validate,
};

op_table_t op_table[] = {
    operation_add,
    operation_subtract,
    operation_multiply,
    operation_divide,
    operation_modulus,
};

int operation_validate(int op, int type1, int type2) {
    return (op_valid_table[op])(type1, type2);
}

int operation_binary_arith_validate(int type1, int type2) {
    return type1 == type2 || 
        (type1 == TYPE_INT && type2 == TYPE_FLOAT) ||
        (type1 == TYPE_FLOAT && type2 == TYPE_INT) ;
}

int operation_binary_int_arith_validate(int type1, int type2) {
    return type1 == TYPE_INT && type2 == TYPE_INT;
}

type_value_t* operation(int op, type_value_t *val1, type_value_t *val2) {
    if (operation_validate(op, val1->type, val2->type)) {
        return (op_table[op])(val1, val2);
    }
    return NULL;
}

type_value_t* operation_add(type_value_t *val1, type_value_t *val2) {
    if (val1->type == TYPE_INT && val1->type == val2->type) {
        long result = CAST(long, val1->value) + CAST(long, val2->value);
        return type_construct(TYPE_INT, &result);
    } else if (val1->type == TYPE_FLOAT && val1->type == val2->type) {
        double result = CAST(double, val1->value) + CAST(double, val2->value);
        return type_construct(TYPE_FLOAT, &result);
    } else if (val1->type != val2->type) {
        double arg1 = CAST(double, val1->value);
        double arg2 = CAST(double, val2->value);
        if (val1->type == TYPE_INT) {
            int arg1_int = CAST(int, val1->value);
            arg1 = (double)arg1_int;
        }
        if (val2->type == TYPE_INT) {
            int arg2_int = CAST(int, val2->value);
            arg2 = (double)arg2_int;
        }
        double result = arg1 + arg2;
        return type_construct(TYPE_FLOAT, &result);
    }
    return NULL;
}

type_value_t* operation_subtract(type_value_t *val1, type_value_t *val2) {
    if (val1->type == TYPE_INT && val1->type == val2->type) {
        long result = CAST(long, val1->value) - CAST(long, val2->value);
        return type_construct(TYPE_INT, &result);
    } else if (val1->type == TYPE_FLOAT && val1->type == val2->type) {
        double result = CAST(double, val1->value) - CAST(double, val2->value);
        return type_construct(TYPE_FLOAT, &result);
    } else if (val1->type != val2->type) {
        double arg1 = CAST(double, val1->value);
        double arg2 = CAST(double, val2->value);
        if (val1->type == TYPE_INT) {
            int arg1_int = CAST(int, val1->value);
            arg1 = (double)arg1_int;
        }
        if (val2->type == TYPE_INT) {
            int arg2_int = CAST(int, val2->value);
            arg2 = (double)arg2_int;
        }
        double result = arg1 - arg2;
        return type_construct(TYPE_FLOAT, &result);
    }

    return NULL;
}

type_value_t* operation_multiply(type_value_t *val1, type_value_t *val2) {
    if (val1->type == TYPE_INT && val1->type == val2->type) {
        long result = CAST(long, val1->value) * CAST(long, val2->value);
        return type_construct(TYPE_INT, &result);
    } else if (val1->type == TYPE_FLOAT && val1->type == val2->type) {
        double result = CAST(double, val1->value) * CAST(double, val2->value);
        return type_construct(TYPE_FLOAT, &result);
    } else if (val1->type != val2->type) {
        double arg1 = CAST(double, val1->value);
        double arg2 = CAST(double, val2->value);
        if (val1->type == TYPE_INT) {
            int arg1_int = CAST(int, val1->value);
            arg1 = (double)arg1_int;
        }
        if (val2->type == TYPE_INT) {
            int arg2_int = CAST(int, val2->value);
            arg2 = (double)arg2_int;
        }
        double result = arg1 * arg2;
        return type_construct(TYPE_FLOAT, &result);
    }
    return NULL;
}

type_value_t* operation_divide(type_value_t *val1, type_value_t *val2) {
    if (val1->type == TYPE_INT && val1->type == val2->type) {
        long result = CAST(long, val1->value) / CAST(long, val2->value);
        return type_construct(TYPE_INT, &result);
    } else if (val1->type == TYPE_FLOAT && val1->type == val2->type) {
        double result = CAST(double, val1->value) / CAST(double, val2->value);
        return type_construct(TYPE_FLOAT, &result);
    } else if (val1->type != val2->type) {
        double arg1 = CAST(double, val1->value);
        double arg2 = CAST(double, val2->value);
        if (val1->type == TYPE_INT) {
            int arg1_int = CAST(int, val1->value);
            arg1 = (double)arg1_int;
        }
        if (val2->type == TYPE_INT) {
            int arg2_int = CAST(int, val2->value);
            arg2 = (double)arg2_int;
        }
        double result = arg1 / arg2;
        return type_construct(TYPE_FLOAT, &result);
    }
    return NULL;
}

type_value_t* operation_modulus(type_value_t *val1, type_value_t *val2) {
    if (val1->type == TYPE_INT && val1->type == val2->type) {
        long result = CAST(long, val1->value) % CAST(long, val2->value);
        return type_construct(TYPE_INT, &result);
    } 
    return NULL;
}

