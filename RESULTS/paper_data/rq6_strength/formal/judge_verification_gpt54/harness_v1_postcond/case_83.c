#include <limits.h>


/*@
  logic integer power(integer b, integer e) =
    e <= 0 ? 1 : b * power(b, e - 1);

  logic integer geom_sum(integer b, integer e) =
    e <= 0 ? 1 : geom_sum(b, e - 1) * b + 1;
*/

/*@requires k >= 1;*/
void stub_A(int z,int k,int a);

/*@loop invariant y == z * y || y == 1;
    loop invariant y == 0 || y == 1 || y == z * y;
    loop invariant y == (z == 1 ? 1 : y);
    loop invariant x >= a || x <= a;
    loop invariant x == a + y * a;
    loop invariant x == a + (c-1)*a;
    loop invariant x == a * y;
    loop invariant c <= k;
    loop invariant c - 1 <= k;
    loop invariant 1 <= c;
    loop invariant 0 <= c - 1;
    loop assigns y;
    loop assigns x;
    loop assigns c;*/
void stub_B(int z,int k,int a);

/*@loop invariant y == z * y || y == 1;
    loop invariant y == 0 || y == 1 || y == z * y;
    loop invariant y == (z == 1 ? 1 : y);
    loop invariant x >= a || x <= a;
    loop invariant x == a + y * a;
    loop invariant x == a + (c-1)*a;
    loop invariant x == a * y;
    loop invariant c <= k;
    loop invariant c - 1 <= k;
    loop invariant 1 <= c;
    loop invariant 0 <= c - 1;
    loop assigns y;
    loop assigns x;
    loop assigns c;*/
void check_A_implies_B(int z,int k,int a) {
    stub_A(z, k, a);
}

/*@requires k >= 1;*/
void check_B_implies_A(int z,int k,int a) {
    stub_B(z, k, a);
}
