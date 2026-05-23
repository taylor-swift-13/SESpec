
/*@
  assigns \nothing;
  ensures diff == \at(diff,Pre);
*/
int foo329(int diff) {

    int ret = 0;
    int max = 0;

    /*@
      loop invariant 1 <= j;
      loop invariant 0 <= ret;
      loop invariant j == 1 ==> ret == 0;
      loop invariant j >= 2 ==> ret >= 1;
      loop invariant j >= 2 ==> ret >= (j-1)*(j-1)*(j-1);
      loop invariant diff == \at(diff,Pre);
      loop invariant max == 0;
      loop assigns j, ret;
    */
    for (int j = 1; j <= diff; j++) {
        ret += j * j * j;
    }

    /*@
      loop invariant 1 <= j;
      loop invariant 0 <= max;
      loop invariant j == 1 ==> max == 0;
      loop invariant j >= 2 ==> max >= 1;
      loop invariant diff == \at(diff,Pre);
      loop invariant j >= 2 ==> max >= (j-1);
      loop invariant j >= 2 ==> max >= (j*(j-1))/2;
      loop invariant (j <= diff) ==> (j <= \at(diff,Pre));
      loop assigns j, max;
    */
    for (int j = 1; j <= diff; j++) {
        max += j;
    }

    return ret - max;
}
