#include <limits.h>



/*@assigns \nothing;
  ensures (1 < \old(k)) ==> (z == \old(z));
  ensures (1 < \old(k)) ==> (k == \old(k));*/
int stub_A(int z,int k);

/*@loop invariant y == 1;
    loop invariant x == (z^(c-1) - 1) / (z - 1) + 1;
    loop invariant c <= k;
    loop invariant 1 <= x;
    loop invariant 1 <= c;
    loop invariant 0 <= c - 1;
    loop assigns y;
    loop assigns x;
    loop assigns c;*/
int stub_B(int z,int k);

/*@loop invariant y == 1;
    loop invariant x == (z^(c-1) - 1) / (z - 1) + 1;
    loop invariant c <= k;
    loop invariant 1 <= x;
    loop invariant 1 <= c;
    loop invariant 0 <= c - 1;
    loop assigns y;
    loop assigns x;
    loop assigns c;*/
int check_A_implies_B(int z,int k) {
    return stub_A(z, k);
}

/*@assigns \nothing;
  ensures (1 < \old(k)) ==> (z == \old(z));
  ensures (1 < \old(k)) ==> (k == \old(k));*/
int check_B_implies_A(int z,int k) {
    return stub_B(z, k);
}
