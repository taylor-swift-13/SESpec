#include <limits.h>



/*@requires n >= 0;
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result <= n;
  ensures \result == 0 <==> (\forall integer k; 1 <= k <= n ==> (k % x) != y);
  ensures \result > 0 ==> ((\result % x) == y);
  ensures \result > 0 ==> (\forall integer k; \result < k <= n ==> (k % x) != y);
  ensures \result > 0 ==> (\forall integer k; 1 <= k <= n && (k % x) == y ==> k <= \result);*/
int stub_A(int n, int x, int y);

/*@loop invariant max == 0 || max >= 1;
        loop invariant max == 0 || max == i || max < i;
        loop invariant max == 0 || max == i || (max % x) == y;
        loop invariant max == 0 || max == i - 1 || max <= i;
        loop invariant max == 0 || max <= n;
        loop invariant max == 0 || max <= i;
        loop invariant max == 0 || max <= i-1;
        loop invariant max == 0 || max <= i - 1;
        loop invariant max == 0 || max <= i + 1;
        loop invariant max == 0 || max < i;
        loop invariant max == 0 || max < i || max == i-1;
        loop invariant max == 0 || max < i + 1;
        loop invariant max == 0 || max % x == y;
        loop invariant max == 0 || max % x == y || max == i;
        loop invariant max == 0 || \forall integer k; 1 <= k < i ==> (k % x) != y || k <= max;
        loop invariant max == 0 || \forall integer k; 1 <= k < i ==> ((k % x) == y ==> k <= max);
        loop invariant max == 0 || \forall integer k; 1 <= k < i && (k % x) == y ==> k <= max;
        loop invariant max == 0 || \exists integer k; 1 <= k <= i && (k % x) == y && max == k;
        loop invariant max == 0 || \exists integer k; 1 <= k < i && (k % x) == y && max == k;
        loop invariant max == 0 || 1 <= max <= n;
        loop invariant max == 0 || 1 <= max <= i;
        loop invariant max == 0 || 0 <= max <= n;
        loop invariant max == 0 || (max == i-1 || max < i);
        loop invariant max == 0 || (max == i || max < i);
        loop invariant max == 0 || (max == i - 1 || max <= i);
        loop invariant max == 0 || (max <= n);
        loop invariant max == 0 || (max <= i);
        loop invariant max == 0 || (max <= i - 1);
        loop invariant max == 0 || (max % x) == y;
        loop invariant max == 0 || (max % x) == y || max == i;
        loop invariant max == 0 || (max % x) == y || max == i - 1;
        loop invariant max == 0 || (max % x == y);
        loop invariant max == 0 || (\forall integer k; 1 <= k < i ==> (k % x) != y || k <= max);
        loop invariant max == 0 || (\forall integer k; 1 <= k < i && (k % x) == y ==> k <= max);
        loop invariant max == 0 || (\exists integer k; 1 <= k <= i && (k % x) == y && max == k);
        loop invariant max == 0 || (\exists integer k; 1 <= k < i && (k % x) == y && max == k);
        loop invariant max == 0 || (1 <= max <= n);
        loop invariant max == 0 || (1 <= max <= i);
        loop invariant max == 0 || (1 <= max <= i && (max % x) == y);
        loop invariant max == 0 || (1 <= max < i && (max % x) == y);
        loop invariant max == 0 || (1 <= max && max <= i);
        loop invariant max == 0 || ((max % x) == y);
        loop invariant max <= i;
        loop invariant max <= i-1;
        loop invariant max <= i - 1;
        loop invariant \forall integer k; 1 <= k <= i ==> max >= 0;
        loop invariant \forall integer k; 1 <= k < i ==> max >= 0;
        loop invariant \forall integer k; 1 <= k < i ==> k <= i;
        loop invariant \forall integer k; 1 <= k < i ==> (k % x) == y ==> max >= k;
        loop invariant \forall integer k; 1 <= k < i ==> (k % x) == y ==> k <= max;
        loop invariant \forall integer k; 1 <= k < i ==> (k % x) != y || k <= max;
        loop invariant \forall integer k; 1 <= k < i ==> ((k % x) == y ==> k <= max);
        loop invariant \forall integer k; 1 <= k < i ==> ((k % x) != y || k <= max);
        loop invariant \forall integer k; 1 <= k < i && (k % x) == y ==> max >= k;
        loop invariant \forall integer k; 1 <= k < i && (k % x) == y ==> k <= max;
        loop invariant \forall integer k; 1 <= k < i && (k % x) == y ==> k <= max || max == 0;
        loop invariant \forall integer k; 1 <= k < i && (k % x == y) ==> max >= k;
        loop invariant \exists integer k; 1 <= k <= i && (k % x) == y ==> max >= k;
        loop invariant \exists integer k; 1 <= k < i && (k % x) == y ==> max == k;
        loop invariant 1 <= i;
        loop invariant 0 <= max;
        loop invariant 0 <= i;
        loop assigns max;
        loop assigns i;*/
int stub_B(int n, int x, int y);

/*@loop invariant max == 0 || max >= 1;
        loop invariant max == 0 || max == i || max < i;
        loop invariant max == 0 || max == i || (max % x) == y;
        loop invariant max == 0 || max == i - 1 || max <= i;
        loop invariant max == 0 || max <= n;
        loop invariant max == 0 || max <= i;
        loop invariant max == 0 || max <= i-1;
        loop invariant max == 0 || max <= i - 1;
        loop invariant max == 0 || max <= i + 1;
        loop invariant max == 0 || max < i;
        loop invariant max == 0 || max < i || max == i-1;
        loop invariant max == 0 || max < i + 1;
        loop invariant max == 0 || max % x == y;
        loop invariant max == 0 || max % x == y || max == i;
        loop invariant max == 0 || \forall integer k; 1 <= k < i ==> (k % x) != y || k <= max;
        loop invariant max == 0 || \forall integer k; 1 <= k < i ==> ((k % x) == y ==> k <= max);
        loop invariant max == 0 || \forall integer k; 1 <= k < i && (k % x) == y ==> k <= max;
        loop invariant max == 0 || \exists integer k; 1 <= k <= i && (k % x) == y && max == k;
        loop invariant max == 0 || \exists integer k; 1 <= k < i && (k % x) == y && max == k;
        loop invariant max == 0 || 1 <= max <= n;
        loop invariant max == 0 || 1 <= max <= i;
        loop invariant max == 0 || 0 <= max <= n;
        loop invariant max == 0 || (max == i-1 || max < i);
        loop invariant max == 0 || (max == i || max < i);
        loop invariant max == 0 || (max == i - 1 || max <= i);
        loop invariant max == 0 || (max <= n);
        loop invariant max == 0 || (max <= i);
        loop invariant max == 0 || (max <= i - 1);
        loop invariant max == 0 || (max % x) == y;
        loop invariant max == 0 || (max % x) == y || max == i;
        loop invariant max == 0 || (max % x) == y || max == i - 1;
        loop invariant max == 0 || (max % x == y);
        loop invariant max == 0 || (\forall integer k; 1 <= k < i ==> (k % x) != y || k <= max);
        loop invariant max == 0 || (\forall integer k; 1 <= k < i && (k % x) == y ==> k <= max);
        loop invariant max == 0 || (\exists integer k; 1 <= k <= i && (k % x) == y && max == k);
        loop invariant max == 0 || (\exists integer k; 1 <= k < i && (k % x) == y && max == k);
        loop invariant max == 0 || (1 <= max <= n);
        loop invariant max == 0 || (1 <= max <= i);
        loop invariant max == 0 || (1 <= max <= i && (max % x) == y);
        loop invariant max == 0 || (1 <= max < i && (max % x) == y);
        loop invariant max == 0 || (1 <= max && max <= i);
        loop invariant max == 0 || ((max % x) == y);
        loop invariant max <= i;
        loop invariant max <= i-1;
        loop invariant max <= i - 1;
        loop invariant \forall integer k; 1 <= k <= i ==> max >= 0;
        loop invariant \forall integer k; 1 <= k < i ==> max >= 0;
        loop invariant \forall integer k; 1 <= k < i ==> k <= i;
        loop invariant \forall integer k; 1 <= k < i ==> (k % x) == y ==> max >= k;
        loop invariant \forall integer k; 1 <= k < i ==> (k % x) == y ==> k <= max;
        loop invariant \forall integer k; 1 <= k < i ==> (k % x) != y || k <= max;
        loop invariant \forall integer k; 1 <= k < i ==> ((k % x) == y ==> k <= max);
        loop invariant \forall integer k; 1 <= k < i ==> ((k % x) != y || k <= max);
        loop invariant \forall integer k; 1 <= k < i && (k % x) == y ==> max >= k;
        loop invariant \forall integer k; 1 <= k < i && (k % x) == y ==> k <= max;
        loop invariant \forall integer k; 1 <= k < i && (k % x) == y ==> k <= max || max == 0;
        loop invariant \forall integer k; 1 <= k < i && (k % x == y) ==> max >= k;
        loop invariant \exists integer k; 1 <= k <= i && (k % x) == y ==> max >= k;
        loop invariant \exists integer k; 1 <= k < i && (k % x) == y ==> max == k;
        loop invariant 1 <= i;
        loop invariant 0 <= max;
        loop invariant 0 <= i;
        loop assigns max;
        loop assigns i;*/
int check_A_implies_B(int n, int x, int y) {
    return stub_A(n, x, y);
}

/*@requires n >= 0;
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result <= n;
  ensures \result == 0 <==> (\forall integer k; 1 <= k <= n ==> (k % x) != y);
  ensures \result > 0 ==> ((\result % x) == y);
  ensures \result > 0 ==> (\forall integer k; \result < k <= n ==> (k % x) != y);
  ensures \result > 0 ==> (\forall integer k; 1 <= k <= n && (k % x) == y ==> k <= \result);*/
int check_B_implies_A(int n, int x, int y) {
    return stub_B(n, x, y);
}
