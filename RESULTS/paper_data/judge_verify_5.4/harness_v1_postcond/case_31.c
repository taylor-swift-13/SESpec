#include <limits.h>



/*@ensures i != 0 ==> \result == 1;

ensures i == 0 ==> \result == 0;


assigns \nothing;*/
int stub_A(int i);

/*@requires i != 0;
requires i != 0 || \true;
ensures i == 0 ==> \result == 0;
ensures i != 0 ==> \result == 1;
ensures \result == 1;
ensures \result == 0 || \result == 1;
assigns \nothing;*/
int stub_B(int i);

/*@requires i != 0;
requires i != 0 || \true;
ensures i == 0 ==> \result == 0;
ensures i != 0 ==> \result == 1;
ensures \result == 1;
ensures \result == 0 || \result == 1;
assigns \nothing;*/
int check_A_implies_B(int i) {
    return stub_A(i);
}

/*@ensures i != 0 ==> \result == 1;

ensures i == 0 ==> \result == 0;


assigns \nothing;*/
int check_B_implies_A(int i) {
    return stub_B(i);
}
