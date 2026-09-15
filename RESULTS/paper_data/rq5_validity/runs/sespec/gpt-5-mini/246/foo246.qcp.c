#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo246(int * args, int args_len, int num) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int ret = 0;

	
 	/*0*/ 
 /*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= index && index <= num@pre) &&
    (0 <= ret) &&
    (ret <= num@pre * (num@pre - 1) / 2) &&
    (true)) &&
    (forall (p:Z), 0 <= p && p < args_len => 0 <= args_l[p] && args_l[p] <= 100) &&
    ((forall (i:Z), 0 <= i && i < index => (forall (j:Z), i < j && j < num@pre => 0 <= args_l[i] && args_l[i] <= 100))) &&
    ((index < num@pre) => (0 <= ret && ret <= index * (num@pre - 1))) &&
    ((!(index < num@pre)) => ((ret >= 0) && (num == num@pre) && (args_len == args_len@pre) && (args == args@pre))) &&
    (num == num@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre) &&
    (forall (q:Z), 0 <= q && q < args_len => args_l[q] == args_l[q]@pre)
    */
for (int index = 0; index < num; index++) {
		
 	/*1*/ 
 /*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= index && index <= num) &&
    (true)) &&
    (0 <= ret) &&
    (ret <= num * (num - 1) / 2) &&
    ((forall (i:Z), 0 <= i && i < index => (forall (j:Z), i < j && j < num => 0 <= args_l[i] && args_l[i] <= 100))) &&
    ((forall (p:Z), 0 <= p && p < args_len => args_l[p] == args_l[p]@pre))
    */
for (int k = index + 1; k < num; k++) {
				if (args[index] > args[k]) {
					ret++;
				}
			}
		}
		return ret;
}