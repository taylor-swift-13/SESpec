
/*@
requires a_len >= 0;
requires \valid_read(a + (0 .. a_len - 1));
requires \forall integer i, j; 0 <= i <= j < a_len ==> a[i] <= a[j];
assigns \nothing;
ensures \result == -1 || (0 <= \result < a_len && a[\result] == x && (\result == a_len - 1 || a[\result + 1] != x));
ensures \result == -1 ==> \forall integer i; 0 <= i < a_len ==> a[i] != x;
ensures \result != -1 ==> 0 <= \result < a_len;
ensures \result != -1 ==> a[\result] == x;
ensures \result != -1 ==> (\result == a_len - 1 || a[\result + 1] != x);
*/
int foo182(int * a, int a_len, int x)
{
    int i = 0;
    int res = -1;

    /*@
      loop invariant 0 <= i <= a_len;
      loop invariant -1 <= res < i;
      loop invariant res == -1 || a[res] == x;
      loop invariant res == -1 ==> (\forall integer k; 0 <= k < i ==> a[k] != x);
      loop invariant res != -1 ==> (\forall integer k; res < k < i ==> a[k] != x);
      loop assigns i, res;
      loop variant a_len - i;
    */
    while (i < a_len) {
        if (a[i] == x) {
            res = i;
        }
        i++;
    }

    return res;
}
