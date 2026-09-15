
/*@
  requires n >= 1;
  assigns \nothing;
  ensures \result == (n + 1) / 2;
  ensures \result >= 1;
  ensures \result <= (n + 1) / 2;
  ensures (n == 1) ==> (\result == 1);
  ensures (n == 2) ==> (\result == 1);
  ensures (n == 2 * \result) || (n == 2 * \result - 1);
  ensures n == \old(n);
  ensures \result == (n + 1) / 2;
*/
int foo365(int n) {

        int sum = 0;
        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant 0 <= count <= i - 1;
          loop invariant 0 <= sum;

          loop invariant count == i / 2;
          loop invariant sum == count * count;

          loop invariant (i % 2 == 0) ==> (i == 2 * count);
          loop invariant (i % 2 != 0) ==> (i == 2 * count + 1);

          loop invariant count == 0 <==> i == 1;
          loop invariant i <= n ==> count <= n / 2;

          loop invariant n == \at(n,Pre);
          loop assigns i, sum, count;
            */
            for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                sum += i;
                count++;
            }
        }
            
        return sum / count;
}
