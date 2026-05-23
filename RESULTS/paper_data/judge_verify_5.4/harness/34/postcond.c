#include <limits.h>

/*@ ensures denominator == 0 && numerator >= 0 ==> \result == INT_MAX;
  ensures denominator == 0 && numerator < 0 ==> \result == INT_MIN;
  ensures denominator != 0 && ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) == 0 ==> \result == ((numerator >= 0 ? numerator : -numerator) / (denominator >= 0 ? denominator : -denominator));
  ensures denominator != 0 && ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) != 0 ==> \result == -((numerator >= 0 ? numerator : -numerator) / (denominator >= 0 ? denominator : -denominator));
  assigns \nothing; */
int stub_A(int numerator, int denominator);

/*@ requires numerator != INT_MIN || denominator == 0 || denominator == 1 || denominator == -1;
requires denominator != 0 || numerator == numerator;
requires denominator != 0 || numerator == INT_MIN || numerator == INT_MAX || numerator >= INT_MIN;
requires denominator != 0 || numerator == 0 || numerator == INT_MIN || numerator == INT_MAX;
requires denominator != 0 || numerator != INT_MIN;
requires denominator != 0 || (numerator != INT_MIN);
requires denominator != 0 ==> denominator > INT_MIN;
requires denominator != 0 ==> denominator != INT_MIN || numerator == 0;
requires denominator != 0 ==> denominator != -1 || numerator != INT_MIN;
ensures denominator == 0 ==> \result == (numerator >= 0 ? INT_MAX : INT_MIN);
ensures denominator == 0 ==> (\result == INT_MAX || \result == INT_MIN);
ensures denominator != 0 ==> \result == numerator / denominator;
ensures denominator != 0 ==> \result == (numerator / denominator);
ensures denominator != 0 ==> (\result == 0 || (\result < 0 <==> (numerator < 0) != (denominator < 0)));
assigns \nothing; */
int stub_B(int numerator, int denominator);

/*@ requires numerator != INT_MIN || denominator == 0 || denominator == 1 || denominator == -1;
requires denominator != 0 || numerator == numerator;
requires denominator != 0 || numerator == INT_MIN || numerator == INT_MAX || numerator >= INT_MIN;
requires denominator != 0 || numerator == 0 || numerator == INT_MIN || numerator == INT_MAX;
requires denominator != 0 || numerator != INT_MIN;
requires denominator != 0 || (numerator != INT_MIN);
requires denominator != 0 ==> denominator > INT_MIN;
requires denominator != 0 ==> denominator != INT_MIN || numerator == 0;
requires denominator != 0 ==> denominator != -1 || numerator != INT_MIN;
ensures denominator == 0 ==> \result == (numerator >= 0 ? INT_MAX : INT_MIN);
ensures denominator == 0 ==> (\result == INT_MAX || \result == INT_MIN);
ensures denominator != 0 ==> \result == numerator / denominator;
ensures denominator != 0 ==> \result == (numerator / denominator);
ensures denominator != 0 ==> (\result == 0 || (\result < 0 <==> (numerator < 0) != (denominator < 0)));
assigns \nothing; */
int check_A_implies_B(int numerator, int denominator) {
    return stub_A(numerator, denominator);
}

/*@ ensures denominator == 0 && numerator >= 0 ==> \result == INT_MAX;
  ensures denominator == 0 && numerator < 0 ==> \result == INT_MIN;
  ensures denominator != 0 && ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) == 0 ==> \result == ((numerator >= 0 ? numerator : -numerator) / (denominator >= 0 ? denominator : -denominator));
  ensures denominator != 0 && ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) != 0 ==> \result == -((numerator >= 0 ? numerator : -numerator) / (denominator >= 0 ? denominator : -denominator));
  assigns \nothing; */
int check_B_implies_A(int numerator, int denominator) {
    return stub_B(numerator, denominator);
}
