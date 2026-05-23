#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo62(int idBitLength, int material_length, int nlen) 
/*@

Require emp
Ensure emp
*/{

    int j;
    int k;

    j = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= j) &&
    (j <= ((idBitLength / 8 > 0 ? idBitLength / 8 : 0) + (material_length > 0 ? material_length : 0))) &&
    ((j <= idBitLength / 8) || (idBitLength / 8 <= 0)) &&
    ((j <= material_length) || (material_length <= 0)) &&
    ((exists (m:Z), 0 <= m && m <= ((idBitLength / 8 > 0 ? idBitLength / 8 : 0) + (material_length > 0 ? material_length : 0)) && j == m) || (j == idBitLength/8) || (j == material_length)) &&
    ((j >= idBitLength/8 && j >= material_length && idBitLength/8 >= 0 && material_length >= 0) => (j == (idBitLength/8 < material_length ? idBitLength/8 : material_length))) &&
    ((j >= idBitLength/8 && material_length <= 0 && idBitLength/8 >= 0) => (j == idBitLength/8)) &&
    ((j >= material_length && idBitLength/8 <= 0 && material_length >= 0) => (j == material_length)) &&
    (((0 < idBitLength@pre / 8) && (0 < material_length@pre)) => (PLACE_HOLDER_j)) &&
    (!((0 < idBitLength@pre / 8) && (0 < material_length@pre)) => ((j == 0) && (nlen == nlen@pre) && (material_length == material_length@pre) && (idBitLength == idBitLength@pre))) &&
    (nlen == nlen@pre) &&
    (material_length == material_length@pre) &&
    (idBitLength == idBitLength@pre)
    */
    
    while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
    }

  }