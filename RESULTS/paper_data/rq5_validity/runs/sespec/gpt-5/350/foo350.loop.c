
int foo350(int num) {

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
