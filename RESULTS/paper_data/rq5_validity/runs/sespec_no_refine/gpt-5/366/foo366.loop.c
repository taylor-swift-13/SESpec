
/*@
  logic integer even_sum_upto(integer m) =
    m <= 0 ? 0 :
    (m % 2 == 0 ? m + even_sum_upto(m - 1) : even_sum_upto(m - 1));

  logic integer even_count_upto(integer m) =
    m <= 0 ? 0 :
    (m % 2 == 0 ? 1 + even_count_upto(m - 1) : even_count_upto(m - 1));
*/

int foo366(int n) {

        int sum = 0;
        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns i, sum, count;
            */
            for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }
            
        return sum / count;
}
