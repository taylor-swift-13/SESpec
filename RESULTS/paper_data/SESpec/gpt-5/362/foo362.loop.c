
int foo362(int size) {

    int result = 0;
    int total = 0;
        
    /*@
      loop invariant size == \at(size,Pre);

      loop invariant 0 <= result;
      loop invariant 0 <= total && total <= (c - 1);

      loop invariant \forall integer k;
        (1 <= k && k < c && k % 2 == 0) ==> (result >= k);

      loop invariant \forall integer k1, k2;
        (1 <= k1 && k1 < c && 1 <= k2 && k2 < c &&
         k1 % 2 == 0 && k2 % 2 == 0 && k1 != k2) ==> (result >= k1 + k2);

      loop invariant \forall integer k;
        (1 <= k && k < c && k % 2 == 0) ==> (total >= 1);

      loop invariant (c <= \at(size,Pre)) ==> (total <= c - 1);

      loop invariant (c <= \at(size,Pre)) ==>
        (\forall integer k; (1 <= k && k < c && k % 2 == 0) ==> (result >= k));

      loop invariant (c <= \at(size,Pre)) ==> (0 <= result);

      loop invariant (c <= \at(size,Pre)) ==> (0 <= total && total <= c - 1);
      loop invariant size == \at(size,Pre);
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
