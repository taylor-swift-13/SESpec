/*@
    requires num >= 0;
    assigns \nothing;
    ensures 0 <= \result <= 9;
    ensures \result == num || \result < 10;
*/
int digitRoot(int num);

 /*@
    requires num >= 0;
    assigns \nothing;
    ensures 0 <= \result <= 9;
*/
int digitRoot(int num) {

        /*@
            loop invariant num >= 0;
            loop invariant num < 10 || num >= 10;
            loop assigns num, sum;
            loop variant num;
        */
        while (num >= 10) {
            int sum = 0;
            /*@
                loop invariant num >= 0;
                loop invariant sum >= 0;
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
