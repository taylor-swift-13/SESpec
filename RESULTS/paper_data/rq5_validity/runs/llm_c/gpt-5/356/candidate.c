int evenBitToggleNumber(int n);

/*@ 
  logic integer bitlen(integer x) = x <= 0 ? 0 : 1 + bitlen(x >> 1);

  logic integer even_mask_upto(integer k) =
     k <= 0 ? 0 : (((k-1) % 2 == 0 ? (1 << (k-1)) : 0) + even_mask_upto(k-1));
*/

/*@ 
  assigns \nothing;
  ensures \result == (n ^ even_mask_upto(bitlen(n)));
  ensures \forall integer i; i >= 0 ==>
            (i < bitlen(n) && i % 2 == 0 ==> ((\result >> i) & 1) == 1 - ((n >> i) & 1)) &&
            (i < bitlen(n) && i % 2 == 1 ==> ((\result >> i) & 1) == ((n >> i) & 1)) &&
            (i >= bitlen(n) ==> ((\result >> i) & 1) == ((n >> i) & 1));
*/
int evenBitToggleNumber(int n) {

        int res = 0;
        int count = 0;
        int temp = n;
        /*@
          loop invariant count >= 0;
          loop invariant temp >= 0;
          loop invariant res == even_mask_upto(count);
          loop assigns res, count, temp;
          loop variant temp;
        */
        while (temp > 0) {
            if (count % 2 == 0) {
                res = res | (1 << count);
            }
            count++;
            temp >>= 1;
        }
        return n ^ res;
}
