
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
  logic integer max(int* array, integer begin, integer end) =
    end <= begin ? array[begin] : (array[end - 1] > max(array, begin, end - 1) ? array[end - 1] : max(array, begin, end - 1));
*/

/*@
  logic integer min(int* array, integer begin, integer end) =
    end <= begin ? array[begin] : (array[end - 1] < min(array, begin, end - 1) ? array[end - 1] : min(array, begin, end - 1));
*/

int foo201(int * data, int data_len, int array) {

    int i = 0, top = array - 1;

    /*@
      loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (i >= 0 && i <= top));
      loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (top >= i && top < \at(array,Pre)));
      loop invariant (!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre)));
      loop invariant array == \at(array,Pre);
      loop invariant data_len == \at(data_len,Pre);
      loop invariant data == \at(data,Pre);
      loop invariant \forall integer k; 0 <= k < data_len ==> data[k] == \at(data[k], Pre);
      loop assigns i, top;
    */
    while (i < top) {
        int p = i + (top - i) / 2;
        if (data[p] < data[p + 1]) {
            i = p + 1;
        } else {
            top = p;
        }
    }

    return i;
}
