
        /*@
        logic integer sum_cubes(integer n) =
            n <= 0 ? 0 : sum_cubes(n - 1) + n * n * n;

        logic integer sum_upto(integer n) =
            n <= 0 ? 0 : sum_upto(n - 1) + n;
        */
        
/*@
  assigns \nothing;
  ensures diff <= 0 ==> \result == 0;
  ensures diff > 0 ==> \result == sum_cubes(diff) - sum_upto(diff);
  ensures \result == (diff <= 0 ? 0 : sum_cubes(diff) - sum_upto(diff));
  ensures \result >= 0;
*/
int foo328(int diff)
{
    int result = 0;

    if (diff <= 0) {
        return 0;
    }

    int c = 0;
    /*@
      loop invariant 0 <= c <= diff;
      loop invariant result == sum_cubes(c) - sum_upto(c);
      loop invariant result >= 0;
      loop assigns c, result;
      loop variant diff - c;
    */
    while (c < diff) {
        c++;
        result += c * c * c - c;
    }

    return result;
}
