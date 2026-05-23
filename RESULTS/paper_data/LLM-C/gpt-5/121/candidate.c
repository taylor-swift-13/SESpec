int isOneBitCharacter(int * bits, int bits_len);

/*@ 
  requires 0 <= bits_len;
  requires \valid_read(bits + (0 .. bits_len - 1));
  requires \forall integer k; 0 <= k < bits_len ==> (bits[k] == 0 || bits[k] == 1);
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures 0 <= i <= bits_len;
  ensures i == bits_len - 1 || i == bits_len;
  ensures \result == (i == bits_len - 1);
*/
int isOneBitCharacter(int * bits, int bits_len) {

        int n = bits_len, i = 0;
        /*@
          loop invariant 0 <= i <= n;
          loop invariant i < n ==> \valid_read(bits + i);
          loop assigns i;
          loop variant n - i;
        */
        while (i < n - 1) {
            /*@ assert bits[i] == 0 || bits[i] == 1; */
            i += bits[i] + 1;
        }
        return i == n - 1;
}
