
/*@
  assigns \nothing;
  ensures \result >= 0;
  ensures number == 0 ==> \result == 0;
*/
int foo373(int number) {

    int div = 0;

    /*@
      loop invariant number == \at(number,Pre);
      loop invariant 0 <= div && div <= index - 1;
      loop invariant \forall integer k; 1 <= k < index ==> ((\at(number,Pre) % k == 0) ==> 0 <= div);
      loop invariant \forall integer k; 1 <= k < index ==> ((\at(number,Pre) % k == 0) ==> (1 <= k && k <= \at(number,Pre)));
      loop invariant \forall integer k; 1 <= k < index && (\at(number,Pre) % k == 0) ==> 1 <= div;
      loop invariant (index <= \at(number,Pre)) ==> (index >= 1 && index <= \at(number,Pre));
      loop invariant (index <= \at(number,Pre)) ==> (0 <= div && div <= index - 1);
      loop assigns index, div;
    */
    for (int index = 1; index <= number; index++) {
        if (number % index == 0) {
            div++;
        }
    }

    return div;
}
