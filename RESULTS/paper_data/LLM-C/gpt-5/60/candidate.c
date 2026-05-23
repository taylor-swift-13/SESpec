/*@ logic integer min_int(integer a, integer b) = (a <= b ? a : b); */

/*@ 
  requires idBitLength >= 0;
  requires material_length >= 0;
  assigns \nothing;
  ensures j == min_int(idBitLength / 8, material_length);
*/
void foo246(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;

    /*@ 
      loop invariant 0 <= j <= min_int(idBitLength / 8, material_length);
      loop assigns j;
      loop variant min_int(idBitLength / 8, material_length) - j;
    */
    while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
      }

  }
