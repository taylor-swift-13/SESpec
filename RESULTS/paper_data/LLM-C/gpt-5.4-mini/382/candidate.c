/*@
    requires n >= 0;
    requires x > 0;
    assigns \nothing;
    ensures 0 <= \result <= n;
    ensures \result == 0 || (\result % x) == y;
    ensures \result == 0 ==> \forall integer i; 1 <= i <= n ==> (i % x) != y;
    ensures \result != 0 ==> \forall integer i; \result < i <= n ==> (i % x) != y;
*/
int findMaxVal(int n, int x, int y);

int findMaxVal(int n, int x, int y) {

        int max = 0;
        /*@
            loop invariant 1 <= i <= n + 1;
            loop invariant 0 <= max <= n;
            loop invariant max == 0 || (max % x) == y;
            loop invariant max == 0 ==> \forall integer k; 1 <= k < i ==> (k % x) != y;
            loop invariant max != 0 ==> \forall integer k; max < k < i ==> (k % x) != y;
            loop assigns i, max;
            loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            if ((i % x) == y) {
                max = i;
            }
        }
        return max;
}
