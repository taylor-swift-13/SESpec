
/*@
  requires p >= 0;
*/
int foo396(int p) {

	int even = 0;
	
	/*@
	  loop invariant 1 <= c <= p + 1;
	  loop invariant 0 <= count && count == 2 * c;
	  loop invariant 0 <= even;

	  /* Functional progression (inductive style):
	     - If no iterations processed (c == 1) then even == 0.
	     - If c > 1 then even equals the previous sum plus (2*(c-1))^4.
	     This is written without nested comments or prose. */
	  loop invariant (c == 1 && even == 0)
	                || (c > 1 && (\exists integer prev; prev >= 0
	                              && even == prev + (2*(c-1))*(2*(c-1))*(2*(c-1))*(2*(c-1))));
	  
	  loop invariant c > 1 ==> (\exists integer last; last == 2*(c-1) && last % 2 == 0);

	  loop invariant (c == \at(p,Pre) + 1) ==> (p == \at(p,Pre));

	  loop assigns c, count, even;
	*/
	for (int c = 1; c <= p; c++) {
		int count = 2 * c;
		even = even + (count * count * count * count);
	}
		
	return even;
}
