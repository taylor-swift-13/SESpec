#include <limits.h>

/*@ ensures x % 2 != 0 ==> \result == 1;

ensures x % 2 == 0 ==> \result == 0;


assigns \nothing; */
int stub_A(int x);

/*@ ensures \result == 1 <==> x % 2 == 0;
ensures \result == 0 <==> x % 2 != 0;
ensures \result == (x % 2 == 0);
assigns \nothing; */
int stub_B(int x);

/*@ ensures \result == 1 <==> x % 2 == 0;
ensures \result == 0 <==> x % 2 != 0;
ensures \result == (x % 2 == 0);
assigns \nothing; */
int check_A_implies_B(int x) {
    return stub_A(x);
}

/*@ ensures x % 2 != 0 ==> \result == 1;

ensures x % 2 == 0 ==> \result == 0;


assigns \nothing; */
int check_B_implies_A(int x) {
    return stub_B(x);
}
