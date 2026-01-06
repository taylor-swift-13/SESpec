
/*@
    requires k >= 0 && k <= 20000001;
*/
void foo263(int k) {
    int n;
    int i;

    n = 0;
    i = 0;

    /*@
        loop invariant (0 < 2 * \at(k,Pre)) ==> (n == (i+1)/2 && i <= 2 * \at(k,Pre));
        loop invariant (0 < 2 * \at(k,Pre)) ==> (i >= 0 && n >= 0);
        loop invariant (!(0 < 2 * \at(k,Pre))) ==> ((i == 0)&&(n == 0)&&(k == \at(k,Pre)));
        loop invariant k == \at(k,Pre);
        loop assigns n, i;
    */
    while (i < 2 * k) {
        if(i % 2 == 0) {
            n = n + 1;
        }
        i = i + 1;
    }

    /*@ assert n == k; */
}
