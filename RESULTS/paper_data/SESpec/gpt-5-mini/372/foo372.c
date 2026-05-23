
/*@ 
  logic integer count_divs_upto(integer n, integer k) =
    k <= 0 ? 0
           : count_divs_upto(n, k - 1) + ((n % k) == 0 ? 1 : 0);
*/

/*@
  requires \true;
  assigns \nothing;
  ensures num == \at(num, Pre);
  ensures \result >= 0;
*/
int foo372(int num) {

	int div = 0;
		
	/*@
	  loop invariant c >= 1;
	  loop invariant div >= 0;
	  loop invariant div == count_divs_upto(num, c - 1);
	  loop invariant num == \at(num,Pre);
	  loop assigns c, div;
	*/
	for (int c = 1; c <= num; c++) {
		if (num % c == 0) {
			div++;
		}
	}
			
	return div;
}
