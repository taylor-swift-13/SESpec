
/*@ logic integer last_digit(integer x) =
    x >= 0 ? x % 10 : (-x) % 10;
*/
/*@ 
  assigns \nothing;
  ensures num <= 1 ==> \result == 1;
  ensures num > 1 ==> \result == last_digit(fact_up_to(num));
*/
int foo150(int num) {

		int first = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant first == fact_up_to(j - 1);
          loop invariant j >= 2;
          loop invariant num == \at(num,Pre);
          loop assigns j, first;
            */
            for (int j = 2; j <= num; j++) {
			first *= j;
		}
            
		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant first >= 0;
          loop invariant result >= 0;
          loop invariant first == 0 || first > 0;
          loop invariant (!(first > 0)) ==> ();
          loop assigns result, first;
            */
            while (first > 0) {
			result = first % 10;
			first /= 10;
		}
            
		return result;
}
