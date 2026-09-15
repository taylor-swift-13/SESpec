/*@
    requires \true;
    assigns \nothing;
    ensures \true;
*/
void foo246(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;

    /*@
        loop invariant 0 <= j;
        loop invariant (material_length > 0) ==> j <= material_length;
        loop invariant (idBitLength / 8 > 0) ==> j <= idBitLength / 8;
        loop assigns j;
        loop variant ( (material_length > 0 ? material_length - j : 0) + (idBitLength / 8 > 0 ? idBitLength / 8 - j : 0) );
    */
    while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
      }

  }
