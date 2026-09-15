
/*@
  logic integer sum_of_odds(integer n) =
    n <= 0 ? 0 : (n % 2 != 0 ? n : 0) + sum_of_odds(n - 1);
*/

/*@
  logic integer count_of_odds(integer n) =
    n <= 0 ? 0 : (n % 2 != 0 ? 1 : 0) + count_of_odds(n - 1);
*/

/*@
  requires n > 0;
  assigns \nothing;
  ensures count_of_odds(n) > 0 ==> 
          \result == sum_of_odds(n) / count_of_odds(n);
*/
int foo263(int n) {

    int sum = 0;
    int count = 0;

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant sum == sum_of_odds(i - 1);
      loop invariant count == count_of_odds(i - 1);
      loop assigns i, sum, count;
      loop variant n - i;
    */
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            sum += i;
            count++;
        }
    }

    return sum / count;
}
