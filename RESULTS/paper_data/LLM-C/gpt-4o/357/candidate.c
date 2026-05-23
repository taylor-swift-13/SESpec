/*@
    requires n >= 0;
    ensures \result >= n;
    ensures \forall integer i; 0 <= i < 32 ==> ((i % 2 == 1) && ((n >> i) & 1) == 0) ==> ((\result >> i) & 1) == 1;
    ensures \forall integer i; 0 <= i < 32 ==> ((i % 2 == 1) && ((n >> i) & 1) == 1) ==> ((\result >> i) & 1) == 1;
    ensures \forall integer i; 0 <= i < 32 ==> (i % 2 == 0) ==> ((\result >> i) & 1) == ((n >> i) & 1);
    assigns \nothing;
*/
int evenBitSetNumber(int n) {

        int count = 0;
        int res = 0;
        int temp = n;
        /*@
            loop invariant temp >= 0;
            loop invariant count >= 0;
            loop invariant res >= 0;
            loop invariant \forall integer i; 0 <= i < count ==> ((i % 2 == 1) && ((n >> i) & 1) == 0) ==> ((res >> i) & 1) == 1;
            loop invariant \forall integer i; 0 <= i < count ==> ((i % 2 == 1) && ((n >> i) & 1) == 1) ==> ((res >> i) & 1) == 1;
            loop invariant \forall integer i; 0 <= i < count ==> (i % 2 == 0) ==> ((res >> i) & 1) == 0;
            loop assigns count, res, temp;
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
