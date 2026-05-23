
/*@
  logic integer sum_cubes(integer n) =
    n <= 0 ? 0 : n * n * n + sum_cubes(n - 1);

  logic integer arith_sum(integer n) =
    n <= 0 ? 0 : n + arith_sum(n - 1);
*/


int foo328(int diff) {

    int result = 0;
    int max = 0;

    /*@
      loop invariant max == 0;
      loop invariant diff == \at(diff,Pre);
      loop assigns c, result;
    */
    for (int c = 1; c <= diff; c++) {
        result += c * c * c;
    }

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant diff == \at(diff,Pre);
          loop invariant (c <= diff) ==> (max + (diff - (c - 1)) >= max);
          loop assigns c, max;
            */
            for (int c = 1; c <= diff; c++) {
        max += c;
    }
            
    return result - max;
}
