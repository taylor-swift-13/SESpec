
/*@
  logic integer neq_count_from(int* a, integer i, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[i] != a[hi - 1] ? 1 : 0) + neq_count_from(a, i, lo, hi - 1);
*/

/*@
  logic integer total_neq_prefix(int* a, integer n) =
    n <= 1 ? 0
           : total_neq_prefix(a, n - 1) + neq_count_from(a, n - 2, (n - 2) + 1, n);
*/

        
/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
*/

int foo89(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= total - 1;
          loop invariant total == \at(pairs_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant pairs_len == \at(pairs_len,Pre);
          loop invariant pairs == \at(pairs,Pre);
          loop invariant \forall integer t; 0 <= t < pairs_len ==> pairs[t] == \at(pairs[t],Pre);
          loop invariant 0 <= count;
          loop assigns index, count;
            */
            for (int index = 0; index < total - 1; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant index + 1 <= k <= total;
              loop invariant 0 <= count;
              loop invariant \forall integer t; 0 <= t < pairs_len ==> pairs[t] == \at(pairs[t],Pre);
              loop assigns count, k;
            */
            for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
            
		}
            
		return count;
}
