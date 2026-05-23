class SVCOMP_linear_0164__246 {
    /*@ 
      @ requires idBitLength >= 0 && material_length >= 0;
      @ 
      @ // After the method finishes, there exists a final counter value jj
      @ // such that all numbers < jj satisfied the loop condition
      @ // and the final jj is at least one of the bounds (i.e. jj == min(idBitLength/8, material_length)).
      @ ensures (\exists int jj;
      @            jj >= 0 &&
      @            (\forall int k; 0 <= k && k < jj ==> (k < idBitLength/8 && k < material_length)) &&
      @            (jj >= idBitLength/8 || jj >= material_length)
      @         );
      @*/
    static void foo246(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;

    /*@ 
      @ maintaining 0 <= j && j <= material_length && j <= idBitLength/8;
      @ maintaining (\forall int k0; 0 <= k0 && k0 < j ==> (k0 < idBitLength/8 && k0 < material_length));
      @ decreases material_length - j;
      @*/
    while((j < idBitLength / 8) && (j < material_length)){
    j = j + 1;
    }

    }
}