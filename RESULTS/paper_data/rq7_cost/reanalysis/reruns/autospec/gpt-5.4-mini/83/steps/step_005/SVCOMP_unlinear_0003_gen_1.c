int main11(int z,int k,int a){

    int x=a;
    int y=1;
    int c=1;

    /*@
      loop invariant 1 <= c <= k + 1;
      loop invariant y == \pow(z, c - 1);
      loop invariant x == a * \sum(0, c - 2, \lambda integer i; \pow(z, i)) + a * \pow(z, c - 1);
      loop assigns c, x, y;
      loop variant k - c;
    */
    while (c < k){
   c = c + 1;
   x = x*z + a;
   y = y*z;
    }

  }