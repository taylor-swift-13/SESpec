/*@
    requires n >= 0;
    ensures \forall integer i; 0 <= i < 32 ==> 
             ((i % 2 == 0) ==> ((\old(n) & (1 << i)) != (n & (1 << i))));
    ensures \forall integer i; 0 <= i < 32 ==> 
             ((i % 2 != 0) ==> ((\old(n) & (1 << i)) == (n & (1 << i))));
    assigns \nothing;
*/
int evenBitToggleNumber(int n) {

        int res = 0;
        int count = 0;
        int temp = n;
        /*@
            loop invariant temp >= 0;
            loop invariant count >= 0;
            loop invariant res >= 0;
            loop invariant \forall integer i; 0 <= i < count ==> 
                           ((i % 2 == 0) ==> ((res & (1 << i)) != 0));
            loop invariant \forall integer i; 0 <= i < count ==> 
                           ((i % 2 != 0) ==> ((res & (1 << i)) == 0));
            loop assigns temp, count, res;
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
