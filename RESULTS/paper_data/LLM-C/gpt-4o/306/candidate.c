#include <stdlib.h>

/*@
    requires n >= 0;
    ensures \result == 2 || \result == 1 || \result > 1;
    assigns \nothing;
*/
int findLucas(int n);

/*@
    requires n >= 0;
    ensures \result == 2 || \result == 1 || \result > 1;
    assigns \nothing;
*/
int findLucas(int n) {

        int *lucas = (int *)malloc(sizeof(int) * (n + 1));
int lucas_len = n + 1;
        lucas[0] = 2;
        lucas[1] = 1;
        for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
        return lucas[n];
}
