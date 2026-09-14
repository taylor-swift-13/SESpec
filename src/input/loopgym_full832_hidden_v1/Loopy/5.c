                                                                                                     
extern int unknown_int(void);

;
/*@
  requires n>=1;
*/
void loopy_5(int n) {
int x=0;
int y=0;


	

	while(x < 2*n){
	   x = x + 1;

	   if ( x > n )
		  y = y - 1;
	   else
		  y = y + 2;
	}

	if(x < y)
		goto __loopgym_label_0;

	return;
{ __loopgym_label_0: {; 

}
}
	return;
}