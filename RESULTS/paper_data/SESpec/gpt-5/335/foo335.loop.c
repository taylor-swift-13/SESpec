
/*@
  logic integer mod10(integer x) = x % 10;

  logic integer prod10(integer lo, integer hi) =
    lo >= hi ? 1 : mod10(prod10(lo, hi - 1) * mod10(hi - 1));
*/

int foo335(int a, int b) {

        int variable = 1;
        if (a == b) {
            return 1;
        } else if ((b - a) >= 5) {
            return 0;
        } else {


        /* >>> LOOP INVARIANT TO FILL <<< */

            /*@
          loop invariant b == \at(b,Pre);
          loop invariant a == \at(a,Pre);

          loop invariant (b > a) ==> (a + 1 <= i <= b + 1);
          loop invariant (b <= a) ==> (i == a + 1);

          loop invariant (b > a) ==> (0 <= i - (a + 1) <= b - a);
          loop invariant b - a < 5;

          loop invariant variable == prod10(\at(a,Pre) + 1, i);
          loop invariant -9 <= variable <= 9;

          loop invariant \forall integer k; \at(a,Pre) + 1 <= k < i ==> -9 <= (k % 10) <= 9;
          loop invariant \forall integer k; \at(a,Pre) + 1 <= k < i ==> mod10(k) == (k % 10);

          loop assigns i, variable;
            */
            for (int i = a + 1; i < b + 1; i++) {
                variable = (variable * (i % 10)) % 10;
            }

            return variable % 10;
        }
}
