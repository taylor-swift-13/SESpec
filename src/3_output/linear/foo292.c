
/*@
    requires i < j && k > 0;
    */
    
void foo292(int i, int j, int k) {

        /*@
          loop invariant (\at(i,Pre) < \at(j,Pre)) ==> (k - i == \at(k,Pre) - \at(i,Pre));
          loop invariant (\at(i,Pre) < \at(j,Pre)) ==> (k == \at(k,Pre) + (i - \at(i,Pre)));
          loop invariant (!(\at(i,Pre) < \at(j,Pre))) ==> ((k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)));
          loop invariant j == \at(j,Pre);
          loop assigns k, i;
        */
        while (i < j) {
            k = k + 1;
            i = i + 1;
        }

    /*@ assert k > j - i; */
}
