
int foo352(int number) {

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
