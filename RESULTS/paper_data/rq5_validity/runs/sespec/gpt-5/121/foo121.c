
/* No additional logic or predicate definitions are needed. */

/*@
  requires bits_len >= 0 ==> \valid(&bits[0] + (0..bits_len-1));
  requires \forall integer i; 0 <= i < bits_len ==> 0 <= bits[i] <= 100;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures bits_len == \at(bits_len, Pre);
  ensures bits == \at(bits, Pre);
  ensures \forall integer k; 0 <= k < bits_len ==> bits[k] == \at(bits[k], Pre);
*/
int foo121(int * bits, int bits_len) {

        int n = bits_len, i = 0;
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant n == \at(bits_len,Pre);
          loop invariant bits_len == \at(bits_len,Pre);
          loop invariant bits == \at(bits,Pre);
          loop invariant \forall integer k; 0 <= k < n ==> bits[k] == \at(bits[k], Pre);
          loop assigns i;
        */
        while (i < n - 1) {
            i += bits[i] + 1;
        }
            
        return i == n - 1;
}
