
/*@
  assigns \nothing;
  ensures size == \old(size);
  ensures odd_count_upto(size) != 0 ==> \result == odd_sum_upto(size) / odd_count_upto(size);
*/
int foo360(int size) {

    int average = 0;
    int total = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant 1 <= c;
      loop invariant average == odd_sum_upto(c - 1);
      loop invariant total == odd_count_upto(c - 1);
      loop invariant (c <= \at(size,Pre)) ==> (average == odd_sum_upto(c - 1) && total == odd_count_upto(c - 1));
      loop invariant (c <= \at(size,Pre)) ==> (average == odd_sum_upto(c - 1));
      loop invariant (c <= \at(size,Pre)) ==> (total == odd_count_upto(c - 1));
      loop invariant (!(c <= \at(size,Pre))) ==> ((total == odd_count_upto(\at(size,Pre)))&&(average == odd_sum_upto(\at(size,Pre)))&&(size == \at(size,Pre)));
      loop invariant size == \at(size,Pre);
      loop assigns c, average, total;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 != 0) {
            average += c;
            total++;
        }
    }

    return average / total;
}
