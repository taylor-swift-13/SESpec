//svcomp_benchmark32_linear
int unknown();
/*@
  requires x == 1 || x == 2;
*/
int hoo13(int x){

    //loop-body
    /*@
    */
    while (unknown()) {
        if(x == 1) 
            x = 2;
        else if(x == 2)
            x = 1;
    }

    //post-condition
    /*@ assert x <= 8; */
}