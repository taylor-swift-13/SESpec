
/* No additional predicates needed for this numeric loop */

int foo350(int num) {

    int result = 0;
    int ret = 0;
    int total = num;
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant 0 <= ret;
      loop invariant num == \at(num,Pre);
      loop invariant total == (\at(num,Pre) >> ret);
           (((result >> i) & 1) == (((\at(num,Pre) >> i) & 1))));

      loop invariant
        ((\exists integer i; 0 <= i < ret && i % 2 == 0 &&
           (((\at(num,Pre) >> i) & 1) == 1))
         ==> (\exists integer j; 0 <= j < ret && j % 2 == 0 &&
               (((result >> j) & 1) == 1)));
             (i % 2 == 0 ? (((result >> i) & 1) == (((\at(num,Pre) >> i) & 1)))
                         : (((result >> i) & 1) == 0)));

      loop invariant (!(\at(num,Pre) > 0)) ==>
        ((total == \at(num,Pre)) && (ret == 0) && (result == 0) && (num == \at(num,Pre)));

      loop assigns result, total, ret;
    */
    while (total > 0) {
        if (ret % 2 == 0) {
            result = result | (1 << ret);
        }
        ret++;
        total >>= 1;
    }
        
    return num ^ result;
}
