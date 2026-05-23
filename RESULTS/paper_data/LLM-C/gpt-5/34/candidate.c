#include <limits.h>

/*@ 
  requires INT_MIN < 0;
  requires INT_MAX > 0;

  assigns \nothing;

  behavior div_by_zero:
    assumes denominator == 0;
    ensures (numerator >= 0 ==> \result == INT_MAX);
    ensures (numerator < 0  ==> \result == INT_MIN);

  behavior normal:
    assumes denominator != 0;
    /* Avoid undefined behavior from negating INT_MIN and from INT_MIN / -1 */
    assumes numerator != INT_MIN;
    assumes denominator != INT_MIN;
    assumes !(numerator == INT_MIN && denominator == -1);
    ensures \result == (numerator / denominator);

  complete behaviors;
  disjoint behaviors;
*/
int divS32(int numerator, int denominator);

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
