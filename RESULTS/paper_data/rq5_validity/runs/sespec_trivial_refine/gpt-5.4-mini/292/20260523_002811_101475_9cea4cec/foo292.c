
/*@
*/

/*@
  loop invariant 2 <= count <= seed + 1;
  loop invariant p[0] == 0 && p[1] == 1;
  loop invariant \forall integer i; 2 <= i < count ==> p[i] == (2 * p[i - 1] + p[i - 2]) % 1000000000;
  loop assigns count, p[2 .. seed];
*/
for (int count = 2; count <= seed; count++) {
    p[count] = (2 * p[count - 1] + p[count - 2]) % 1000000000;
}

