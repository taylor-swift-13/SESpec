void foo248(int idBitLength, int material_length, int nlen) {
    /*@ 
      requires idBitLength >= 0;
      requires material_length >= 0;
      assigns \nothing;
      ensures \true;
    */

    int j;
    int k;

    j = 0;

    /*@
      loop invariant 0 <= j;
      loop invariant j <= idBitLength / 8;
      loop invariant j <= material_length;
      loop assigns j;
      loop variant (idBitLength/8 < material_length ? (idBitLength/8 - j) : (material_length - j));
    */
    while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
      }

  }
