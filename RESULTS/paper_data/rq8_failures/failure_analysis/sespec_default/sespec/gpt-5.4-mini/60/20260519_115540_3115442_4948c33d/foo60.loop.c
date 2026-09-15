
/*@
  logic integer abs_int(integer x) = x < 0 ? -x : x;
*/

void foo60(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant ((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre))) ==> (0 <= j <= \at(idBitLength,Pre) / 8 && 0 <= j <= \at(material_length,Pre));
          loop invariant ((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre))) ==> (j == 0 || j > 0);
          loop invariant (!((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre)))) ==> ((j == 0)&&(nlen == \at(nlen,Pre))&&(material_length == \at(material_length,Pre))&&(idBitLength == \at(idBitLength,Pre)));
          loop invariant nlen == \at(nlen,Pre);
          loop invariant material_length == \at(material_length,Pre);
          loop invariant idBitLength == \at(idBitLength,Pre);
          loop assigns j;
            */
            while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
      }
            

  }
