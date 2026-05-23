
/*@ 
  ensures (0 <= \result < array.length) ==> array[\result] == search;
  ensures (\result == -1) ==> (\forall integer i; 0 <= i < array.length ==> array[i] != search);
*/
int foo53(int search, int array[]) {

	      int c;

        
            
            /*@
          loop invariant 0 <= c <= array.length;
          loop invariant (!(c < array.length)) ==> (location == -1);
          loop invariant \forall integer i; 0 <= i < c ==> array[i] != search;
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
