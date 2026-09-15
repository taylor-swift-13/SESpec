int foo352(int number);


/*@
ensures \exists integer ret_68, total_67, result_66; (total_67 <= 0) && (0 <= ret_68) && (total_67 == number >> ret_68) && (\forall integer k_53; 0 <= k_53 && k_53 < ret_68 ==> (k_53 % 2 == 0 ==> (result_66 & 1 << k_53) != 0) && (k_53 % 2 != 0 ==> (result_66 & 1 << k_53) == 0)) && (\forall integer k_54; k_54 >= ret_68 ==> (result_66 & 1 << k_54) == 0) && (ret_68 == 0 ==> result_66 == 0) ==> (\result == (number ^ result_66));

assigns \nothing;
*/

int foo352(int number) 
{

    int result = 0;
    int ret = 0;
    int total = number;
        
    /*@
      loop invariant 0 <= ret;
      loop invariant number == \at(number,Pre);
      loop invariant total == (\at(number,Pre) >> ret);
      loop invariant (\forall integer k; 0 <= k < ret ==> 
                        ( (k % 2 == 0) ==> ((result & (1 << k)) != 0) ) &&
                        ( (k % 2 != 0) ==> ((result & (1 << k)) == 0) ));
      loop invariant (\forall integer k; k >= ret ==> ((result & (1 << k)) == 0));
      loop invariant (ret == 0) ==> (result == 0);
      loop assigns result, total, ret;
    */
    while (total > 0) {
        if (ret % 2 == 0) {
            result = result | (1 << ret);
        }
        ret++;
        total >>= 1;
    }
        
    return number ^ result;
}