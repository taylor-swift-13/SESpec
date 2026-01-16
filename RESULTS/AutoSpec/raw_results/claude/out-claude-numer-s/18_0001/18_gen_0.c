//svcomp_benchmark50_linear
int unknown();
/*@
  requires xa + ya > 0;
*/
int hoo18(int xa,int ya){

    //pre-condition
   
    //loop-body
    /*@
    loop invariant xa >= 0;
    loop invariant xa + ya == \at(xa + ya, Pre);
    loop assigns xa, ya;
    */
    while (xa > 0) {
        xa--;
        ya++;
    }

    //post-condition
    /*@ assert ya >= 0; */
}