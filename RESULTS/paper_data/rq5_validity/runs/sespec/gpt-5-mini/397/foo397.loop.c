
/*@ 
  predicate is_even(integer x) = (x % 2) == 0;
*/

/*@
  logic integer sum_fourth_powers(integer n) =
    n <= 0 ? 0 : sum_fourth_powers(n-1) + (2*n)*(2*n)*(2*n)*(2*n);
*/

int foo397(int p) {

	int even = 0;
	
    /*@
      loop invariant 1 <= c;
      loop invariant (c <= \at(p,Pre)) ==> (even == sum_fourth_powers(c-1));
      loop invariant (c <= \at(p,Pre)) ==> is_even(even);
      loop invariant (!(c <= \at(p,Pre))) ==> ((even == sum_fourth_powers(\at(p,Pre))) && (p == \at(p,Pre)));
      loop invariant p == \at(p,Pre);
      loop assigns c, even;
    */
    for (int c = 1; c <= p; c++) {
		int tmp = 2 * c;
		even = even + (tmp * tmp * tmp * tmp);
	}
        
	return even;
}
