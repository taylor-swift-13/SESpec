#include <limits.h>

/*@ requires (0 <= n <= array) && (0 <= max_so_far) && (0 <= max_ending_here) && (0 <= max) && (0 <= stop) && (0 <= step <= n) && (max_so_far >= max_ending_here) && (stop <= n) && (max <= stop + 1) && (array == \at(array,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (\forall integer k; 0 <= k < n ==> a[k] == \at(a[k],Pre)) && (!(n < \at(array,Pre)) ==> n == \at(array,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *a, int a_len, int array, int k, int max_ending_here, int max_so_far, int n, int step, int stop) {
    /*@ assert (stop == 0 || stop < array); */
    /*@ assert (stop == 0 || max_so_far >= a[stop]); */
    /*@ assert (stop == 0 || a[stop] <= max_so_far); */
    /*@ assert (stop <= n); */
    /*@ assert (stop <= n || stop <= array); */
    /*@ assert (stop <= n || step <= stop + 1); */
    /*@ assert (stop <= n || step <= array); */
    /*@ assert (stop <= n || n <= array); */
    /*@ assert (stop <= n || max <= step); */
    /*@ assert (stop <= n || max <= array); */
    /*@ assert (stop <= array || step <= stop + 1); */
    /*@ assert (stop <= array || step <= n); */
    /*@ assert (stop <= array || max <= step); */
    /*@ assert (stop <= array || max <= n + 1); */
    /*@ assert (stop < array || stop == 0); */
    /*@ assert (step == 0 || step <= n + 1); */
    /*@ assert (step == 0 || step <= array); */
    /*@ assert (step == 0 || 0 <= step <= n); */
    /*@ assert (step <= stop + 1 || step <= n); */
    /*@ assert (step <= stop + 1 || n <= array); */
    /*@ assert (step <= stop + 1 || max <= n + 1); */
    /*@ assert (step <= stop + 1 || max <= array); */
    /*@ assert (step <= n); */
    /*@ assert (step <= n || n <= array); */
    /*@ assert (step <= n || max <= n + 1); */
    /*@ assert (step <= n || max <= array); */
    /*@ assert (step <= n + 1); */
    /*@ assert (step <= array || step <= stop + 1); */
    /*@ assert (step <= array || step <= n); */
    /*@ assert (step <= array || max <= step); */
    /*@ assert (step <= array || max <= n + 1); */
    /*@ assert (max_so_far >= max_ending_here || max_ending_here >= max_so_far); */
    /*@ assert (max_so_far >= max_ending_here || max_ending_here == 0); */
    /*@ assert (max_ending_here >= 0 || step == n + 1); */
    /*@ assert (max_ending_here >= 0 || max_ending_here < 0); */
    /*@ assert (max_ending_here == 0 || step <= n); */
    /*@ assert (max_ending_here == 0 || step <= n + 1); */
    /*@ assert (max_ending_here == 0 || max_ending_here > 0); */
    /*@ assert (max_ending_here <= max_so_far); */
    /*@ assert (max_ending_here <= max_so_far || max_so_far == 0); */
    /*@ assert (max_ending_here <= max_so_far || max_so_far < 0); */
    /*@ assert (max == step || max <= step); */
    /*@ assert (max == 0 || max < n + 1); */
    /*@ assert (max <= stop + 1); */
    /*@ assert (max <= step); */
    /*@ assert (max <= step || step <= stop + 1); */
    /*@ assert (max <= step || n <= array); */
    /*@ assert (max <= step || max <= array); */
    /*@ assert (max <= step + 1); */
    /*@ assert (max <= n + 1); */
    /*@ assert (max <= n + 1 || n <= array); */
    /*@ assert (max <= array || max <= n + 1); */
    /*@ assert (max < n + 1); */
    /*@ assert (max - 1 <= stop); */
    /*@ assert (0 <= stop); */
    /*@ assert (0 <= stop < array || stop == 0); */
    /*@ assert (0 <= step); */
    /*@ assert (0 <= n); */
    /*@ assert (0 <= max_so_far); */
    /*@ assert (0 <= max_ending_here); */
    /*@ assert (0 <= max); */
}

/*@ requires (stop == 0 || stop < array) && (stop == 0 || max_so_far >= a[stop]) && (stop == 0 || a[stop] <= max_so_far) && (stop <= n) && (stop <= n || stop <= array) && (stop <= n || step <= stop + 1) && (stop <= n || step <= array) && (stop <= n || n <= array) && (stop <= n || max <= step) && (stop <= n || max <= array) && (stop <= array || step <= stop + 1) && (stop <= array || step <= n) && (stop <= array || max <= step) && (stop <= array || max <= n + 1) && (stop < array || stop == 0) && (step == 0 || step <= n + 1) && (step == 0 || step <= array) && (step == 0 || 0 <= step <= n) && (step <= stop + 1 || step <= n) && (step <= stop + 1 || n <= array) && (step <= stop + 1 || max <= n + 1) && (step <= stop + 1 || max <= array) && (step <= n) && (step <= n || n <= array) && (step <= n || max <= n + 1) && (step <= n || max <= array) && (step <= n + 1) && (step <= array || step <= stop + 1) && (step <= array || step <= n) && (step <= array || max <= step) && (step <= array || max <= n + 1) && (max_so_far >= max_ending_here || max_ending_here >= max_so_far) && (max_so_far >= max_ending_here || max_ending_here == 0) && (max_ending_here >= 0 || step == n + 1) && (max_ending_here >= 0 || max_ending_here < 0) && (max_ending_here == 0 || step <= n) && (max_ending_here == 0 || step <= n + 1) && (max_ending_here == 0 || max_ending_here > 0) && (max_ending_here <= max_so_far) && (max_ending_here <= max_so_far || max_so_far == 0) && (max_ending_here <= max_so_far || max_so_far < 0) && (max == step || max <= step) && (max == 0 || max < n + 1) && (max <= stop + 1) && (max <= step) && (max <= step || step <= stop + 1) && (max <= step || n <= array) && (max <= step || max <= array) && (max <= step + 1) && (max <= n + 1) && (max <= n + 1 || n <= array) && (max <= array || max <= n + 1) && (max < n + 1) && (max - 1 <= stop) && (0 <= stop) && (0 <= stop < array || stop == 0) && (0 <= step) && (0 <= n) && (0 <= max_so_far) && (0 <= max_ending_here) && (0 <= max);
    assigns \nothing;
*/
void check_B_implies_A(int *a, int a_len, int array, int k, int max_ending_here, int max_so_far, int n, int step, int stop) {
    /*@ assert (0 <= n <= array); */
    /*@ assert (0 <= max_so_far); */
    /*@ assert (0 <= max_ending_here); */
    /*@ assert (0 <= max); */
    /*@ assert (0 <= stop); */
    /*@ assert (0 <= step <= n); */
    /*@ assert (max_so_far >= max_ending_here); */
    /*@ assert (stop <= n); */
    /*@ assert (max <= stop + 1); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (a_len == \at(a_len,Pre)); */
    /*@ assert (a == \at(a,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < n ==> a[k] == \at(a[k],Pre)); */
    /*@ assert (!(n < \at(array,Pre)) ==> n == \at(array,Pre)); */
}
