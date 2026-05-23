/*@ 
  requires \true;
  assigns \nothing;
*/
int main14(int a,int b){

    int x=a;
    int y=b;
    int z=0;

    /*@ 
      loop invariant x == a * (1 << (\at(y,Pre) >= 0 ? 0 : 0)); 
      loop invariant \true;
      loop assigns x, y, z;
      loop variant y < 0 ? -y : y;
    */
    while(y!=0) {

     /*@ 
       assigns z, y;
     */
     if (y%2 ==1 ){
          z = z+x;
          y = y-1;
     }
     /*@ assigns x; */
     x = 2*x;
     /*@ assigns y; */
     y = y/2;
    }

}
