int main14(int a,int b){

    int x=a;
    int y=b;
    int z=0;

    while(y!=0) {

     if (y%2 ==1 ){
          z = z+x;
          y = y-1;
     }
     x = 2*x;
     y = y/2;
    }

}
