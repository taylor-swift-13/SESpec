#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <limits.h>

int foo34(int numerator, int denominator);

int foo34(int numerator, int denominator) 
/*@

Require emp
Ensure Results(__return)
*/{
    int quotient;
    int quotientNeedsNegation = 0;
    if (denominator == 0) {
        quotient = numerator >= 0 ? INT_MAX : INT_MIN;
    } else {
        if ((numerator < 0) && (denominator > 0)) quotientNeedsNegation = 1;
        else if ((numerator > 0) && (denominator < 0)) quotientNeedsNegation = 1;
        int calcDenominator = denominator >= 0 ? denominator : -denominator;
        int tempAbsQuotient = (numerator >= 0 ? numerator : -numerator) / calcDenominator;
        quotient = quotientNeedsNegation ? -tempAbsQuotient : tempAbsQuotient;
    }
    return quotient;
}