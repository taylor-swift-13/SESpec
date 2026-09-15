
/*@ logic integer lucas_seq(integer n) =
      n == 0 ? 2 :
      n == 1 ? 1 :
      lucas_seq(n - 1) + lucas_seq(n - 2);
*/

/*@
  requires n >= 1;
  ensures n >= 1 ==> \result == lucas_seq(n - 1) + lucas_seq(n - 2) || n == 1;
  ensures n >= 1 ==> \true;
  ensures n >= 1 ==> \true;
  
*/
int foo306(int n) {
        int *lucas = (int *)malloc(sizeof(int) * (n + 1));
        int lucas_len = n + 1;
        lucas[0] = 2;
        lucas[1] = 1;

        /*@
          loop invariant i >= 2;
          loop invariant lucas[0] == 2;
          loop invariant lucas[1] == 1;
          loop invariant \forall integer k; 2 <= k < i ==> lucas[k] == lucas[k - 1] + lucas[k - 2];
          loop invariant \forall integer k; 0 <= k < i ==> lucas[k] == lucas_seq(k);
          loop assigns i, lucas[0..n];
        */
        for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }

        return lucas[n];
}
