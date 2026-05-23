
/*@
  requires positions_len > 0;
  requires 0 <= array <= positions_len;
  requires \valid(positions + (0 .. positions_len - 1));
  assigns positions[0 .. positions_len - 1];
  ensures 1 <= \result <= array + 1;
  ensures \result == array + 1 <==> (\forall integer i; 0 <= i < array ==> positions[i] == i + 1);
  ensures 1 <= \result <= array ==> positions[\result - 1] != \result;
  ensures 1 <= \result <= array ==> (\forall integer i; 0 <= i < \result - 1 ==> positions[i] == i + 1);
  ensures \result == array + 1 ==> (\forall integer i; 0 <= i < array ==> positions[i] == i + 1);
*/
int foo160(int *positions, int positions_len, int array) {

  int ret = 0;

  /*@
    loop invariant 0 <= ret <= array;
    loop assigns ret, positions[0 .. positions_len - 1];
    loop variant array - ret;
  */
  while (ret < array) {
    if (positions[ret] <= 0 || positions[ret] > array
        || positions[ret] == ret + 1) {
      ret++;
    } else {
      int index = positions[ret];
      positions[ret] = positions[index - 1];
      positions[index - 1] = index;
    }
  }

  /*@
    loop invariant 0 <= ret <= array;
    loop invariant \forall integer i; 0 <= i < ret ==> positions[i] == i + 1;
    loop assigns ret;
    loop variant array - ret;
  */
  for (ret = 0; ret < array; ret++) {
    if (positions[ret] != ret + 1) {
      return ret + 1;
    }
  }

  return array + 1;
}
