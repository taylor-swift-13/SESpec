
/*@
    requires l > 0;
*/
void foo265(int l) {
    int n;
    int i;

    i = l;

    /*@
        loop invariant (\at(l,Pre) < n) ==> (i >= \at(l,Pre) && i <= n && l == \at(l,Pre));
        loop invariant (!(\at(l,Pre) < n)) ==> ((i == \at(l,Pre)) && (l == \at(l,Pre)));
        loop invariant l == \at(l,Pre);
        loop assigns i;
    */
    while (i < n) {
        i = i + 1;
    }

    /*@ assert l >= 1; */
}
