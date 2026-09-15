
/*@ logic integer pow10(integer k) =
        k <= 0 ? 1 : 10 * pow10(k-1); */
/*@
  requires \true;
  assigns \nothing; 
  ensures \at(number,Pre) <= 0 ==> \result == 0;
  ensures \at(number,Pre) <= 0 ==> (\result == 0 && number == \at(number,Pre));
  ensures \at(number,Pre) > 0 ==> \result >= 1;
*/
int foo398(int number) {

    int ret = 0;

    /*@ 
      loop invariant 0 <= ret;                                       
      loop invariant (\at(number,Pre) > 0) ==> number >= 0;                                   
      loop invariant (\at(number,Pre) > 0) ==> (\at(number,Pre) >= number);
      loop invariant (\at(number,Pre) > 0) ==> (ret >= 0);
      loop invariant (\at(number,Pre) > 0) ==> (ret == 0 ==> number == \at(number,Pre));
      loop invariant (\at(number,Pre) > 0) ==> (ret > 0 ==> number < \at(number,Pre));
      loop invariant (!(\at(number,Pre) > 0)) ==> ((ret == 0) && (number == \at(number,Pre)));
      loop assigns number, ret;
    */
    while (number > 0) {
        number /= 10;
        ret++;
    }

    return ret;
}
