class SVCOMP_linear_0164__246 {
//@ requires idBitLength >= 0 && material_length >= 0;
//@ assignable \nothing;
//@ ensures idBitLength == \old(idBitLength) && material_length == \old(material_length) && nlen == \old(nlen);
    /*@ spec_public @*/ static void foo246(int idBitLength, int material_length, int nlen) {

int j;
int k;

j = 0;

//@ maintaining 0 <= j && j <= idBitLength / 8 && j <= material_length;
//@ decreases ((idBitLength / 8 <= material_length ? idBitLength / 8 : material_length) - j);
while((j < idBitLength / 8) && (j < material_length)){
j = j + 1;
}

}
}