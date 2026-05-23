
/*@
  assigns \nothing;
  ensures number <= 0 ==> \result == 0;
  ensures number > 0 ==> \result >= 1;
*/
int foo374(int number) {
    int div = 0;
    int c = 1;

    /*@
      loop invariant c >= 1;
      loop invariant number <= 0 ==> (c == 1 && div == 0);
      loop invariant number > 0 ==> c <= number + 1;
      loop invariant number > 0 ==> div >= (c > 1 ? 1 : 0);
      loop assigns c, div;
      loop variant number > 0 ? number - c + 1 : 0;
    */
    while (c <= number) {
        if (c == 1 || number % c == 0) {
            div++;
        }
        c++;
    }

    return div;
}
