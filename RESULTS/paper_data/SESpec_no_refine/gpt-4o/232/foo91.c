
/*@
  logic integer count_pairs(int* pairs, integer lo, integer hi) =
    lo >= hi ? 0
             : count_pairs(pairs, lo, hi - 1) + (pairs[hi - 1] != pairs[lo] ? 1 : 0);
*/

/*@
  requires \valid(pairs + (0 .. pairs_len - 1));
  requires pairs_len >= 0;
  assigns \nothing;
*/
int foo91(int * pairs, int pairs_len, int array) {

    int count = 0;
    int total = pairs_len;
    
    /*@
      loop assigns index, count;
    */
    for (int index = 0; index < total - 1; index++) {
        
        /*@
          loop invariant index + 1 <= c <= total;
          loop assigns c, count;
        */
        for (int c = index + 1; c < total; c++) {
            if (pairs[index] != pairs[c]) {
                count++;
            }
        }
        
    }
    
    return count;
}
