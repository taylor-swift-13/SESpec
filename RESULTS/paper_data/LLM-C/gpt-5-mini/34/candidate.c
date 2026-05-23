#include <limits.h>

int divS32(int numerator, int denominator);

/*@
    requires !(denominator != 0 && (numerator == INT_MIN || denominator == INT_MIN));
    behavior denom_zero:
        assumes denominator == 0;
        ensures \result == (numerator >= 0 ? INT_MAX : INT_MIN);
    behavior denom_nonzero:
        assumes denominator != 0;
        assumes numerator != INT_MIN && denominator != INT_MIN;
        ensures ((numerator < 0) != (denominator < 0)) ==>
                \result == - ((numerator >= 0 ? numerator : -numerator) / (denominator >= 0 ? denominator : -denominator));
        ensures !(((numerator < 0) != (denominator < 0))) ==>
                \result ==  ((numerator >= 0 ? numerator : -numerator) / (denominator >= 0 ? denominator : -denominator));
    complete behaviors denom_zero, denom_nonzero;
    disjoint behaviors denom_zero, denom_nonzero;
    assigns \nothing;
*/
int divS32(int numerator, int denominator) {
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
