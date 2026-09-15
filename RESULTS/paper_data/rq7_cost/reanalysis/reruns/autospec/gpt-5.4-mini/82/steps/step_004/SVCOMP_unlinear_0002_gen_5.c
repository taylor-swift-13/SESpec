int main10(int z,int k){

    int x=1;
    int y=1;
    int c=1;

    /*@
    loop invariant 1 <= c <= k + 1;
    loop invariant x >= 1;
    loop invariant y >= 1;
    loop invariant x >= y;
    loop invariant c - 1 <= k;
    loop invariant x - y == 1;
    loop invariant x == y + 1;
    loop invariant z == 0 ==> y == 0 || y == 1;
    loop invariant y == z^(c-1);
    loop invariant y == z * (y / z);
    loop invariant y == 1;
    loop invariant y == 1 ==> c == 1;
    loop invariant y <= x;
    loop invariant x >= 1 && y >= 1;
    loop invariant x == y + c;
    loop invariant x == y + 1;
    loop invariant x == y + (c-1);
    loop invariant x == (z^(c-1) - 1) / (z - 1) + 1;
    loop invariant x == (y - 1) / (z - 1) + 1;
    loop invariant x - y == c - 1;
    loop invariant x - y == 1;
    loop invariant c > 1 ==> x > y;
    loop invariant c == 1 ==> x == 1 && y == 1;
    loop invariant c <= k;
    loop invariant c <= k + 1;
    loop invariant c - 1 <= k;
    loop invariant 1 <= y;
    loop invariant 1 <= x;
    loop invariant 1 <= c;
    loop invariant 0 <= c - 1;
    loop assigns y;
    loop assigns x;
    loop assigns c;
    */
    while (c < k){
   c = c + 1;
   x = x*z + 1;
   y = y*z;
    }

  }
