/*@
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==> (\exists integer k; k >= 0 && n == 3^k);
*/
int isPowerOfThree(int n);

#include <limits.h>

int isPowerOfThree(int n) {

        int temp = n;
        /*@
            loop invariant temp >= 0 || temp <= n;
            loop invariant temp == n || (\exists integer k; k >= 0 && n == temp * 3^k);
            loop assigns temp;
            loop variant temp;
        */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}
