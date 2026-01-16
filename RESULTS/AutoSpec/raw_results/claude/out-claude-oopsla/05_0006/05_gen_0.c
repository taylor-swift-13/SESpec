#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

void main(int flag)
{

	int x = 0;
	int y = 0;

	int j = 0;
	int i = 0;

	/*@
	loop invariant i == x * (x + 1) / 2;
	loop invariant j == y * (y + 1) / 2 + (flag ? y : 0);
	loop invariant x == y;
	loop invariant j >= i;
	loop assigns x;
	loop assigns y;
	loop assigns i;
	loop assigns j;
	*/
	while(unknown1())
	{
	  x++;
	  y++;
	  i += x;
	  j += y;
	  if (flag)
	  	j+=1;
	} 
	// @ assert j>=i;
	
}
