
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

/*@
*/

int foo346(int n) {
        int max = 0;
        /*@
          loop invariant 2 <= i;
          loop invariant max >= 0;
          loop assigns i, max, n;
          ensures max >= 0;
          ensures 0 <= n;
        */
        for (int i = 2; i <= n; i++) {
            /*@
              loop invariant 2 <= i;
              loop invariant max >= 0;
              loop invariant n >= 0;
              loop assigns i, max, n;
              ensures max >= 0;
              ensures 0 <= n;
            */
            while (n % i == 0) {
                max = i;
                n /= i;
            }
        }
        return max;
}
