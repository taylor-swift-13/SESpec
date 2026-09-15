#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo319(int n, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
		int l = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
	
 	/*@ Inv
    (forall (d:Z), 1 <= d && d < j => ((n % d == 0 && y % d == 0) => d <= ret)) &&
    ((exists (d:Z), 1 <= d && d < j && n % d == 0 && y % d == 0) => (ret >= 1 && n % ret == 0 && y % ret == 0)) &&
    ((ret >= 1) => (n % ret == 0 && y % ret == 0) || ret == 1) &&
    (l == 1) &&
    (forall (d:Z), 1 <= d && d <= j-1 => ((n % d == 0 && y % d == 0) => d <= ret)) &&
    ((n % ret == 0 && y % ret == 0))
    */
for (int j = 1; j <= n; j++) {
        if (n % j == 0 && y % j == 0) {
            ret = j;
        }
    }
		l = (n * y) / ret;
		return l;
}