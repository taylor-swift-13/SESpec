#include <limits.h>

int foo34(int numerator, int denominator);


/*@
  requires numerator != INT_MIN;
  requires denominator != INT_MIN;
  assigns \nothing;

  ensures denominator == 0 ==> (\result == INT_MAX || \result == INT_MIN);
  ensures denominator == 0 && numerator >= 0 ==> \result == INT_MAX;
  ensures denominator == 0 && numerator < 0 ==> \result == INT_MIN;

  ensures denominator != 0 && numerator >= 0 && denominator > 0
       ==> \result == numerator / denominator;

  ensures denominator != 0 && numerator >= 0 && denominator < 0
       ==> \result == -(numerator / (-denominator));

  ensures denominator != 0 && numerator < 0 && denominator > 0
       ==> \result == -((-numerator) / denominator);

  ensures denominator != 0 && numerator < 0 && denominator < 0
       ==> \result == (-numerator) / (-denominator);
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