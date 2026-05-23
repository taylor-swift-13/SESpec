
/*@
  requires array_len >= 0;
  requires array_len == 0 || \valid_read(array + (0 .. array_len - 1));
*/

int foo130(int search, int array[], int array_len) {

      int location = -1;
      int c;

      /*@
        loop invariant 0 <= c <= array_len;
        loop invariant location == -1 || (0 <= location < array_len && array[location] == search);
        loop assigns c, location;
        loop variant array_len - c;
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
