/*@
requires a >= 0 && b >= 0;
*/
int main14(int a,int b){
   
    int x=a;
    int y=b;
    int z=0;

    // loop body
    /*@
    loop invariant z + x * y == a * b;
    loop invariant x == a * (2 ^ (initial_y - y - number_of_iterations));
    loop invariant 0 <= y;
    loop assigns z;
    loop assigns y;
    loop assigns x;
    /*@;
    */
    while(y!=0) {
     
     if (y%2 ==1 ){
          z = z+x;
          y = y-1;
     }
     x = 2*x;
     y = y/2;
    }

    // @ assert z == a*b;
}
