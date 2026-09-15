
/*@ logic integer msd(integer x) =
      (x < 10 ? x : msd(x / 10)); */
/*@
  assigns \nothing;
  ensures \result == msd(fact_prefix(num));
  ensures 1 <= \result <= 9;
*/
int foo326(int num) {

    int first = 1;

    /*@
      loop invariant num == \at(num,Pre);
      loop assigns c, first;
    */
    for (int c = 2; c <= num; c++) {
        first *= c;
    }

    int result = 0;
    
    /*@
      loop invariant 0 <= result <= 9;
      loop assigns result, first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }
            
    return result;
}
