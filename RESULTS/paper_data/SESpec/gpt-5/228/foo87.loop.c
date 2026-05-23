
/*@
logic integer sum_prefix(int* a, integer i) =
  i <= 0 ? 0 : sum_prefix(a, i - 1) + a[i - 1];
*/

/*@
logic integer sum_up_to(int* a, integer i) =
  i < 0 ? 0 : sum_up_to(a, i - 1) + a[i];
*/

/*@
logic integer sum_c_prefix(int* a, integer d, integer c) =
  c <= 0 ? 0 : sum_c_prefix(a, d, c - 1) + a[c - 1];
*/

/*@
logic integer sum_inner_result(int* a, integer d) = sum_c_prefix(a, d, d);
*/

/*@
logic integer sum_outer_result(int* a, integer d) =
  d <= 0 ? a[0] : sum_outer_result(a, d - 1) + sum_inner_result(a, d);
*/

/*@
logic integer expected_temp(integer d) =
  d <= 0 ? 1 : expected_temp(d - 1) + (d * (d - 1)) / 2 + 1;
*/

/*@
logic integer tri(integer n) = n <= 0 ? 0 : tri(n - 1) + n;
*/

/*@
logic integer pow2(integer n) = n <= 0 ? 1 : 2 * pow2(n - 1);
*/

/*@
logic integer expected_temp_closed(integer d) = pow2(d);
*/

/*@
logic integer sum_prefix2(int* a, integer i) =
  i <= 0 ? 0 : sum_prefix2(a, i - 1) + a[i - 1];
*/

int foo87(int seed) {

		int result = 0;
		int *temp = (int *)malloc(sizeof(int) * (seed + 1));
int temp_len = seed + 1;
		temp[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant temp_len == seed + 1;
          loop invariant temp[0] == 1;
          loop invariant 1 <= d <= temp_len ==> \true;
          loop invariant \forall integer k; 0 <= k < temp_len ==> (k == 0 ==> temp[k] == 1);
          loop assigns d, temp[0..temp_len-1];
            */
            for (int d = 1; d <= seed; d++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c;
          loop invariant d > 0 ==> c <= d;
          loop invariant temp[0] == 1;
          loop invariant \forall integer k; 0 <= k < d ==> (k < c ==> \true) && (k >= c ==> \true);
          loop invariant \forall integer k; 0 <= k < d ==> k != d ==> \true;
          loop invariant \forall integer k; d < k < temp_len ==> \true;
          loop assigns temp[d], c;
            */
            for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
            
		}
            
		return temp[seed];
}
