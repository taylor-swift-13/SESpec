/*@
    requires \valid_read(array + (0 .. \at(array.length, Pre) - 1));
    ensures (\result == -1) || (0 <= \result < \at(array.length, Pre));
    ensures (\result == -1) <==> (\forall integer i; 0 <= i < \at(array.length, Pre) ==> array[i] != search);
    ensures (\result != -1) ==> array[\result] == search;
    assigns \nothing;
*/
int linearSearch(int search, int array[]);

int linearSearch(int search, int array[]) {

	      int c;
      int location = -1;

        /*@
            loop invariant 0 <= c <= \at(array.length, Pre);
            loop invariant location == -1 || (0 <= location < c && array[location] == search);
            loop invariant location == -1 ==> (\forall integer i; 0 <= i < c ==> array[i] != search);
            loop assigns c, location;
            loop variant \at(array.length, Pre) - c;
        */
        for (c = 0; c < array.length; c++) {
          if (array[c] == search) {
	      location = c;
              break;
          }
        }
       if (c == array.length) {
            location = -1;
       }
     return location;
}
