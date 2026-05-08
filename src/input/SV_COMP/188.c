int unknown();

void foo188(int x, int y) {

    while(unknown()){
       if(x >= 0 && y >= 0){
       x = x - 1;
      }
       else if(x < 0 && y >= 0){
       y = y - 1;
      }
       else if(y < 0){
       x = x + 1;
       y = y - 1;
      }
      }

  }
