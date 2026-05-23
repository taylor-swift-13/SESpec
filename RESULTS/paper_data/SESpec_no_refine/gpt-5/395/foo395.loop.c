
/*@
  logic integer pow4(integer x) = x * x * x * x;
*/

int foo395(int p) {

    int odd = 0;
        
    /*@
      loop invariant p == \at(p,Pre);
      loop invariant 1 <= c <= p + 1;
      loop invariant odd == \sum(integer k = 1; k < c; k = k + 1) (pow4(2 * k));
      loop assigns c, tmp, odd;
    */
    for (int c = 1; c <= p; c++) {
        int tmp = 2 * c;
        odd = odd + (tmp * tmp * tmp * tmp);
    }
        
    return odd;
}
