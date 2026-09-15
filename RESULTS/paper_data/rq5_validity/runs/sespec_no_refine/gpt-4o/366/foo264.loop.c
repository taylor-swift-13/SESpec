
/*@
  logic integer sum_of_evens(integer n) =
    n <= 0 ? 0 : (n % 2 == 0 ? n : 0) + sum_of_evens(n - 1);

  logic integer count_of_evens(integer n) =
    n <= 0 ? 0 : (n % 2 == 0 ? 1 : 0) + count_of_evens(n - 1);
*/

int foo264(int n) {

    int sum = 0;
    int count = 0;

    /*@
      loop invariant n == \at(n,Pre);
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
