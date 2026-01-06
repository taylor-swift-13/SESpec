
/*@
    requires i >= 0 && i <= 200;
*/
void foo273(int i) {
    /*@
        loop invariant (\at(i,Pre) > 0) ==> (0 <= i <= \at(i,Pre));
        loop invariant (!(\at(i,Pre) > 0)) ==> (i == \at(i,Pre));
        loop assigns i;
    */
    while (i > 0) {
        i = i - 1;
    }

    /*@ assert i >= 0; */
}
