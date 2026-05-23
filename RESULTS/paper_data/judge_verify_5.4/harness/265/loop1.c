#include <limits.h>

/*@ logic integer count_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odd(a, lo, hi - 1) + ((a[hi - 1] % 2) != 0 ? 1 : 0); */
/*@ logic integer selected_odd(int* a, integer lo, integer hi, integer cnt) =
    lo >= hi ? 0 :
    (((a[lo] % 2) != 0) ?
      ((((cnt + 1) % 2) != 0) ? a[lo] : selected_odd(a, lo + 1, hi, cnt + 1)) :
      selected_odd(a, lo + 1, hi, cnt)); */
/*@ logic integer last_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : ((a[hi - 1] % 2) != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1)); */

/*@ requires (0 <= index) && ((array < 0) || (index <= array)) && (0 <= start <= index) && (start == count_odd(ints, 0, index)) && (ret == 0 || ret % 2 != 0) && ((start == 0) ==> (ret == 0)) && ((start > 0) ==> (ret == 0 || ret % 2 != 0)) && (\forall integer k; 0 <= k < index && (ints[k] % 2) != 0 ==> count_odd(ints, 0, k + 1) >= 1) && ((index == array) ==> (start == count_odd(ints, 0, array))) && (array == \at(array,Pre)) && (ints_len == \at(ints_len,Pre)) && (ints == \at(ints,Pre)) && (0 <= ints_len ==> (\forall integer k; 0 <= k < ints_len ==> ints[k] == \at(ints[k],Pre))) && ((!(index < \at(array,Pre))) ==> (array == \at(array,Pre) && ints_len == \at(ints_len,Pre) && ints == \at(ints,Pre)));
    assigns \nothing;
*/
void check_A_implies_B(int array, int index, int *ints, int ints_len, int k, int ret, int start, int t) {
    /*@ assert (start > 0 ==> (\exists integer k; 0 <= k < index && ints[k] == ret)); */
    /*@ assert (start != 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> \exists integer t; 0 <= t <= index && ret == ints[t])); */
    /*@ assert (start > 0 ==> ret == 0 || ret % 2 != 0); */
    /*@ assert (start > 0 ==> ret != 0); */
    /*@ assert (start > 0 ==> (ret == 0 || ret % 2 != 0)); */
    /*@ assert (start > 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0)); */
    /*@ assert (start == index || start == index - 1 || start <= index); */
    /*@ assert (start == index || start == index + 1 || start <= index); */
    /*@ assert (start == index - (index - start)); */
    /*@ assert (start == 0 || start >= 1); */
    /*@ assert (start == 0 || start > 0); */
    /*@ assert (start == 0 || start <= index); */
    /*@ assert (start == 0 || start % 2 == 0 || start % 2 != 0); */
    /*@ assert (start == 0 || ret != 0); */
    /*@ assert (start == 0 ==> ret == 0); */
    /*@ assert (start <= index); */
    /*@ assert (start <= index + 1); */
    /*@ assert (start <= array || 0 <= ret); */
    /*@ assert (start % 2 == 0 || start % 2 != 0); */
    /*@ assert (start % 2 == 0 ==> ret == 0 || ret % 2 != 0); */
    /*@ assert (start % 2 == 0 ==> ret == 0 || ret != 0); */
    /*@ assert (start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret)); */
    /*@ assert (start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret && ints[k] % 2 != 0)); */
    /*@ assert (start % 2 != 0 ==> ret == 0 || ret % 2 != 0); */
    /*@ assert (start % 2 != 0 ==> ret == 0 || ret != 0); */
    /*@ assert (start % 2 != 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret)); */
    /*@ assert (start % 2 != 0 ==> ret != 0); */
    /*@ assert (start % 2 != 0 ==> ret != 0 || ret == 0); */
    /*@ assert (start != 0 ==> ret == 0 || ret != 0); */
    /*@ assert (ret == 0 || ret % 2 != 0); */
    /*@ assert (ret == 0 || ret != 0); */
    /*@ assert (ret == 0 || \exists integer k; 0 <= k < index ==> ints[k] == ret); */
    /*@ assert (ret == 0 || \exists integer k; 0 <= k < index && ints[k] == ret); */
    /*@ assert (ret == 0 || (ret % 2 != 0)); */
    /*@ assert (ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret)); */
    /*@ assert (ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret && ret % 2 != 0)); */
    /*@ assert (ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret && ints[k] % 2 != 0)); */
    /*@ assert (ret == 0 || (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ret == ints[k])); */
    /*@ assert (ret == 0 || (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ints[k] == ret)); */
    /*@ assert (ret == 0 || (\exists integer k; 0 <= k < index && (ints[k] % 2 != 0) && ret == ints[k])); */
    /*@ assert (ret == 0 ==> start == 0); */
    /*@ assert (ret == 0 ==> start == 0 || start > 0); */
    /*@ assert (ret == 0 ==> start == 0 || start % 2 == 0); */
    /*@ assert (ret != 0 ==> start > 0); */
    /*@ assert (ret != 0 ==> ret % 2 != 0); */
    /*@ assert (ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] == ret)); */
    /*@ assert (ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] == ret && ints[k] % 2 != 0)); */
    /*@ assert (ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ret == ints[k])); */
    /*@ assert (ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ints[k] == ret)); */
    /*@ assert (index <= array || 0 <= ret); */
    /*@ assert (\forall integer k; 0 <= k < index ==> ints[k] >= 0 || ints[k] < 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> ints[k] % 2 == 0 || ints[k] % 2 != 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (ints[k] % 2 == 0 || ints[k] % 2 != 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> start >= 1)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> start >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> start > 0)); */
    /*@ assert (\forall integer k; 0 <= k < index && ints[k] % 2 != 0 ==> start >= 1); */
    /*@ assert (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 ==> start >= 1); */
    /*@ assert (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 ==> start > 0); */
    /*@ assert (0 <= start); */
    /*@ assert (0 <= index); */
}

/*@ requires (start > 0 ==> (\exists integer k; 0 <= k < index && ints[k] == ret)) && (start != 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0)) && (\forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> \exists integer t; 0 <= t <= index && ret == ints[t])) && (start > 0 ==> ret == 0 || ret % 2 != 0) && (start > 0 ==> ret != 0) && (start > 0 ==> (ret == 0 || ret % 2 != 0)) && (start > 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0)) && (start == index || start == index - 1 || start <= index) && (start == index || start == index + 1 || start <= index) && (start == index - (index - start)) && (start == 0 || start >= 1) && (start == 0 || start > 0) && (start == 0 || start <= index) && (start == 0 || start % 2 == 0 || start % 2 != 0) && (start == 0 || ret != 0) && (start == 0 ==> ret == 0) && (start <= index) && (start <= index + 1) && (start <= array || 0 <= ret) && (start % 2 == 0 || start % 2 != 0) && (start % 2 == 0 ==> ret == 0 || ret % 2 != 0) && (start % 2 == 0 ==> ret == 0 || ret != 0) && (start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret)) && (start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret && ints[k] % 2 != 0)) && (start % 2 != 0 ==> ret == 0 || ret % 2 != 0) && (start % 2 != 0 ==> ret == 0 || ret != 0) && (start % 2 != 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret)) && (start % 2 != 0 ==> ret != 0) && (start % 2 != 0 ==> ret != 0 || ret == 0) && (start != 0 ==> ret == 0 || ret != 0) && (ret == 0 || ret % 2 != 0) && (ret == 0 || ret != 0) && (ret == 0 || \exists integer k; 0 <= k < index ==> ints[k] == ret) && (ret == 0 || \exists integer k; 0 <= k < index && ints[k] == ret) && (ret == 0 || (ret % 2 != 0)) && (ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret)) && (ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret && ret % 2 != 0)) && (ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret && ints[k] % 2 != 0)) && (ret == 0 || (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ret == ints[k])) && (ret == 0 || (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ints[k] == ret)) && (ret == 0 || (\exists integer k; 0 <= k < index && (ints[k] % 2 != 0) && ret == ints[k])) && (ret == 0 ==> start == 0) && (ret == 0 ==> start == 0 || start > 0) && (ret == 0 ==> start == 0 || start % 2 == 0) && (ret != 0 ==> start > 0) && (ret != 0 ==> ret % 2 != 0) && (ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] == ret)) && (ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] == ret && ints[k] % 2 != 0)) && (ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ret == ints[k])) && (ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ints[k] == ret)) && (index <= array || 0 <= ret) && (\forall integer k; 0 <= k < index ==> ints[k] >= 0 || ints[k] < 0) && (\forall integer k; 0 <= k < index ==> ints[k] % 2 == 0 || ints[k] % 2 != 0) && (\forall integer k; 0 <= k < index ==> (ints[k] % 2 == 0 || ints[k] % 2 != 0)) && (\forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> start >= 1)) && (\forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> start >= 0)) && (\forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> start > 0)) && (\forall integer k; 0 <= k < index && ints[k] % 2 != 0 ==> start >= 1) && (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 ==> start >= 1) && (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 ==> start > 0) && (0 <= start) && (0 <= index);
    assigns \nothing;
*/
void check_B_implies_A(int array, int index, int *ints, int ints_len, int k, int ret, int start, int t) {
    /*@ assert (0 <= index); */
    /*@ assert ((array < 0) || (index <= array)); */
    /*@ assert (0 <= start <= index); */
    /*@ assert (start == count_odd(ints, 0, index)); */
    /*@ assert (ret == 0 || ret % 2 != 0); */
    /*@ assert ((start == 0) ==> (ret == 0)); */
    /*@ assert ((start > 0) ==> (ret == 0 || ret % 2 != 0)); */
    /*@ assert (\forall integer k; 0 <= k < index && (ints[k] % 2) != 0 ==> count_odd(ints, 0, k + 1) >= 1); */
    /*@ assert ((index == array) ==> (start == count_odd(ints, 0, array))); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (ints_len == \at(ints_len,Pre)); */
    /*@ assert (ints == \at(ints,Pre)); */
    /*@ assert (0 <= ints_len ==> (\forall integer k; 0 <= k < ints_len ==> ints[k] == \at(ints[k],Pre))); */
    /*@ assert ((!(index < \at(array,Pre))) ==> (array == \at(array,Pre) && ints_len == \at(ints_len,Pre) && ints == \at(ints,Pre))); */
}
