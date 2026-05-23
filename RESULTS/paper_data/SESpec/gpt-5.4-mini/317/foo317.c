
/*@ logic integer count_divs(integer num, integer size) =
      size < 2 ? 0 :
      count_divs(num, size - 1) + (num % size == 0 ? 1 : 0);
*/

/*@ 
  requires num >= 1;
  assigns \nothing;
  ensures num == 1 ==> \result == 1;
  ensures \result >= 0;
*/
int foo317(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= size;
          loop invariant result >= 0;
          loop invariant result == count_divs(num, size - 1);
          loop invariant result <= size - 2;
          loop invariant \forall integer d; 2 <= d < size && d <= num / d && num % d == 0 ==> result >= 1;
          loop invariant (size > 2) ==> result <= size - 2;
          loop invariant (size <= num / size) ==> (result == count_divs(num, size - 1));
          loop invariant (!(size <= num / size)) ==> (result == count_divs(num, size - 1));
          loop assigns size, result;
            */
            for (int size = 2; size <= num / size; size++) {
			if (num % size == 0) {
				result++;
				if (num / size == size) {
					break;
				}
			}
		}
            
		return result;
}
