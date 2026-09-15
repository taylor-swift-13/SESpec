
/*@
    requires n >= 0;
    assigns \result, sumOfPrimeDivisors[0..n];
    ensures \result == (\sum int d; 1 <= d <= n && n % d == 0 && is_prime(d); d);
    ensures \valid(sumOfPrimeDivisors + (0 .. n));
    ensures \forall int k; 2 <= k <= n ==> 
        (is_prime(k) ==> sumOfPrimeDivisors[k] == k) &&
        (!is_prime(k) ==> sumOfPrimeDivisors[k] == 
            (\sum int d; 1 <= d <= k && k % d == 0 && is_prime(d); d));
*/
int foo184(int n) {

    int *sumOfPrimeDivisors = (int *)malloc(sizeof(int) * (n + 1));
    int sumOfPrimeDivisors_len = n + 1;
    sumOfPrimeDivisors[0] = 0;
    sumOfPrimeDivisors[1] = 0;

    /*@
      loop invariant 2 <= i <= n + 1;
      loop invariant \forall int k; 2 <= k < i ==> 
          (is_prime(k) ==> sumOfPrimeDivisors[k] == k) &&
          (!is_prime(k) ==> sumOfPrimeDivisors[k] == 
              (\sum int d; 1 <= d <= k && k % d == 0 && is_prime(d); d));
      loop assigns i, sumOfPrimeDivisors[2..n];
      loop variant n - i;
    */
    for (int i = 2; i <= n; i++) {
        if (sumOfPrimeDivisors[i] == 0) {
            /*@
              loop invariant i <= j <= n + 1;
              loop invariant \forall int k; i <= k < j ==> sumOfPrimeDivisors[k] == 
                  (\sum int d; 1 <= d <= k && k % d == 0 && is_prime(d); d);
              loop assigns j, sumOfPrimeDivisors[i..n];
              loop variant n - j;
            */
            for (int j = i; j <= n; j += i) {
                sumOfPrimeDivisors[j] += i;
            }
        }
    }

    return sumOfPrimeDivisors[n];
}
