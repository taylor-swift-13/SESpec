int sumInRange(int l, int r);

/*@
  assigns \nothing;
  ensures \result == \sum(k, l, r, ((k % 2 != 0) ? k : 0));
*/
int sumInRange(int l, int r) {

        int sum = 0;
        /*@
          loop invariant (integer)l <= (integer)i <= (integer)r + 1;
          loop invariant sum == \sum(k, l, (integer)i - 1, ((k % 2 != 0) ? k : 0));
          loop assigns i, sum;
          loop variant (integer)r - (integer)i + 1;
        */
        for (int i = l; i <= r; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
        return sum;
}
