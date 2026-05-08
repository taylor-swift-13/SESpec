/*@
requires k>=0 && k<=30;
*/
int main19(int k){
   
    int y=0;
    int x=0;
    int c=0;

    // loop body
    while(c < k){
     c = c + 1 ;
     y = y + 1;
     x=y*y*y*y*y+x;
    }

    /*@ assert -2*(k*k*k*k*k*k) - 6*(k*k*k*k*k) - 5*(k*k*k*k) + (k*k) + 12*x == 0; */

}