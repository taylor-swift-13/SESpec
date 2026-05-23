/*@ 
  logic integer pow10(integer k) = (k == 0) ? 1 : 10 * pow10(k - 1);
*/

int findNthDigit(int p, int q, int n);

/*@ 
  requires n >= 0;
  requires 0 < q;
  requires 0 <= p < q;

  assigns \nothing;

  ensures 0 <= \result <= 9;
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> \result == ((\old(p) * pow10(n)) / \old(q)) % 10;
*/
int findNthDigit(int p, int q, int n) {

        int res = 0;
        /*@ 
          loop invariant 0 <= n <= \at(n,Pre);
          loop invariant q == \at(q,Pre) && q > 0;
          loop invariant (\at(n,Pre) - n == 0 ==> p == \at(p,Pre)) &&
                         (\at(n,Pre) - n > 0 ==> 0 <= p < q);
          loop variant n;
        */
        while (n > 0) {
            n -= 1;
            /*@ assert (\at(n,Pre) - n) >= 0; */
            p *= 10;
            res = p / q;
            p %= q;
            /*@ assert 0 <= p < q; */
        }
        return res;
}
