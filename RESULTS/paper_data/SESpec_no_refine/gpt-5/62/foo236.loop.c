
/*@
  logic integer min_int(integer a, integer b) = a <= b ? a : b;
*/

void foo236(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;

    /*@
      loop invariant 0 <= j;
      loop invariant nlen == \at(nlen,Pre);
      loop invariant material_length == \at(material_length,Pre);
      loop invariant idBitLength == \at(idBitLength,Pre);
      loop assigns j;
    */
    while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
    }

}
