/*@
  predicate strictly_increasing_by_at_least_one(int *a, integer lo, integer hi) =
    \forall integer i; lo <= i < hi ==> a[i+1] >= a[i] + 1;
*/

/*@ 
  requires array != \null;
  requires 0 <= array_len;
  requires 0 <= start;
  requires start <= end ==> end < array_len;
  requires start <= end ==> \valid_read(array + (start .. end));
  requires start <= end ==> strictly_increasing_by_at_least_one(array, start, end);

  assigns \nothing;

  ensures start > end ==> \result == start;

  ensures start <= end ==> start <= \result <= end + 1;
  ensures start <= end ==> (\forall integer i; start <= i < \result ==> array[i] <= i);
  ensures start <= end ==> (\result <= end ==> array[\result] > \result);

  ensures start <= end ==> ((\forall integer i; start <= i <= end ==> array[i] <= i) ==> \result == end + 1);

  ensures start <= end ==> (
            (\exists integer i; start <= i <= end && array[i] > i)
         ==> (start <= \result <= end 
              && array[\result] > \result
              && (\forall integer j; start <= j < \result ==> array[j] <= j)));
*/
int findFirstMissing(int * array, int array_len, int start, int end);

int findFirstMissing(int * array, int array_len, int start, int end) {

        int min = start;
        int max = end;
        int mid;

        /*@
          loop invariant start <= min <= max + 1;
          loop invariant max <= end;
          loop invariant start <= min;
          loop invariant \valid_read(array + (start .. end));
          loop invariant \forall integer i; start <= i < min ==> array[i] <= i;
          loop invariant \forall integer i; max < i <= end ==> array[i] > i;
          loop assigns min, max, mid;
          loop variant (max - min + 1);
        */
        while (min <= max) {
            mid = (min + max) / 2;
            //@ assert start <= min <= mid <= max <= end;
            int current = array[mid];

            if (current == mid) {
                min = mid + 1;
            } else if (current < mid) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return min;
}
