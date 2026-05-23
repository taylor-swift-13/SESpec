
int foo373(int number) {

    int div = 0;

    /*@
      loop invariant number == \at(number,Pre);
      loop invariant 0 <= div <= index - 1;
      loop invariant \forall integer k; 1 <= k < index ==> ( ( \at(number,Pre) % k == 0 ) ==> 0 <= div );
      loop invariant \forall integer k; 1 <= k < index ==> ( ( \at(number,Pre) % k == 0 ) ==> 1 <= k <= \at(number,Pre) );
      loop invariant \forall integer k1, k2; 1 <= k1 < index && 1 <= k2 < index && k1 != k2 ==> !((\at(number,Pre) % k1 == 0) && (\at(number,Pre) % k2 == 0) && k1 == k2);
      loop invariant \forall integer k; 1 <= k < index && (\at(number,Pre) % k == 0) ==> 1 <= div;
      loop invariant (index <= \at(number,Pre)) ==> (index >= 1 && index <= \at(number,Pre));
      loop invariant (index <= \at(number,Pre)) ==> (0 <= div <= index - 1);
      loop assigns index, div;
    */
    for (int index = 1; index <= number; index++) {
        if (number % index == 0) {
            div++;
        }
    }

    return div;
}
