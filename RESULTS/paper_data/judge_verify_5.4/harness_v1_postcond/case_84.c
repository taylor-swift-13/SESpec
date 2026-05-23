#include <limits.h>



/*@requires x >= 0;
  requires y >= 0;
  requires x == 0 || y <= INT_MAX / x;*/
void stub_A(int x,int y);

/*@loop invariant q + a * b * p == x * y;
    loop invariant p == 4 || p >= 1;
    loop invariant p == 4 || p == 1 || p > 1;
    loop invariant p == 1 || p % 4 == 0;
    loop invariant p == 1 || p % 2 == 0;
    loop invariant a >= 0 && b >= 0;
    loop invariant a == 0 || b == 0 || (a != 0 && b != 0);
    loop invariant a != 0 && b != 0 ==> (a * b * p + q >= 0);
    loop invariant \true;
    loop invariant 1 <= p;
    loop invariant 0 <= q;
    loop invariant 0 <= p*q;
    loop invariant 0 <= b;
    loop invariant 0 <= a;
    loop invariant 0 < p;
    loop invariant (a == 0 || b == 0) || (p >= 1);
    loop assigns q;
    loop assigns p;
    loop assigns b;
    loop assigns a;*/
void stub_B(int x,int y);

/*@loop invariant q + a * b * p == x * y;
    loop invariant p == 4 || p >= 1;
    loop invariant p == 4 || p == 1 || p > 1;
    loop invariant p == 1 || p % 4 == 0;
    loop invariant p == 1 || p % 2 == 0;
    loop invariant a >= 0 && b >= 0;
    loop invariant a == 0 || b == 0 || (a != 0 && b != 0);
    loop invariant a != 0 && b != 0 ==> (a * b * p + q >= 0);
    loop invariant \true;
    loop invariant 1 <= p;
    loop invariant 0 <= q;
    loop invariant 0 <= p*q;
    loop invariant 0 <= b;
    loop invariant 0 <= a;
    loop invariant 0 < p;
    loop invariant (a == 0 || b == 0) || (p >= 1);
    loop assigns q;
    loop assigns p;
    loop assigns b;
    loop assigns a;*/
void check_A_implies_B(int x,int y) {
    stub_A(x, y);
}

/*@requires x >= 0;
  requires y >= 0;
  requires x == 0 || y <= INT_MAX / x;*/
void check_B_implies_A(int x,int y) {
    stub_B(x, y);
}
