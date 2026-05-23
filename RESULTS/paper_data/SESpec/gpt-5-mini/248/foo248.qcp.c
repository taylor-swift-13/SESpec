#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo248(int * args, int args_len, int num) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int ret = 0;

	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= index && index <= num) &&
    (0 <= ret) &&
    ((index < num@pre) => (0 <= index && index < num)) &&
    ((index < num@pre) => (0 <= ret)) &&
    ((!(index < num@pre)) => (index == num && num == num@pre && args_len == args_len@pre && args == args@pre)) &&
    (num == num@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre) &&
    (forall (i:Z), 0 <= i && i < args_len => 0 <= args_l[i] && args_l[i] <= 100)
    */
for (int index = 0; index < num; index++) {

        /*@
          loop invariant index + 1 <= c && c <= num;
          loop invariant 0 <= index && index <= num;
          loop invariant 0 <= ret;
          loop invariant (\forall int i; 0 <= i && i < index ==>
                          (\forall int j; i+1 <= j && j < num ==>
                             (args[i] > args[j] ? \true : \true)));
          loop assigns c, ret;
        */
        /*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (index + 1 <= c && c <= num) &&
    (0 <= index && index <= num) &&
    (0 <= ret) &&
    ((forall (i:Z), 0 <= i && i < index => (forall (j:Z), i+1 <= j && j < num => (args_l[i] > args_l[j] ? true : true))))
    */
for (int c = index + 1; c < num; c++) {
            if (args[index] > args[c]) {
                ret++;
            }
        }
    }
		return ret;
}