// C version of <iostream>
#include <stdio.h>       

int main(void)        //'void' is not necessary, but good practice in C
{
  // %s is the string format conversion specifier, replaced by 'Hello, World!\n'
  printf("%s", "Hello, world!\n");           

  return 0;
}
