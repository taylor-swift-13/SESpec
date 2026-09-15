
/*@
  assigns \nothing;
  ensures
    (\exists integer d; 2 <= d && d <= n / d && n % d == 0)
      ==> (\result >= 2 && \result <= n / \result && \result * \result <= n && n % \result == 0);
  ensures
    (\forall integer k; 2 <= k <= n / k ==> n % k != 0) ==> \result == n;
  ensures
    n <= 1 ==> \result == n;
  ensures
    \result == n ==> (\forall integer k; 2 <= k <= n / k ==> n % k != 0);
*/
int foo367(int n) {

        int i = 2;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 2 <= i;
              loop invariant n == \at(n,Pre);
              loop invariant i == 2 + (i - 2);
              loop invariant \forall integer k; 2 <= k < i ==> n % k != 0;
              loop invariant \forall integer k; 2 <= k < i ==> (k == 0 || n / k < n);
              loop invariant i == 2 ==> \true;
              loop invariant 2 <= \at(n,Pre) ==> i <= \at(n,Pre);
              loop invariant i <= \at(n,Pre) || i > \at(n,Pre);
              loop invariant (i > \at(n,Pre) / i) ==> (\forall integer k; 2 <= k < i ==> n % k != 0);
              loop invariant (i > \at(n,Pre) / i) ==> (i * i > \at(n,Pre));
              loop invariant (2 <= \at(n,Pre) / 2) ==> ((\forall integer k; 2 <= k <= \at(n,Pre) / k ==> n % k != 0) ==> \false || \true);
              loop invariant (2 <= \at(n,Pre) / 2) ==> (\forall integer k; 2 <= k < i ==> k <= \at(n,Pre) / k);
              loop invariant (i <= \at(n,Pre) / i) ==> (i <= \at(n,Pre));
              loop invariant (i >= 3) ==> (i - 1 >= 2);
              loop invariant \exists integer t; t == i - 2 && t >= 0;
              loop invariant (i > \at(n,Pre) / i) ==> (n == \at(n,Pre));
              loop invariant (2 <= \at(n,Pre) / 2) ==> ( (i >= 2) && (i <= \at(n,Pre)) );
              loop invariant (2 <= \at(n,Pre) / 2) ==> (i >= 2);
              loop invariant (!(2 <= \at(n,Pre) / 2)) ==> ((i == 2)&&(n == \at(n,Pre)));
              loop invariant n == \at(n,Pre);
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
