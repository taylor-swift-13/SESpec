int evenBitToggleNumber(int n);

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \exists integer m; m >= 0 &&
            ( ( \old(n) == 0 && m == 0 )
              ||
              ( \old(n) > 0 && ((\old(n) >> (m-1)) != 0 && (\old(n) >> m) == 0) )
            )
            &&
            \result == \old(n) ^ (\sum integer k; 0 <= k < m; (k % 2 == 0 ? (1 << k) : 0));
*/
int evenBitToggleNumber(int n) {

        int res = 0;
        int count = 0;
        int temp = n;
        /*@
            loop invariant temp == (\old(n) >> count);
            loop invariant count >= 0;
            loop invariant \forall integer j; 0 <= j < count ==> (((res >> j) & 1) == (j % 2 == 0 ? 1 : 0));
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
