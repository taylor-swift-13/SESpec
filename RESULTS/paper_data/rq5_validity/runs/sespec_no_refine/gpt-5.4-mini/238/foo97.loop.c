
/*@
  logic integer parity_odd_pairs(int *a, integer len, integer i) =
    i >= len ? 0
             : parity_odd_pairs(a, len, i + 1) +
               (\forall integer j; i < j < len ==> ((a[i] ^ a[j]) % 2 == 1) ? 1 : 0);
*/

        
/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
*/

int foo97(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (i < \at(a_len,Pre)) ==> (count >= 0);
          loop invariant (!(i < \at(a_len,Pre))) ==> ((length == \at(a_len,Pre))&&(count == 0)&&(n == \at(n,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)));
          loop invariant length == \at(a_len,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < length ==> a[k] == \at(a[k],Pre);
          loop assigns i, j, count;
            */
            for (int i = 0; i < length; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant 0 <= i <= length;
            loop invariant count >= 0;
            loop assigns i, count;
            */
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
            
        }
            
        return count;
}
