//svcomp_const
int unknown();
int hoo3() {
    //pre-condition
    int s = 0;

    //loop-body
    /*@
    loop invariant s == 0 || s > 0;
    loop invariant 0 <= s;
    loop assigns s;
    */
    while(unknown()){
        if (s != 0){
            s = s + 1;
        }
    }

    //post-condition
    /*@ assert s == 0; */

}