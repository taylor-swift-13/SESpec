
/*@ 
  logic integer is_odd_xor(int x, int y) = ((x ^ y) % 2 == 1 ? 1 : 0);
*/

/*@ 
  logic integer cnt_suffix_from(int* a, integer i, integer j, integer n) =
    j >= n ? 0
           : cnt_suffix_from(a, i, j + 1, n) + (is_odd_xor(a[i], a[j]) ? 1 : 0);
*/

/*@
  logic integer cnt_odd_xor_pairs_up_to_i(int* a, integer n, integer i) =
    i <= 0 ? 0
           : cnt_odd_xor_pairs_up_to_i(a, n, i - 1)
             + cnt_suffix_from(a, i - 1, i, n);
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
*/

int foo238(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant length == \at(a_len,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre);
          loop invariant \forall integer k; 0 <= k < \at(a_len,Pre) ==> 0 <= a[k] <= 100;
          loop invariant 0 <= count;
          loop invariant (i < \at(a_len,Pre)) ==> (0 <= i < length);
            */
            for (int i = 0; i < length; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i+1 <= j <= length;
          loop invariant 0 <= i < length;
          loop invariant 0 <= count;
          loop assigns j, count;
            */
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
            
        }
            
        return count;
}
