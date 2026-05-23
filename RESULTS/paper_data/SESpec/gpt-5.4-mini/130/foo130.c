
/*@
  requires array_len >= 0;
  requires \valid_read(array + (0 .. array_len - 1));
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < array_len);
  ensures \result != -1 ==> array[\result] == search;
  ensures \result == -1 <==> (\forall integer k; 0 <= k < array_len ==> array[k] != search);
*/
int foo130(int search, int array[], int array_len) {

	      int location = -1;
        int c;

        
            
        /*@
          loop invariant 0 <= c <= array_len;
          loop invariant location == -1;
          loop invariant \forall integer k; 0 <= k < c ==> array[k] != search;
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
          loop invariant (c < array_len) ==> (location == -1);
          loop invariant (!(c < array_len)) ==> (c == array_len);

          
          loop invariant (!(c < array_len)) ==> (c == array_len);
          loop invariant \forall integer i; 0 <= i < array_len ==> array[i] == \at(array[i], Pre);
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
