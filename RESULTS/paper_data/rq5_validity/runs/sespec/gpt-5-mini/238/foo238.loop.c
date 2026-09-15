
/*@
  /* No additional logic function required */
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
*/

int foo238(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant 0 <= i <= \at(a_len,Pre);
            loop invariant length == \at(a_len,Pre);
            loop invariant n == \at(n,Pre);
            loop invariant a_len == \at(a_len,Pre);
            loop invariant a == \at(a,Pre);
            loop invariant 0 <= count;
            loop invariant \forall integer k; 0 <= k < \at(a_len,Pre) ==> 0 <= a[k] <= 100;
            loop assigns i, j, count;
            */
            for (int i = 0; i < length; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant 0 <= i <= length;
            loop invariant 0 <= count;
            loop invariant \forall integer p; 0 <= p < length ==> 0 <= a[p] <= 100;
            loop assigns i, count, a[..];
            */
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
            
        }
            
        return count;
}
