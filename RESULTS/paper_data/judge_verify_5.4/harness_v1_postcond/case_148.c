#include <limits.h>



/*@assigns \nothing;
  ensures \at(n, Pre) <= 0 ==> \result == 0;
  ensures \at(n, Pre) > 0 ==> (0 <= \result <= 1);
  ensures 0 <= \result <= 1;*/
int stub_A(int n);

/*@loop invariant n > 0 ==> n / 2 < n;
        loop invariant n > 0 ==> n % 2 == 0 || n % 2 == 1;
        loop invariant n >= 1 ==> n / 2 >= 0;
        loop invariant n >= 1 ==> n != 0;
        loop invariant n >= 1 && (n % 2 == 0 || n % 2 == 1);
        loop invariant n > 0 ==> n >= 1;
        loop invariant n > 0 ==> n != 0;
        loop invariant n > 0 && n <= n;
        loop invariant n == 1 || n >= 2;
        loop invariant n == 1 || n >= 1;
        loop invariant n == 1 || n > 1;
        loop invariant n == 1 || n > 0;
        loop invariant n == 1 || n % 2 == 1 || n % 2 == 0;
        loop invariant n == 1 || n % 2 == 0 || n % 2 == 1;
        loop invariant n == 1 || n != 0;
        loop invariant n / 2 <= n;
        loop invariant n / 2 < n;
        loop invariant n % 2 == 1 ==> n >= 1;
        loop invariant n % 2 == 1 ==> n > 0;
        loop invariant n % 2 == 1 ==> n == 1 || n > 1;
        loop invariant n % 2 == 1 ==> n == 1 || n > 0;
        loop invariant n % 2 == 1 ==> n != 0;
        loop invariant n % 2 == 0 || n % 2 == 1;
        loop invariant n % 2 == 0 || n % 2 == 1 || n == 1;
        loop invariant n % 2 == 0 ==> n/2 >= 0;
        loop invariant n % 2 == 0 ==> n >= 2;
        loop invariant n % 2 == 0 ==> n >= 1;
        loop invariant n % 2 == 0 ==> n > 1;
        loop invariant n % 2 == 0 ==> n > 0;
        loop invariant n % 2 == 0 ==> n / 2 >= 1;
        loop invariant n % 2 == 0 ==> n / 2 >= 1 || n == 2;
        loop invariant n % 2 == 0 ==> n / 2 >= 0;
        loop invariant n % 2 == 0 ==> n / 2 > 0;
        loop invariant n % 2 == 0 ==> n / 2 <= n;
        loop invariant n % 2 == 0 ==> n / 2 <= n && n > 0;
        loop invariant n % 2 == 0 ==> n / 2 < n;
        loop invariant n % 2 == 0 ==> n % 4 == 0 || n % 4 == 2;
        loop invariant n % 2 == 0 ==> n != 1;
        loop invariant n % 2 == 0 ==> n != 0 && n > 0;
        loop invariant n != 0;
        loop invariant n != 0 && n >= 1;
        loop invariant n != 0 && n > 0;
        loop invariant \forall integer k; k >= 0 ==> n >= 1;
        loop invariant \exists integer m; m > 0 && n * m >= 1;
        loop invariant \exists integer m; m > 0 && n * m > 0;
        loop invariant \exists integer k; k >= 0 && n >= (1 << k);
        loop invariant \exists integer k; k >= 0 && n * (1 << k) > 0;
        loop invariant 1 <= n;
        loop invariant 0 <= n / 2;
        loop invariant 0 < n;
        loop assigns n;*/
int stub_B(int n);

/*@loop invariant n > 0 ==> n / 2 < n;
        loop invariant n > 0 ==> n % 2 == 0 || n % 2 == 1;
        loop invariant n >= 1 ==> n / 2 >= 0;
        loop invariant n >= 1 ==> n != 0;
        loop invariant n >= 1 && (n % 2 == 0 || n % 2 == 1);
        loop invariant n > 0 ==> n >= 1;
        loop invariant n > 0 ==> n != 0;
        loop invariant n > 0 && n <= n;
        loop invariant n == 1 || n >= 2;
        loop invariant n == 1 || n >= 1;
        loop invariant n == 1 || n > 1;
        loop invariant n == 1 || n > 0;
        loop invariant n == 1 || n % 2 == 1 || n % 2 == 0;
        loop invariant n == 1 || n % 2 == 0 || n % 2 == 1;
        loop invariant n == 1 || n != 0;
        loop invariant n / 2 <= n;
        loop invariant n / 2 < n;
        loop invariant n % 2 == 1 ==> n >= 1;
        loop invariant n % 2 == 1 ==> n > 0;
        loop invariant n % 2 == 1 ==> n == 1 || n > 1;
        loop invariant n % 2 == 1 ==> n == 1 || n > 0;
        loop invariant n % 2 == 1 ==> n != 0;
        loop invariant n % 2 == 0 || n % 2 == 1;
        loop invariant n % 2 == 0 || n % 2 == 1 || n == 1;
        loop invariant n % 2 == 0 ==> n/2 >= 0;
        loop invariant n % 2 == 0 ==> n >= 2;
        loop invariant n % 2 == 0 ==> n >= 1;
        loop invariant n % 2 == 0 ==> n > 1;
        loop invariant n % 2 == 0 ==> n > 0;
        loop invariant n % 2 == 0 ==> n / 2 >= 1;
        loop invariant n % 2 == 0 ==> n / 2 >= 1 || n == 2;
        loop invariant n % 2 == 0 ==> n / 2 >= 0;
        loop invariant n % 2 == 0 ==> n / 2 > 0;
        loop invariant n % 2 == 0 ==> n / 2 <= n;
        loop invariant n % 2 == 0 ==> n / 2 <= n && n > 0;
        loop invariant n % 2 == 0 ==> n / 2 < n;
        loop invariant n % 2 == 0 ==> n % 4 == 0 || n % 4 == 2;
        loop invariant n % 2 == 0 ==> n != 1;
        loop invariant n % 2 == 0 ==> n != 0 && n > 0;
        loop invariant n != 0;
        loop invariant n != 0 && n >= 1;
        loop invariant n != 0 && n > 0;
        loop invariant \forall integer k; k >= 0 ==> n >= 1;
        loop invariant \exists integer m; m > 0 && n * m >= 1;
        loop invariant \exists integer m; m > 0 && n * m > 0;
        loop invariant \exists integer k; k >= 0 && n >= (1 << k);
        loop invariant \exists integer k; k >= 0 && n * (1 << k) > 0;
        loop invariant 1 <= n;
        loop invariant 0 <= n / 2;
        loop invariant 0 < n;
        loop assigns n;*/
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@assigns \nothing;
  ensures \at(n, Pre) <= 0 ==> \result == 0;
  ensures \at(n, Pre) > 0 ==> (0 <= \result <= 1);
  ensures 0 <= \result <= 1;*/
int check_B_implies_A(int n) {
    return stub_B(n);
}
