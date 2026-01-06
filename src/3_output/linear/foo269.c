
/*@
    requires n >= 0;
*/
void foo269(int n) {
    int i;
    int sum;

    sum = 0;
    i = 0;

    /*@
        loop invariant (0 < \at(n,Pre)) ==> (i >= 0 && i <= n && sum == (i-1)*i/2);
        loop invariant (0 < \at(n,Pre)) ==> (sum >= 0);
        loop invariant (!(0 < \at(n,Pre))) ==> ((sum == 0)&&(i == 0)&&(n == \at(n,Pre)));
        loop invariant n == \at(n,Pre);
        loop assigns sum, i;
    */
    while (i < n) {
        sum = sum + i;
        i = i + 1;
    }

    /*@ assert sum >= 0; */
}
