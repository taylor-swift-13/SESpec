
/*@ 
  predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION = \true;
*/

/*@
  predicate PLACE_HOLDER_j = \true;
*/

void foo62(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;

    /*@
      loop invariant 0 <= j;
      loop invariant j <= ((idBitLength / 8 > 0 ? idBitLength / 8 : 0) + (material_length > 0 ? material_length : 0));
      loop invariant (j <= idBitLength / 8) || (idBitLength / 8 <= 0);
      loop invariant (j <= material_length) || (material_length <= 0);
      loop invariant (\exists integer m; 0 <= m && m <= ((idBitLength / 8 > 0 ? idBitLength / 8 : 0) + (material_length > 0 ? material_length : 0)) && j == m)
                     || (j == idBitLength/8) || (j == material_length);
      loop invariant (j >= idBitLength/8 && j >= material_length && idBitLength/8 >= 0 && material_length >= 0) ==> (j == (idBitLength/8 < material_length ? idBitLength/8 : material_length));
      loop invariant (j >= idBitLength/8 && material_length <= 0 && idBitLength/8 >= 0) ==> (j == idBitLength/8);
      loop invariant (j >= material_length && idBitLength/8 <= 0 && material_length >= 0) ==> (j == material_length);
      loop invariant ((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre))) ==> (PLACE_HOLDER_j);
      loop invariant !((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre))) ==>
                     ((j == 0) && (nlen == \at(nlen,Pre)) && (material_length == \at(material_length,Pre)) && (idBitLength == \at(idBitLength,Pre)));
      loop invariant nlen == \at(nlen,Pre);
      loop invariant material_length == \at(material_length,Pre);
      loop invariant idBitLength == \at(idBitLength,Pre);
      loop assigns j;
    */
    while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
    }
}
