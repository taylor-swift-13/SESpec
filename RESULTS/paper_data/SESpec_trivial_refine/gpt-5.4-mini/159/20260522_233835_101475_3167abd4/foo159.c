
/*@
  requires 0 <= array <= args_len;
  requires \valid(args + (0 .. args_len - 1));
  assigns args[0 .. array - 1];
  ensures 1 <= \result <= array + 1;
  ensures \result == array + 1 <==> \forall integer i; 0 <= i < array ==> args[i] == i + 1;
  ensures \result <= array ==> 0 <= \result - 1 < array;
  ensures \result <= array ==> args[\result - 1] != \result;
  ensures \result <= array ==> \forall integer i; 0 <= i < \result - 1 ==> args[i] == i + 1;
*/
int foo159(int *args, int args_len, int array) {
    int ret = 0;

    /*@
      loop invariant 0 <= ret <= array;
      loop invariant \forall integer i; 0 <= i < ret ==> (args[i] == i + 1 || args[i] <= 0 || args[i] > array);
      loop assigns ret, args[0 .. array - 1];
      loop variant array - ret;
    */
    while (ret < array) {
        if (args[ret] <= 0 || args[ret] > array || args[ret] == ret + 1) {
            ret++;
        } else {
            int j = args[ret];
            args[ret] = args[j - 1];
            args[j - 1] = j;
        }
    }

    /*@
      loop invariant 0 <= ret <= array;
      loop invariant \forall integer i; 0 <= i < ret ==> args[i] == i + 1;
      loop assigns ret;
      loop variant array - ret;
    */
    for (ret = 0; ret < array; ret++) {
        if (args[ret] != ret + 1) {
            return ret + 1;
        }
    }

    return array + 1;
}
