
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo248(int idBitLength, int material_length, int nlen) 

            /*@
            Require nlen == idBitLength / 32 && idBitLength >= 0 && material_length >= 0
            Ensure Results(__return)
            */
            {

    int j;
    int k;

    j = 0;


    while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
      }

    

  }