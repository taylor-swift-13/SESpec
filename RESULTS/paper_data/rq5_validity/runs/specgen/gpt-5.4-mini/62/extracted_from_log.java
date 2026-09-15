class SVCOMP_linear_0164__246 {
    //@ requires true;
    //@ ensures true;
static void foo246(int idBitLength, int material_length, int nlen) {

int j;
int k;

j = 0;
 
 
        //@ decreases ((idBitLength / 8) <= material_length ? (idBitLength / 8) : material_length) - j;
while((j < idBitLength / 8) && (j < material_length)){
j = j + 1;
}

}
}