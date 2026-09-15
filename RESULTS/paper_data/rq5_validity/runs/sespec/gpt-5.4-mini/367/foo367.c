
/*@
  assigns \nothing;
  ensures \result == n || (2 <= \result && \result <= n && n % \result == 0);
  ensures \result == n || (\forall integer j; 2 <= j < \result ==> n % j != 0);
  ensures \result == n <==> \result == n;
  ensures \result != n ==> (2 <= \result && n % \result == 0);
*/
int foo367(int n) {

        int i = 2;
        
        /*@
          loop invariant 2 <= i;
          loop invariant n == \at(n,Pre);
          loop invariant \forall integer j; 2 <= j < i ==> n % j != 0;
          loop invariant (2 <= \at(n,Pre) / 2) ==> (i > 1);
          loop invariant (2 <= \at(n,Pre) / 2) ==> (2 <= i);
          loop invariant (!(2 <= \at(n,Pre) / 2)) ==> ((i == 2)&&(n == \at(n,Pre)));
          loop assigns i;
        */
        while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
            
        return n;
}
