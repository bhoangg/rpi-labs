#include <assert.h>
#include <fcntl.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int           f      ;
    char          buf[500+1];
    struct pollfd pfd    ;

    while(1) {
        memset(buf,0,sizeof(buf));

        if((f=open("/sys/my_sysfs/data",O_RDONLY)) <0) {
            fprintf(stderr,"Failed to open sysfs file\n");
            exit(1);
        }

        if((lseek(f,0L,SEEK_SET)) <0) {
            fprintf(stderr,"Failed to set pointer\n");
            exit(2);
        }

	if(read(f,buf,sizeof(buf))<0){
	   fprintf(stderr,"Failed to read\n"); 
    	   exit(3);
	}
	printf("%s\n",buf);
	memset(buf,0,sizeof(buf));

        pfd.fd     = f      ;
        pfd.events = POLLPRI;

        poll(&pfd,1,-1); // This should block until value has changed....

        printf("Data readable!!!\n");
        // Do some stuff
	read(f,buf,sizeof(buf));
	printf("%s\n",buf);
	close(f);

    }
}

