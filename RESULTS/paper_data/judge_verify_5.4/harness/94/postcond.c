#include <limits.h>

/*@ ensures n % 4 != 0 ==> \result == 1;

ensures n % 4 == 0 ==> \result == 0;


assigns \nothing; */
int stub_A(int n);

/*@ requires n >= 0;
requires n > 0;
ensures \result == 1 <==> n % 4 != 0;
ensures \result == 0 <==> n % 4 == 0;
ensures \result == (n % 4 != 0);
ensures \result == ((n % 4) != 0);
assigns \nothing; */
int stub_B(int n);

/*@ requires n >= 0;
requires n > 0;
ensures \result == 1 <==> n % 4 != 0;
ensures \result == 0 <==> n % 4 == 0;
ensures \result == (n % 4 != 0);
ensures \result == ((n % 4) != 0);
assigns \nothing; */
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@ ensures n % 4 != 0 ==> \result == 1;

ensures n % 4 == 0 ==> \result == 0;


assigns \nothing; */
int check_B_implies_A(int n) {
    return stub_B(n);
}
