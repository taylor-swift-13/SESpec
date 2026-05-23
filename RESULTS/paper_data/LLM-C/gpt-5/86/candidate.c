/*@ 
  requires \true;
  assigns \nothing;
*/
int main16(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
      loop assigns c, y, x;
      loop invariant c >= 0;
      loop invariant y == c;
      loop invariant c <= k;
      loop variant k - c;
    */
    while(c < k){
     c = c + 1;
     y = y + 1;
     x = y * y + x;
    }

}
