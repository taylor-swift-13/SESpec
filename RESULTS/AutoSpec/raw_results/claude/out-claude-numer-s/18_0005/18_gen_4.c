//svcomp_benchmark50_linear
int unknown();
/*@
  requires xa + ya > 0;
*/
int hoo18(int xa,int ya){

    //pre-condition
   
    //loop-body
    /*@
    */
    while (xa > 0) {
        xa--;
        ya++;
    }

    //post-condition
    /*@ assert ya >= 0; */
}