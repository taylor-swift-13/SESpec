
/*@ logic integer count_evens_upto(integer n) =
      n <= 0 ? 0 : ((n % 2 == 0 ? 1 : 0) + count_evens_upto(n - 1)); */

/*@ logic integer sum_evens_upto(integer n) =
      n <= 0 ? 0 : ((n % 2 == 0 ? n : 0) + sum_evens_upto(n - 1)); */

int foo255_c363(int size) {

    int average = 0;
    int total = 0;

    /*@
      loop invariant 1 <= c;
      loop invariant size == \at(size,Pre);
      loop invariant total == count_evens_upto(c - 1);
      loop invariant average == sum_evens_upto(c - 1);
      loop invariant 0 <= total <= c - 1;
      loop invariant 0 <= average;
      loop assigns c, average, total;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 == 0) {
            average += c;
            total++;
        }
    }

    return average / total;
}
