int main10(int z,int k){

    int x=1;
    int y=1;
    int c=1;

    /*@
    loop invariant 1 <= c <= k;
    loop invariant y == z^(c-1);
    loop invariant x == (y - 1) / (z - 1) + 1;
    loop assigns c;
    loop assigns x;
    loop assigns y;
    */
    while (c < k){
   c = c + 1;
   x = x*z + 1;
   y = y*z;
    }

  }
