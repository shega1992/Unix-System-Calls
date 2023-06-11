#include <stdio.h>
#include <signal.h>
#include "wlib.h"

int wsiginterrupt(int sig, int flag)
{
     struct sigaction act;

     if(sigaction(sig, NULL, &act) == -1)
	  return -1;

     if(!flag)
	  act.sa_flags |= SA_RESTART;
     else
	  act.sa_flags &= ~SA_RESTART;

     return sigaction(sig, &act, NULL);
}
	  
     

