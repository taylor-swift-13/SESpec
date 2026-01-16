#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

int main()
{
	int i = 1;
	int j = 0;
	int z = i - j;
	int x = 0;
	int y = 0;
	int w = 0;

	/*@
	loop invariant z == (i - j) + \sum integer k; 0 <= k < y ==> x + y + w;
	loop invariant y == x || y == x + 1;
	loop invariant y <= i + j + w + x + z + 1000;;
	loop invariant y < i + j + w + x + z + 1000;;
	loop invariant (z % 2 == 1) <==> (x == y);
	loop invariant y >= 0 ==> w == 2 * y;
	loop invariant x <= y;
	loop invariant w == 2 * y;
	loop invariant w % 2 == 0;
	loop invariant 0 <= y;
	loop invariant 0 <= x;
	loop invariant 0 <= w;
	loop assigns z;
	loop assigns y;
	loop assigns x;
	loop assigns w;
	*/
	while(unknown2()) 
	{
		z += x + y + w;
		y++;
		if (z % 2 == 1) 
		  x++;
		w += 2; 
	}

	// @ assert x==y;
}
