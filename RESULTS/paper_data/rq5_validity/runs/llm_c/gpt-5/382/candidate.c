int findMaxVal(int n, int x, int y);

/*@ 
  requires x != 0;

  assigns \nothing;

  behavior none:
    assumes n < 1 || (\forall integer i; 1 <= i <= n ==> (i % x) != y);
    ensures \result == 0;

  behavior some:
    assumes n >= 1 && (\exists integer i; 1 <= i <= n && (i % x) == y);
    ensures 1 <= \result <= n;
    ensures (\result % x) == y;
    ensures (\forall integer j; \result < j <= n ==> (j % x) != y);

  disjoint behaviors;
  complete behaviors;
*/
int findMaxVal(int n, int x, int y) {

        int max = 0;
        for (int i = 1; i <= n; i++)
        /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant 0 <= max < i;
          loop invariant
            (max == 0 ==> (\forall integer j; 1 <= j < i ==> (j % x) != y)) &&
            (max > 0 ==> (1 <= max < i && (max % x) == y &&
                          (\forall integer j; max < j < i ==> (j % x) != y)));
          loop assigns max, i;
          loop variant n - i + 1;
        */
        {
            if ((i % x) == y) {
                max = i;
            }
        }
        return max;
}
