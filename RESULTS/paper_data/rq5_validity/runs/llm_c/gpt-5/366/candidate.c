int averageEven(int n);

/*@ 
  requires n >= 2;
  requires ((n/2) * ((n/2) + 1)) <= 2147483647;
  assigns \nothing;
  ensures \result == (n/2) + 1;
*/
int averageEven(int n) {

        int sum = 0;
        int count = 0;
        /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant 0 <= count <= n/2;
          loop invariant 0 <= sum <= (n/2) * ((n/2) + 1);
          loop invariant \let t = (i - 1) / 2; sum == t * (t + 1) && count == t;
          loop assigns i, sum, count;
          loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }
        /*@ assert count > 0; */
        return sum / count;
}
