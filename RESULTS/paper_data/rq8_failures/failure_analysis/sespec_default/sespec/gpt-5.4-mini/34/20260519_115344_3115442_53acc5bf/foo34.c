#include <limits.h>

int foo34(int numerator, int denominator);


/*@
  ensures denominator == 0 && numerator >= 0 ==> \result == INT_MAX;
  ensures denominator == 0 && numerator < 0 ==> \result == INT_MIN;
  ensures denominator != 0 && ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) == 0 ==> \result == ((numerator >= 0 ? numerator : -numerator) / (denominator >= 0 ? denominator : -denominator));
  ensures denominator != 0 && ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) != 0 ==> \result == -((numerator >= 0 ? numerator : -numerator) / (denominator >= 0 ? denominator : -denominator));
  assigns \nothing;
*/
int foo34(int numerator, int denominator) {
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