int foo350(int num);


/*@
ensures \exists integer ret_62, result_61; (num <= 0) && (0 <= ret_62) && (0 <= ret_62) && (result_61 == (result_61 | 0)) ==> (\result == (num ^ result_61));

assigns \nothing;
*/

int foo350(int num) 
{

    int result = 0;
    int ret = 0;
    int total = num;
        
    /*@
      loop invariant 0 <= ret;
      loop invariant num == \at(num,Pre);

      // Supplementary invariants (no undefined helpers, ACSL-safe):
      loop invariant 0 <= ret;
      loop invariant result == (result | 0);
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