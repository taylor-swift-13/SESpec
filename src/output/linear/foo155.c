
void foo155() {
    int j;
    int k;
    int t;

    j = 2;
    k = 0;

    /*@
      loop invariant (t == 0 ==> j == 2 + 4*(j-2)/4) && 
             (t != 0 ==> j == 2 + 2*k);
      loop invariant k >= 0;
      loop invariant (k == 0) || (t != 0);
      loop assigns j, k;
    */
    while(unknown()){
        if (t == 0){
            j = j + 4;
        }
        else {
            j = j + 2;
            k = k + 1;
        }
    }

    /*@ assert (k != 0) ==> (t != 0 && j == k * 2 + 2); */
}
