
        /*@
  requires n <= 0;
  assigns \nothing;
  ensures \result == n;
*/
int foo356(int n) {
    if (n <= 0) {
        return n;
    }

    int res = 0;
    int count = 0;
    int temp = n;

    /*@
      loop invariant count >= 0;
      loop invariant count == 0 || temp >= 0;
      loop assigns res, count, temp;
    */
    while (temp > 0) {
        if (count % 2 == 0) {
            res = res | (1 << count);
        }
        count++;
        temp >>= 1;
    }

    return n ^ res;
}
