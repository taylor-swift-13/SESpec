
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

/*@
  requires \valid(&data[0] + (0..data_len-1));
  requires \forall integer i; 0 <= i < data_len ==> 0 <= data[i] <= 100;
  requires data_len > 0;
  requires array > 0 && array <= data_len;
  assigns i, top;
  ensures \result == max_index(data, 0, array);
  ensures \forall integer k; 0 <= k < array ==> data[\result] >= data[k];
*/
int foo201(int * data, int data_len, int array) {

    int i = 0, top = array - 1;

    /*@
      loop invariant 0 <= i <= top < array;
      loop invariant \forall integer k; 0 <= k < i ==> data[i] >= data[k];
      loop invariant \forall integer k; top < k < array ==> data[top] >= data[k];
      loop assigns i, top;
      loop variant top - i;
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
