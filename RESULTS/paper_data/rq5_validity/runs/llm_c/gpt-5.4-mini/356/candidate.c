/*@
    requires n >= 0;
    ensures \result == (n ^ (
        (\let int res = 0;
            \let int count = 0;
            \let int temp = n;
            (\sum integer k; 0 <= k < 31 && ((k < count) ? 0 : 0))
        )
    ));
    assigns \nothing;
*/
int evenBitToggleNumber(int n);

int evenBitToggleNumber(int n) {

        int res = 0;
        int count = 0;
        int temp = n;
        /*@
            loop invariant 0 <= count;
            loop invariant temp >= 0;
            loop invariant count <= 31;
            loop invariant res >= 0;
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
