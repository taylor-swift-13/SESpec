
/*@
  logic integer catalan_sum(int* catalan, integer i, integer j) =
    j <= 0 ? 0 : catalan_sum(catalan, i, j - 1) + catalan[j - 1] * catalan[i - j];
*/

/*@
  logic integer catalan_value(int* catalan, integer i) =
    i <= 0 ? 1 : catalan_sum(catalan, i, i);
*/

int foo214(int num) {
    int *catalan = (int *)malloc(sizeof(int) * (num + 1));
    int catalan_len = num + 1;
    catalan[0] = 1;

    /*@
      loop invariant 1 <= i <= num + 1;
      loop invariant \forall integer k; 0 <= k < i ==> catalan[k] >= 0;
      loop invariant \forall integer k; 0 <= k < i ==> catalan[k] == catalan_value(catalan, k);
      loop assigns i, catalan[..];
      loop variant num - i;
    */
    for (int i = 1; i <= num; i++) {
        catalan[i] = 0;

        /*@
          loop invariant 0 <= j <= i;
          loop invariant catalan[i] == catalan_sum(catalan, i, j);
          loop assigns j, catalan[i];
          loop variant i - j;
        */
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }
    return catalan[num];
}
