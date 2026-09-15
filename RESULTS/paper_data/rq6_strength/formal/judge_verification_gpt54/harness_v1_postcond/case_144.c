#include <limits.h>



/*@ensures \old(time) % (n - 1) * 2 >= n ==> \result == n * 2 - \old(time) % (n - 1) * 2 - 1;

ensures \old(time) % (n - 1) * 2 < n ==> \result == \old(time) % (n - 1) * 2 + 1;


assigns \nothing;*/
int stub_A(int n, int time);

/*@requires time >= 0;
requires n > 1;
ensures 1 <= \result <= n;
assigns \nothing;*/
int stub_B(int n, int time);

/*@requires time >= 0;
requires n > 1;
ensures 1 <= \result <= n;
assigns \nothing;*/
int check_A_implies_B(int n, int time) {
    return stub_A(n, time);
}

/*@ensures \old(time) % (n - 1) * 2 >= n ==> \result == n * 2 - \old(time) % (n - 1) * 2 - 1;

ensures \old(time) % (n - 1) * 2 < n ==> \result == \old(time) % (n - 1) * 2 + 1;


assigns \nothing;*/
int check_B_implies_A(int n, int time) {
    return stub_B(n, time);
}
