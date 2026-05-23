/*@
  logic integer pow3(integer k) = (k == 0 ? 1 : 3 * pow3(k-1));
*/

/*@
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==> (\exists integer k; k >= 0 && n == pow3(k));
*/
int isPowerOfThree(int n);

int isPowerOfThree(int n) {

        int temp = n;
        /*@
            loop invariant \exists integer k; k >= 0 && n == temp * pow3(k);
            loop assigns temp;
            loop variant (temp >= 0 ? temp : -temp);
        */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}
