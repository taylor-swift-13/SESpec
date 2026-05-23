#include <limits.h>

/*@ logic integer sum(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum(a, lo, hi - 1) + a[hi - 1]; */

/*@ requires (0 <= max_ending_here) && (0 <= max_so_far) && (0 <= stop <= n) && (0 <= count <= n + 1) && (0 <= max <= n + 1) && (max_so_far >= max_ending_here) && (max <= stop + 1) && ((n < \at(array,Pre)) ==> (stop - max + 1 >= 0)) && ((n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= max_so_far))) && ((n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= max_ending_here))) && ((n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= max))) && ((n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= stop))) && ((n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= count))) && (array == \at(array,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (a == \at(a,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int a, int a_len, int array, int count, int max_ending_here, int max_so_far, int n, int stop) {
    /*@ assert (stop == 0 || stop < n); */
    /*@ assert (stop == 0 || stop < array); */
    /*@ assert (stop <= n); */
    /*@ assert (stop <= n || stop == 0); */
    /*@ assert (stop < array || stop == 0); */
    /*@ assert (stop - max + 1 <= n + 1); */
    /*@ assert (n <= array || count <= n); */
    /*@ assert (max_so_far >= max_ending_here || max_ending_here == 0); */
    /*@ assert (max_ending_here >= 0 || max_ending_here < 0); */
    /*@ assert (max_ending_here >= 0 || count == n + 1); */
    /*@ assert (max_ending_here == 0 || max_ending_here >= 0); */
    /*@ assert (max_ending_here == 0 || max_ending_here > 0); */
    /*@ assert (max_ending_here <= max_so_far); */
    /*@ assert (max_ending_here <= max_so_far || max_so_far == 0); */
    /*@ assert (max_ending_here <= max_so_far || max_ending_here == 0); */
    /*@ assert (max == 0 || max <= stop); */
    /*@ assert (max == 0 || max <= stop + 1); */
    /*@ assert (max == 0 || max <= count); */
    /*@ assert (max == 0 || max <= count + 1); */
    /*@ assert (max <= stop); */
    /*@ assert (max <= stop + 1); */
    /*@ assert (max <= stop + 1 || max == 0); */
    /*@ assert (max <= n); */
    /*@ assert (max <= n || stop <= array); */
    /*@ assert (max <= n || n <= array); */
    /*@ assert (max <= n || count <= stop + 1); */
    /*@ assert (max <= n || count <= array); */
    /*@ assert (max <= n + 1); */
    /*@ assert (max <= count); */
    /*@ assert (max <= count || max == 0); */
    /*@ assert (max <= count + 1); */
    /*@ assert (count <= stop + 1 || stop <= array); */
    /*@ assert (count <= stop + 1 || n <= array); */
    /*@ assert (count <= stop + 1 || count <= array); */
    /*@ assert (count <= n); */
    /*@ assert (count <= n || stop < array); */
    /*@ assert (count <= n + 1); */
    /*@ assert (count <= array || count <= stop + 1); */
    /*@ assert (0 <= stop); */
    /*@ assert (0 <= stop || stop == 0); */
    /*@ assert (0 <= stop <= n || stop == 0); */
    /*@ assert (0 <= stop < array || stop == 0); */
    /*@ assert (0 <= stop - max + 1); */
    /*@ assert (0 <= n); */
    /*@ assert (0 <= max_so_far); */
    /*@ assert (0 <= max_ending_here); */
    /*@ assert (0 <= max); */
    /*@ assert (0 <= count); */
    /*@ assert (-1 <= stop); */
}

/*@ requires (stop == 0 || stop < n) && (stop == 0 || stop < array) && (stop <= n) && (stop <= n || stop == 0) && (stop < array || stop == 0) && (stop - max + 1 <= n + 1) && (n <= array || count <= n) && (max_so_far >= max_ending_here || max_ending_here == 0) && (max_ending_here >= 0 || max_ending_here < 0) && (max_ending_here >= 0 || count == n + 1) && (max_ending_here == 0 || max_ending_here >= 0) && (max_ending_here == 0 || max_ending_here > 0) && (max_ending_here <= max_so_far) && (max_ending_here <= max_so_far || max_so_far == 0) && (max_ending_here <= max_so_far || max_ending_here == 0) && (max == 0 || max <= stop) && (max == 0 || max <= stop + 1) && (max == 0 || max <= count) && (max == 0 || max <= count + 1) && (max <= stop) && (max <= stop + 1) && (max <= stop + 1 || max == 0) && (max <= n) && (max <= n || stop <= array) && (max <= n || n <= array) && (max <= n || count <= stop + 1) && (max <= n || count <= array) && (max <= n + 1) && (max <= count) && (max <= count || max == 0) && (max <= count + 1) && (count <= stop + 1 || stop <= array) && (count <= stop + 1 || n <= array) && (count <= stop + 1 || count <= array) && (count <= n) && (count <= n || stop < array) && (count <= n + 1) && (count <= array || count <= stop + 1) && (0 <= stop) && (0 <= stop || stop == 0) && (0 <= stop <= n || stop == 0) && (0 <= stop < array || stop == 0) && (0 <= stop - max + 1) && (0 <= n) && (0 <= max_so_far) && (0 <= max_ending_here) && (0 <= max) && (0 <= count) && (-1 <= stop);
    assigns \nothing;
*/
void check_B_implies_A(int a, int a_len, int array, int count, int max_ending_here, int max_so_far, int n, int stop) {
    /*@ assert (0 <= max_ending_here); */
    /*@ assert (0 <= max_so_far); */
    /*@ assert (0 <= stop <= n); */
    /*@ assert (0 <= count <= n + 1); */
    /*@ assert (0 <= max <= n + 1); */
    /*@ assert (max_so_far >= max_ending_here); */
    /*@ assert (max <= stop + 1); */
    /*@ assert ((n < \at(array,Pre)) ==> (stop - max + 1 >= 0)); */
    /*@ assert ((n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= max_so_far))); */
    /*@ assert ((n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= max_ending_here))); */
    /*@ assert ((n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= max))); */
    /*@ assert ((n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= stop))); */
    /*@ assert ((n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= count))); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (a_len == \at(a_len,Pre)); */
    /*@ assert (a == \at(a,Pre)); */
    /*@ assert (a == \at(a,Pre)); */
}
