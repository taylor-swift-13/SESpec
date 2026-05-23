/*@
    requires m > 0;
    assigns \nothing;
    ensures (\result == -1) || (\result >= 0 && \result <= n && \result % m == 0);
    ensures \result == -1 ==> \forall integer i; 0 <= i <= n ==> i % m != 0;
    ensures \result != -1 ==> \exists integer i; 0 <= i <= n && i % m == 0 && \result == i;
*/
int roundNum(int n, int m);

 /*@
    requires m > 0;
    assigns \nothing;
    ensures (\result == -1) || (\result >= 0 && \result <= n && \result % m == 0);
    ensures \result == -1 ==> \forall integer i; 0 <= i <= n ==> i % m != 0;
    ensures \result != -1 ==> \exists integer i; 0 <= i <= n && i % m == 0 && \result == i;
*/
int roundNum(int n, int m) {

        /*@
            loop invariant -1 <= i <= n;
            loop invariant \forall integer j; i < j <= n ==> j % m != 0;
            loop assigns i;
            loop variant i + 1;
        */
        for (int i = n; i >= 0; i--) {
            if (i % m == 0) {
                return i;
            }
        }
        return -1;
}
