#include <limits.h>

/*@ ensures n % 2 != 0 && n != 1 ==> \result == n;

ensures n % 2 == 0 && n != 1 ==> \result == n / 2;

ensures n == 1 ==> \result == 0;


assigns \nothing; */
int stub_A(int n);

/*@ requires n >= 1;
requires n > 0;
ensures n > 1 && n % 2 == 0 ==> \result == n / 2;
ensures n > 1 && n % 2 != 0 ==> \result == n;
ensures n == 1 ==> \result == 0;
assigns \nothing; */
int stub_B(int n);

/*@ requires n >= 1;
requires n > 0;
ensures n > 1 && n % 2 == 0 ==> \result == n / 2;
ensures n > 1 && n % 2 != 0 ==> \result == n;
ensures n == 1 ==> \result == 0;
assigns \nothing; */
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@ ensures n % 2 != 0 && n != 1 ==> \result == n;

ensures n % 2 == 0 && n != 1 ==> \result == n / 2;

ensures n == 1 ==> \result == 0;


assigns \nothing; */
int check_B_implies_A(int n) {
    return stub_B(n);
}
