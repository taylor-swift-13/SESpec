
/*@
  // Logic function to get the value of the k-th bit of integer x
  logic integer bit(integer x, integer k) = (x >> k) & 1;

  // Logic function to reconstruct an integer composed of bits at odd indices < k from x
  logic integer odd_bits_prefix(integer x, integer k) =
    k <= 0 ? 0 :
    (odd_bits_prefix(x, k - 1) | ( ((k - 1) % 2 == 1 && bit(x, k - 1) == 1) ? (1 << (k - 1)) : 0 ));
*/

/*@ logic integer bit_length(integer x) =
      x <= 0 ? 0 : 1 + bit_length(x >> 1); */
/*@ logic integer odd_mask_prefix(integer k) =
      k <= 0 ? 0 :
      (odd_mask_prefix(k - 1) | ( ((k - 1) % 2 == 1) ? (1 << (k - 1)) : 0 )); */
/*@
  requires \true;
  assigns \nothing;
*/
int foo357(int n) {

        int count = 0;
        int res = 0;
        int temp = n;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(n,Pre) > 0) ==> (0 <= count && temp == (\at(n,Pre) >> count));
          loop invariant (!(\at(n,Pre) > 0)) ==> ((temp == \at(n,Pre))&&(res == 0)&&(count == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns res, temp, count;
            */
            while (temp > 0) {
            if (count % 2 == 1) {
                res |= (1 << count);
            }
            count++;
            temp >>= 1;
        }
            
        return (n | res);
}
