int firstDigit(int n);

/*@
    requires 0 <= n <= 12;
    assigns \nothing;
    ensures 1 <= \result <= 9;
    ensures
      let total = (\product integer j; 1 <= j <= n; j) in
      \exists integer k; k >= 0 &&
        total / \pow(10,k) == \result &&
        total < (\result + 1) * \pow(10,k);
*/
int firstDigit(int n) {

        int fact = 1;
        /*@
            loop invariant 2 <= i <= n + 1;
            loop invariant fact == (\product integer j; 2 <= j < i; j);
            loop assigns i, fact;
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        int firstDigit = 0;
        /*@
            loop invariant fact >= 0;
            loop invariant 0 <= firstDigit <= 9;
            loop invariant
              let total = (\product integer j; 1 <= j <= n; j) in
              \exists integer k; k >= 0 &&
                total == firstDigit * \pow(10,k) + fact;
            loop assigns fact, firstDigit;
            loop variant fact;
        */
        while (fact > 0) {
            firstDigit = fact % 10;
            fact /= 10;
        }
        return firstDigit;
}
