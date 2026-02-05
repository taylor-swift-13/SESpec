
/*@
    requires x == 1 && x <= y;
    */
    
int main26(int x,int y) {
	
	int z=1;
	int w=1;

	
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant (\at(x,Pre) <= \at(y,Pre)) ==> (x <= y + 1);
              loop invariant (\at(x,Pre) <= \at(y,Pre)) ==> (z == \at(z,Pre) * (x - 1));
              loop invariant (\at(x,Pre) <= \at(y,Pre)) ==> (w == \at(w,Pre) * (x - 1));
              loop invariant (!(\at(x,Pre) <= \at(y,Pre))) ==> ((w == 1)&&(z == 1)&&(y == \at(y,Pre))&&(x == \at(x,Pre)));
              loop invariant y == \at(y,Pre);
              loop assigns x, w, z;
            */
            while(x <= y)
	{
		w = w * x;
		if (x < y) {
			z = z * x;
		}
		x += 1;
	}
            

	/*@ assert w == z * y; */
	return 0;
}
