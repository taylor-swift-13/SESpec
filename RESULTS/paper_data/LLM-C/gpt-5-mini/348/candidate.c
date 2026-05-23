/*@
    requires a != 0;
    requires n > 0;
    requires l <= r;
    assigns \nothing;
    ensures \result == -1 <==> \num_of integer i; l <= i <= r && (i % a != 0) < n;
    ensures \result != -1 ==> l <= \result <= r && (\result % a != 0) &&
                             \num_of integer i; l <= i <= \result && (i % a != 0) == n;
*/
int countNo(int a, int n, int l, int r) {

        int count = 0;
        /*@ 
            loop invariant l <= i && i <= r+1;
            loop invariant 0 <= count && count <= n;
            loop invariant count == \num_of integer j; l <= j < i && (j % a != 0);
            loop assigns i, count;
            loop variant r - i + 1;
        */
        for (int i = l; i <= r; i++) {
            if (i % a != 0) {
                count++;
            }
            if (count == n) {
                return i;
            }
        }
        return -1;
}
