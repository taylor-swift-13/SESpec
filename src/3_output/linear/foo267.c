
/*@
    requires n >= 1 && k >= n;
*/
void foo267(int k, int n) {
    int j;
    j = 0;

    /*@
        loop invariant (0 <= \at(n,Pre) - 1) ==> (k == \at(k,Pre) - j);
        loop invariant (0 <= \at(n,Pre) - 1) ==> (j <= n);
        loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((j == 0)&&(n == \at(n,Pre))&&(k == \at(k,Pre)));
        loop invariant n == \at(n,Pre);
        loop assigns j, k;
    */
    while (j <= n - 1) {
        j = j + 1;
        k = k - 1;
    }

    /*@ assert k >= 0; */
}
