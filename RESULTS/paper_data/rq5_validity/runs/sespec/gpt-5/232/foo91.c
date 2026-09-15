
/*@ 
  logic integer count_neq_prefix(int* a, integer n, integer i) =
    i <= 0 ? 0
           : count_neq_prefix(a, n, i - 1)
             + ((0 <= i - 1 && i - 1 < n) ? ((a[i - 1] != a[i]) ? 1 : 0) : 0);
*/

/*@ 
  logic integer sum_neq_pairs{L}(int *a, integer n, integer i, integer j) =
    (i >= n - 1) ? 0 :
    (j >= n) ? sum_neq_pairs{L}(a, n, i + 1, i + 1 + 1) :
    (sum_neq_pairs{L}(a, n, i, j + 1) + ((\at(a[i], L) != \at(a[j], L)) ? 1 : 0));
*/

/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
  assigns \nothing;
  ensures \forall integer k; 0 <= k < pairs_len ==> pairs[k] == \old(pairs[k]);
  ensures pairs == \old(pairs);
  ensures pairs_len == \old(pairs_len);
  ensures array == \old(array);
  ensures \result >= 0;
*/
int foo91(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		
        /*@
          loop invariant 0 <= index <= total - 1;
          loop invariant total == \at(pairs_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant pairs_len == \at(pairs_len,Pre);
          loop invariant pairs == \at(pairs,Pre);
          loop invariant \forall integer k; 0 <= k < total ==> pairs[k] == \at(pairs[k],Pre);
          loop invariant 0 <= count;
          loop assigns index, count;
        */
        for (int index = 0; index < total - 1; index++) {
            /*@
              loop invariant 0 <= index < total;
              loop invariant index + 1 <= c <= total;
              loop invariant 0 <= count;
              loop assigns count, c;
            */
            for (int c = index + 1; c < total; c++) {
				if (pairs[index] != pairs[c]) {
					count++;
				}
			}
            
		}
            
		return count;
}
