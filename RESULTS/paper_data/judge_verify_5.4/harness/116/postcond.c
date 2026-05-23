#include <limits.h>

/*@ ensures b % factor == 0 && a % factor == 0 ==> \result == 1;

ensures b % factor != 0 && a % factor == 0 ==> \result == 0;

ensures a % factor != 0 ==> \result == 0;


assigns \nothing; */
int stub_A(int a, int b, int factor);

/*@ requires factor != 0;
ensures \result == 1 ==> a % factor == 0 && b % factor == 0;
ensures \result == 1 <==> (a % factor == 0 && b % factor == 0);
ensures \result == 0 ==> (a % factor != 0 || b % factor != 0);
ensures \result == 0 <==> (a % factor != 0 || b % factor != 0);
assigns \nothing; */
int stub_B(int a, int b, int factor);

/*@ requires factor != 0;
ensures \result == 1 ==> a % factor == 0 && b % factor == 0;
ensures \result == 1 <==> (a % factor == 0 && b % factor == 0);
ensures \result == 0 ==> (a % factor != 0 || b % factor != 0);
ensures \result == 0 <==> (a % factor != 0 || b % factor != 0);
assigns \nothing; */
int check_A_implies_B(int a, int b, int factor) {
    return stub_A(a, b, factor);
}

/*@ ensures b % factor == 0 && a % factor == 0 ==> \result == 1;

ensures b % factor != 0 && a % factor == 0 ==> \result == 0;

ensures a % factor != 0 ==> \result == 0;


assigns \nothing; */
int check_B_implies_A(int a, int b, int factor) {
    return stub_B(a, b, factor);
}
