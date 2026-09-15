int main14(int a,int b){

    int x=a;
    int y=b;
    int z=0;

    /*@
    loop invariant x >= 0;
    loop invariant y >= 0;
    loop invariant z >= 0;
    loop invariant x % 2 == 0 || y % 2 == 0;
    loop invariant z <= a * b || z >= a * b;
    loop invariant x * y <= a * b;
    loop invariant z + x * y == a * b;
    loop invariant z + x * y == a * b;
    loop invariant y == 0 || x * y + z == a * b;
    loop invariant x * y + z == a * b;
    loop invariant a <= x;
    loop invariant 0 <= z;
    loop invariant 0 <= y;
    loop invariant 0 <= x;
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
