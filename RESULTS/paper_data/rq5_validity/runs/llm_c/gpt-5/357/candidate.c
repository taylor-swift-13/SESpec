/*@ 
  logic integer bitlen(integer x);

  axiom bitlen_zero: bitlen(0) == 0;
  axiom bitlen_pos1: \forall integer x; x > 0 ==> ((x >> (bitlen(x)-1)) > 0);
  axiom bitlen_pos2: \forall integer x; x > 0 ==> ((x >> bitlen(x)) == 0);
  axiom bitlen_bound: \forall integer x; x >= 0 ==> bitlen(x) < 8*sizeof(int);
*/

/*@ 
  requires n >= 0;
  assigns \nothing;
  ensures \forall integer k; 0 <= k < bitlen(n) && k % 2 == 1 ==> (((\result >> k) & 1) == 1);
  ensures \forall integer k; 0 <= k < bitlen(n) && k % 2 == 0 ==> (((\result >> k) & 1) == ((n >> k) & 1));
  ensures \forall integer k; k >= bitlen(n) ==> (((\result >> k) & 1) == ((n >> k) & 1));
*/
int evenBitSetNumber(int n);

int evenBitSetNumber(int n) {

        int count = 0;
        int res = 0;
        int temp = n;
        /*@
          loop invariant 0 <= temp;
          loop invariant 0 <= count;
          loop invariant temp == (n >> count);
          loop invariant count <= bitlen(n);
          loop invariant \forall integer k; 0 <= k < count ==> (((res >> k) & 1) == (k % 2));
          loop invariant \forall integer k; k >= count ==> (((res >> k) & 1) == 0);
          loop assigns res, temp, count;
          loop variant temp;
        */
        while (temp > 0) {
            /*@ assert count < 8*sizeof(int); */
            if (count % 2 == 1) {
                res |= (1 << count);
            }
            count++;
            temp >>= 1;
        }
        return (n | res);
}
