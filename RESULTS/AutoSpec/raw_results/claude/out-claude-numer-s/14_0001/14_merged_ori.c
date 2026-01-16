//svcomp_css2003
int unknown();
/*@
  requires k >= 0;
  requires k <= 1;
*/
int hoo14(int k){
    int i = 1;
    int j = 1;

    //pre-condition
    //loop-body
    /*@
    loop invariant k >= 0 && k <= 1;
    loop invariant j == 1 + (1 - k) * (k == 1 ? 1 : 0);
    loop invariant i == 1 + (1 - k);
    loop invariant 1 <= i;
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
    /*@ assert i >= 1; */
}