
/*@
  logic integer sum_to(integer n) =
    n <= 0 ? 0 : n + sum_to(n - 1);
*/


int foo330(int diff) {

    int result = 0;
    int max = 0;

    /*@
      loop invariant max == 0;
      loop invariant diff == \at(diff,Pre);
      loop assigns j, result;
    */
    for (int j = 1; j <= diff; j++) {
        result += j * j * j;
    }

    /*@
      loop invariant (j <= \at(diff,Pre)) ==> (max == 0) ;
      loop invariant max == 0;
      loop invariant diff == \at(diff,Pre);
      loop assigns j, result;
    */
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= j <= diff + 1;
          loop invariant result == \sum(integer k, 1, j - 1, k*k*k);
          loop invariant max == 0;
          loop invariant diff == \at(diff,Pre);
          loop assigns j, result;
            */
            for (int j = 1; j <= diff; j++) {
        result += j * j * j;
    }
            

    for (int j = 1; j <= diff; j++) {
        max += j;
    }
    return result - max;
}
