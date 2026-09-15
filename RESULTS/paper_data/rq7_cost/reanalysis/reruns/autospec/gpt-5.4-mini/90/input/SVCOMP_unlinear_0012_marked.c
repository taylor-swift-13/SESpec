/* 2. FUNC CONTRACT */
int main2(int x,int y){

  int q=0;
  int r=0;

  /* 1. LOOP INVARIANT */
  while(x > y * q + r) {
      if (r == y - 1){
          r = 0;
          q += 1;
      }
      else{
          r += 1;
      }

  }

}
