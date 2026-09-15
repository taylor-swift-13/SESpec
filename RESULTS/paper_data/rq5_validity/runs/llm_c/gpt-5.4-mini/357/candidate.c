/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= n;
    ensures (\result & n) == n;
*/
int evenBitSetNumber(int n);

 /*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= n;
    ensures (\result & n) == n;
*/
int evenBitSetNumber(int n) {

        int count = 0;
        int res = 0;
        int temp = n;
        /*@
            loop invariant 0 <= count;
            loop invariant temp >= 0;
            loop invariant res >= 0;
            loop invariant (n | res) >= n;
            loop assigns count, temp, res;
            loop variant temp;
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
