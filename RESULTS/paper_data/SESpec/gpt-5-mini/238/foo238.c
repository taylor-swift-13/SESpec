
/*@
  /* No additional logic function required */
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre);
  ensures n == \at(n,Pre);
  ensures a_len == \at(a_len,Pre);
  ensures \result == (\sum integer i; 0 <= i < a_len; 
                        (\sum integer j; i < j < a_len; 
                           ( (\at(a[i],Pre) % 2) != (\at(a[j],Pre) % 2) ? 1 : 0 )
                        ));
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
