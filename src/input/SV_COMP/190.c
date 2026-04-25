int unknown();

void foo190(int x, int z) {

    while(x < 100 && z > 100){
       if(unknown()){
       x = x + 1;
      }
       else{
       x = x - 1;
       z = z - 1;
      }
      }

  }
