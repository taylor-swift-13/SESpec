#include <limits.h>



/*@requires args_len >= 0;
  requires \valid_read(args + (0..args_len-1));
  requires 0 <= y <= args_len;
  assigns \nothing;
  ensures -1 <= \result < args_len;
  ensures \result == -1 || (0 <= \result < args_len && args[\result] == x);
  ensures \result != -1 ==> args[\result] == x;*/
int stub_A(int * args, int args_len, int x, int y);

/*@loop invariant \forall integer k; 0 <= k < i ==> args[k] != x || args[k] == x;
		loop invariant r <= y - 1;
		loop invariant r < y;
		loop invariant r < i || i <= r + 1;
		loop invariant p == -1 || p >= i || p <= r;
		loop invariant p == -1 || p <= r + 1;
		loop invariant p == -1 || p < i;
		loop invariant p == -1 || p < i || p > r;
		loop invariant p == -1 || args[p] == x;
		loop invariant p == -1 || args[p] <= x;
		loop invariant p == -1 || \exists integer k; 0 <= k < y && args[k] == x;
		loop invariant p == -1 || \exists integer k; 0 <= k < i && args[k] == x;
		loop invariant p == -1 || 0 <= p < y;
		loop invariant p == -1 || 0 <= p < y && args[p] == x;
		loop invariant p == -1 || 0 <= p < i;
		loop invariant p == -1 || (\exists integer k; 0 <= k < y && args[k] == x);
		loop invariant p == -1 || (\exists integer k; 0 <= k < i && args[k] == x);
		loop invariant p == -1 || (0 <= p < y && args[p] == x);
		loop invariant p != -1 ==> p >= i || p <= r;
		loop invariant p != -1 ==> p >= 0;
		loop invariant p != -1 ==> p <= y - 1;
		loop invariant p != -1 ==> p <= r + 1;
		loop invariant p != -1 ==> p < i;
		loop invariant p != -1 ==> p < i || p > r;
		loop invariant p != -1 ==> args[p] == x;
		loop invariant p != -1 ==> \exists integer k; 0 <= k < y && args[k] == x;
		loop invariant p != -1 ==> \exists integer k; 0 <= k < i && args[k] == x;
		loop invariant p != -1 ==> 0 <= p < y;
		loop invariant p != -1 ==> 0 <= p < i;
		loop invariant 0 <= i;
		loop invariant -1 <= p;
		loop invariant -1 <= p < i || p == -1;
		loop assigns r;
		loop assigns p;
		loop assigns i;*/
int stub_B(int * args, int args_len, int x, int y);

/*@loop invariant \forall integer k; 0 <= k < i ==> args[k] != x || args[k] == x;
		loop invariant r <= y - 1;
		loop invariant r < y;
		loop invariant r < i || i <= r + 1;
		loop invariant p == -1 || p >= i || p <= r;
		loop invariant p == -1 || p <= r + 1;
		loop invariant p == -1 || p < i;
		loop invariant p == -1 || p < i || p > r;
		loop invariant p == -1 || args[p] == x;
		loop invariant p == -1 || args[p] <= x;
		loop invariant p == -1 || \exists integer k; 0 <= k < y && args[k] == x;
		loop invariant p == -1 || \exists integer k; 0 <= k < i && args[k] == x;
		loop invariant p == -1 || 0 <= p < y;
		loop invariant p == -1 || 0 <= p < y && args[p] == x;
		loop invariant p == -1 || 0 <= p < i;
		loop invariant p == -1 || (\exists integer k; 0 <= k < y && args[k] == x);
		loop invariant p == -1 || (\exists integer k; 0 <= k < i && args[k] == x);
		loop invariant p == -1 || (0 <= p < y && args[p] == x);
		loop invariant p != -1 ==> p >= i || p <= r;
		loop invariant p != -1 ==> p >= 0;
		loop invariant p != -1 ==> p <= y - 1;
		loop invariant p != -1 ==> p <= r + 1;
		loop invariant p != -1 ==> p < i;
		loop invariant p != -1 ==> p < i || p > r;
		loop invariant p != -1 ==> args[p] == x;
		loop invariant p != -1 ==> \exists integer k; 0 <= k < y && args[k] == x;
		loop invariant p != -1 ==> \exists integer k; 0 <= k < i && args[k] == x;
		loop invariant p != -1 ==> 0 <= p < y;
		loop invariant p != -1 ==> 0 <= p < i;
		loop invariant 0 <= i;
		loop invariant -1 <= p;
		loop invariant -1 <= p < i || p == -1;
		loop assigns r;
		loop assigns p;
		loop assigns i;*/
int check_A_implies_B(int * args, int args_len, int x, int y) {
    return stub_A(args, args_len, x, y);
}

/*@requires args_len >= 0;
  requires \valid_read(args + (0..args_len-1));
  requires 0 <= y <= args_len;
  assigns \nothing;
  ensures -1 <= \result < args_len;
  ensures \result == -1 || (0 <= \result < args_len && args[\result] == x);
  ensures \result != -1 ==> args[\result] == x;*/
int check_B_implies_A(int * args, int args_len, int x, int y) {
    return stub_B(args, args_len, x, y);
}
