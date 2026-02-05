
/*@
    requires z>=0 && z<=10 && k>0 && k<=10;
    */
    
int main10(int z,int k){

    int x=1;
    int y=1;
    int c=1;
  
            
    /*@
      loop invariant (1 < \at(k,Pre)) ==> (1 + x*z - x - z*y == 0);
      loop invariant (1 < \at(k,Pre)) ==> (c >= 1 && c <= k);
      loop invariant (1 < \at(k,Pre)) ==> (y >= 0);
      loop invariant !(1 < \at(k,Pre)) ==> (c == 1 && y == 1 && x == 1 && k == \at(k,Pre) && z == \at(z,Pre));
      loop invariant k == \at(k,Pre);
      loop invariant z == \at(z,Pre);
      loop assigns c, x, y;
    */
    while (c < k){
       c = c + 1;
       x = x*z + 1;
       y = y*z;
    }
        
  
   /*@ assert 1+x*z-x-z*y==0; */
  }
