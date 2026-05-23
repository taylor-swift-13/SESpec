
/*@ 
  predicate undef_data_at(int *p) = \true;
*/

/*@
  // Helper logic describing the desired exit property when sizes are positive.
  logic boolean verification_goal(integer j, integer idBitLength, integer material_length) =
    0 <= j && j <= idBitLength/8 && j <= material_length &&
    (j == idBitLength/8 || j == material_length);
*/

void foo235_c61(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant ((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre))) ==> (0 <= j && j <= \at(idBitLength,Pre) / 8 && j <= \at(material_length,Pre));
      loop invariant (!((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre)))) ==> (j == 0);
      loop invariant nlen == \at(nlen,Pre);
      loop invariant material_length == \at(material_length,Pre);
      loop invariant idBitLength == \at(idBitLength,Pre);
      loop assigns j;
    */
    while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
    }

}
