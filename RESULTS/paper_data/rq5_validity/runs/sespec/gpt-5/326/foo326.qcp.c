#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo326(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int first = 1;
	
 	/*@ Inv
    (2 <= c) &&
    ((c == 2) => (first == 1)) &&
    (1 <= first) &&
    (forall (k:Z), 2 <= k && k < c => (first >= k)) &&
    ((c >= 3) => (first >= (c - 1))) &&
    ((c <= num@pre) => (first >= 1)) &&
    ((c >= 2 && c <= num@pre) => (num == num@pre)) &&
    ((c <= num@pre) => (first >= 1)) &&
    ((c <= num@pre) => ((c == 2) => (first == 1))) &&
    (num == num@pre)
    */
for (int c = 2; c <= num; c++) {
        first *= c;
    }
		int result = 0;
	
 	/*@ Inv
    (0 <= first) &&
    ((first > 0) => (0 <= result && result <= 9)) &&
    (first == 0 => (0 <= result && result <= 9))
    */
while (first > 0) {
        result = first % 10;
        first /= 10;
    }
		return result;
}