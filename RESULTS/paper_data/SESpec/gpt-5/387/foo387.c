


/*@
  assigns \nothing;
  ensures c == \at(c,Pre);
  ensures \at(r,Pre) <= 0 ==> (\result == 0 && r == \at(r,Pre) && num == \at(num,Pre));
  ensures \at(r,Pre) > 0 ==> \true;
*/
int foo387(int num, int c, int r) {

    int ret = 0;

    /*@
      loop invariant c == \at(c,Pre);
      loop invariant (r == \at(r,Pre)) ==> (ret == 0 && num == \at(num,Pre));
      loop invariant (\at(r,Pre) > 0) ==> ( (r == \at(r,Pre)) ==> (num == \at(num,Pre)) );
      loop invariant (\at(r,Pre) > 0) ==> (0 <= r && r <= \at(r,Pre));
      loop invariant (\at(r,Pre) > 0) ==> ( (r == \at(r,Pre)) ==> (ret == 0) );
      loop invariant (!(\at(r,Pre) > 0)) ==> ((ret == 0)&&(r == \at(r,Pre))&&(c == \at(c,Pre))&&(num == \at(num,Pre)));
      loop invariant c == \at(c,Pre);
      loop assigns r, num, ret;
    */
    while (r > 0) {
        r -= 1;
        num *= 10;
        ret = num / c;
        num %= c;
    }

    return ret;
}
