/*@
    requires num >= 0;
    assigns \nothing;
    ensures 0 <= \result <= 9;
    ensures \old(num) == 0 ==> \result == 0;
    ensures \old(num) > 0 ==>
        ( (\old(num) % 9 == 0)  ==> \result == 9 ) &&
        ( (\old(num) % 9 != 0) ==> \result == (\old(num) % 9) );
*/
int digitRoot(int num) {

        /*@
            loop invariant num >= 0;
            loop assigns num;
            loop variant num;
        */
        while (num >= 10) {
            int sum = 0;
            /*@
                loop invariant sum >= 0;
                loop invariant num >= 0;
                loop assigns num, sum;
                loop variant num;
            */
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
}
