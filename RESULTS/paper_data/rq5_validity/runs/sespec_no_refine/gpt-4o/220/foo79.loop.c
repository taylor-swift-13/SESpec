
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  logic integer sorted{L}(int* a, integer lo, integer hi) =
    lo >= hi - 1 ? 1
                 : (a[lo] <= a[lo + 1] ? sorted(a, lo + 1, hi) : 0);
*/

/*@
  requires \valid(args + (0 .. args_len - 1));
  requires args_len > 0 && args_len < 100;
  requires sorted(args, 0, args_len) == 1;
  ensures \result == -1 || (0 <= \result < args_len && args[\result] == array);
*/
int foo79(int * args, int args_len, int array, int n) {

    int i = 0;
    int hi = n - 1;
    int result = -1;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant -1 <= hi < n;
      loop invariant result == -1 || (0 <= result < n && args[result] == array);
      loop invariant \forall integer k; 0 <= k < i ==> args[k] < array;
      loop invariant \forall integer k; hi < k < n ==> args[k] > array;
      loop invariant n == \at(n,Pre);
      loop invariant array == \at(array,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop invariant sorted(args, 0, args_len) == 1;
      loop assigns tmp, result, hi, i;
    */
    while (i <= hi) {
        int tmp = (i + hi) / 2;
        if (args[tmp] == array) {
            result = tmp;
            hi = tmp - 1;
        } else if (args[tmp] < array) {
            i = tmp + 1;
        } else {
            hi = tmp - 1;
        }
    }

    return result;
}
