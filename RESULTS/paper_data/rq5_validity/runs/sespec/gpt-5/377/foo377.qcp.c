#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo377(int seed, int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (p > seed - p)
			p = seed - p;
		int b = 1;
	
 	/*@ Inv
    ((1 <= r && r <= p@pre) => (1 <= r)) &&
    (seed == seed@pre) &&
    (r >= 1) &&
    ((r <= p@pre) => (p == p@pre || p == seed@pre - p@pre)) &&
    ((r <= p@pre) => ((p == p@pre && p@pre <= seed@pre - p@pre) || (p == seed@pre - p@pre && p@pre > seed@pre - p@pre))) &&
    ((r <= p@pre) => (r >= 1)) &&
    ((r <= p@pre) => (seed - r + 1 <= seed)) &&
    ((r <= p@pre) => (r != 0)) &&
    ((r <= p@pre) => (seed == seed@pre)) &&
    ((r <= p@pre) => (b >= 0)) &&
    ((r <= p@pre) => (b == 1 || r > 1)) &&
    ((r <= p@pre) => (forall (k:Z), 1 <= k && k < r => k <= p)) &&
    (forall (k:Z), 1 <= k && k < r => (seed - k + 1) >= (seed - r + 1)) &&
    (forall (k:Z), 1 <= k && k < r => (seed - k + 1) >= 0) &&
    (seed == seed@pre)
    */
for (int r = 1; r <= p; r++) {
        b = b * (seed - r + 1) / r;
    }
		return b;
}