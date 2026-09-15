/*@ 
    requires m > 0;
    requires n >= 0;
    ensures \result == -1 || (\result % m == 0 && \result <= n);
    ensures \result == -1 ==> \forall integer i; 0 <= i <= n ==> i % m != 0;
    ensures \result != -1 ==> \exists integer i; 0 <= i <= n && i % m == 0 && \result == i;
    assigns \nothing;
*/
int roundNum(int n, int m) {

    /*@
    loop invariant 0 <= i <= n + 1;
    loop invariant \forall integer j; i < j <= n ==> j % m != 0;
    loop assigns i;
    loop variant i;
    */
    for (int i = n; i >= 0; i--) {
        if (i % m == 0) {
            return i;
        }
    }
    return -1;
}
