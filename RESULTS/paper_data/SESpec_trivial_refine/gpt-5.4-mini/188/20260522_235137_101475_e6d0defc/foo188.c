
/*@
*/

/*@
  loop invariant 1 <= c <= size;
  loop invariant \forall integer i; 0 <= i < c ==> f <= a[i];
  loop invariant \exists integer i; 0 <= i < c && f == a[i];
  loop invariant max >= 1;
  loop assigns c, f, max;
*/
