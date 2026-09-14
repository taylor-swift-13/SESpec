                                                                            
extern int unknown_int(void);
/*@
  requires x < 100 && y < 100;
*/
void loopy_429(int x, int y) {
  
  
  
  while (x < 100 && y < 100) {
    x=x+1;
    y=y+1;
  }
  {;

}

  return;
}