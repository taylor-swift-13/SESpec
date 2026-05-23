#include <limits.h>

/*@ requires (0 <= j) && (0 <= j) && (0 <= j) && (j == 0 || (j > 0 && j <= idBitLength / 8 && j <= material_length)) && (((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre))) ==> (j <= idBitLength / 8 && j <= material_length)) && (((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre))) ==> (j >= 0)) && ((!((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre)))) ==> ((j == 0)&&(nlen == \at(nlen,Pre))&&(material_length == \at(material_length,Pre))&&(idBitLength == \at(idBitLength,Pre)))) && (nlen == \at(nlen,Pre)) && (material_length == \at(material_length,Pre)) && (idBitLength == \at(idBitLength,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int idBitLength, int j, int material_length, int nlen) {
    /*@ assert (0 <= j); */
}

/*@ requires (0 <= j);
    assigns \nothing;
*/
void check_B_implies_A(int idBitLength, int j, int material_length, int nlen) {
    /*@ assert (0 <= j); */
    /*@ assert (0 <= j); */
    /*@ assert (0 <= j); */
    /*@ assert (j == 0 || (j > 0 && j <= idBitLength / 8 && j <= material_length)); */
    /*@ assert (((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre))) ==> (j <= idBitLength / 8 && j <= material_length)); */
    /*@ assert (((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre))) ==> (j >= 0)); */
    /*@ assert ((!((0 < \at(idBitLength,Pre) / 8) && (0 < \at(material_length,Pre)))) ==> ((j == 0)&&(nlen == \at(nlen,Pre))&&(material_length == \at(material_length,Pre))&&(idBitLength == \at(idBitLength,Pre)))); */
    /*@ assert (nlen == \at(nlen,Pre)); */
    /*@ assert (material_length == \at(material_length,Pre)); */
    /*@ assert (idBitLength == \at(idBitLength,Pre)); */
}
