
/*@
    requires n > 0;
*/
void foo175(int n) {
    int i;
    int c;

    i = 0;
    c = 0;

    /*@
        loop invariant (0 < \at(n,Pre)) ==> (0 <= i <= n);
        loop invariant (0 < \at(n,Pre)) ==> (c == (i*(i-1))/2);
        loop invariant (!(0 < \at(n,Pre))) ==> ((c == 0)&&(i == 0)&&(n == \at(n,Pre)));
        loop invariant n == \at(n,Pre);
        loop assigns c, i;
    */
    while(i < n) {
       c = c + i;
       i = i + 1;
    }

    /*@ assert (i >= n) ==> (c >= 0); */
}
