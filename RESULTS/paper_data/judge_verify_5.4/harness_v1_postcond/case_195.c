#include <limits.h>


/*@
  logic integer sum(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@requires array >= 0;
  requires array <= 0;
  requires array == 0;
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;*/
int stub_A(int * a, int a_len, int array);

/*@loop invariant stop == 0 || stop < n;
		loop invariant stop == 0 || stop < array;
		loop invariant stop <= n;
		loop invariant stop <= n || stop == 0;
		loop invariant stop < array || stop == 0;
		loop invariant stop - max + 1 <= n + 1;
		loop invariant n <= array || count <= n;
		loop invariant max_so_far >= max_ending_here || max_ending_here == 0;
		loop invariant max_ending_here >= 0 || max_ending_here < 0;
		loop invariant max_ending_here >= 0 || count == n + 1;
		loop invariant max_ending_here == 0 || max_ending_here >= 0;
		loop invariant max_ending_here == 0 || max_ending_here > 0;
		loop invariant max_ending_here <= max_so_far;
		loop invariant max_ending_here <= max_so_far || max_so_far == 0;
		loop invariant max_ending_here <= max_so_far || max_ending_here == 0;
		loop invariant max == 0 || max <= stop;
		loop invariant max == 0 || max <= stop + 1;
		loop invariant max == 0 || max <= count;
		loop invariant max == 0 || max <= count + 1;
		loop invariant max <= stop;
		loop invariant max <= stop + 1;
		loop invariant max <= stop + 1 || max == 0;
		loop invariant max <= n;
		loop invariant max <= n || stop <= array;
		loop invariant max <= n || n <= array;
		loop invariant max <= n || count <= stop + 1;
		loop invariant max <= n || count <= array;
		loop invariant max <= n + 1;
		loop invariant max <= count;
		loop invariant max <= count || max == 0;
		loop invariant max <= count + 1;
		loop invariant count <= stop + 1 || stop <= array;
		loop invariant count <= stop + 1 || n <= array;
		loop invariant count <= stop + 1 || count <= array;
		loop invariant count <= n;
		loop invariant count <= n || stop < array;
		loop invariant count <= n + 1;
		loop invariant count <= array || count <= stop + 1;
		loop invariant 0 <= stop;
		loop invariant 0 <= stop || stop == 0;
		loop invariant 0 <= stop <= n || stop == 0;
		loop invariant 0 <= stop < array || stop == 0;
		loop invariant 0 <= stop - max + 1;
		loop invariant 0 <= n;
		loop invariant 0 <= max_so_far;
		loop invariant 0 <= max_ending_here;
		loop invariant 0 <= max;
		loop invariant 0 <= count;
		loop invariant -1 <= stop;
		loop assigns stop;
		loop assigns n;
		loop assigns max_so_far;
		loop assigns max_ending_here;
		loop assigns max;
		loop assigns count;*/
int stub_B(int * a, int a_len, int array);

/*@loop invariant stop == 0 || stop < n;
		loop invariant stop == 0 || stop < array;
		loop invariant stop <= n;
		loop invariant stop <= n || stop == 0;
		loop invariant stop < array || stop == 0;
		loop invariant stop - max + 1 <= n + 1;
		loop invariant n <= array || count <= n;
		loop invariant max_so_far >= max_ending_here || max_ending_here == 0;
		loop invariant max_ending_here >= 0 || max_ending_here < 0;
		loop invariant max_ending_here >= 0 || count == n + 1;
		loop invariant max_ending_here == 0 || max_ending_here >= 0;
		loop invariant max_ending_here == 0 || max_ending_here > 0;
		loop invariant max_ending_here <= max_so_far;
		loop invariant max_ending_here <= max_so_far || max_so_far == 0;
		loop invariant max_ending_here <= max_so_far || max_ending_here == 0;
		loop invariant max == 0 || max <= stop;
		loop invariant max == 0 || max <= stop + 1;
		loop invariant max == 0 || max <= count;
		loop invariant max == 0 || max <= count + 1;
		loop invariant max <= stop;
		loop invariant max <= stop + 1;
		loop invariant max <= stop + 1 || max == 0;
		loop invariant max <= n;
		loop invariant max <= n || stop <= array;
		loop invariant max <= n || n <= array;
		loop invariant max <= n || count <= stop + 1;
		loop invariant max <= n || count <= array;
		loop invariant max <= n + 1;
		loop invariant max <= count;
		loop invariant max <= count || max == 0;
		loop invariant max <= count + 1;
		loop invariant count <= stop + 1 || stop <= array;
		loop invariant count <= stop + 1 || n <= array;
		loop invariant count <= stop + 1 || count <= array;
		loop invariant count <= n;
		loop invariant count <= n || stop < array;
		loop invariant count <= n + 1;
		loop invariant count <= array || count <= stop + 1;
		loop invariant 0 <= stop;
		loop invariant 0 <= stop || stop == 0;
		loop invariant 0 <= stop <= n || stop == 0;
		loop invariant 0 <= stop < array || stop == 0;
		loop invariant 0 <= stop - max + 1;
		loop invariant 0 <= n;
		loop invariant 0 <= max_so_far;
		loop invariant 0 <= max_ending_here;
		loop invariant 0 <= max;
		loop invariant 0 <= count;
		loop invariant -1 <= stop;
		loop assigns stop;
		loop assigns n;
		loop assigns max_so_far;
		loop assigns max_ending_here;
		loop assigns max;
		loop assigns count;*/
int check_A_implies_B(int * a, int a_len, int array) {
    return stub_A(a, a_len, array);
}

/*@requires array >= 0;
  requires array <= 0;
  requires array == 0;
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;*/
int check_B_implies_A(int * a, int a_len, int array) {
    return stub_B(a, a_len, array);
}
