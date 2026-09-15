
/*@
  logic integer max(int* array, integer begin, integer end) =
    end <= begin ? array[begin] : (max(array, begin, end - 1) > array[end - 1] ? max(array, begin, end - 1) : array[end - 1]);

  logic integer second_max(int* array, integer begin, integer end) =
    end <= begin + 1 ? array[begin] : 
    (max(array, begin, end - 1) == array[end - 1] ? second_max(array, begin, end - 1) : 
    (array[end - 1] > second_max(array, begin, end - 1) ? array[end - 1] : second_max(array, begin, end - 1)));
*/

/*@
  requires \valid(arg + (0 .. arg_len - 1));
  requires arg_len > 0 && arg_len < 100;
  assigns \nothing;
*/
int foo158(int * arg, int arg_len) {

    int g = 0;
    int ret = arg[0];

    /*@
      loop invariant 1 <= j <= arg_len;
      loop invariant ret == max(arg, 0, j);
      loop invariant arg_len == \at(arg_len,Pre);
      loop invariant \forall integer k; 0 <= k < arg_len ==> arg[k] == \at(arg[k],Pre);
      loop assigns j, g, ret;
      loop variant arg_len - j;
    */
    for (int j = 1; j < arg_len; j++) {
        if (arg[j] > ret) {
            g = g > ret ? g : ret;
            ret = arg[j];
        } else {
            g = g > arg[j] ? g : arg[j];
        }
    }

    return g;
}
