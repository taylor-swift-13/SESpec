//svcomp_css2003
int unknown();
/*@
  requires k >= 0;
  requires k <= 1;
*/
int hoo1(int k){
    int i = 1;
    int j = 1;

    //pre-condition
 

    //loop-body
    /*@
    loop invariant k <= 1;
    loop invariant i + k <= 2;
    loop invariant 0 <= k;
    loop assigns k;
    loop assigns j;
    loop assigns i;
    */
    while (unknown()) {
        i = i + 1;
        j = j + k;
        k = k - 1;
    }

    //post-condition
    /*@ assert i + k <= 2; */
}