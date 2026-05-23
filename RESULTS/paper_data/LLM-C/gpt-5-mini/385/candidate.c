int roundNum(int n, int m);

/*@
    requires m > 0;
    assigns \nothing;
    ensures (\result == -1) <==> (\forall integer k; 0 <= k <= n ==> k % m != 0);
    ensures \result != -1 ==> 0 <= \result <= n;
    ensures \result != -1 ==> \result % m == 0;
    ensures \result != -1 ==> \forall integer k; 0 <= k <= n && k % m == 0 ==> k <= \result;
*/
int roundNum(int n, int m) {

        /*@
            loop invariant -1 <= i <= n;
            loop invariant \forall integer k; i < k <= n ==> k % m != 0;
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
