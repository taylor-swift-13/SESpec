#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo215(int * args, int args_len, int x, int y) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int i = 0;
		int r = y - 1;
		int p = -1;

	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= y => -1 <= p && p < y) &&
    (0 <= y => (-1 <= r && r < y) || (r < -1)) &&
    (0 <= y => 0 <= i && i <= y) &&
    (p == -1 || (0 <= p && p < y && args_l[p] == x)) &&
    (p != -1 => (exists (k:Z), 0 <= k && k < y && args_l[k] == x && k <= p)) &&
    ((i > r && p != -1) => (0 <= p && p < y && args_l[p] == x)) &&
    ((0 <= y@pre - 1) => (0 <= i && i <= y@pre && -1 <= p && p < y@pre && r < y@pre)) &&
    ((0 <= y@pre - 1) => (((p == -1)&&(r == y@pre - 1)&&(i == 0)&&(y == y@pre)&&(x == x@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (0 <= i && i <= y@pre))) &&
    ((0 <= y@pre - 1) => (((p == -1)&&(r == y@pre - 1)&&(i == 0)&&(y == y@pre)&&(x == x@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (-1 <= r && r < y@pre))) &&
    ((0 <= y@pre - 1) => (((p == -1)&&(r == y@pre - 1)&&(i == 0)&&(y == y@pre)&&(x == x@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (-1 <= p && p < y@pre))) &&
    ((!(0 <= y@pre - 1)) => ((p == -1)&&(r == y@pre - 1)&&(i == 0)&&(y == y@pre)&&(x == x@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
    (y == y@pre) &&
    (x == x@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre)
    */
while (i <= r) {
			int tmp = (i + r) / 2;
			if (args[tmp] == x) {
				p = tmp;
				i = tmp + 1;
			} else if (args[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}

		return p;
}