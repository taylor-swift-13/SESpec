//svcomp_benchmark50_linear
int unknown();
/*@
  requires xa + ya > 0;
*/
int hoo18(int xa,int ya){

    //pre-condition
   
    //loop-body
    /*@
    loop invariant xa + ya == \old(xa) + \old(ya);
    loop invariant 0 <= ya;
    loop invariant 0 <= xa;
    loop assigns ya;
    loop assigns xa;
    */
    while (xa > 0) {
        xa--;
        ya++;
    }

    //post-condition
    /*@ assert ya >= 0; */
}