
/*@
  assigns \nothing;
  ensures size <= 1 ==> \true;
*/
int foo362(int size) {

    int result = 0;
    int total = 0;
        
    /*@
      loop invariant size == \at(size,Pre);
      loop invariant 0 <= result;
      loop invariant 0 <= total && total <= c - 1;
      loop invariant \forall integer k; 1 <= k < c && k % 2 == 0 ==> result >= k;
      loop assigns c, result, total;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 == 0) {
            result += c;
            total++;
        }
    }
        
    return result / total;
}
