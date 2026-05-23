
/*@ 
  logic integer sum_evens_upto(integer n) =
    n <= 0 ? 0 :
    (n % 2 == 0 ? n + sum_evens_upto(n-1) : sum_evens_upto(n-1));

  logic integer count_evens_upto(integer n) =
    n <= 0 ? 0 :
    (n % 2 == 0 ? 1 + count_evens_upto(n-1) : count_evens_upto(n-1));
*/

/*@
  requires size >= 2;
  assigns \nothing;
*/
int foo254_c362(int size) {

		int result = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c <= \at(size,Pre) + 1;
          loop invariant size == \at(size,Pre);
          loop assigns c, result, total;
            */
            for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				result += c;
				total++;
			}
		}
            
		return result / total;
}
