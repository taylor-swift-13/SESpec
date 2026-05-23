#include <limits.h>

/*@ requires (0 <= ret <= args_len) && (-1 <= top < args_len) && (ret <= top + 1) && (args_len == \at(args_len,Pre)) && (array == \at(array,Pre)) && (args == \at(args,Pre)) && (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre)) && (ret == 0 || args[ret - 1] < array) && (top == args_len - 1 || args[top + 1] > array) && ((ret > top) ==> (ret == 0 || args[ret - 1] < array)) && ((ret > top) ==> (top == args_len - 1 || args[top + 1] > array));
    assigns \nothing;
*/
void check_A_implies_B(int *args, int args_len, int array, int k, int ret, int top) {
    /*@ assert (args_len > 0 ==> top + 1 == args_len || array <= args[top + 1]); */
    /*@ assert (args_len > 0 ==> 0 <= ret <= top + 1 <= args_len); */
    /*@ assert (top == args_len - 1 || top < args_len - 1); */
    /*@ assert (top == args_len - 1 || args[top + 1] >= array); */
    /*@ assert (top < args_len); */
    /*@ assert (ret == 0 || args[ret - 1] < array); */
    /*@ assert (args_len > 0 ==> top + 1 <= args_len); */
    /*@ assert (args_len > 0 ==> ret == 0 || args[ret - 1] < array); */
    /*@ assert (args_len > 0 ==> ret <= top + 1 <= args_len); */
    /*@ assert (args_len > 0 ==> ret <= args_len && top + 1 >= 0); */
    /*@ assert (args_len > 0 ==> ret <= args_len && top + 1 <= args_len); */
    /*@ assert (args_len > 0 ==> 0 <= top + 1 <= args_len); */
    /*@ assert (args_len > 0 ==> 0 <= ret <= args_len); */
    /*@ assert (args_len > 0 ==> (top + 1 == args_len || array <= args[top + 1])); */
    /*@ assert (args_len > 0 ==> (top + 1 < args_len ==> array <= args[top + 1])); */
    /*@ assert (args_len > 0 ==> (ret > 0 ==> args[ret - 1] < array)); */
    /*@ assert (args_len > 0 ==> (ret == 0 || args[ret - 1] < array)); */
    /*@ assert (args_len > 0 ==> (0 <= ret && top < args_len)); */
    /*@ assert (args_len == 0 ==> top == -1); */
    /*@ assert (args_len == 0 ==> top == -1 && ret == 0); */
    /*@ assert (args_len == 0 ==> ret == 0); */
    /*@ assert (args_len == 0 ==> ret == 0 && top == -1); */
    /*@ assert (0 <= ret); */
}

/*@ requires (args_len > 0 ==> top + 1 == args_len || array <= args[top + 1]) && (args_len > 0 ==> 0 <= ret <= top + 1 <= args_len) && (top == args_len - 1 || top < args_len - 1) && (top == args_len - 1 || args[top + 1] >= array) && (top < args_len) && (ret == 0 || args[ret - 1] < array) && (args_len > 0 ==> top + 1 <= args_len) && (args_len > 0 ==> ret == 0 || args[ret - 1] < array) && (args_len > 0 ==> ret <= top + 1 <= args_len) && (args_len > 0 ==> ret <= args_len && top + 1 >= 0) && (args_len > 0 ==> ret <= args_len && top + 1 <= args_len) && (args_len > 0 ==> 0 <= top + 1 <= args_len) && (args_len > 0 ==> 0 <= ret <= args_len) && (args_len > 0 ==> (top + 1 == args_len || array <= args[top + 1])) && (args_len > 0 ==> (top + 1 < args_len ==> array <= args[top + 1])) && (args_len > 0 ==> (ret > 0 ==> args[ret - 1] < array)) && (args_len > 0 ==> (ret == 0 || args[ret - 1] < array)) && (args_len > 0 ==> (0 <= ret && top < args_len)) && (args_len == 0 ==> top == -1) && (args_len == 0 ==> top == -1 && ret == 0) && (args_len == 0 ==> ret == 0) && (args_len == 0 ==> ret == 0 && top == -1) && (0 <= ret);
    assigns \nothing;
*/
void check_B_implies_A(int *args, int args_len, int array, int k, int ret, int top) {
    /*@ assert (0 <= ret <= args_len); */
    /*@ assert (-1 <= top < args_len); */
    /*@ assert (ret <= top + 1); */
    /*@ assert (args_len == \at(args_len,Pre)); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (args == \at(args,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre)); */
    /*@ assert (ret == 0 || args[ret - 1] < array); */
    /*@ assert (top == args_len - 1 || args[top + 1] > array); */
    /*@ assert ((ret > top) ==> (ret == 0 || args[ret - 1] < array)); */
    /*@ assert ((ret > top) ==> (top == args_len - 1 || args[top + 1] > array)); */
}
