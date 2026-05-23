#include <limits.h>



/*@loop invariant 0 <= i;
      loop invariant 0 <= j <= i;
      loop invariant 0 <= k <= i;
      loop invariant j + k == i;
      loop invariant i % 3 == 0;
      loop invariant j % 3 == 0;
      loop invariant k % 3 == 0;
      loop invariant i == j + k;
      loop invariant 0 <= i;
      loop invariant (i < n) ==> (j + k < n + 2);
      loop invariant (i >= n) ==> (j + k >= n);
      loop assigns i, j, k;*/
void stub_A(int n);

/*@loop invariant k % 3 == 0;
    loop invariant j <= i && k <= i;
    loop invariant j + k == i;
    loop invariant j % 3 == 0;
    loop invariant i == j + k;
    loop invariant i % 3 == 0;
    loop invariant i % 2 == 0 || i % 2 == 1;
    loop invariant 0 <= k;
    loop invariant 0 <= j;
    loop invariant 0 <= i;
    loop invariant (i % 2 == 0) ==> (k == i - j);
    loop invariant (i % 2 != 0) ==> (j == i - k);
    loop assigns k;
    loop assigns j;
    loop assigns i;*/
void stub_B(int n);

/*@loop invariant k % 3 == 0;
    loop invariant j <= i && k <= i;
    loop invariant j + k == i;
    loop invariant j % 3 == 0;
    loop invariant i == j + k;
    loop invariant i % 3 == 0;
    loop invariant i % 2 == 0 || i % 2 == 1;
    loop invariant 0 <= k;
    loop invariant 0 <= j;
    loop invariant 0 <= i;
    loop invariant (i % 2 == 0) ==> (k == i - j);
    loop invariant (i % 2 != 0) ==> (j == i - k);
    loop assigns k;
    loop assigns j;
    loop assigns i;*/
void check_A_implies_B(int n) {
    stub_A(n);
}

/*@loop invariant 0 <= i;
      loop invariant 0 <= j <= i;
      loop invariant 0 <= k <= i;
      loop invariant j + k == i;
      loop invariant i % 3 == 0;
      loop invariant j % 3 == 0;
      loop invariant k % 3 == 0;
      loop invariant i == j + k;
      loop invariant 0 <= i;
      loop invariant (i < n) ==> (j + k < n + 2);
      loop invariant (i >= n) ==> (j + k >= n);
      loop assigns i, j, k;*/
void check_B_implies_A(int n) {
    stub_B(n);
}
