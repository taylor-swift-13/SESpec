#include <limits.h>


/*@
  logic integer max2(integer x, integer y) = x >= y ? x : y;

  logic integer best_end(int* a, integer i) =
    i <= 0 ? 0 : max2(0, best_end(a, i - 1) + a[i - 1]);

  logic integer best_overall(int* a, integer i) =
    i <= 0 ? 0 : max2(best_overall(a, i - 1), best_end(a, i));
*/

/*@requires \valid(&a[0] + (0..a_len-1));
  requires size == 0;
  requires size <= a_len;
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures size > 0 ==> \result <= size;
  ensures a_len == \old(a_len);
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \old(a[k]);*/
int stub_A(int * a, int a_len, int size);

/*@loop invariant start <= s || s == 0;
        loop invariant start <= end + 1 ==> max_so_far >= max_ending_here;
        loop invariant max_ending_here >= 0 || s == i + 1;
        loop invariant start == s || start < s;
        loop invariant start <= s;
        loop invariant start <= s || start == 0;
        loop invariant start <= s && s <= i + 1;
        loop invariant start <= i;
        loop invariant start <= i + 1;
        loop invariant start <= end + 1;
        loop invariant start <= end + 1 || end == 0;
        loop invariant start <= end + 1 && end < size || end == 0;
        loop invariant s == 0 || start <= s;
        loop invariant s == 0 || s <= i + 1;
        loop invariant s <= i + 1;
        loop invariant s <= i + 1 ==> start <= s;
        loop invariant s <= i + 1 && start <= s;
        loop invariant max_so_far >= max_ending_here || max_ending_here == 0;
        loop invariant max_so_far >= 0 && max_ending_here >= 0;
        loop invariant max_ending_here == 0 || max_ending_here <= max_so_far;
        loop invariant max_ending_here <= max_so_far;
        loop invariant max_ending_here <= max_so_far || max_ending_here == 0;
        loop invariant end == 0 || start <= end + 1;
        loop invariant end == 0 || end < size;
        loop invariant end <= i;
        loop invariant end <= i || end == 0;
        loop invariant end < size || end == 0;
        loop invariant end < size ==> start <= end + 1;
        loop invariant \forall integer k; 0 <= k < i ==> max_so_far >= a[k];
        loop invariant \forall integer k; 0 <= k < i ==> max_ending_here >= 0;
        loop invariant \forall integer k; 0 <= k < i ==> a[k] <= max_so_far;
        loop invariant 0 <= start;
        loop invariant 0 <= s;
        loop invariant 0 <= max_so_far;
        loop invariant 0 <= max_ending_here;
        loop invariant 0 <= i;
        loop invariant 0 <= end;
        loop invariant 0 <= end <= i || end == 0;
        loop invariant 0 <= end < size || end == 0;
        loop invariant 0 <= end - start + 1;
        loop invariant 0 <= end + 1;
        loop assigns start;
        loop assigns s;
        loop assigns max_so_far;
        loop assigns max_ending_here;
        loop assigns i;
        loop assigns end;*/
int stub_B(int * a, int a_len, int size);

/*@loop invariant start <= s || s == 0;
        loop invariant start <= end + 1 ==> max_so_far >= max_ending_here;
        loop invariant max_ending_here >= 0 || s == i + 1;
        loop invariant start == s || start < s;
        loop invariant start <= s;
        loop invariant start <= s || start == 0;
        loop invariant start <= s && s <= i + 1;
        loop invariant start <= i;
        loop invariant start <= i + 1;
        loop invariant start <= end + 1;
        loop invariant start <= end + 1 || end == 0;
        loop invariant start <= end + 1 && end < size || end == 0;
        loop invariant s == 0 || start <= s;
        loop invariant s == 0 || s <= i + 1;
        loop invariant s <= i + 1;
        loop invariant s <= i + 1 ==> start <= s;
        loop invariant s <= i + 1 && start <= s;
        loop invariant max_so_far >= max_ending_here || max_ending_here == 0;
        loop invariant max_so_far >= 0 && max_ending_here >= 0;
        loop invariant max_ending_here == 0 || max_ending_here <= max_so_far;
        loop invariant max_ending_here <= max_so_far;
        loop invariant max_ending_here <= max_so_far || max_ending_here == 0;
        loop invariant end == 0 || start <= end + 1;
        loop invariant end == 0 || end < size;
        loop invariant end <= i;
        loop invariant end <= i || end == 0;
        loop invariant end < size || end == 0;
        loop invariant end < size ==> start <= end + 1;
        loop invariant \forall integer k; 0 <= k < i ==> max_so_far >= a[k];
        loop invariant \forall integer k; 0 <= k < i ==> max_ending_here >= 0;
        loop invariant \forall integer k; 0 <= k < i ==> a[k] <= max_so_far;
        loop invariant 0 <= start;
        loop invariant 0 <= s;
        loop invariant 0 <= max_so_far;
        loop invariant 0 <= max_ending_here;
        loop invariant 0 <= i;
        loop invariant 0 <= end;
        loop invariant 0 <= end <= i || end == 0;
        loop invariant 0 <= end < size || end == 0;
        loop invariant 0 <= end - start + 1;
        loop invariant 0 <= end + 1;
        loop assigns start;
        loop assigns s;
        loop assigns max_so_far;
        loop assigns max_ending_here;
        loop assigns i;
        loop assigns end;*/
int check_A_implies_B(int * a, int a_len, int size) {
    return stub_A(a, a_len, size);
}

/*@requires \valid(&a[0] + (0..a_len-1));
  requires size == 0;
  requires size <= a_len;
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures size > 0 ==> \result <= size;
  ensures a_len == \old(a_len);
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \old(a[k]);*/
int check_B_implies_A(int * a, int a_len, int size) {
    return stub_B(a, a_len, size);
}
