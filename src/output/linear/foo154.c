
/*@
    requires x > 0;
*/
void foo154(int x) {
    int i;
    int j;

    j = 0;
    i = 0;

    /*@
        loop invariant (0 < \at(x,Pre)) ==> (i >= 0 && i <= x && j == 2 * i);
        loop invariant (0 < \at(x,Pre)) ==> (j >= 0 && j <= 2 * x);
        loop invariant (!(0 < \at(x,Pre))) ==> ((j == 0)&&(i == 0)&&(x == \at(x,Pre)));
        loop invariant x == \at(x,Pre);
        loop assigns j, i;
    */
    while(i < x) {
        j = j + 2;
        i = i + 1;
    }

    /*@ assert (i >= x) ==> (j == 2 * x); */
}
