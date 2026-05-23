/*@
    requires idBitLength >= 0;
    requires material_length >= 0;
    requires nlen >= 0;
    assigns \nothing;
    ensures \true;
*/
void foo246(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;

    /*@
        loop invariant 0 <= j <= idBitLength / 8;
        loop invariant 0 <= j <= material_length;
        loop assigns j;
        loop variant (idBitLength / 8) - j;
    */
    while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
    }

}
