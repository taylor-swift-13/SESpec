
/*@
    requires nlen == idBitLength / 32 && idBitLength >= 0 && material_length >= 0;
    */
    
void foo247(int idBitLength, int material_length, int nlen) {

    int j;
    int k;

    j = 0;


    
            /*@
          loop invariant ((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre))) ==> 
            (0 <= j <= \at(idBitLength,Pre)/8 && j <= \at(material_length,Pre));
          loop invariant (!((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre)))) ==> 
            ((j == 0)&&(nlen == \at(nlen,Pre))&&(material_length == \at(material_length,Pre))&&(idBitLength == \at(idBitLength,Pre)));
          loop invariant nlen == \at(nlen,Pre);
          loop invariant material_length == \at(material_length,Pre);
          loop invariant idBitLength == \at(idBitLength,Pre);
          loop assigns j;
            */
            while((j < idBitLength / 8) && (j < material_length)){
       j = j + 1;
      }
            

    /*@ assert j <= material_length; */

  }
