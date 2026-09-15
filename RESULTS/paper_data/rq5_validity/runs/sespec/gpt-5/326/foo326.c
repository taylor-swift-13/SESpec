
/*@
  assigns \nothing;
*/
int foo326(int num) {

    int first = 1;

    /*@
      loop invariant 2 <= c;
      loop invariant (c == 2) ==> (first == 1);
      loop invariant 1 <= first;
      loop invariant \forall integer k; 2 <= k < c ==> (first >= k);
      loop invariant (c >= 3) ==> (first >= (c - 1));
      loop invariant (c <= \at(num,Pre)) ==> (first >= 1);
      loop invariant (c >= 2 && c <= \at(num,Pre)) ==> (num == \at(num,Pre));
      loop invariant (c <= \at(num,Pre)) ==> (first >= 1);
      loop invariant (c <= \at(num,Pre)) ==> ((c == 2) ==> (first == 1));
      loop invariant num == \at(num,Pre);
      loop assigns c, first;
    */
    for (int c = 2; c <= num; c++) {
        first *= c;
    }

    int result = 0;
    
    /*@
      loop invariant 0 <= first;
      loop invariant (first > 0) ==> (0 <= result && result <= 9);
      loop invariant first == 0 ==> (0 <= result && result <= 9);
      
      loop assigns result, first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }
            
    return result;
}
