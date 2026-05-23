
/*@
  logic integer count_pairs_with(int* a, integer i, integer p) =
    (i <= 0) ? 0
             : count_pairs_with(a, i - 1, p) + (a[i] + a[i - 1] == p ? 1 : 0);

*/
/*@
  logic integer count_pairs_sum(int* a, integer n, integer p) =
    (n <= 1) ? 0
             : count_pairs_sum(a, n - 1, p)
               + count_pairs_with(a, n - 1, p);
*/

/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
*/

int foo245(int * pairs, int pairs_len, int num, int p) {

		int ret = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index;
          loop invariant \forall integer k; 0 <= k < pairs_len ==> 0 <= pairs[k] <= 100;
          loop invariant \forall integer k; 0 <= k < pairs_len ==> pairs[k] == \at(pairs[k], Pre);
          loop invariant (index < \at(num,Pre)) ==> (ret >= 0);
          loop invariant (index < \at(num,Pre)) ==> (0 <= index);
          loop invariant (index < \at(num,Pre)) ==> (index <= \at(num,Pre));
          loop invariant p == \at(p,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant pairs_len == \at(pairs_len,Pre);
          loop invariant pairs == \at(pairs,Pre);
          loop assigns index, ret;
            */
            for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant index + 1 <= j <= num;
          loop invariant 0 <= ret;
          loop assigns j, ret;
            */
            for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
