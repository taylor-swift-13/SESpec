#include <limits.h>

/*@ ensures denom != 0 ==> \result == 1;

ensures denom == 0 ==> \result == 0;


assigns \nothing; */
int stub_A(int denom);

/*@ requires denom != 0;
ensures \result == 1;
assigns \nothing; */
int stub_B(int denom);

/*@ requires denom != 0;
ensures \result == 1;
assigns \nothing; */
int check_A_implies_B(int denom) {
    return stub_A(denom);
}

/*@ ensures denom != 0 ==> \result == 1;

ensures denom == 0 ==> \result == 0;


assigns \nothing; */
int check_B_implies_A(int denom) {
    return stub_B(denom);
}
