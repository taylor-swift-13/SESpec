
/*@
  logic integer foo335_prod(integer l, integer u) =
    l > u ? 1 : ((foo335_prod(l + 1, u) * (l % 10)) % 10);
*/
/*@
  assigns \nothing;
  ensures a == b ==> \result == 1;
  ensures a != b && (b - a) >= 5 ==> \result == 0;
*/
int foo335(int a, int b) {

        int variable = 1;
        if (a == b) {
            return 1;
        } else if ((b - a) >= 5) {
            return 0;
        } else {
            
            /*@
              loop invariant a + 1 <= i;
              loop invariant -10 <= variable <= 10;
              loop assigns i, variable;
              loop variant (b + 1) - i;
            */
            for (int i = a + 1; i < b + 1; i++) {
                variable = (variable * (i % 10)) % 10;
            }
            
            return variable;
        }
}
