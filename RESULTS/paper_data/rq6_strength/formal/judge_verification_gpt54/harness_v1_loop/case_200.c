#include <limits.h>

/*@logic integer max2(integer x, integer y) = x >= y ? x : y;

  logic integer best_end(int* a, integer i) =
    i <= 0 ? 0 : max2(0, best_end(a, i - 1) + a[i - 1]);

  logic integer best_overall(int* a, integer i) =
    i <= 0 ? 0 : max2(best_overall(a, i - 1), best_end(a, i));*/

/*@ requires (0 <= i) && (0 <= max_so_far) && (0 <= max_ending_here) && (0 <= start <= i) && (0 <= end <= i) && (0 <= s <= i) && (max_ending_here <= max_so_far) && (max_ending_here == best_end(a, i)) && (max_so_far >= best_overall(a, i)) && (\forall integer k) && ((i < \at(size,Pre)) ==> (max_so_far >= max_ending_here)) && ((i < \at(size,Pre)) ==> (max_so_far >= best_overall(a, i))) && ((i < \at(size,Pre)) ==> (max_ending_here == best_end(a, i))) && ((i < \at(size,Pre)) ==> (0 <= start <= i)) && ((i < \at(size,Pre)) ==> (0 <= end <= i)) && ((i < \at(size,Pre)) ==> (0 <= s <= i)) && ((!(i < \at(size,Pre))) ==> (i >= \at(size,Pre))) && (size == \at(size,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int a, int a_len, int end, int i, int k, int max_ending_here, int max_so_far, int s, int size, int start) {
    /*@ assert (start <= s || s == 0) && (start <= end + 1 ==> max_so_far >= max_ending_here) && (max_ending_here >= 0 || s == i + 1) && (start == s || start < s) && (start <= s) && (start <= s || start == 0) && (start <= s && s <= i + 1) && (start <= i) && (start <= i + 1) && (start <= end + 1) && (start <= end + 1 || end == 0) && (start <= end + 1 && end < size || end == 0) && (s == 0 || start <= s) && (s == 0 || s <= i + 1) && (s <= i + 1) && (s <= i + 1 ==> start <= s) && (s <= i + 1 && start <= s) && (max_so_far >= max_ending_here || max_ending_here == 0) && (max_so_far >= 0 && max_ending_here >= 0) && (max_ending_here == 0 || max_ending_here <= max_so_far) && (max_ending_here <= max_so_far) && (max_ending_here <= max_so_far || max_ending_here == 0) && (end == 0 || start <= end + 1) && (end == 0 || end < size) && (end <= i) && (end <= i || end == 0) && (end < size || end == 0) && (end < size ==> start <= end + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (0 <= start) && (0 <= s) && (0 <= max_so_far) && (0 <= max_ending_here) && (0 <= i) && (0 <= end) && (0 <= end <= i || end == 0) && (0 <= end < size || end == 0) && (0 <= end - start + 1) && (0 <= end + 1); */
}

/*@ requires (start <= s || s == 0) && (start <= end + 1 ==> max_so_far >= max_ending_here) && (max_ending_here >= 0 || s == i + 1) && (start == s || start < s) && (start <= s) && (start <= s || start == 0) && (start <= s && s <= i + 1) && (start <= i) && (start <= i + 1) && (start <= end + 1) && (start <= end + 1 || end == 0) && (start <= end + 1 && end < size || end == 0) && (s == 0 || start <= s) && (s == 0 || s <= i + 1) && (s <= i + 1) && (s <= i + 1 ==> start <= s) && (s <= i + 1 && start <= s) && (max_so_far >= max_ending_here || max_ending_here == 0) && (max_so_far >= 0 && max_ending_here >= 0) && (max_ending_here == 0 || max_ending_here <= max_so_far) && (max_ending_here <= max_so_far) && (max_ending_here <= max_so_far || max_ending_here == 0) && (end == 0 || start <= end + 1) && (end == 0 || end < size) && (end <= i) && (end <= i || end == 0) && (end < size || end == 0) && (end < size ==> start <= end + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (0 <= start) && (0 <= s) && (0 <= max_so_far) && (0 <= max_ending_here) && (0 <= i) && (0 <= end) && (0 <= end <= i || end == 0) && (0 <= end < size || end == 0) && (0 <= end - start + 1) && (0 <= end + 1);
    assigns \nothing;
*/
void check_B_implies_A(int a, int a_len, int end, int i, int k, int max_ending_here, int max_so_far, int s, int size, int start) {
    /*@ assert (0 <= i) && (0 <= max_so_far) && (0 <= max_ending_here) && (0 <= start <= i) && (0 <= end <= i) && (0 <= s <= i) && (max_ending_here <= max_so_far) && (max_ending_here == best_end(a, i)) && (max_so_far >= best_overall(a, i)) && (\forall integer k) && ((i < \at(size,Pre)) ==> (max_so_far >= max_ending_here)) && ((i < \at(size,Pre)) ==> (max_so_far >= best_overall(a, i))) && ((i < \at(size,Pre)) ==> (max_ending_here == best_end(a, i))) && ((i < \at(size,Pre)) ==> (0 <= start <= i)) && ((i < \at(size,Pre)) ==> (0 <= end <= i)) && ((i < \at(size,Pre)) ==> (0 <= s <= i)) && ((!(i < \at(size,Pre))) ==> (i >= \at(size,Pre))) && (size == \at(size,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (\forall integer k); */
}
