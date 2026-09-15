
        /*@ logic integer count_even(integer n) =
      n <= 0 ? 0 : count_even(n - 1) + (n % 2 == 0 ? 1 : 0); */
/*@ logic integer sum_even(integer n) =
      n <= 0 ? 0 : sum_even(n - 1) + (n % 2 == 0 ? n : 0); */
/*@ 
  requires size >= 2;
  assigns \nothing;
  ensures \result == sum_even(size) / count_even(size);
*/
int foo362(int size) {
    int result = 0;
    int total = 0;
    int c = 1;

    /*@
      loop invariant 1 <= c <= size + 1;
      loop invariant total == count_even(c - 1);
      loop invariant result == sum_even(c - 1);
      loop invariant total >= 0;
      loop invariant result >= 0;
      loop assigns c, result, total;
      loop variant size - c + 1;
    */
    for (; c <= size; c++) {
        if (c % 2 == 0) {
            result += c;
            total++;
        }
    }

    return result / total;
}
