
/* No additional predicates or logic functions are required. */

int foo328(int diff) {

    int result = 0;
    int max = 0;

    /*@
      loop invariant c >= 1;
      loop invariant diff == \at(diff,Pre);
      loop invariant max == 0;

      loop invariant result >= 0;
      loop invariant c == 1 ==> result == 0;
      loop invariant c >= 2 ==> result >= (c - 1) * (c - 1) * (c - 1);
      loop invariant \forall integer k; 1 <= k < c ==> k >= 1;

      loop invariant (c <= \at(diff,Pre)) ==> (c >= 1);
      loop invariant (c <= \at(diff,Pre)) ==> (result >= 0);
      loop invariant !(c <= \at(diff,Pre)) ==> ((max == 0) && (result >= 0) && (diff == \at(diff,Pre)));

      loop assigns c, result;
    */
    for (int c = 1; c <= diff; c++) {
        result += c * c * c;
    }

    /*@
      loop invariant 1 <= c;
      loop invariant diff == \at(diff,Pre);
      loop invariant max >= 0;

      loop invariant c == 1 ==> max == 0;
      loop invariant c >= 2 ==> max >= c - 1;
      loop invariant c >= 2 ==> max >= (c - 1);
      loop invariant c >= 2 ==> max <= (c - 1) * diff;

      loop invariant (c <= diff) ==> (max + c >= max);

      loop assigns c, max;
    */
    for (int c = 1; c <= diff; c++) {
        max += c;
    }

    return result - max;
}
