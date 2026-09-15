
/*@
  logic integer square_of(integer x) = x * x;
*/

/*@
  requires n >= 1;
  ensures \result == square_of(\result - 1);
*/
int foo313(int n) {

    int i = 1;
    int square = 1;

    /*@
      loop invariant (1 <= \at(n,Pre)) ==> (((square == 1)&&(i == 1)&&(n == \at(n,Pre))) || (square == square_of(i - 1)));
      loop invariant (!(1 <= \at(n,Pre))) ==> ((square == 1)&&(i == 1)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns square, i;
    */
    while (square <= n) {
        square = i * i;
        i++;
    }

    return square;
}
