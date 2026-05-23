#include <limits.h>



/*@ensures m % b == 0 && m % a == 0 ==> \result == 1;

ensures m % b != 0 && m % a == 0 ==> \result == 0;

ensures m % a != 0 ==> \result == 0;


assigns \nothing;*/
int stub_A(int a, int b, int m);

/*@requires m >= 0;
requires b != 0;
requires a != 0;
ensures \result == 1 ==> m % a == 0 && m % b == 0;
ensures \result == 1 ==> (m % a == 0 && m % b == 0);
ensures \result == 1 <==> (m % a == 0 && m % b == 0);
ensures \result == 0 ==> (m % a != 0 || m % b != 0);
ensures \result == 0 <==> (m % a != 0 || m % b != 0);
assigns \nothing;*/
int stub_B(int a, int b, int m);

/*@requires m >= 0;
requires b != 0;
requires a != 0;
ensures \result == 1 ==> m % a == 0 && m % b == 0;
ensures \result == 1 ==> (m % a == 0 && m % b == 0);
ensures \result == 1 <==> (m % a == 0 && m % b == 0);
ensures \result == 0 ==> (m % a != 0 || m % b != 0);
ensures \result == 0 <==> (m % a != 0 || m % b != 0);
assigns \nothing;*/
int check_A_implies_B(int a, int b, int m) {
    return stub_A(a, b, m);
}

/*@ensures m % b == 0 && m % a == 0 ==> \result == 1;

ensures m % b != 0 && m % a == 0 ==> \result == 0;

ensures m % a != 0 ==> \result == 0;


assigns \nothing;*/
int check_B_implies_A(int a, int b, int m) {
    return stub_B(a, b, m);
}
