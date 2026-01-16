//svcomp_id_trans
/*@
  requires nlen == idBitLength / 32;
  requires idBitLength >= 0;
  requires material_length >= 0;
*/
int hoo20(int idBitLength,int material_length,int nlen){
    int j = 0;

    //pre-condition

    //loop-body
    /*@
    loop invariant j <= material_length;
    loop invariant j <= idBitLength / 8;
    loop invariant 0 <= j;
    loop invariant (j / 4) <= nlen;
    loop assigns j;
    */
    while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
    }

    //post-condition
    /*@ assert (j / 4) <= nlen; */
}