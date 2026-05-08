int foo399(int n){

    int a=0;
    int s=1;
    int t=1;

    while(s <= n){
     a=a+1;
     t=t+2;
     s=s+t;
    }

    return a;
}
