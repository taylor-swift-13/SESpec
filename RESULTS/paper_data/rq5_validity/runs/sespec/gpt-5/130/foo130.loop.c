


int foo130(int search, int array[], int array_len) {

  int location = -1;
  int c;

  /*@
    loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
    loop invariant location == -1 || (0 <= location < c && array[location] == search);
    loop invariant \forall integer k; 0 <= k < c ==> array[k] != search;
    loop invariant location == -1 ==> \forall integer k; 0 <= k < c ==> array[k] != search;
    loop invariant location != -1 ==> (array[location] == search && 0 <= location < c);
    loop invariant c == 0 ==> location == -1;
    loop invariant (c < array_len) ==> (c >= 0 && c < array_len);
    loop invariant (!(c < array_len)) ==> (c >= array_len);
    loop assigns c, location;
  */
  for (c = 0; c < array_len; c++) {
    if (array[c] == search) {
      location = c;
      break;
    }
  }

  if (c == array_len) {
    location = -1;
  }
  return location;
}
