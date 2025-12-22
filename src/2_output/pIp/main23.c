
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        typedef struct __CheckCal
{

	int		len;
	int		*pkv;
	int     chksum;
	
} CheckCal;

void main23(CheckCal *pIp)

/*@
With pIp_len pIp_pkv_v pIp_pkv pIp_chksum
Require pIp->len == pIp_len && *(pIp->pkv) == pIp_pkv_v && (pIp->pkv) == pIp_pkv && pIp->chksum == pIp_chksum
Ensure emp
*/{

	int i = 0;
	int chksum = 0;


 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < pIp@pre->len) => (0 <= i && i <= pIp@pre->len)) &&
((0 < pIp@pre->len) => (chksum == sum(pIp->pkv, 0, i))) &&
((!(0 < pIp@pre->len)) => ((chksum == 0) && (i == 0) && (pIp == pIp@pre) && (pIp@pre->len == pIp_len) && (pIp@pre->pkv == pIp_pkv) && (*pIp_pkv == pIp_pkv_v) && (pIp@pre->chksum == pIp_chksum))) &&
(pIp == pIp@pre) &&
(pIp@pre->len == pIp_len) &&
(pIp@pre->pkv == pIp_pkv) &&
(*pIp_pkv == pIp_pkv_v) &&
(pIp@pre->chksum == pIp_chksum) &&
(forall (j:Z), 0 <= j && j < 10 => pIp->pkv_l[j] == pIp->pkv_l[j]@pre
      loop assigns i, chksum)
    */
    
    for(; i < pIp->len; i++)
    {
        chksum = chksum + pIp->pkv[i];
    }

	
	
	


	pIp->chksum = chksum;


	return;
}