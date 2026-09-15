/*@ 
    requires n >= 0;
    requires x > 0;
    requires 0 <= y < x;
    ensures \result == 0 || (\result % x == y && \result <= n);
    ensures \result == 0 ==> \forall integer i; 1 <= i <= n ==> i % x != y;
    ensures \result != 0 ==> \exists integer i; 1 <= i <= n && i % x == y && \result == i;
    assigns \nothing;
*/
int findMaxVal(int n, int x, int y);

int findMaxVal(int n, int x, int y) {

        int max = 0;
        /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant max == 0 || (max % x == y && max <= n);
        loop invariant \forall integer j; 1 <= j < i ==> (j % x == y ==> max >= j);
        loop assigns i, max;
        loop variant n - i;
        */
        for (int i = 1; i <= n; i++) {
            if ((i % x) == y) {
                max = i;
            }
        }
        return max;
}
