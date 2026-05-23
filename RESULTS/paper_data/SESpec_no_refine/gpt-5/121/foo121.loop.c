
/*@
  requires bits_len >= 0;
  assigns \nothing;
*/
        
int foo121(int * bits, int bits_len) {

        int n = bits_len, i = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant \forall integer k; 0 <= k < i ==> bits[k] == 0 ==> \false;
          loop invariant \forall integer k; 0 <= k < i ==> (bits[k] + 1) >= 1;
          loop assigns i, bits[..];
            */
            while (i < n - 1) {
            i += bits[i] + 1;
        }
            
        return i == n - 1;
}
