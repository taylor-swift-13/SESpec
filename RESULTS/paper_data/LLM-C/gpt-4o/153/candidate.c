#include <stdlib.h>

/*@
    requires n > 0;
    requires k > 0;
    ensures \result == 0 || (1 <= \result && \result <= n);
    assigns \nothing;
*/
int getNumber(int n, int k);

int getNumber(int n, int k) {

    /*@
        allocates a, b;
        ensures \valid(a + (0..n-1));
        ensures \valid(b + (0..n-1));
    */
    int *a = (int *)malloc(sizeof(int) * (n));
    int a_len = n;

    int *b = (int *)malloc(sizeof(int) * (n));
    int b_len = n;

    int i, count = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant \valid(a + (0..n-1));
        loop assigns i, a[0..n-1];
        loop ensures \forall integer j; 0 <= j < i ==> a[j] == j + 1;
    */
    for (i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= k;
        loop invariant \valid(b + (0..n-1));
        loop assigns i, count, b[0..n-1];
        loop ensures \forall integer j; 0 <= j < i ==> b[j] == a[j];
        loop ensures count == \sum(0, i-1, a[j] % 2 != 0 ? 1 : 0);
    */
    for (i = 0; i < n; i++) {
        b[i] = a[i];
        if (a[i] % 2 != 0) {
            count++;
            if (count == k) {
                free(a);
                free(b);
                return a[i];
            }
        }
    }

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= k;
        loop invariant \valid(b + (0..n-1));
        loop assigns i, count, b[0..n-1];
        loop ensures \forall integer j; 0 <= j < i ==> b[j] == a[j];
        loop ensures count == \sum(0, n-1, a[j] % 2 != 0 ? 1 : 0) + \sum(0, i-1, a[j] % 2 == 0 ? 1 : 0);
    */
    for (i = 0; i < n; i++) {
        b[i] = a[i];
        if (a[i] % 2 == 0) {
            count++;
            if (count == k) {
                free(a);
                free(b);
                return a[i];
            }
        }
    }

    free(a);
    free(b);
    return 0;
}
