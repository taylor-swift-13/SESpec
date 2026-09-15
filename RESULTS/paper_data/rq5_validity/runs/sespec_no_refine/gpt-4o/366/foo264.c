
/*@
  requires n > 0; // The function is only valid for positive n to avoid division by zero.
  assigns \nothing; // No global variables are modified.
  ensures \result == sum_of_evens(n) / count_of_evens(n); // The result is the average of even numbers.
*/
int foo264(int n) {

    int sum = 0;
    int count = 0;

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant sum == sum_of_evens(i - 1);
      loop invariant count == count_of_evens(i - 1);
      loop assigns i, sum, count;
      loop variant n - i;
    */
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sum += i;
            count++;
        }
    }

    return sum / count;
}
