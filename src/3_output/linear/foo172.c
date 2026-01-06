
/*@
    requires n > 0;
*/
void foo172(int n) {
    int i;
    int sum;

    sum = 0;
    i = 0;

    /*@
        loop invariant (0 < \at(n,Pre)) ==> (0 <= i <= \at(n,Pre));
        loop invariant (0 < \at(n,Pre)) ==> (sum == (i * (i - 1)) / 2);
        loop invariant (!(0 < \at(n,Pre))) ==> ((sum == 0)&&(i == 0)&&(n == \at(n,Pre)));
        loop invariant n == \at(n,Pre);
        loop assigns sum, i;
    */
    while(i < n) {
       sum = sum + i;
       i = i + 1;
    }

    /*@ assert (i >= n) ==> (sum >= 0); */
}
