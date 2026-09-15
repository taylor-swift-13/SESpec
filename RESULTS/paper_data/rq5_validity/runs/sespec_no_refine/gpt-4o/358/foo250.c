
/*@
  logic integer sum_of_odds(integer n) =
    n <= 0 ? 0 : (n % 2 != 0 ? n : 0) + sum_of_odds(n - 1);
*/

/*@
  requires size >= 1;
  assigns average, total;
  ensures average == sum_of_odds(size);
  ensures total == count_of_odds(size);
  ensures \result == (count_of_odds(size) > 0 ? sum_of_odds(size) / count_of_odds(size) : 0);
*/
int foo250(int size) {

    int average = 0;
    int total = 0;

    /*@
      loop invariant 1 <= index <= size + 1;
      loop invariant average == sum_of_odds(index - 1);
      loop invariant total == count_of_odds(index - 1);
      loop invariant size == \at(size, Pre);
      loop assigns index, average, total;
      loop variant size - index;
    */
    for (int index = 1; index <= size; index++) {
        if (index % 2 != 0) {
            average += index;
            total++;
        }
    }

    return average / total;
}
