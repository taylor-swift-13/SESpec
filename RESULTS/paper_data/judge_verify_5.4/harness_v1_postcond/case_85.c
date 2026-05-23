#include <limits.h>


/*@ logic integer pow2(integer n) = (n <= 0 ? 1 : 2 * pow2(n - 1)); */

/*@loop invariant (\at(b,Pre)!=0) ==> (b == \at(b,Pre));
      loop invariant (\at(b,Pre)!=0) ==> (a == \at(a,Pre));
      loop invariant (!(\at(b,Pre)!=0)) ==> ((z == 0)&&(y == \at(b,Pre))&&(x == \at(a,Pre))&&(b == \at(b,Pre))&&(a == \at(a,Pre)));
      loop invariant b == \at(b,Pre);
      loop invariant a == \at(a,Pre);
      loop assigns z, y, x;*/
void stub_A(int a,int b);

/*@loop invariant z + x*y == a*b;
    loop invariant z + x * y == a * b;
    loop invariant y == 0 || y > 0;
    loop invariant x * y + z == a * b;
    loop invariant a <= x;
    loop invariant 0 <= z;
    loop invariant 0 <= y;
    loop invariant 0 <= x;
    loop assigns z;
    loop assigns y;
    loop assigns x;*/
void stub_B(int a,int b);

/*@loop invariant z + x*y == a*b;
    loop invariant z + x * y == a * b;
    loop invariant y == 0 || y > 0;
    loop invariant x * y + z == a * b;
    loop invariant a <= x;
    loop invariant 0 <= z;
    loop invariant 0 <= y;
    loop invariant 0 <= x;
    loop assigns z;
    loop assigns y;
    loop assigns x;*/
void check_A_implies_B(int a,int b) {
    stub_A(a, b);
}

/*@loop invariant (\at(b,Pre)!=0) ==> (b == \at(b,Pre));
      loop invariant (\at(b,Pre)!=0) ==> (a == \at(a,Pre));
      loop invariant (!(\at(b,Pre)!=0)) ==> ((z == 0)&&(y == \at(b,Pre))&&(x == \at(a,Pre))&&(b == \at(b,Pre))&&(a == \at(a,Pre)));
      loop invariant b == \at(b,Pre);
      loop invariant a == \at(a,Pre);
      loop assigns z, y, x;*/
void check_B_implies_A(int a,int b) {
    stub_B(a, b);
}
