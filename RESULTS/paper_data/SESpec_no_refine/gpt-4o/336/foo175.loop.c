
/*@
  // No additional predicate or logic function is required for this program.
*/

int foo175(int num) {

    int result = 0;

    /*@
      loop invariant 2 <= c <= \at(num, Pre) + 1;
      loop invariant (c <= \at(num, Pre)) ==> (num >= 0);
      loop invariant (c <= \at(num, Pre)) ==> (((result == 0) && (num == \at(num, Pre))) || (result > 0 && \at(num, Pre) % result == 0 && num % result != 0));
      loop invariant (!(c <= \at(num, Pre))) ==> ((result == 0) && (num == \at(num, Pre)));
      loop assigns c, result, num;
    */
    for (int c = 2; c <= num; c++) {

        /*@
          loop invariant 2 <= c <= num + 1;
          loop invariant result == 0 || (num % result != 0 && result <= num);
          loop invariant num >= 0;
          loop assigns c, result, num;
        */
        while (num % c == 0) {
            result = c;
            num /= c;
        }

    }

    return result;
}
