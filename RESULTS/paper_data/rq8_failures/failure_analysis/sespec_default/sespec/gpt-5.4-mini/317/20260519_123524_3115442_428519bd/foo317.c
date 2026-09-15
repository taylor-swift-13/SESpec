
/*@
  assigns \nothing;
  ensures \result >= 0;
*/
int foo317(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		
        /*@
          loop invariant 2 <= size;
          loop invariant result >= 0;
          loop invariant (size <= num / size) ==> (result <= size - 2);
          loop invariant (!(size <= num / size)) ==> (result >= 0);
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
