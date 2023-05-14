#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include "wlib.h"

struct passwd * wgetpwnam(const char * name)
{
     struct passwd * pwd;

     while((pwd = getpwent()) != NULL && strcmp(pwd->pw_name, name))
	  ;

     endpwent();
     return pwd;
}
	  

     
