
/*@
    requires i >= 1 && j >= 1 && i * i < j * j;
    */
    
void foo279(int i, int j) {

        /*@
          loop invariant (\at(i,Pre) < \at(j,Pre)) ==> (i >= 1 && j >= 1 && i <= j);
          loop invariant (\at(i,Pre) < \at(j,Pre)) ==> (i + j <= \at(i,Pre) + \at(j,Pre));
          loop invariant (!(\at(i,Pre) < \at(j,Pre))) ==> ((j == \at(j,Pre))&&(i == \at(i,Pre)));
          loop assigns i, j;
            */
            while (i < j) {
       j = j - i;
       if (j < i) {
       j = j + i;
       i = j - i;
       j = j - i;
      }
      }
            

    /*@ assert j == i; */

  }
