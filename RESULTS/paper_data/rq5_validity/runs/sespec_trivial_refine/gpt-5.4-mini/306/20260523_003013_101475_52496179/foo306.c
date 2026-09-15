
        /*@
        /*@
          loop invariant 2 <= i <= n + 1;
          loop invariant \forall integer k; 2 <= k < i ==> lucas[k] == lucas[k - 1] + lucas[k - 2];
          loop assigns i, lucas[2..n];
        */
        */

/*@ logic integer lucas306(integer n) =
      n == 0 ? 2 :
      n == 1 ? 1 :
      lucas306(n - 1) + lucas306(n - 2); */
/*@
  requires 1 <= n;
  assigns \nothing;
  ensures \result == lucas306(n);
  ensures n == 1 ==> \result == 1;
  ensures n == 2 ==> \result == 3;
  ensures n >= 2 ==> \result == lucas306(n - 1) + lucas306(n - 2);
  ensures \result >= 1;
*/
int foo306(int n) {

        int *lucas = (int *)malloc(sizeof(int) * (n + 1));
int lucas_len = n + 1;
        lucas[0] = 2;
        lucas[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= i <= n + 1;
          loop invariant \forall integer k; 2 <= k < i ==> lucas[k] == lucas[k - 1] + lucas[k - 2];
          loop assigns i, lucas[2..n];
            */
            for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
            
        return lucas[n];
}
