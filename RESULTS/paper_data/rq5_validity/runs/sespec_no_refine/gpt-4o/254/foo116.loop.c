Here is the complete C code with the placeholders filled:

```c
/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  logic integer min_value(int* array, integer begin, integer end) =
    end <= begin ? 2147483647 : \min(array[end - 1], min_value(array, begin, end - 1));
*/

/*@
  logic integer max_value(int* array, integer begin, integer end) =
    end <= begin ? -2147483648 : \max(array[end - 1], max_value(array, begin, end - 1));
*/

int foo116(int * array, int array_len, int start, int end) {

        int min = start;
        int max = end;
        int mid;

        /*@
          loop invariant (\at(start,Pre) <= \at(end,Pre)) ==> (((max == \at(end,Pre))&&(min == \at(start,Pre))&&(end == \at(end,Pre))&&(start == \at(start,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre))) || (min_value(array