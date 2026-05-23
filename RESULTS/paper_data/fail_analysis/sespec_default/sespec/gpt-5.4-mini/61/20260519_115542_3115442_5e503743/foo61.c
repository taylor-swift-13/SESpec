
/*@
  logic integer min_int(integer a, integer b) = a < b ? a : b;
*/

/*@ 
  predicate undef_data_at(int *p) = \true;
*/

void foo61(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;

    /*@
      loop invariant nlen == \at(nlen,Pre);
      loop invariant material_length == \at(material_length,Pre);
      loop invariant idBitLength == \at(idBitLength,Pre);
      loop assigns j;
    */
    while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
      }

  }
