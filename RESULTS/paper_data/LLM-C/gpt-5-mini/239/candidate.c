int findMissing(int * ar, int ar_len, int n);

/*@
    requires n >= 0 ==> \valid(ar + (0 .. n-1));
    assigns \nothing;
    behavior small_n:
        assumes n <= 1;
        ensures \result == 1;
    behavior normal:
        assumes n >= 2;
        ensures 1 <= \result <= n;
        ensures \forall integer j; 1 <= j < \result ==> ar[j-1] == j;
        ensures (ar[\result-1] != \result) || (\forall integer j; 1 <= j <= n ==> ar[j-1] == j);
    complete behaviors small_n, normal;
    disjoint behaviors small_n, normal;
*/
int findMissing(int * ar, int ar_len, int n) {

        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        /*@
            loop invariant 1 <= i <= n+1;
            loop invariant \forall integer j; 1 <= j < i ==> ar[j-1] == j;
            loop invariant i == 1 ==> missing == 1;
            loop invariant i >= 2 ==> missing == i-1;
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
