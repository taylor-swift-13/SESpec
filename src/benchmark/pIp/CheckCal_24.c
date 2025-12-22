typedef struct __CheckCal
{

	int		len;
	int		*pkv;
	int     chksum;
	
} CheckCal;

/*@
	requires \valid(pIp);
	requires \valid(pIp->pkv+(0..9));
	requires pIp->len <= 10;
	requires \forall integer i; 0 <= i < 10 ==> 0 <= pIp -> pkv[i] && pIp -> pkv[i] <= 100;
*/
void main24(CheckCal *pIp)
{

	int i = 0;
	int chksum = 0;

	for(; i< pIp -> len; i++)
	{
	    chksum = chksum + pIp -> pkv[i];
	}

	/*@ assert chksum >= 0; */
	
	pIp->chksum = chksum;

	return;
}






