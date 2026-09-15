
/*@ 
*/

/*@
  loop invariant count >= 0;
  loop invariant temp == (n >> count);
  loop assigns count, res, temp;
*/
while (temp > 0) {
    if (count % 2 == 1) {
        res |= (1 << count);
    }
    count++;
    temp >>= 1;
}
