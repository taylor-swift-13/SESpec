int main14(int a,int b){

    int x=a;
    int y=b;
    int z=0;

    /*@
    loop invariant y >= 0;
    loop invariant x >= a;
    loop invariant z <= a * b;
    loop invariant y == 0 || z + x * y == a * b;
    loop invariant y == 0 || x * y + z == a * b;
    loop invariant a * b == x * y + z;
    loop invariant x >= 0;
    loop invariant z >= 0;
    loop invariant z >= 0 || z <= a * b;
    loop invariant z == a * b - x * y;
    loop invariant z <= a * b || z >= a * b;
    loop invariant z + x * y == a * b;
    loop invariant y == 0 || z + x * y == a * b;
    loop invariant y == 0 || x * y + z == a * b;
    loop invariant y == 0 || (x * y + z == a * b);
    loop invariant y <= b;
    loop invariant y < b;
    loop invariant y % 2 == 0 || y % 2 == 1;
    loop invariant x >= a || y >= 0;
    loop invariant x >= a || x <= a;
    loop invariant x == a * (1 << 0) || x == a;
    loop invariant x == 0 || y == 0 || z <= a * b;
    loop invariant x * y <= a * b;
    loop invariant x * y + z == a * b;
    loop invariant x % 2 == 0 || y % 2 == 0;
    loop invariant a <= x;
    loop invariant a <= x || b <= y;
    loop invariant a * b == x * y + z;
    loop invariant 0 <= z;
    loop invariant 0 <= y;
    loop invariant 0 <= x;
    loop invariant (y == 0) || (x <= a * b || z <= a * b);
    loop invariant (y % 2 == 0) || (y % 2 == 1);
    loop assigns z;
    loop assigns y;
    loop assigns x;
    */
    while(y!=0) {

     if (y%2 ==1 ){
          z = z+x;
          y = y-1;
     }
     x = 2*x;
     y = y/2;
    }

}
