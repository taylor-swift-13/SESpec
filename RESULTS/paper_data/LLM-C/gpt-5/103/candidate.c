/*@ 
  requires \true;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures (\result != 0) <=> (\exists integer k; n == 2*k);
*/
int divisorGame(int n);

 /*@ 
   requires \true;
   assigns \nothing;
   ensures \result == 0 || \result == 1;
   ensures (\result != 0) <=> (\exists integer k; n == 2*k);
 */
int divisorGame(int n) {

        return n % 2 == 0;
}
