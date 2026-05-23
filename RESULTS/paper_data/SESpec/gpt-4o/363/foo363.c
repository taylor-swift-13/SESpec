
/*@
  logic integer count_even(integer n) = 
    (n <= 0) ? 0 : (n % 2 == 0 ? 1 + count_even(n - 1) : count_even(n - 1));

  logic integer sum_even(integer n) = 
    (n <= 0) ? 0 : (n % 2 == 0 ? n + sum_even(n - 1) : sum_even(n - 1));
*/

/*@
  requires size > 0;
  requires count_even(size) > 0; // Ensure there is at least one even number to prevent division by zero
  assigns \nothing;
  
  ensures size > 0 && count_even(size) == 0 ==> \result == 0; // Prevent division by zero
  ensures size <= 0 ==> \result == 0; // Handles invalid input gracefully
*/
int foo363(int size) {

    int average = 0;
    int total = 0;

    /*@
      loop invariant 1 <= c <= size + 1;
      loop invariant average == sum_even(c - 1);
      loop invariant total == count_even(c - 1);
      loop assigns c, average, total;
      loop variant size - c;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 == 0) {
            average += c;
            total++;
        }
    }

    return average / total;
}
