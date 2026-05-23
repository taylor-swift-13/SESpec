

/*@
  requires \true;
  assigns \nothing;

  ensures \result != \null;
*/
const char * foo285(int n) {

  int count = 0;

  /*@
    loop invariant count >= 0;
    loop invariant 1 <= i;
    loop invariant count <= i - 1;
    loop assigns i, count;
  */
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      count++;
    }
  }

  if (count % 2 == 0) {
    return "Even";
  } else {
    return "Odd";
  }
}
