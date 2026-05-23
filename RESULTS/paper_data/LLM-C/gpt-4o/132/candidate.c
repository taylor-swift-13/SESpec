#include <limits.h>

/*@
    requires \valid(a + (0..a_len-1));
    requires a_len > 0;
    ensures \forall integer i; 0 <= i < a_len ==> a[i] >= \result;
    ensures \exists integer i; 0 <= i < a_len && a[i] == \result;
    assigns \nothing;
*/
int minElementInArray(int *a, int a_len);

int minElementInArray(int *a, int a_len) {
    if (a_len == 0) return -1;

    int res = INT_MAX;

    /*@
        loop invariant 0 <= i <= a_len;
        loop invariant \forall integer j; 0 <= j < i ==> a[j] >= res;
        loop assigns i, res;
        loop variant a_len - i;
    */
    for (int i = 0; i < a_len; i++) {
        res = (a[i] < res) ? a[i] : res;
    }

    return res;
}
