
/*@
  requires bits_len >= 0;
  requires bits_len >= 2 ==> \valid(bits + (0 .. bits_len - 2));
  assigns \nothing;
  ensures 0 <= \result <= 1;
  ensures bits_len <= 0 ==> \result == 0;
  ensures bits_len == 1 ==> \result == 1;
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
