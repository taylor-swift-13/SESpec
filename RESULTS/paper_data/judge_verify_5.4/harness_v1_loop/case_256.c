#include <limits.h>

/*@ requires ((0 <= \at(args_len,Pre) - 1) ==> (ret <= top + 1)) && ((0 <= \at(args_len,Pre) - 1) ==> (((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(Array == \at(Array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (ret <= top + 1))) && ((!(0 <= \at(args_len,Pre) - 1)) ==> ((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(Array == \at(Array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)))) && (Array == \at(Array,Pre)) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int *Array, int *args, int *args_len, int k, int *ret, int *top) {
    /*@ assert (top == args_len - 1 || args[top+1] > Array) && (top == args_len - 1 || top < args_len - 1) && (top < args_len) && (top < args_len - 1 || top == args_len - 1) && (top < args_len - 1 || top + 1 == args_len) && (top < args_len - 1 ==> args[top+1] > Array) && (top + 1 == args_len || args[top+1] >= Array) && (top + 1 == args_len || args[top+1] > Array) && (top + 1 <= args_len) && (ret > 0 ==> ret - 1 <= top) && (ret > 0 ==> args[ret-1] < Array) && (ret == 0 || ret >= 0) && (ret == 0 || ret > 0) && (ret == 0 || ret - 1 <= top) && (ret == 0 || args[ret-1] <= Array) && (ret == 0 || args[ret-1] < Array) && (0 <= ret) && (0 <= ret || top < 0) && (0 <= ret || ret == top + 1); */
}

/*@ requires (top == args_len - 1 || args[top+1] > Array) && (top == args_len - 1 || top < args_len - 1) && (top < args_len) && (top < args_len - 1 || top == args_len - 1) && (top < args_len - 1 || top + 1 == args_len) && (top < args_len - 1 ==> args[top+1] > Array) && (top + 1 == args_len || args[top+1] >= Array) && (top + 1 == args_len || args[top+1] > Array) && (top + 1 <= args_len) && (ret > 0 ==> ret - 1 <= top) && (ret > 0 ==> args[ret-1] < Array) && (ret == 0 || ret >= 0) && (ret == 0 || ret > 0) && (ret == 0 || ret - 1 <= top) && (ret == 0 || args[ret-1] <= Array) && (ret == 0 || args[ret-1] < Array) && (0 <= ret) && (0 <= ret || top < 0) && (0 <= ret || ret == top + 1);
    assigns \nothing;
*/
void check_B_implies_A(int *Array, int *args, int *args_len, int k, int *ret, int *top) {
    /*@ assert ((0 <= \at(args_len,Pre) - 1) ==> (ret <= top + 1)) && ((0 <= \at(args_len,Pre) - 1) ==> (((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(Array == \at(Array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (ret <= top + 1))) && ((!(0 <= \at(args_len,Pre) - 1)) ==> ((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(Array == \at(Array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)))) && (Array == \at(Array,Pre)) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)) && (\forall integer k); */
}
