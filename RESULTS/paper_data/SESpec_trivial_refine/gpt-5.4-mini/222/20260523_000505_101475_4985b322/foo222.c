
/*@
predicate odd_xor(int a, int b) = ((a ^ b) % 2) == 1;
*/

/*@
  requires 0 <= arr_len;
  requires arr_len == 0 || \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;
  ensures \result >= 0;
  ensures arr_len <= 1 ==> \result == 0;
  ensures n == \old(n);
  ensures arr_len == \old(arr_len);
*/
int foo222(int * arr, int arr_len, int n) {

  if (arr_len <= 1) {
    return 0;
  }

  int result = 0;
  int offset = arr_len;

  /*@
    loop invariant 0 <= index && index <= offset;
    loop invariant result >= 0;
    loop assigns result, index;
    loop variant offset - index;
  */
  for (int index = 0; index < offset; index++) {

    /*@
      loop invariant 0 <= index && index < offset;
      loop invariant index + 1 <= c && c <= offset;
      loop invariant result >= 0;
      loop assigns result, c;
      loop variant offset - c;
    */
    for (int c = index + 1; c < offset; c++) {
      if ((arr[index] ^ arr[c]) % 2 == 1) {
        result++;
      }
    }
  }

  return result;
}
