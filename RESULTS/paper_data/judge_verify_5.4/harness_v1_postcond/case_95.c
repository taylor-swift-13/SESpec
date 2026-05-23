#include <limits.h>



/*@requires a_len >= 0;
  requires b_len == a_len;
  requires \valid_read(a + (0 .. a_len - 1));
  requires \valid_read(b + (0 .. b_len - 1));
  assigns \nothing;
  ensures \result == 1 ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]);
  ensures \result == 0 ==> (\exists integer k; 0 <= k < a_len && a[k] != b[k]);
  ensures \result == 1 <==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]);
  ensures 0 <= \result <= 1;
  ensures \result == 0 ==> b_len == a_len;*/
int stub_A(int * a, int a_len, int * b, int b_len);

/*@loop invariant i == 0 || a[i-1] == b[i-1];
        loop invariant a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] == b[k];
        loop invariant a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] - b[k] == 0;
        loop invariant a_len == b_len && \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k]);
        loop invariant a_len == b_len && \forall integer k; 0 <= k < i ==> !(a[k] != b[k]);
        loop invariant a_len == b_len && (i == 0 || a[i-1] == b[i-1]);
        loop invariant (i == 0) || a[i-1] == b[i-1];
        loop invariant (i == 0 || a[i-1] == b[i-1]);
        loop invariant a_len == b_len;
        loop invariant a_len == b_len ==> \forall integer k; i <= k < a_len ==> a_len == b_len;
        loop invariant a_len == b_len ==> \forall integer k; 0 <= k < i ==> a[k] == b[k];
        loop invariant a_len == b_len ==> \forall integer k; 0 <= k < i ==> !(a[k] != b[k]);
        loop invariant a_len == b_len ==> \exists integer k; 0 <= k < i && a[k] != b[k] ==> \false;
        loop invariant a_len == b_len ==> (i == 0 || a[i-1] == b[i-1]);
        loop invariant a_len == b_len && 0 <= i;
        loop invariant a_len == b_len && (\forall integer k; 0 <= k < i ==> a[k] == b[k]);
        loop invariant \forall integer k; i <= k < a_len ==> a_len == b_len;
        loop invariant \forall integer k; i <= k < a_len ==> a[k] == b[k] || a[k] != b[k];
        loop invariant \forall integer k; i <= k < a_len ==> (k < a_len);
        loop invariant \forall integer k; i <= k < a_len ==> (a_len == b_len);
        loop invariant \forall integer k; i <= k < a_len ==> (a[k] == b[k] || a[k] != b[k]);
        loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
        loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k] || a[k] != b[k];
        loop invariant \forall integer k; 0 <= k < i ==> a[k] - b[k] == 0;
        loop invariant \forall integer k; 0 <= k < i ==> a[k] != b[k] ==> \false;
        loop invariant \forall integer k; 0 <= k < i ==> a[k] != b[k] ==> 0 == 0;
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] == b[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] == b[k] || a[k] != b[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] - b[k] == 0);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> 1 == 1);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0 || a[k] - b[k] != 0);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] != b[k] ==> \false);
        loop invariant \forall integer k; 0 <= k < i ==> !(a[k] != b[k]);
        loop invariant \forall integer k; 0 <= k < a_len ==> (k < i ==> a[k] == b[k]);
        loop invariant \exists integer k; 0 <= k < i ==> a[k] != b[k];
        loop invariant \exists integer k; 0 <= k < i && a[k] != b[k] ==> \false;
        loop invariant \exists integer k; 0 <= k < i && a[k] != b[k] ==> 0 <= k < a_len;
        loop invariant 0 <= i;
        loop assigns i;*/
int stub_B(int * a, int a_len, int * b, int b_len);

/*@loop invariant i == 0 || a[i-1] == b[i-1];
        loop invariant a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] == b[k];
        loop invariant a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] - b[k] == 0;
        loop invariant a_len == b_len && \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k]);
        loop invariant a_len == b_len && \forall integer k; 0 <= k < i ==> !(a[k] != b[k]);
        loop invariant a_len == b_len && (i == 0 || a[i-1] == b[i-1]);
        loop invariant (i == 0) || a[i-1] == b[i-1];
        loop invariant (i == 0 || a[i-1] == b[i-1]);
        loop invariant a_len == b_len;
        loop invariant a_len == b_len ==> \forall integer k; i <= k < a_len ==> a_len == b_len;
        loop invariant a_len == b_len ==> \forall integer k; 0 <= k < i ==> a[k] == b[k];
        loop invariant a_len == b_len ==> \forall integer k; 0 <= k < i ==> !(a[k] != b[k]);
        loop invariant a_len == b_len ==> \exists integer k; 0 <= k < i && a[k] != b[k] ==> \false;
        loop invariant a_len == b_len ==> (i == 0 || a[i-1] == b[i-1]);
        loop invariant a_len == b_len && 0 <= i;
        loop invariant a_len == b_len && (\forall integer k; 0 <= k < i ==> a[k] == b[k]);
        loop invariant \forall integer k; i <= k < a_len ==> a_len == b_len;
        loop invariant \forall integer k; i <= k < a_len ==> a[k] == b[k] || a[k] != b[k];
        loop invariant \forall integer k; i <= k < a_len ==> (k < a_len);
        loop invariant \forall integer k; i <= k < a_len ==> (a_len == b_len);
        loop invariant \forall integer k; i <= k < a_len ==> (a[k] == b[k] || a[k] != b[k]);
        loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
        loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k] || a[k] != b[k];
        loop invariant \forall integer k; 0 <= k < i ==> a[k] - b[k] == 0;
        loop invariant \forall integer k; 0 <= k < i ==> a[k] != b[k] ==> \false;
        loop invariant \forall integer k; 0 <= k < i ==> a[k] != b[k] ==> 0 == 0;
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] == b[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] == b[k] || a[k] != b[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] - b[k] == 0);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> 1 == 1);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0 || a[k] - b[k] != 0);
        loop invariant \forall integer k; 0 <= k < i ==> (a[k] != b[k] ==> \false);
        loop invariant \forall integer k; 0 <= k < i ==> !(a[k] != b[k]);
        loop invariant \forall integer k; 0 <= k < a_len ==> (k < i ==> a[k] == b[k]);
        loop invariant \exists integer k; 0 <= k < i ==> a[k] != b[k];
        loop invariant \exists integer k; 0 <= k < i && a[k] != b[k] ==> \false;
        loop invariant \exists integer k; 0 <= k < i && a[k] != b[k] ==> 0 <= k < a_len;
        loop invariant 0 <= i;
        loop assigns i;*/
int check_A_implies_B(int * a, int a_len, int * b, int b_len) {
    return stub_A(a, a_len, b, b_len);
}

/*@requires a_len >= 0;
  requires b_len == a_len;
  requires \valid_read(a + (0 .. a_len - 1));
  requires \valid_read(b + (0 .. b_len - 1));
  assigns \nothing;
  ensures \result == 1 ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]);
  ensures \result == 0 ==> (\exists integer k; 0 <= k < a_len && a[k] != b[k]);
  ensures \result == 1 <==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]);
  ensures 0 <= \result <= 1;
  ensures \result == 0 ==> b_len == a_len;*/
int check_B_implies_A(int * a, int a_len, int * b, int b_len) {
    return stub_B(a, a_len, b, b_len);
}
