#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "MouseEvent.h"
MouseEvent::MouseEvent()
{
	char pipeName[32] = "/tmp/evfb_mouse";
	unlink(pipeName);
	if( mkfifo(pipeName, 0777)< 0 )
	{
		fprintf ( stderr, "Can't create '%s'; %s\n", pipeName, strerror(errno) );
		exit(255);
	}
	fd = open(pipeName, O_WRONLY);
	if( fd < 0 )
	{
		fprintf ( stderr, "Can't open '%s'; %s\n", pipeName, strerror(errno) );
		exit(255);
	}
}
void MouseEvent::input(int const x, int const y, bool const down)
{
	memset(mouseDate, 0, 11);
	mouseDate[0]=100;
	if(down)
	{
		mouseDate[1]=1;
	}
	else
	{
		mouseDate[1]=2;
	}
	memcpy(&mouseDate[3], &x, 4);
	memcpy(&mouseDate[7], &y, 4);
	write(fd, mouseDate, 11); 
}
MouseEvent::~MouseEvent()
{
	close(fd);
	unlink("/tmp/evfb_mouse");
}
