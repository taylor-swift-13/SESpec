
/*@
  // sum_odds(n) = sum of all odd integers i with 1 <= i <= n.
  logic integer sum_odds(integer n) =
    n <= 0 ? 0 :
    (n % 2 == 1 ? n + sum_odds(n-1) : sum_odds(n-1));
*/

/*@
  requires size >= 0;
  requires \true; // no requirements on initial average/total here
*/
int foo252_c360(int size) {

	int average = 0;
	int total = 0;
	
        
    /* >>> LOOP INVARIANT TO FILL <<< */
    
        /*@
          loop invariant 1 <= c <= \at(size,Pre) + 1;
          loop invariant (c <= \at(size,Pre)) ==> (average == sum_odds(c-1));
          loop invariant (c <= \at(size,Pre)) ==> (total == (c-1 + 1) / 2);
          loop invariant size == \at(size,Pre);
          loop assigns c, average, total;
        */
        for (int c = 1; c <= size; c++) {
		if (c % 2 != 0) {
			average += c;
			total++;
		}
	}
        
	return average / total;
}
