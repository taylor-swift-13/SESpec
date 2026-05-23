
/*@
  logic integer count_pairs_with_sum(int* pairs, integer len, integer p) =
    (len <= 1) ? 0 : count_pairs_with_sum(pairs, len - 1, p) +
    (\exists integer j; 0 <= j < len - 1 && pairs[len - 1] + pairs[j] == p ? 1 : 0);
*/

/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
*/
int foo104(int * pairs, int pairs_len, int num, int p) {

		int ret = 0;
		
        /*@
          loop invariant 0 <= index <= num;
          loop invariant 0 <= ret <= count_pairs_with_sum(pairs, pairs_len, p);
          loop invariant ret == count_pairs_with_sum(pairs, index, p);
          loop invariant p == \at(p,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant pairs_len == \at(pairs_len,Pre);
          loop invariant pairs == \at(pairs,Pre);
          loop assigns index, j, ret;
        */
        for (int index = 0; index < num; index++) {
			
            /*@
              loop invariant index + 1 <= j <= num;
              loop invariant 0 <= ret <= count_pairs_with_sum(pairs, pairs_len, p);
              loop invariant ret == count_pairs_with_sum(pairs, index, p) +
                                   count_pairs_with_sum(&pairs[index], j - index, p);
              loop invariant p == \at(p,Pre);
              loop invariant num == \at(num,Pre);
              loop invariant pairs_len == \at(pairs_len,Pre);
              loop invariant pairs == \at(pairs,Pre);
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
