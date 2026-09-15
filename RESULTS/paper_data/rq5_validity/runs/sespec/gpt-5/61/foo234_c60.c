
/*@
  predicate PLACE_HOLDER_VERFICATION_GOAL(int j, integer idBitLength_pre, integer material_length_pre) =
    0 <= j <= idBitLength_pre / 8 && 0 <= j <= material_length_pre;
*/

/*@
  predicate PLACE_HOLDER_j(int j, integer idBitLength_pre, integer material_length_pre) =
    0 <= j && j <= idBitLength_pre / 8 && j <= material_length_pre;
*/

void foo234_c60(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;

    /*@
      loop invariant 0 <= j;
      loop invariant (idBitLength / 8 > 0) ==> (j <= idBitLength / 8);
      loop invariant (material_length > 0) ==> (j <= material_length);
      loop invariant ((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre))) ==> (PLACE_HOLDER_VERFICATION_GOAL(j, \at(idBitLength,Pre), \at(material_length,Pre)));
      loop invariant ((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre))) ==> (PLACE_HOLDER_j(j, \at(idBitLength,Pre), \at(material_length,Pre))) ;
      loop invariant (!((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre)))) ==> ((j == 0)&&(nlen == \at(nlen,Pre))&&(material_length == \at(material_length,Pre))&&(idBitLength == \at(idBitLength,Pre)));
      loop invariant nlen == \at(nlen,Pre);
      loop invariant material_length == \at(material_length,Pre);
      loop invariant idBitLength == \at(idBitLength,Pre);
      loop assigns j;
    */
    while((j < idBitLength / 8) && (j < material_length)){
        j = j + 1;
    }

}
