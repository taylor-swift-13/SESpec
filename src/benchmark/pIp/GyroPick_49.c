typedef struct TAG_DIGITAL_GYRO_DATA
{

    int		countPick[9];		 			 	
    int 	wa[9];				 	
    int 	wal[9];				 	
	
} SGyroData;

typedef struct __GyroPick
{
	SGyroData*			pGyroData;
} GyroPick;

int ABS(int x)
{
    if (x < 0)
        return -x;
    else
        return x;
}

/*@
requires \valid(pIp);
*/
void GyroPickFun(GyroPick *pIp)
{

    int iy = 0 ;
    int tmpgi = 0 ;

    for (; iy < 9 ; iy++ )
    {

        tmpgi = ABS(pIp -> pGyroData->wa[iy] - pIp -> pGyroData->wal[iy]) ;

        if (tmpgi > 0)
        {
            pIp -> pGyroData->countPick[iy]++ ;

            if (pIp -> pGyroData->countPick[iy] < 6)
            {
                pIp -> pGyroData->wa[iy] = pIp -> pGyroData->wal[iy] ;

            }
            else
            {
                pIp -> pGyroData->wal[iy] = pIp -> pGyroData->wa[iy] ;

                pIp -> pGyroData->countPick[iy] = 0 ;

            }
        }
        else
        {
            pIp -> pGyroData->wal[iy] = pIp -> pGyroData->wa[iy] ;

            pIp -> pGyroData->countPick[iy] = 0 ;

        }
    }

    return ;

}

/*@
requires \valid(pIp);
*/
main49(GyroPick *pIp)
{
    pIp -> pGyroData->wa[0] = 0;
    pIp -> pGyroData->wal[0] = 0;
    GyroPickFun(pIp);

    /*@ assert pIp -> pGyroData->countPick[0] == 0; */
    /*@ assert pIp -> pGyroData->wal[0] == pIp -> pGyroData->wa[0]; */
}