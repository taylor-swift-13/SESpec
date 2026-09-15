#include <limits.h>



/*@ensures n % 2 == 0 ==> \result == 1;

ensures n % 2 != 0 ==> \result == 0;


assigns \nothing;*/
int stub_A(int n);

/*@requires n >= 1;
requires n > 0;
ensures \result == (n % 2 == 0);
assigns \nothing;*/
int stub_B(int n);

/*@requires n >= 1;
requires n > 0;
ensures \result == (n % 2 == 0);
assigns \nothing;*/
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@ensures n % 2 == 0 ==> \result == 1;

ensures n % 2 != 0 ==> \result == 0;


assigns \nothing;*/
int check_B_implies_A(int n) {
    return stub_B(n);
}
