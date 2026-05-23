/*@
    requires \valid(ar + (0..ar_len-1));
    requires ar_len >= 0;
    requires n >= 0;
    ensures \result >= 1 && \result <= n;
    ensures \forall integer i; 0 <= i < ar_len ==> (ar[i] == i+1 || \result == i+1);
    assigns \nothing;
*/
int findMissing(int * ar, int ar_len, int n);

int findMissing(int * ar, int ar_len, int n) {

        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        /*@
            loop invariant 1 <= i <= n+1;
            loop invariant missing >= 1 && missing <= n;
            loop invariant \forall integer j; 1 <= j < i ==> (ar[j-1] == j || missing == j);
            loop assigns i, missing;
            loop variant n - i;
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
