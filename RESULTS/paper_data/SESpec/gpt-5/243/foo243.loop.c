
/*@
  requires pairs_len >= 0;
  requires \valid(pairs + (0 .. pairs_len-1));
  requires 0 <= num <= pairs_len;
  assigns \nothing;
  ensures \result >= 0;
*/

int foo243(int * pairs, int pairs_len, int num, int p) {

    int result = 0;
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= \at(num,Pre);
          loop invariant 0 <= result;
          loop invariant p == \at(p, Pre);
          loop invariant num == \at(num, Pre);
          loop invariant pairs_len == \at(pairs_len, Pre);
          loop invariant pairs == \at(pairs, Pre);
          loop invariant \forall integer k; 0 <= k < pairs_len ==> pairs[k] == \at(pairs[k], Pre);
          loop assigns index, result;
            */
            for (int index = 0; index < num; index++) {

        /* >>> LOOP INVARIANT TO FILL <<< */

        /*@
          loop invariant index + 1 <= j <= num;
          loop invariant 0 <= result;
          loop invariant p == \at(p, Pre);
          loop invariant num == \at(num, Pre);
          loop invariant pairs_len == \at(pairs_len, Pre);
          loop invariant pairs == \at(pairs, Pre);
          loop invariant \forall integer k; 0 <= k < pairs_len ==> pairs[k] == \at(pairs[k], Pre);
          loop assigns j, result;
        */
        for (int j = index + 1; j < num; j++) {
            if (pairs[index] + pairs[j] == p) {
                result++;
            }
        }

    }
            
    return result;
}
