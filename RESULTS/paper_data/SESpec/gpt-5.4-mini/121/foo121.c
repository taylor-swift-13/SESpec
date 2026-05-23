
/*@
  logic integer bit_at(int *bits, integer idx) = bits[idx];
*/

/*@
  requires \valid(&bits[0] + (0..bits_len-1));
  requires \forall integer i; 0 <= i < bits_len ==> 0 <= bits[i] <= 100;
  requires bits_len > 0;
  requires bits_len < 100;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
*/
int foo121(int * bits, int bits_len) {

        int n = bits_len, i = 0;
        
        /*@
          loop invariant (0 < \at(bits_len,Pre) - 1) ==> (n == \at(bits_len,Pre));
          loop invariant (!(0 < \at(bits_len,Pre) - 1)) ==> ((i == 0)&&(n == \at(bits_len,Pre))&&(bits_len == \at(bits_len,Pre))&&(bits == \at(bits,Pre)));
          loop invariant n == \at(bits_len,Pre);
          loop invariant bits_len == \at(bits_len,Pre);
          loop invariant bits == \at(bits,Pre);
          loop invariant \forall integer k; 0 <= k < \at(bits_len,Pre) ==> bits[k] == \at(bits[k],Pre);
          loop assigns i;
        */
        while (i < n - 1) {
            i += bits[i] + 1;
        }
            
        return i == n - 1;
}
