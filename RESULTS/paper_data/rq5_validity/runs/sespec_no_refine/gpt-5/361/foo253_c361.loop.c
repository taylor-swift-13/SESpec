
/*@
  logic integer sum_even_from_1_to(integer n) =
    n <= 0 ? 0 : (n % 2 == 0 ? n : 0) + sum_even_from_1_to(n - 1);

  logic integer count_even_from_1_to(integer n) =
    n <= 0 ? 0 : (n % 2 == 0 ? 1 : 0) + count_even_from_1_to(n - 1);
*/

int foo253_c361(int size) {

    int average = 0;
    int total = 0;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant size == \at(size,Pre);
      loop assigns j, average, total;
    */
    for (int j = 1; j <= size; j++) {
        if (j % 2 == 0) {
            average += j;
            total++;
        }
    }
            
    return average / total;
}
