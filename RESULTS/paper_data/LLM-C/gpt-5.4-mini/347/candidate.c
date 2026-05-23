/*@
    requires y >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int findDivisor(int x, int y);

#include <limits.h>

/*@
    requires y >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int findDivisor(int x, int y) {

        if (y < 0) {
            y = -y;
        }
        int count = 0;
        /*@
            loop invariant 1 <= i <= y + 1;
            loop invariant 0 <= count <= i - 1;
            loop assigns i, count;
            loop variant y - i + 1;
        */
        for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
        return count;
}
