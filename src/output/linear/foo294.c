
/*@
    requires xa + ya > 0;
*/
void foo294(int xa, int ya) {
    /*@
        loop invariant (\at(xa,Pre) > 0) ==> (xa + ya == \at(xa,Pre) + \at(ya,Pre));
        loop invariant (\at(xa,Pre) > 0) ==> (ya == \at(ya,Pre) + (\at(xa,Pre) - xa));
        loop invariant (!(\at(xa,Pre) > 0)) ==> ((ya == \at(ya,Pre))&&(xa == \at(xa,Pre)));
        loop assigns xa, ya;
    */
    while (xa > 0) {
        xa--;
        ya++;
    }
    /*@ assert ya >= 0; */
}
