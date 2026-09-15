int isCommonFactor(int a, int b, int factor);

/*@ 
  requires factor != 0;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures (\result != 0) <==> ((a % factor == 0) && (b % factor == 0));
  terminates \true;
*/
int isCommonFactor(int a, int b, int factor) {

        return a % factor == 0 && b % factor == 0;
}
