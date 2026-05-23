
#include <stddef.h>

static const char even_str[] = "Even";
static const char odd_str[]  = "Odd";

/*@ logic integer divisor_count_upto(integer n, integer i) =
      i <= 0 ? 0 : divisor_count_upto(n, i - 1) + (n % i == 0 ? 1 : 0); */

/*@
  requires num >= 0;
  assigns \nothing;

  behavior even:
    assumes num < 1 || divisor_count_upto(num, num) % 2 == 0;
    ensures \result == even_str;
    ensures \result[0] == 'E';
    ensures \result[1] == 'v';
    ensures \result[2] == 'e';
    ensures \result[3] == 'n';
    ensures \result[4] == '\0';

  behavior odd:
    assumes num >= 1 && divisor_count_upto(num, num) % 2 != 0;
    ensures \result == odd_str;
    ensures \result[0] == 'O';
    ensures \result[1] == 'd';
    ensures \result[2] == 'd';
    ensures \result[3] == '\0';

  complete behaviors;
  disjoint behaviors;
*/
const char * foo281(int num) {
    int result = 0;
    int index = 1;

    /*@
      loop invariant 1 <= index <= num + 1;
      loop invariant result == divisor_count_upto(num, index - 1);
      loop invariant result >= 0;
      loop invariant num >= 0;
      loop assigns result, index;
      loop variant num - index + 1;
    */
    while (index <= num) {
        if (num % index == 0) {
            result++;
        }
        index++;
    }

    if (result % 2 == 0) {
        return even_str;
    } else {
        return odd_str;
    }
}
