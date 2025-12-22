

typedef struct __SendUartData
{
/* 输入端口 */
	int		addr[10];
	int		data[10];
    int         len;
	
} SendUartData;


/*@
requires \valid(pIp);
requires 0 <= pIp->len <=10;
*/
void SendUartDataFun(SendUartData *pIp)
{
    
	int i =0;

	for (; i < pIp -> len; i++)
	{
		pIp -> addr[i] =  pIp -> data[i];
	}
	return;
}

/*@
requires \valid(pIp);
requires 0 <= pIp->len <=10;
*/
main46(SendUartData *pIp)
{
    
    pIp->len = 5;
    pIp->data[0] = 1;
    pIp->data[1] = 2;
    pIp->data[2] = 3;
    pIp->data[3] = 4;
    pIp->data[4] = 5;
    SendUartDataFun(pIp);
    
    /*@ assert pIp.addr[0] == 1; */
    /*@ assert pIp.addr[1] == 2; */
    /*@ assert pIp.addr[2] == 3; */
    /*@ assert pIp.addr[3] == 4; */
    /*@ assert pIp.addr[4] == 5; */

}