#include <limits.h>


/*@
  logic integer parity(integer x) = x % 2;
*/

/*@loop invariant 0 <= n;
          loop invariant b == n % 2;
          loop invariant i + j == \at(i,Pre) + \at(j,Pre) + n;
          loop invariant i >= \at(i,Pre);
          loop invariant j >= \at(j,Pre);
          loop invariant 0 <= b <= 1;
          loop invariant \at(i,Pre) <= i <= \at(i,Pre) + n;
          loop invariant \at(j,Pre) <= j <= \at(j,Pre) + n;
          loop invariant n == i + j - \at(i,Pre) - \at(j,Pre);
          loop invariant (n % 2 == 0) ==> (b == 0);
          loop invariant (n % 2 == 1) ==> (b == 1);

          loop invariant (0 < (2 * \at(k,Pre))) ==> (b == n % 2);
          loop invariant (0 < (2 * \at(k,Pre))) ==> (0 <= n);
          loop invariant (0 < (2 * \at(k,Pre))) ==> (\at(i,Pre) <= i <= \at(i,Pre) + n);
          loop invariant (0 < (2 * \at(k,Pre))) ==> (\at(j,Pre) <= j <= \at(j,Pre) + n);
          loop invariant (0 < (2 * \at(k,Pre))) ==> (0 <= b <= 1);
          loop invariant (!(0 < (2 * \at(k,Pre)))) ==> ((b == 0)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)));
          loop invariant k == \at(k,Pre);
          loop assigns n, b, i, j;*/
void stub_A(int i, int j, int k);

/*@loop invariant n == i + j - (i + j - n);
    loop invariant n % 2 == b;
    loop invariant b == n % 2;
    loop invariant b == 0 || b == 1;
    loop invariant 0 <= n;
    loop invariant (n % 2 == 1) ==> b == 1;
    loop invariant (n % 2 == 0) ==> b == 0;
    loop assigns n;
    loop assigns j;
    loop assigns i;
    loop assigns b;*/
void stub_B(int i, int j, int k);

/*@loop invariant n == i + j - (i + j - n);
    loop invariant n % 2 == b;
    loop invariant b == n % 2;
    loop invariant b == 0 || b == 1;
    loop invariant 0 <= n;
    loop invariant (n % 2 == 1) ==> b == 1;
    loop invariant (n % 2 == 0) ==> b == 0;
    loop assigns n;
    loop assigns j;
    loop assigns i;
    loop assigns b;*/
void check_A_implies_B(int i, int j, int k) {
    stub_A(i, j, k);
}

/*@loop invariant 0 <= n;
          loop invariant b == n % 2;
          loop invariant i + j == \at(i,Pre) + \at(j,Pre) + n;
          loop invariant i >= \at(i,Pre);
          loop invariant j >= \at(j,Pre);
          loop invariant 0 <= b <= 1;
          loop invariant \at(i,Pre) <= i <= \at(i,Pre) + n;
          loop invariant \at(j,Pre) <= j <= \at(j,Pre) + n;
          loop invariant n == i + j - \at(i,Pre) - \at(j,Pre);
          loop invariant (n % 2 == 0) ==> (b == 0);
          loop invariant (n % 2 == 1) ==> (b == 1);

          loop invariant (0 < (2 * \at(k,Pre))) ==> (b == n % 2);
          loop invariant (0 < (2 * \at(k,Pre))) ==> (0 <= n);
          loop invariant (0 < (2 * \at(k,Pre))) ==> (\at(i,Pre) <= i <= \at(i,Pre) + n);
          loop invariant (0 < (2 * \at(k,Pre))) ==> (\at(j,Pre) <= j <= \at(j,Pre) + n);
          loop invariant (0 < (2 * \at(k,Pre))) ==> (0 <= b <= 1);
          loop invariant (!(0 < (2 * \at(k,Pre)))) ==> ((b == 0)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)));
          loop invariant k == \at(k,Pre);
          loop assigns n, b, i, j;*/
void check_B_implies_A(int i, int j, int k) {
    stub_B(i, j, k);
}
