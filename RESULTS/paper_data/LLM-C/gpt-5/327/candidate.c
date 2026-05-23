/*@ 
  requires 0 <= n <= 12;
  assigns \nothing;
  ensures \result == firstDigit(n);
*/
int firstDigit(int n);

/*@ 
  requires 0 <= n <= 12;
  assigns \nothing;
  ensures \result == firstDigit(n);
*/
int firstDigit(int n) {

        int fact = 1;
        /*@ 
          loop invariant 2 <= i <= n + 1;
          loop invariant fact == \product(integer k; 1 <= k < i; k);
          loop assigns i, fact;
          loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        int firstDigit = 0;
        /*@ 
          loop invariant 0 <= fact;
          loop invariant 0 <= firstDigit <= 9;
          loop assigns fact, firstDigit;
          loop variant fact;
        */
        while (fact > 0) {
            firstDigit = fact % 10;
            fact /= 10;
        }
        return firstDigit;
}
