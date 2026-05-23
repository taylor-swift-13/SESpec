
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

int foo304(int num, int c, int r) {

    int result = 0;

    /*@
      loop invariant (\at(r,Pre) > 0) ==> (r >= 0);
      loop invariant (!(\at(r,Pre) > 0)) ==> ((result == 0) && (r == \at(r,Pre)) && (c == \at(c,Pre)) && (num == \at(num,Pre)));
      loop invariant c == \at(c,Pre);
      loop assigns r, num, result;
    */
    while (r > 0) {
        r -= 1;
        num *= 10;
        result = num / c;
        num %= c;
    }

    return result;
}
