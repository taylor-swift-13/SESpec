#include <limits.h>

int foo10_c34(int numerator, int denominator);


/*@
  requires \true;
  assigns \nothing;
  ensures
    // denominator == 0: saturated by sign of numerator
    (denominator == 0 && numerator >= 0 ==> \result == INT_MAX) &&
    (denominator == 0 && numerator < 0  ==> \result == INT_MIN) &&

    // denominator != 0: result equals trunc(|numerator|/|denominator|) with sign
    (denominator != 0 ==>
      (\let calcDenominator = (denominator >= 0 ? denominator : -denominator);
       \let tempAbsQuotient = ((numerator >= 0 ? numerator : -numerator) / calcDenominator);
       (
         // if numerator and denominator have opposite signs -> negative result
         (((numerator < 0) && (denominator > 0) || ((numerator > 0) && (denominator < 0)))
            ==> \result == -tempAbsQuotient)
         &&
         // if same sign or numerator zero -> non-negative result equal to tempAbsQuotient
         (!((numerator < 0) && (denominator > 0) || ((numerator > 0) && (denominator < 0)))
            ==> \result == tempAbsQuotient)
       )
      )
    );
*/
int foo10_c34(int numerator, int denominator) {
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