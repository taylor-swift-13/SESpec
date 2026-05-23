
        /*@
        */
        
void foo61(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant j >= 0;
          loop invariant j <= idBitLength / 8;
          loop invariant j <= material_length;
          loop assigns j;
            */
            while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
      }
            

  }
