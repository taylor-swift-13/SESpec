/* 2. FUNC CONTRACT */
int main17(int k){

    int y=0;
    int x=0;
    int c=0;

    /* 1. LOOP INVARIANT */
    while(c < k){
     c = c +1 ;
     y = y +1;
     x=y*y*y+x;
    }

}
