
/*@
  loop invariant (c <= \at(num,Pre)) ==> (result >= 0 && result <= c - 1);
  loop invariant (!(c <= \at(num,Pre))) ==> ((result == 0)&&(num == \at(num,Pre)));
  loop invariant num == \at(num,Pre);
  loop assigns c, result;
*/
