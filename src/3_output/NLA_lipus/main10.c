
/*@
    requires z>=0 && z<=10 && k>0 && k<=10;
    */
    
int main10(int z,int k){

    int x=1;
    int y=1;
    int c=1;
  
        /*@
            loop invariant 1 <= c && c <= k;
            loop invariant (z != 1 ==> x == (z * c - 1) / (z - 1) + 1) && (z == 1 ==> x == c);
            loop invariant y == (c == 1 ? 1 : y * z);
            loop invariant k == \at(k, Pre);
            loop invariant z == \at(z, Pre);
        */
            while (c < k){
   c = c + 1;
   x = x*z + 1;
   y = y*z;
    }
            
  
   /*@ 1+x*z-x-z*y==0; */
}
