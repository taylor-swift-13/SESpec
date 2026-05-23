int foo67_helper1_c142(int x);
int foo142(int x);


/*@
  assigns \nothing;
  ensures \result == (x % 2 != 0);
  ensures \result == 0 || \result == 1;
  ensures \result == 1 <==> x % 2 != 0;
*/
int foo142(int x) {

         	return x%2 != 0;
}