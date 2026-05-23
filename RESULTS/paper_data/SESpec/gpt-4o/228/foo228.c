
/*@
  // No additional predicate or logic function is required for this program.
*/

int foo228(int seed) {
    int result = 0;
    int *temp = (int *)malloc(sizeof(int) * (seed + 1));
    int temp_len = seed + 1;
    temp[0] = 1;

    /*@
      loop invariant 1 <= d <= seed + 1;
      loop invariant \valid(temp + (0 .. temp_len - 1));
      loop invariant temp[0] == 1;
      loop invariant \forall integer i; 0 <= i < d ==> temp[i] >= 1;
      loop invariant \forall integer i; d <= i < temp_len ==> temp[i] == 0;
      loop assigns temp[1 .. temp_len - 1];
    */
    for (int d = 1; d <= seed; d++) {
        /*@
          loop invariant 0 <= c <= d;
          loop invariant \valid(temp + (0 .. temp_len - 1));
          loop invariant temp[0] == 1;
          loop invariant \forall integer i; 0 <= i < d ==> temp[i] >= 1;
          loop assigns temp[d];
        */
        for (int c = 0; c < d; c++) {
            temp[d] = temp[d] + temp[c];
        }
    }

    return temp[seed];
}
