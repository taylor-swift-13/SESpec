
/*@
  assigns location;
  ensures (0 <= \result < array.length && array[\result] == search) || (\result == -1);
  ensures (\result == -1) ==> (location == -1);
  ensures (0 <= \result < array.length && array[\result] == search) ==> (location == \result);
*/
int foo53(int search, int array[]) {

	      int c;

        
            
        /*@
          loop invariant 0 <= c <= array.length;
          loop invariant (!(c < array.length)) ==> ();
          loop invariant PLACE_HOLDER_ARRAY_array ;
          loop assigns c, location;
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
