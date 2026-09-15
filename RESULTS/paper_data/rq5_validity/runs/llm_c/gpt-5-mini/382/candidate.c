int findMaxVal(int n, int x, int y);

/*@
    requires n >= 0;
    requires x != 0;
    requires 0 <= y && y < \abs(x);
    assigns \nothing;
    ensures 0 <= \result;
    ensures (\result == 0) <==> (\forall integer j; 1 <= j && j <= n ==> j % x != y);
    ensures (\result != 0) ==> (1 <= \result && \result <= n && \result % x == y &&
                                (\forall integer j; 1 <= j && j <= n && j % x == y ==> j <= \result));
*/
int findMaxVal(int n, int x, int y) {

        int max = 0;
        /*@
            loop invariant 1 <= i && i <= n+1;
            loop invariant max == 0 || (1 <= max && max <= i-1 && max % x == y &&
                           (\forall integer j; 1 <= j && j <= i-1 && j % x == y ==> j <= max));
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
