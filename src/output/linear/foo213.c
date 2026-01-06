
void foo213() {

    int invalid;
    int unowned;
    int nonexclusive;
    int exclusive;
    int RETURN;


    
        /*@
          loop invariant (nonexclusive + unowned > 0) ==> 
                         (invalid == 0 || exclusive == 0 || !\initialized(&invalid));
          loop assigns invalid, unowned, nonexclusive, exclusive, RETURN;
        */
            while(!((nonexclusive + unowned) >= 1 && invalid >= 1)) {
       if(invalid >= 1){
       if(unknown()){
       nonexclusive = nonexclusive + exclusive;
       exclusive = 0;
       invalid = invalid - 1;
       unowned = unowned + 1;
      }
       else{
       exclusive = 1;
       unowned = 0;
       nonexclusive = 0;
      }
      }
       else if((nonexclusive + unowned) >= 1){
       invalid = invalid + unowned + nonexclusive - 1;
       nonexclusive = 0;
       exclusive = exclusive + 1;
       unowned = 0;
      }
      }
            

  }
