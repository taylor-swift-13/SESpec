#include <limits.h>

/*@ logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0); */

/*@ requires (1 <= c) && (1 <= max <= c) && (\forall integer i; 0 <= i < c ==> f <= array[i]) && (array_len == \at(array_len,Pre)) && (array == \at(array,Pre)) && (size == \at(size,Pre)) && (array[0] == \at(array[0],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *array, int array_len, int c, int f, int i, int k, int size) {
    /*@ assert (max <= c && max >= 1); */
    /*@ assert (c > 1 ==> (\exists integer k; 0 <= k < c && array[k] == f)); */
    /*@ assert (max >= 1 || c == 0); */
    /*@ assert (max >= 1 ==> f <= array[0]); */
    /*@ assert (max >= 1 ==> c >= 1); */
    /*@ assert (max >= 1 ==> \forall integer k; 0 <= k < c ==> f <= array[k]); */
    /*@ assert (max >= 1 && f <= array[0]); */
    /*@ assert (max >= 1 && c >= 0); */
    /*@ assert (max > 1 ==> max <= c); */
    /*@ assert (max > 1 ==> c > 1); */
    /*@ assert (max > 1 ==> \forall integer k; 0 <= k < c ==> array[k] >= f); */
    /*@ assert (max > 1 ==> \exists integer k; 1 <= k < c && array[k] == f); */
    /*@ assert (max > 1 ==> \exists integer k; 0 <= k < c && array[k] == f); */
    /*@ assert (max > 1 ==> (\exists integer k; 0 <= k < c && array[k] == f)); */
    /*@ assert (max == 1 || max > 1); */
    /*@ assert (max == 1 ==> f <= array[c-1]); */
    /*@ assert (max == 1 ==> f <= array[0]); */
    /*@ assert (max == 1 ==> c >= 1); */
    /*@ assert (max == 1 ==> \forall integer k; 0 <= k < c ==> f <= array[k]); */
    /*@ assert (max == 1 ==> \forall integer k; 0 <= k < c ==> array[k] >= f); */
    /*@ assert (max == 1 ==> \exists integer k; 0 <= k < c && array[k] == f); */
    /*@ assert (max == 1 ==> (\forall integer k; 0 <= k < c ==> f <= array[k])); */
    /*@ assert (max <= c); */
    /*@ assert (max <= c + 1); */
    /*@ assert (f == array[0] || f <= array[c-1]); */
    /*@ assert (f == array[0] || \exists integer k; 0 <= k < c && f == array[k]); */
    /*@ assert (f == array[0] || (\exists integer k; 0 <= k < c && f == array[k])); */
    /*@ assert (f <= array[c-1]); */
    /*@ assert (f <= array[c-1] || c == 1); */
    /*@ assert (f <= array[c-1] || c <= size); */
    /*@ assert (f <= array[c-1] || 0 <= max); */
    /*@ assert (f <= array[c-1] || 0 < size); */
    /*@ assert (f <= array[0]); */
    /*@ assert (f <= array[0] || f == array[0]); */
    /*@ assert (f <= array[0] || f <= array[c]); */
    /*@ assert (f <= array[0] || f <= array[c-1]); */
    /*@ assert (f <= array[0] || c == 1); */
    /*@ assert (c > 1 ==> max >= 1); */
    /*@ assert (c > 1 ==> \exists integer k; 0 <= k < c && array[k] == f); */
    /*@ assert (c == 1 ==> max == 1); */
    /*@ assert (c == 1 ==> f == array[0]); */
    /*@ assert (c <= size || 0 <= max); */
    /*@ assert (c <= size ==> max >= 1); */
    /*@ assert (\forall integer k; 1 <= k < c ==> f <= array[k]); */
    /*@ assert (\forall integer k; 0 <= k < c ==> f <= array[k]); */
    /*@ assert (\forall integer k; 0 <= k < c ==> f <= array[k] || array[k] == f); */
    /*@ assert (\forall integer k; 0 <= k < c ==> f <= array[k] || array[k] < f); */
    /*@ assert (\forall integer k; 0 <= k < c ==> array[k] >= f); */
    /*@ assert (\forall integer k; 0 <= k < c ==> array[k] >= f || array[k] == f); */
    /*@ assert (\forall integer k; 0 <= k < c ==> (array[k] >= f)); */
    /*@ assert (\forall integer k; 0 <= k < c ==> (array[k] == f || array[k] > f)); */
    /*@ assert (\forall integer k; 0 <= k < c ==> (array[k] == f ==> max >= 1)); */
    /*@ assert (\forall integer k; 0 <= k < c ==> (array[k] < f ==> max >= 1)); */
    /*@ assert (\forall integer k; 0 <= k < c ==> (array[k] < f ==> \false)); */
    /*@ assert (\forall integer k; 0 <= k < c && array[k] == f ==> max >= 1); */
    /*@ assert (\forall integer i; 0 <= i < c ==> f <= array[i]); */
    /*@ assert (\forall integer i; 0 <= i < c ==> (array[i] == f ==> max >= 1)); */
    /*@ assert (\forall integer i; 0 <= i < c && array[i] == f ==> max >= 1); */
    /*@ assert (\exists integer k; 0 <= k < c ==> array[k] <= f); */
    /*@ assert (\exists integer k; 0 <= k < c && f == array[k]); */
    /*@ assert (\exists integer k; 0 <= k < c && array[k] == f); */
    /*@ assert (\exists integer i; 0 <= i < c && f == array[i]); */
    /*@ assert (1 <= max); */
    /*@ assert (1 <= c); */
    /*@ assert (1 <= c || size == 0); */
    /*@ assert (0 <= max); */
    /*@ assert (0 <= c); */
    /*@ assert (0 < size || 0 <= max); */
    /*@ assert (0 < size ==> 1 <= max); */
    /*@ assert (0 < size ==> 0 < max); */
    /*@ assert (0 < max); */
    /*@ assert (0 < c); */
    /*@ assert ((max == 1) || (max > 1)); */
    /*@ assert ((max == 1) || (\exists integer k; 0 <= k < c && array[k] == f)); */
    /*@ assert ((\forall integer k; 0 <= k < c ==> array[k] >= f)); */
    /*@ assert ((\exists integer i; 0 <= i < c && f == array[i])); */
}

/*@ requires (max <= c && max >= 1) && (c > 1 ==> (\exists integer k; 0 <= k < c && array[k] == f)) && (max >= 1 || c == 0) && (max >= 1 ==> f <= array[0]) && (max >= 1 ==> c >= 1) && (max >= 1 ==> \forall integer k; 0 <= k < c ==> f <= array[k]) && (max >= 1 && f <= array[0]) && (max >= 1 && c >= 0) && (max > 1 ==> max <= c) && (max > 1 ==> c > 1) && (max > 1 ==> \forall integer k; 0 <= k < c ==> array[k] >= f) && (max > 1 ==> \exists integer k; 1 <= k < c && array[k] == f) && (max > 1 ==> \exists integer k; 0 <= k < c && array[k] == f) && (max > 1 ==> (\exists integer k; 0 <= k < c && array[k] == f)) && (max == 1 || max > 1) && (max == 1 ==> f <= array[c-1]) && (max == 1 ==> f <= array[0]) && (max == 1 ==> c >= 1) && (max == 1 ==> \forall integer k; 0 <= k < c ==> f <= array[k]) && (max == 1 ==> \forall integer k; 0 <= k < c ==> array[k] >= f) && (max == 1 ==> \exists integer k; 0 <= k < c && array[k] == f) && (max == 1 ==> (\forall integer k; 0 <= k < c ==> f <= array[k])) && (max <= c) && (max <= c + 1) && (f == array[0] || f <= array[c-1]) && (f == array[0] || \exists integer k; 0 <= k < c && f == array[k]) && (f == array[0] || (\exists integer k; 0 <= k < c && f == array[k])) && (f <= array[c-1]) && (f <= array[c-1] || c == 1) && (f <= array[c-1] || c <= size) && (f <= array[c-1] || 0 <= max) && (f <= array[c-1] || 0 < size) && (f <= array[0]) && (f <= array[0] || f == array[0]) && (f <= array[0] || f <= array[c]) && (f <= array[0] || f <= array[c-1]) && (f <= array[0] || c == 1) && (c > 1 ==> max >= 1) && (c > 1 ==> \exists integer k; 0 <= k < c && array[k] == f) && (c == 1 ==> max == 1) && (c == 1 ==> f == array[0]) && (c <= size || 0 <= max) && (c <= size ==> max >= 1) && (\forall integer k; 1 <= k < c ==> f <= array[k]) && (\forall integer k; 0 <= k < c ==> f <= array[k]) && (\forall integer k; 0 <= k < c ==> f <= array[k] || array[k] == f) && (\forall integer k; 0 <= k < c ==> f <= array[k] || array[k] < f) && (\forall integer k; 0 <= k < c ==> array[k] >= f) && (\forall integer k; 0 <= k < c ==> array[k] >= f || array[k] == f) && (\forall integer k; 0 <= k < c ==> (array[k] >= f)) && (\forall integer k; 0 <= k < c ==> (array[k] == f || array[k] > f)) && (\forall integer k; 0 <= k < c ==> (array[k] == f ==> max >= 1)) && (\forall integer k; 0 <= k < c ==> (array[k] < f ==> max >= 1)) && (\forall integer k; 0 <= k < c ==> (array[k] < f ==> \false)) && (\forall integer k; 0 <= k < c && array[k] == f ==> max >= 1) && (\forall integer i; 0 <= i < c ==> f <= array[i]) && (\forall integer i; 0 <= i < c ==> (array[i] == f ==> max >= 1)) && (\forall integer i; 0 <= i < c && array[i] == f ==> max >= 1) && (\exists integer k; 0 <= k < c ==> array[k] <= f) && (\exists integer k; 0 <= k < c && f == array[k]) && (\exists integer k; 0 <= k < c && array[k] == f) && (\exists integer i; 0 <= i < c && f == array[i]) && (1 <= max) && (1 <= c) && (1 <= c || size == 0) && (0 <= max) && (0 <= c) && (0 < size || 0 <= max) && (0 < size ==> 1 <= max) && (0 < size ==> 0 < max) && (0 < max) && (0 < c) && ((max == 1) || (max > 1)) && ((max == 1) || (\exists integer k; 0 <= k < c && array[k] == f)) && ((\forall integer k; 0 <= k < c ==> array[k] >= f)) && ((\exists integer i; 0 <= i < c && f == array[i]));
    assigns \nothing;
*/
void check_B_implies_A(int *array, int array_len, int c, int f, int i, int k, int size) {
    /*@ assert (1 <= c); */
    /*@ assert (1 <= max <= c); */
    /*@ assert (\forall integer i; 0 <= i < c ==> f <= array[i]); */
    /*@ assert (array_len == \at(array_len,Pre)); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (size == \at(size,Pre)); */
    /*@ assert (array[0] == \at(array[0],Pre)); */
}
