
/*@ requires p != 0; */
int foo369(int value, int p, int dy) {

    int result = 0;
        
    /*@ 
      loop invariant 1 <= c;

      loop invariant (\at(value,Pre) >= 1) ==> (c <= \at(value,Pre) + 1);
      loop invariant (\at(value,Pre) < 1) ==> (c == 1);

      loop invariant dy == \at(dy,Pre);
      loop invariant p == \at(p,Pre);
      loop invariant value == \at(value,Pre);

      loop invariant result == 0 || (1 <= result && result < c);
      loop invariant result == 0 || (result % p) == dy;

      loop invariant \forall integer k; (1 <= k && k < c) ==> (((k % p) == dy) ==> (k <= result));
      loop invariant \forall integer k; (result < k && k < c) ==> ((k % p) != dy);

      loop assigns c, result;
    */
    for (int c = 1; c <= value; c++) {
        if ((c % p) == dy) {
            result = c;
        }
    }
        
    return result;
}
