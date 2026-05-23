int evenPowerSum(int p);

 /*@ axiomatic SumPow4 {
       logic integer sum_pow4(integer n);
       axiom sum_pow4_nonpos: \forall integer n; n <= 0 ==> sum_pow4(n) == 0;
       axiom sum_pow4_step: \forall integer n; n > 0 ==> sum_pow4(n) == sum_pow4(n-1) + (2*n)*(2*n)*(2*n)*(2*n);
   } */

 /*@ 
   requires p <= 57;
   assigns \nothing;
   ensures \result == sum_pow4(p);
 */
int evenPowerSum(int p) {

		int even = 0;
		/*@
		  loop invariant 1 <= c <= p + 1;
		  loop invariant even == sum_pow4(c - 1);
		  loop assigns c, even;
		  loop variant p - c + 1;
		*/
		for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
		return even;
}
