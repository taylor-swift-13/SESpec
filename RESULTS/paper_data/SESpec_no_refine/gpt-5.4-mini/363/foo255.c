
/*@ logic integer even_sum(integer n) =
      n <= 1 ? 0 : (n % 2 == 0 ? n + even_sum(n - 1) : even_sum(n - 1)); */
/*@ logic integer even_count(integer n) =
      n <= 1 ? 0 : (n % 2 == 0 ? 1 + even_count(n - 1) : even_count(n - 1)); */
/*@
  assigns \nothing;
*/
int foo255(int size) {

		int average = 0;
		int total = 0;
		
            
        /*@
          loop invariant size == \at(size,Pre);
          loop assigns c, average, total;
            */
            for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				average += c;
				total++;
			}
		}
            
		return average / total;
}
