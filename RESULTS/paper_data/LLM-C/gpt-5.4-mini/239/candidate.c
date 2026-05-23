/*@
    requires ar_len >= 0;
    requires \valid_read(ar + (0 .. ar_len - 1));
    requires 0 <= n <= ar_len;
    assigns \nothing;
    ensures n == 0 || n == 1 ==> \result == 1;
    ensures n > 1 ==> (forall integer i; 1 <= i <= n ==> ar[i - 1] == i) ==> \result == n;
    ensures n > 1 ==> (\exists integer i; 1 <= i <= n && ar[i - 1] != i) ==> 1 <= \result <= n;
*/
int findMissing(int * ar, int ar_len, int n);

 /*@
    requires ar_len >= 0;
    requires \valid_read(ar + (0 .. ar_len - 1));
    requires 0 <= n <= ar_len;
    assigns \nothing;
    ensures n == 0 || n == 1 ==> \result == 1;
    ensures n > 1 ==> (forall integer i; 1 <= i <= n ==> ar[i - 1] == i) ==> \result == n;
    ensures n > 1 ==> (\exists integer i; 1 <= i <= n && ar[i - 1] != i) ==> 1 <= \result <= n;
*/
int findMissing(int * ar, int ar_len, int n) {

        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        /*@
            loop invariant 1 <= i <= n + 1;
            loop invariant 1 <= missing <= i - 1;
            loop invariant \forall integer j; 1 <= j < i ==> ar[j - 1] == j;
            loop assigns i, missing;
            loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            if (ar[i - 1] == i) {
                missing = i;
            } else if (ar[i - 1] != i) {
                return i;
            }
        }
        return missing;
}
