                                                                
extern int unknown_int(void);
#define LIMIT 1000000

/*@
  requires y <= LIMIT;
*/
void loopy_466(int x, int y) {
    
    
    

    if (y>0) {
        while(x<100) {
            x=x+y;
        }
    }

    {;

}

    return;
}
