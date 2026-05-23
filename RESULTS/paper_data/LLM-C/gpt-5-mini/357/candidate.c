/*@
    requires n >= 0;
    assigns \nothing;
    ensures \forall integer i; i >= 0 ==>
        ( (i % 2 == 0) ==> (((\result >> i) & 1) == (((n >> i) & 1))) )
        &&
        ( (i % 2 == 1 && (n >> i) > 0) ==> (((\result >> i) & 1) == 1) )
        &&
        ( (i % 2 == 1 && (n >> i) == 0) ==> (((\result >> i) & 1) == (((n >> i) & 1))) );
*/
int evenBitSetNumber(int n);

int evenBitSetNumber(int n) {

        int count = 0;
        int res = 0;
        int temp = n;
        /*@
            loop invariant 0 <= count;
            loop invariant temp >= 0;
            loop invariant temp == (n >> count);
            loop invariant \forall integer j; 0 <= j < count ==> (((res >> j) & 1) == (j % 2 == 1 ? 1 : 0));
            loop invariant \forall integer j; j >= count ==> (((res >> j) & 1) == 0);
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
