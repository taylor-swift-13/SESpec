
/*@ logic integer pow2(integer n) = (n <= 0 ? 1 : 2 * pow2(n - 1)); */

void foo85(int a,int b){

    int x=a;
    int y=b;
    int z=0;

    /*@
      loop invariant (\at(b,Pre)!=0) ==> (b == \at(b,Pre));
      loop invariant (\at(b,Pre)!=0) ==> (a == \at(a,Pre));
      loop invariant (!(\at(b,Pre)!=0)) ==> ((z == 0)&&(y == \at(b,Pre))&&(x == \at(a,Pre))&&(b == \at(b,Pre))&&(a == \at(a,Pre)));
      loop invariant b == \at(b,Pre);
      loop invariant a == \at(a,Pre);
      loop assigns z, y, x;
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
