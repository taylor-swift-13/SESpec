
/*@
    requires n > 0 && n < 10;
*/
void foo171(int n) {
    int i;
    int j;
    int k;
    int v;

    k = 0;
    i = 0;

    /*@
        loop invariant (0 < \at(n,Pre)) ==> (i >= 0 && i <= n);
        loop invariant (0 < \at(n,Pre)) ==> (k >= 2000*i && k <= 4000*i);
        loop invariant (!(0 < \at(n,Pre))) ==> ((k == 0)&&(i == 0)&&(n == \at(n,Pre)));
        loop invariant n == \at(n,Pre);
        loop assigns i, k, v;
    */
    while(i < n) {
        if(unknown()) {
            i = i + 1;
            k = k + 4000;
            v = 0;
        }
        else {
            i = i + 1;
            k = k + 2000;
            v = 1;
        }
    }

    /*@ assert (i >= n) ==> (k > n); */
}
