#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pwd.h>
#include <wlib.h>

int main(void)
{
     struct passwd * pwd;

     errno = 0;
     pwd = wgetpwnam("games");
     if(pwd == NULL)
     {
	  if(errno == 0)
	       printf("Record wasn't found\n");
	  else
	  {
	       fprintf(stderr, "wgetpwnam: %s\n", strerror(errno));
	       exit(EXIT_FAILURE);
	  }
     }
     else
	  printf("Login name: %s\nPassword: %s\nUID: %u\nGID: %u\nComment: %s\nHome directory: %s\nLogin shell: %s\n", pwd->pw_name, pwd->pw_passwd, pwd->pw_uid, pwd->pw_gid, pwd->pw_gecos, pwd->pw_dir, pwd->pw_shell);
	  
     return 0;
}
