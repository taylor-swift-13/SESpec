
/*@
    requires r > i + j;
    */
    
void foo293(int i, int j, int r) {

    /*@
      loop invariant (\at(i,Pre) > 0) ==> (i + j == \at(i,Pre) + \at(j,Pre));
      loop invariant (\at(i,Pre) > 0) ==> (r > i + j);
      loop invariant (!(\at(i,Pre) > 0)) ==> ((r == \at(r,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)));
      loop invariant r == \at(r,Pre);
      loop assigns i, j;
    */
    while (i > 0) {
       i = i - 1;
       j = j + 1;
    }
            
    /*@ assert r > i + j; */
}
