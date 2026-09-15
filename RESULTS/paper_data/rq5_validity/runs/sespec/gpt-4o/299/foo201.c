
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
  predicate unchanged_array{L1, L2}(int* a, integer len) =
    \forall integer i; 0 <= i < len ==> \at(a[i], L1) == \at(a[i], L2);
*/

/*@
  requires \valid(data + (0..data_len-1));
  requires \forall integer i; 0 <= i < data_len ==> 0 <= data[i] <= 100;
  requires data_len > 0;
  requires data_len < 100;
  requires array > 0;
  requires array <= data_len;
  assigns \nothing;
  ensures 0 <= \result < data_len;
  ensures unchanged_array{Pre, Post}(data, data_len);
*/
int foo201(int * data, int data_len, int array) {

		int i = 0, top = array - 1;
		
        /*@
          loop invariant array == \at(array, Pre);
          loop invariant data_len == \at(data_len, Pre);
          loop invariant data == \at(data, Pre);
          loop invariant unchanged_array{Pre, Here}(data, data_len);
          loop invariant 0 <= i <= top < array;
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
