
/*@
  logic integer sum_bits(int *bits, integer lo, integer hi) =
    lo >= hi ? 0
              : sum_bits(bits, lo, hi - 1) + bits[hi - 1];
*/

/*@
  requires \valid(&bits[0] + (0..bits_len-1));
  requires \forall integer i; 0 <= i < bits_len ==> 0 <= bits[i] <= 100;
  requires bits_len > 0;
  requires bits_len < 100;
  assigns i;
  ensures \result == ( \old(bits_len) - 1 == 0 ? 1 : (i == \old(bits_len) - 1) );
*/
int foo44(int * bits, int bits_len) {

        int n = bits_len, i = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (!(0 < \at(bits_len,Pre) - 1)) ==> ((i == 0)&&(n == \at(bits_len,Pre))&&(bits_len == \at(bits_len,Pre))&&(bits == \at(bits,Pre)));
          loop invariant n == \at(bits_len,Pre);
          loop invariant bits_len == \at(bits_len,Pre);
          loop invariant bits == \at(bits,Pre);
          loop invariant \forall integer k; 0 <= k < n ==> bits[k] == \at(bits[k],Pre);
          loop assigns i;
            */
            while (i < n - 1) {
            i += bits[i] + 1;
        }
            
        return i == n - 1;
}
