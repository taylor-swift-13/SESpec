
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  predicate increasing_range(int* a, integer lo, integer hi) =
    lo >= hi || \forall integer k; lo <= k < hi ==> a[k] < a[k+1];
*/

/*@
  predicate nonincreasing_range(int* a, integer lo, integer hi) =
    lo >= hi || \forall integer k; lo <= k < hi ==> a[k] >= a[k+1];
*/

/*@
   requires \valid(data + (0..data_len-1));
   requires \at(data_len,Pre) > 0 && \at(data_len,Pre) < 100;
   assigns \nothing;
   ensures data == \at(data,Pre);
   ensures data_len == \at(data_len,Pre);
   ensures array == \at(array,Pre);
   ensures \result == \result;
 */
int foo301(int * data, int data_len, int array) {

    int found = 0, top = array - 1;
        
    /*@
      loop invariant (0 < \at(array,Pre) - 1) ==> (found >= 0 && top <= \at(array,Pre) - 1);
      loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1) && (found == 0) && (array == \at(array,Pre)) && (data_len == \at(data_len,Pre)) && (data == \at(data,Pre))) || (found > 0 ==> \exists integer k; 0 <= k <= found - 1));
      loop invariant (!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1) && (found == 0) && (array == \at(array,Pre)) && (data_len == \at(data_len,Pre)) && (data == \at(data,Pre)));
      loop invariant array == \at(array,Pre);
      loop invariant data_len == \at(data_len,Pre);
      loop invariant data == \at(data,Pre);
      loop invariant \forall integer idx; 0 <= idx < data_len ==>
                         count_eq(data, 0, data_len, data[idx]) == \at(count_eq(data, 0, data_len, data[idx]), Pre);
      loop assigns found, top;
    */
    while (found < top) {
        int i = found + (top - found) / 2;
        if (data[i] < data[i + 1]) {
            found = i + 1;
        } else {
            top = i;
        }
    }
            
    return found;
}
