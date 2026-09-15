
/*@
  logic integer count_odds_upto(integer n) =
    n <= 0 ? 0 : (n % 2 == 1 ? 1 + count_odds_upto(n - 1) : count_odds_upto(n - 1));
*/
/*@
  assigns \nothing;
  ensures (size <= 0) ==> (\true);
  ensures (size > 0) ==> (\result == sum_odd_upto(size) / count_odds_upto(size));
*/
int foo358(int size) {

		int average = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (index <= \at(size,Pre)) ==> (sum_odd_upto(index - 1) >= 0 && total >= 0);
          loop invariant size == \at(size,Pre);
          loop assigns index, average, total;
            */
            for (int index = 1; index <= size; index++) {
			if (index % 2 != 0) {
				average += index;
				total++;
			}
		}
            
		return average / total;
}
