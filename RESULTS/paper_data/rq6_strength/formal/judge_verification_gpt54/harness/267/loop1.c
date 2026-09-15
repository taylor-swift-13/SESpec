#include <limits.h>

/*@ logic integer oddcount(int* args, integer lo, integer hi) =
    lo >= hi ? 0
             : oddcount(args, lo, hi - 1) + ((args[hi - 1] % 2) != 0 ? 1 : 0); */
/*@ logic integer oddret(int* args, integer lo, integer hi) =
    lo >= hi ? 0
             : (((args[hi - 1] % 2) != 0) && ((oddcount(args, lo, hi - 1) + 1) % 2 != 0))
               ? args[hi - 1]
               : oddret(args, lo, hi - 1); */

/*@ requires (0 <= index <= array) && (0 <= start <= index) && (start == oddcount(args, 0, index)) && (ret == oddret(args, 0, index)) && (\forall integer k; 0 <= k < index ==> args[k] == \at(args[k], Pre)) && (array == \at(array, Pre)) && (args_len == \at(args_len, Pre)) && (args == \at(args, Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *args, int args_len, int array, int index, int k, int ret, int start) {
    /*@ assert (start > 0 ==> ret == args[index - 1] || ret != 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> start >= 0)); */
    /*@ assert (start > 0 ==> ret == 0 || ret % 2 != 0); */
    /*@ assert (start > 0 ==> ret != 0); */
    /*@ assert (start > 0 ==> ret != 0 || ret == args[index - 1]); */
    /*@ assert (start > 0 ==> (ret == 0 || ret % 2 != 0)); */
    /*@ assert (start > 0 ==> (\exists integer k; 0 <= k < index && args[k] % 2 != 0)); */
    /*@ assert (start == index || start < index); */
    /*@ assert (start == index ==> ret == 0 || ret != 0); */
    /*@ assert (start == index - (index - start)); */
    /*@ assert (start == 0 || start >= 1); */
    /*@ assert (start == 0 || start > 0); */
    /*@ assert (start == 0 || start <= index); */
    /*@ assert (start == 0 || ret != 0); */
    /*@ assert (start == 0 ==> ret == 0); */
    /*@ assert (start <= index); */
    /*@ assert (start <= index + 1); */
    /*@ assert (start <= array || start <= index + 1); */
    /*@ assert (start < index + 1); */
    /*@ assert (start % 2 == 1 ==> ret == args[index - 1] || ret != 0); */
    /*@ assert (start % 2 == 1 ==> ret != 0); */
    /*@ assert (start % 2 == 0 || start % 2 == 1); */
    /*@ assert (start % 2 == 0 || start % 2 != 0); */
    /*@ assert (start % 2 == 0 ==> ret == 0 || ret % 2 != 0); */
    /*@ assert (start % 2 == 0 ==> ret == 0 || ret != 0); */
    /*@ assert (start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret)); */
    /*@ assert (start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0)); */
    /*@ assert (start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0)); */
    /*@ assert (start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0 && ret == args[k])); */
    /*@ assert (start % 2 != 0 ==> ret == args[index-1] || ret != 0); */
    /*@ assert (start % 2 != 0 ==> ret == args[index - 1] || ret != 0); */
    /*@ assert (start % 2 != 0 ==> ret != 0); */
    /*@ assert (start % 2 != 0 ==> ret != 0 || ret == args[index - 1]); */
    /*@ assert (ret == 0 || ret == args[index-1] || ret % 2 != 0); */
    /*@ assert (ret == 0 || ret == args[index-1] || ret != 0); */
    /*@ assert (ret == 0 || ret == args[index - 1] || ret % 2 != 0); */
    /*@ assert (ret == 0 || ret == args[index - 1] || ret != 0); */
    /*@ assert (ret == 0 || ret % 2 != 0); */
    /*@ assert (ret == 0 || ret % 2 != 0 || ret == args[index - 1]); */
    /*@ assert (ret == 0 || ret != 0); */
    /*@ assert (ret == 0 || \exists integer k; 0 <= k < index && args[k] == ret); */
    /*@ assert (ret == 0 || (ret % 2 != 0)); */
    /*@ assert (ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret)); */
    /*@ assert (ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0)); */
    /*@ assert (ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0)); */
    /*@ assert (ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0 && ret == args[k])); */
    /*@ assert (ret == 0 || (\exists integer k; 0 <= k < index && (args[k] % 2 != 0) && ret == args[k])); */
    /*@ assert (ret == 0 ==> start == 0); */
    /*@ assert (ret == 0 ==> start == 0 || start > 0); */
    /*@ assert (ret != 0 ==> \exists integer k; 0 <= k < index && args[k] == ret); */
    /*@ assert (ret != 0 ==> \exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0); */
    /*@ assert (ret != 0 ==> (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0)); */
    /*@ assert (index == start + (index - start)); */
    /*@ assert (index <= array || start <= index + 1); */
    /*@ assert (index % 2 == 0 || index % 2 != 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> args[k] == 0 || args[k] != 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> args[k] % 2 == 0 || args[k] % 2 != 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> start >= 1); */
    /*@ assert (\forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> start > 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> k < array); */
    /*@ assert (\forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> args[k] != 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> args[k] != 0 || args[k] == 0); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (args[k] % 2 == 0 || args[k] % 2 != 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> start >= 1)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> ret == args[k] || ret != 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> k < array)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> args[k] != 0)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> 0 <= k < array)); */
    /*@ assert (\forall integer k; 0 <= k < index && args[k] % 2 != 0 ==> args[k] != 0); */
    /*@ assert (\forall integer k; 0 <= k < index && args[k] % 2 != 0 ==> 0 <= k < array); */
    /*@ assert (\exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> start >= 1); */
    /*@ assert (\exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> start > 0); */
    /*@ assert (\exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> ret == args[k]); */
    /*@ assert (\exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> ret != 0); */
    /*@ assert (0 <= start); */
    /*@ assert (0 <= ret || start <= array); */
    /*@ assert (0 <= ret || index <= array); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= index ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0)); */
    /*@ assert (0 <= index - start); */
    /*@ assert ((start % 2 == 0) ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0)); */
    /*@ assert ((start % 2 == 0) ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0 && ret == args[k])); */
    /*@ assert ((start % 2 != 0) ==> ret != 0); */
    /*@ assert ((\forall integer k; 0 <= k < index ==> args[k] % 2 == 0 || args[k] % 2 != 0)); */
    /*@ assert ((\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> start >= 1))); */
    /*@ assert ((\forall integer k; 0 <= k < index && args[k] % 2 != 0 ==> args[k] != 0)); */
}

/*@ requires (start > 0 ==> ret == args[index - 1] || ret != 0) && (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> start >= 0)) && (start > 0 ==> ret == 0 || ret % 2 != 0) && (start > 0 ==> ret != 0) && (start > 0 ==> ret != 0 || ret == args[index - 1]) && (start > 0 ==> (ret == 0 || ret % 2 != 0)) && (start > 0 ==> (\exists integer k; 0 <= k < index && args[k] % 2 != 0)) && (start == index || start < index) && (start == index ==> ret == 0 || ret != 0) && (start == index - (index - start)) && (start == 0 || start >= 1) && (start == 0 || start > 0) && (start == 0 || start <= index) && (start == 0 || ret != 0) && (start == 0 ==> ret == 0) && (start <= index) && (start <= index + 1) && (start <= array || start <= index + 1) && (start < index + 1) && (start % 2 == 1 ==> ret == args[index - 1] || ret != 0) && (start % 2 == 1 ==> ret != 0) && (start % 2 == 0 || start % 2 == 1) && (start % 2 == 0 || start % 2 != 0) && (start % 2 == 0 ==> ret == 0 || ret % 2 != 0) && (start % 2 == 0 ==> ret == 0 || ret != 0) && (start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret)) && (start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0)) && (start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0)) && (start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0 && ret == args[k])) && (start % 2 != 0 ==> ret == args[index-1] || ret != 0) && (start % 2 != 0 ==> ret == args[index - 1] || ret != 0) && (start % 2 != 0 ==> ret != 0) && (start % 2 != 0 ==> ret != 0 || ret == args[index - 1]) && (ret == 0 || ret == args[index-1] || ret % 2 != 0) && (ret == 0 || ret == args[index-1] || ret != 0) && (ret == 0 || ret == args[index - 1] || ret % 2 != 0) && (ret == 0 || ret == args[index - 1] || ret != 0) && (ret == 0 || ret % 2 != 0) && (ret == 0 || ret % 2 != 0 || ret == args[index - 1]) && (ret == 0 || ret != 0) && (ret == 0 || \exists integer k; 0 <= k < index && args[k] == ret) && (ret == 0 || (ret % 2 != 0)) && (ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret)) && (ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0)) && (ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0)) && (ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0 && ret == args[k])) && (ret == 0 || (\exists integer k; 0 <= k < index && (args[k] % 2 != 0) && ret == args[k])) && (ret == 0 ==> start == 0) && (ret == 0 ==> start == 0 || start > 0) && (ret != 0 ==> \exists integer k; 0 <= k < index && args[k] == ret) && (ret != 0 ==> \exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0) && (ret != 0 ==> (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0)) && (index == start + (index - start)) && (index <= array || start <= index + 1) && (index % 2 == 0 || index % 2 != 0) && (\forall integer k; 0 <= k < index ==> args[k] == 0 || args[k] != 0) && (\forall integer k; 0 <= k < index ==> args[k] % 2 == 0 || args[k] % 2 != 0) && (\forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> start >= 1) && (\forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> start > 0) && (\forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> k < array) && (\forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> args[k] != 0) && (\forall integer k; 0 <= k < index ==> args[k] != 0 || args[k] == 0) && (\forall integer k; 0 <= k < index ==> (args[k] % 2 == 0 || args[k] % 2 != 0)) && (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> start >= 1)) && (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> ret == args[k] || ret != 0)) && (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> k < array)) && (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> args[k] != 0)) && (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> 0 <= k < array)) && (\forall integer k; 0 <= k < index && args[k] % 2 != 0 ==> args[k] != 0) && (\forall integer k; 0 <= k < index && args[k] % 2 != 0 ==> 0 <= k < array) && (\exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> start >= 1) && (\exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> start > 0) && (\exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> ret == args[k]) && (\exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> ret != 0) && (0 <= start) && (0 <= ret || start <= array) && (0 <= ret || index <= array) && (0 <= index) && (0 <= index ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0)) && (0 <= index - start) && ((start % 2 == 0) ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0)) && ((start % 2 == 0) ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0 && ret == args[k])) && ((start % 2 != 0) ==> ret != 0) && ((\forall integer k; 0 <= k < index ==> args[k] % 2 == 0 || args[k] % 2 != 0)) && ((\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> start >= 1))) && ((\forall integer k; 0 <= k < index && args[k] % 2 != 0 ==> args[k] != 0));
    assigns \nothing;
*/
void check_B_implies_A(int *args, int args_len, int array, int index, int k, int ret, int start) {
    /*@ assert (0 <= index <= array); */
    /*@ assert (0 <= start <= index); */
    /*@ assert (start == oddcount(args, 0, index)); */
    /*@ assert (ret == oddret(args, 0, index)); */
    /*@ assert (\forall integer k; 0 <= k < index ==> args[k] == \at(args[k], Pre)); */
    /*@ assert (array == \at(array, Pre)); */
    /*@ assert (args_len == \at(args_len, Pre)); */
    /*@ assert (args == \at(args, Pre)); */
}
