
/*@
  // Define a logic function to compute the product of a range of integers modulo 10
  logic integer product_mod10(integer start, integer end) =
    (start > end) ? 1 : (start % 10) * product_mod10(start + 1, end) % 10;
*/

/*@
  requires \at(c,Pre) - \at(num,Pre) < 5;
  requires \at(num,Pre) != \at(c,Pre);
  requires c == \at(c,Pre);
  requires num == \at(num,Pre);
  ensures \result == product_mod10(\at(num,Pre) + 1, \at(c,Pre));
*/

int foo332(int num, int c) {

    int result = 1;
    if (num == c) {
        return 1;
    } else if ((c - num) >= 5) {
        return 0;
    } else {

        /*@
          loop invariant c == \at(c,Pre);
          loop invariant num == \at(num,Pre);
          loop assigns var, result;
        */
        for (int var = num + 1; var < c + 1; var++) {
            result = (result * (var % 10)) % 10;
        }

        return result % 10;
    }
}
