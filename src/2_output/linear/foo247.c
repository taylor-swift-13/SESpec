
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo247(int idBitLength, int material_length, int nlen) 

            /*@
            Require nlen == idBitLength / 32 && idBitLength >= 0 && material_length >= 0
            Ensure Results(__return)
            */
            {

    int j;
    int k;

    j = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((0 < idBitLength@pre / 8) && (0 < material_length@pre)) => 
            (0 <= j && j <= idBitLength@pre/8 && j <= material_length@pre)) &&
((!((0 < idBitLength@pre / 8) && (0 < material_length@pre))) => 
            ((j == 0)&&(nlen == nlen@pre)&&(material_length == material_length@pre)&&(idBitLength == idBitLength@pre))) &&
(nlen == nlen@pre) &&
(material_length == material_length@pre) &&
(idBitLength == idBitLength@pre
          loop assigns j)
    */
    
            while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
      }

    

  }