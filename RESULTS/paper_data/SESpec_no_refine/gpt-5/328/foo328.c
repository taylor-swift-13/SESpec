
/*@
  assigns \nothing;
  ensures \result == sum_cubes(diff) - arith_sum(diff);
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
