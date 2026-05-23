
/*@ 
  logic integer sum4(integer n) = n <= 0 ? 0 : sum4(n-1) + n*n*n*n;
*/
/*@
  requires p >= 0;
  assigns \nothing;
  ensures p == 0 ==> \result == 0;
  ensures \result >= 0;
  ensures \result == 0 <==> p == 0;
*/
int foo396(int p) {

	int even = 0;
	
	/*@
	  loop invariant 1 <= c && c <= p + 1;
	  loop invariant 0 <= even;

	  loop invariant (c == 1 && even == 0)
	                || (c > 1 && (\exists integer prev; prev >= 0
	                              && even == prev + (2*(c-1))*(2*(c-1))*(2*(c-1))*(2*(c-1))));
	  
	  loop invariant c > 1 ==> (\exists integer last; last == 2*(c-1) && last % 2 == 0);

	  loop assigns c, even;
	*/
	for (int c = 1; c <= p; c++) {
		int count = 2 * c;
		even = even + (count * count * count * count);
	}
		
	return even;
}
