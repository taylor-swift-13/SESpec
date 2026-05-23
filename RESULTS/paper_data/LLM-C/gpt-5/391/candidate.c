int nextPerfectSquare(int n);

/*@ 
  requires n < 46340*46340;
  assigns \nothing;
  ensures \result > n;
  ensures \exists integer k; k >= 1 && \result == k*k;
  ensures \forall integer t; t >= 1 && t*t > n ==> t*t >= \result;
*/

int nextPerfectSquare(int n) {

        int i = 1;
        int square = 1;
        /*@
          loop invariant 1 <= i <= 46341;
          loop invariant square >= 1;
          loop invariant (i == 1 ==> square == 1);
          loop invariant (i >= 2 ==> square == (i-1)*(i-1) && (i-2)*(i-2) <= n);
          loop variant 46341 - i;
        */
        while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
}
