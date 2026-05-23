int averageOdd(int n);

/*@ 
  requires n >= 1;
  assigns \nothing;
  ensures \result == (n + 1) / 2;
*/
int averageOdd(int n) {

        int sum = 0;
        int count = 0;
        /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant count == i / 2;
          loop invariant sum == count * count;
          loop invariant sum >= 0 && count >= 0;
          loop assigns sum, count, i;
          loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                sum += i;
                count++;
            }
        }
        //@ assert count > 0;
        return sum / count;
}
