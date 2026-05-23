
/*@
  logic integer odd_sum(integer up_to, integer limit) =
    up_to <= 1 ? 0
    : ( up_to - 1 > limit ? odd_sum(limit+1, limit)
        : ( ((up_to - 1) % 2 != 0) ? (up_to - 1) + odd_sum(up_to - 1, limit) : odd_sum(up_to - 1, limit) )
      );
*/

/*@
  logic integer odd_count(integer up_to, integer limit) =
    up_to <= 1 ? 0
    : ( up_to - 1 > limit ? odd_count(limit+1, limit)
        : ( ((up_to - 1) % 2 != 0) ? 1 + odd_count(up_to - 1, limit) : odd_count(up_to - 1, limit) )
      );
*/

int foo359(int size) {

    int ret = 0;
    int total = 0;
    
    /* General explanation (plain C comment, not inside ACSL):
       - c starts at 1 and iterates up to size
       - ret accrues the sum of odd numbers seen so far
       - total counts the odd numbers seen so far
       - at loop exit (c == size+1) ret and total equal the sum/count for 1..size
    */
    
    /*@
      loop invariant 1 <= c;
      
      loop invariant ret == odd_sum(c, \at(size,Pre));
      loop invariant total == odd_count(c, \at(size,Pre));
      
      loop invariant 0 <= ret;
      loop invariant 0 <= total;
      
      loop invariant (!(c <= \at(size,Pre)))
        ==> (ret == odd_sum(\at(size,Pre) + 1, \at(size,Pre))
             && total == odd_count(\at(size,Pre) + 1, \at(size,Pre))
             && size == \at(size,Pre));
      
      loop assigns c, ret, total;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 != 0) {
            ret += c;
            total++;
        }
    }
        
    return ret / total;
}
