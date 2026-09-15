int main14(int a,int b){

    int x=a;
    int y=b;
    int z=0;

    /*@
    loop invariant x >= 0;
    loop invariant y >= 0;
    loop invariant z + x * y == a * b;
    loop invariant x * y + z == a * b;
    loop assigns x;
    loop assigns y;
    loop assigns z;
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
