
/*@
  logic integer max(int* array, integer begin, integer end) =
    end <= begin ? array[begin] : (max(array, begin, end - 1) > array[end - 1] ? max(array, begin, end - 1) : array[end - 1]);

  logic integer second_max(int* array, integer begin, integer end) =
    end <= begin + 1 ? array[begin] : 
    (max(array, begin, end - 1) == array[end - 1] ? second_max(array, begin, end - 1) : 
    (array[end - 1] > second_max(array, begin, end - 1) ? array[end - 1] : second_max(array, begin, end - 1)));
*/

/*@
  requires \at(arg_len,Pre) > 0 && \at(arg_len,Pre) < 100;
  ensures g == second_max(arg, 0, arg_len);
*/
int foo158(int * arg, int arg_len) {

    int g = 0;
    int ret = arg[0];

    /*@
      loop invariant 1 <= j <= \at(arg_len,Pre);
      loop invariant g == second_max(arg, 0, j);
      loop invariant ret == max(arg, 0, j);
      loop invariant arg_len == \at(arg_len,Pre);
      loop invariant arg == \at(arg,Pre);
      loop invariant \forall integer k; 0 <= k < \at(arg_len,Pre) ==> arg[k] == \at(arg[k],Pre);
      loop assigns j, g, ret;
    */
    for (int j = 1; j < arg_len; j++) {
        if (arg[j] > ret) {
            g = g > ret ? g : ret;
        } else {
            ret = arg[j];
        }
    }

    return g;
}
