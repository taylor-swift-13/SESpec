
/*@
  logic integer count_divisible_by(integer n, integer divisor) =
    (n < 0) ? 0 : (n % divisor == 0 ? 1 : 0) + count_divisible_by(n - 1, divisor);
*/

/*@
  logic integer count_not_divisible_by(integer n, integer d1, integer d2, integer d3) =
    (n < 0) ? 0 : ((n % d1 != 0) && (n % d2 != 0) && (n % d3 != 0) ? 1 : 0) + count_not_divisible_by(n - 1, d1, d2, d3);
*/

/*@
  logic integer count_divisible_by_only(integer n, integer d, integer d1, integer d2) =
    (n < 0) ? 0 : ((n % d == 0) && (n % d1 != 0) && (n % d2 != 0) ? 1 : 0) + count_divisible_by_only(n - 1, d, d1, d2);
*/

/*@
  logic integer count_divisible_by_exactly_one(integer n, integer d1, integer d2, integer d3) =
    (n < 0) ? 0 : (((n % d1 == 0) && (n % d2 != 0) && (n % d3 != 0)) ||
                   ((n % d2 == 0) && (n % d1 != 0) && (n % d3 != 0)) ||
                   ((n % d3 == 0) && (n % d1 != 0) && (n % d2 != 0)) ? 1 : 0) +
                  count_divisible_by_exactly_one(n - 1, d1, d2, d3);
*/

/*@
  logic integer count_divisible_by_4(integer n) = count_divisible_by(n, 4);
  logic integer count_divisible_by_3_not_4(integer n) = count_divisible_by_only(n, 3, 4, 2);
  logic integer count_divisible_by_2_not_3_or_4(integer n) = count_divisible_by_only(n, 2, 3, 4);
  logic integer count_not_divisible_by_2_3_4(integer n) = count_not_divisible_by(n, 2, 3, 4);
*/

void foo303(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;

    /*@
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns v4, i, j, k, l;
    */
    while (l < n) {
        if ((l % 4) == 0) {
            v4 = v4 + 1;
        }
        else if ((l % 3) == 0) {
            i = i + 1;
        }
        else if ((l % 2) == 0) {
            j = j + 1;
        }
        else {
            k = k + 1;
        }
        l = l + 1;
    }
}
