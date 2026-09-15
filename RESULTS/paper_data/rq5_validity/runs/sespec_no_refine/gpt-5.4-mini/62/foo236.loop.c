
/*@ predicate undef_data_at(integer *p) = \true; */

void foo236(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;

    /*@
      loop invariant 0 <= j;
      loop invariant ((0 < idBitLength / 8) && (0 < material_length)) ==> (j <= idBitLength / 8 && j <= material_length);
      loop invariant (!((0 < idBitLength / 8) && (0 < material_length))) ==> ((j == 0)&&(nlen == nlen)&&(material_length == material_length)&&(idBitLength == idBitLength));
      loop invariant nlen == nlen;
      loop invariant material_length == material_length;
      loop invariant idBitLength == idBitLength;
      loop assigns j;
    */
    while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
    }

}
