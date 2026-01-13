
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        typedef struct __CheckCal
{
        int pkv[10];
        int len;
        int chksum;

} CheckCal;


void CheckCalFun(CheckCal *pIp)/*@
With pIp_pkv_l pIp_len pIp_chksum
Require store_int_array(pIp->pkv,10, pIp_pkv_l) && pIp->len == pIp_len && pIp->chksum == pIp_chksum
Ensure emp
*/
{
        int i = 0;
        int chksum = 0;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  pIp_pkv_l,    
    store_int_array(pIp->pkv, 10, pIp_pkv_l) &&
    (0 <= i && i <= pIp->len) &&
(chksum == \sum(0, i, pIp_pkv))
    */
    
    for (; i < pIp->len; i++){
        chksum = chksum + pIp_pkv[i];
    }
        
        pIp->chksum = chksum;

}
void foo(CheckCal *pIp)

/*@
With pIp_pkv_l pIp_len pIp_chksum
Require store_int_array(pIp->pkv,10, pIp_pkv_l) && pIp->len == pIp_len && pIp->chksum == pIp_chksum
Ensure emp
*/{

    pIp->len = 3;
    CheckCalFun(pIp);

}