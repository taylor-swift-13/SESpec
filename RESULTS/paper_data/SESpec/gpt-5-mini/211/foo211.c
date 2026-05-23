
/*@ 
  logic integer matched_prefix(integer hi) =
    hi <= 0 ? 0 : matched_prefix(hi - 1) + 1;
*/

/*@
  requires \valid(arr + (0 .. arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result <= (\old(n) >= 0 ? \old(n) : 0);
  ensures (\old(n) <= 1) ==> \result == 0;
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \old(arr[k]);
*/
int foo211(int * arr, int arr_len, int n) {

    int count = 0;
    int i = 0;
    int j = 1;

    /*@
      loop invariant 0 <= i;
      loop invariant (\at(n,Pre) >= 0) ==> (i <= \at(n,Pre));
      loop invariant 0 <= j;
      loop invariant 0 <= count;
      loop invariant count <= (i < j ? i : j);
      loop invariant i <= j;
      loop invariant \forall integer k; 0 <= k < i ==> arr[k] == \at(arr[k], Pre);
      loop invariant \forall integer k; 0 <= k < j ==> arr[k] == \at(arr[k], Pre);
      loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (i <= \at(n,Pre) && j <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (count >= 0 && count <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (0 <= i && 0 <= j);
      loop invariant (!(0 < \at(n,Pre) && 1 < \at(n,Pre))) ==> ((j == 1) && (i == 0) && (count == 0) && (n == \at(n,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)));
      loop invariant n == \at(n,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop assigns i, j, count;
    */
    while (i < n && j < n) {
        if (arr[i] == arr[j]) {
            i++;
            j++;
            count++;
        } else if (arr[i] > arr[j]) {
            i++;
        } else {
            j++;
        }
    }

    return count;
}
