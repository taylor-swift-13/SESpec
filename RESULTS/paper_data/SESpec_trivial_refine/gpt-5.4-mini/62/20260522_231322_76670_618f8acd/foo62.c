
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/
        
void foo62(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant 0 <= j;
      loop assigns j;
    */
    while((j < idBitLength / 8) && (j < material_length)){
        j = j + 1;
    }

}
