#include <limits.h>

/*@ ensures n / 400 == 0 && n / 100 == 0 ==> \result == (n - n / 4 + n / 4 * 2) % 7;

ensures n / 400 == 0 && n / 100 != 0 ==> \result == (n - n / 4 + n / 100 + (n / 4 - n / 100) * 2) % 7;

ensures n / 400 != 0 && n / 100 == 0 ==> \result == (n - n / 4 - n / 400 + (n / 4 + n / 400) * 2) % 7;

ensures n / 400 != 0 && n / 100 != 0 ==> \result == (n - n / 4 + n / 100 - n / 400 + (n / 4 - n / 100 + n / 400) * 2) % 7;


assigns \nothing; */
int stub_A(int n);

/*@ requires n >= 0;
ensures 0 <= \result < 7;
assigns \nothing; */
int stub_B(int n);

/*@ requires n >= 0;
ensures 0 <= \result < 7;
assigns \nothing; */
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@ ensures n / 400 == 0 && n / 100 == 0 ==> \result == (n - n / 4 + n / 4 * 2) % 7;

ensures n / 400 == 0 && n / 100 != 0 ==> \result == (n - n / 4 + n / 100 + (n / 4 - n / 100) * 2) % 7;

ensures n / 400 != 0 && n / 100 == 0 ==> \result == (n - n / 4 - n / 400 + (n / 4 + n / 400) * 2) % 7;

ensures n / 400 != 0 && n / 100 != 0 ==> \result == (n - n / 4 + n / 100 - n / 400 + (n / 4 - n / 100 + n / 400) * 2) % 7;


assigns \nothing; */
int check_B_implies_A(int n) {
    return stub_B(n);
}
