class SVCOMP_linear_0164__246 {
    //@ ensures idBitLength == \old(idBitLength) && material_length == \old(material_length) && nlen == \old(nlen);
    /*@ spec_public @*/ static void foo246(int idBitLength, int material_length, int nlen) {

int j;
int k;

j = 0;

//@ maintaining 0 <= j;
//@ maintaining j <= idBitLength / 8 && j <= material_length;
//@ decreases (idBitLength / 8 - j) + (material_length - j);
while((j < idBitLength / 8) && (j < material_length)){
j = j + 1;
}

}
}