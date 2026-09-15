#include <limits.h>

/*@ requires (0 <= ret) && (ret <= stop + 1) && (-1 <= stop < array) && (0 <= array) && (args == \at(args,Pre)) && (args_len == \at(args_len,Pre)) && (array == \at(array,Pre)) && (\forall integer k; 0 <= k < array - 1 ==> args[k] < args[k + 1]) && (\exists integer k; 0 <= k < array ==> args[k] == k || ret > stop) && ((0 <= \at(array,Pre) - 1) ==> ((0 <= ret <= stop + 1) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)))) && ((0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (ret >= 0))) && ((0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (-1 <= stop < array))) && ((!(0 <= \at(array,Pre) - 1)) ==> ((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)))) && (array == \at(array,Pre)) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *args, int args_len, int array, int k, int ret, int stop) {
    /*@ assert (stop == array - 1 || stop < array - 1); */
    /*@ assert (stop <= array - 1); */
    /*@ assert (stop < array); */
    /*@ assert (stop < array ==> ret >= 0); */
    /*@ assert (stop < array - 1 ==> ret >= 0); */
    /*@ assert (stop + 1 <= array); */
    /*@ assert (ret >= 0 || ret == -1); */
    /*@ assert (ret == 0 || ret >= 0); */
    /*@ assert (ret == 0 || ret > 0); */
    /*@ assert (ret == 0 || ret > 0 || ret == -1); */
    /*@ assert (ret == 0 || ret == -1 || ret > 0); */
    /*@ assert (ret == 0 || ret <= array); */
    /*@ assert (ret == 0 ==> \forall integer k; 0 <= k < ret ==> args[k] != k); */
    /*@ assert (ret == -1 || ret >= 0); */
    /*@ assert (ret <= stop + 1 ==> ret <= array); */
    /*@ assert (ret <= array ==> stop < array); */
    /*@ assert (ret <= array ==> stop + 1 <= array); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= ret || ret == -1); */
}

/*@ requires (stop == array - 1 || stop < array - 1) && (stop <= array - 1) && (stop < array) && (stop < array ==> ret >= 0) && (stop < array - 1 ==> ret >= 0) && (stop + 1 <= array) && (ret >= 0 || ret == -1) && (ret == 0 || ret >= 0) && (ret == 0 || ret > 0) && (ret == 0 || ret > 0 || ret == -1) && (ret == 0 || ret == -1 || ret > 0) && (ret == 0 || ret <= array) && (ret == 0 ==> \forall integer k; 0 <= k < ret ==> args[k] != k) && (ret == -1 || ret >= 0) && (ret <= stop + 1 ==> ret <= array) && (ret <= array ==> stop < array) && (ret <= array ==> stop + 1 <= array) && (0 <= ret) && (0 <= ret || ret == -1);
    assigns \nothing;
*/
void check_B_implies_A(int *args, int args_len, int array, int k, int ret, int stop) {
    /*@ assert (0 <= ret); */
    /*@ assert (ret <= stop + 1); */
    /*@ assert (-1 <= stop < array); */
    /*@ assert (0 <= array); */
    /*@ assert (args == \at(args,Pre)); */
    /*@ assert (args_len == \at(args_len,Pre)); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < array - 1 ==> args[k] < args[k + 1]); */
    /*@ assert (\exists integer k; 0 <= k < array ==> args[k] == k || ret > stop); */
    /*@ assert ((0 <= \at(array,Pre) - 1) ==> ((0 <= ret <= stop + 1) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)))); */
    /*@ assert ((0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (ret >= 0))); */
    /*@ assert ((0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (-1 <= stop < array))); */
    /*@ assert ((!(0 <= \at(array,Pre) - 1)) ==> ((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)))); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (args_len == \at(args_len,Pre)); */
    /*@ assert (args == \at(args,Pre)); */
}
