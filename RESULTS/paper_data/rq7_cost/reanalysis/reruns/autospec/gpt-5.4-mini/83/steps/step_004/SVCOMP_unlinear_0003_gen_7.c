/*@ 
    requires c */ 
int main11(int z,int k,int a){

    int x=a;
    int y=1;
    int c=1;

    /*@
        loop invariant 1 <= c <= k + 1;
        loop invariant x == a * (1 + z + (c - 2 >= 0 ? 1 : 0));
        loop invariant y == 1;
        loop assigns c, x, y;
        loop variant k - c;
    */
    while (c < k){
        c = c + 1;
        x = x*z + a;
        y = y*z;
    }

}