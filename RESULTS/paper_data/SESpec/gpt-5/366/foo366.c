
/*@
  requires n >= 2;
  assigns \nothing;
  ensures \result >= 1;
*/
int foo366(int n) {

        int sum = 0;
        int count = 0;
        
        /*@
          loop invariant sum >= 0 && count >= 0;
          loop invariant count == ((i - 1) / 2);
          loop invariant sum == ((i - 1) / 2) * (((i - 1) / 2) + 1);
          loop invariant (i == n + 1) ==> (count == (n / 2));
          loop invariant (i == n + 1) ==> (sum == (n / 2) * ((n / 2) + 1));
          loop invariant (i <= \at(n,Pre)) ==> (i >= 1 && i <= \at(n,Pre));
          loop invariant (i <= \at(n,Pre)) ==> (sum == ((i - 1) / 2) * (((i - 1) / 2) + 1)) ;
          loop invariant (i <= \at(n,Pre)) ==> (count == ((i - 1) / 2)) ;
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
