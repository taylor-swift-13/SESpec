/*@ axiomatic Combinatorics {
  logic integer fact(integer n);
  axiom fact_base0: fact(0) == 1;
  axiom fact_base1: fact(1) == 1;
  axiom fact_step: \forall integer n; n >= 2 ==> fact(n) == n * fact(n-1);

  logic integer choose(integer n, integer k) =
    (k < 0 || k > n) ? 0 : fact(n) / (fact(k) * fact(n-k));

  lemma choose_sym: \forall integer n,k; 0 <= k <= n ==> choose(n,k) == choose(n,n-k);
  lemma choose_step:
    \forall integer n,i; 0 < i <= n ==> choose(n,i) * i == choose(n,i-1) * (n - i + 1);
} */

int binomialCoeff(int n, int k);

/*@ 
  requires n >= 0;
  requires 0 <= k <= n;
  assigns \nothing;
  ensures \result == choose(n, \old(k));
  ensures \result >= 0;
  terminates \true;
*/
int binomialCoeff(int n, int k) {

        if (k > n - k)
            k = n - k;
        int c = 1;
        /*@
          loop invariant 1 <= i <= k + 1;
          loop invariant c >= 0;
          loop invariant c == choose(n, i - 1);
          loop assigns c, i;
          loop variant k - i + 1;
        */
        for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
}
