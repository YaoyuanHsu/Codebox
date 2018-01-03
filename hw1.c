#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
// 0 1 2
int main( int argc, char* argv[] )
{
        ssize_t rs232accLen;
        char rs232BUF[ 256 ];
        int rs232FD = open ( "/dev/ttyS0" , O_RDWR );

        //struct termios tm232;
        //tcgetattr ( rs232FD , &tm232 );
        /*switch( tm232.c_cflag & CSIZE)
        {
                case CS5: printf( "CSIZE is 5 BITs\r\n" );  break;
                case CS6: printf( "CSIZE is 6 BITs\r\n" );  break;
                case CS7: printf( "CSIZE is 7 BITs\r\n" );  break;
                case CS8: printf( "CSIZE is 8 BITs\r\n" ); //  break;
        }*/
        //tcsetattr ( rs232FD , TCSANOW , &tm232 );
        //write ( rs232FD , (void *)"Hi CYH\r\n", 9 );

        //memset( rs232BUF , 0, 256 );
        system("clear");
        rs232accLen=read ( rs232FD , (void *)rs232BUF, 256 );
        //printf( "rs232BUF=%s\r\n", rs232BUF );
        //printf("hi %s\r", rs232BUF);;
        write(rs232FD, (void*)"Hi ", 3);
        write(rs232FD, rs232BUF, rs232accLen);
        //printf( "end...\r\n");
        close ( rs232FD );
        return 0;
}
/*
The functions, data structures, and symbolic constants are all declared in the
header file ¡¥termios.h¡¦.
int tcgetattr (int filedes, struct termios *termios-p)
int tcsetattr (int filedes, int when, const struct termios *termios-p)

TCSANOW Make the change immediately.
TCSADRAIN Make the change after waiting until all queued output has been written.
You should usually use this option when changing parameters that affect output.

TCSAFLUSH
This is like TCSADRAIN, but also discards any queued input.
TCSASOFT
This is a flag bit that you can add to any of the above alternatives.
Its meaning is to inhibit alteration of the state of the terminal hardware.
It is a BSD extension; it is only supported on BSD systems and the GNU system.


struct termios
tcflag_t c_iflag
A bit mask specifying flags for input modes; see Section 17.4.4 [Input Modes], page 437.
tcflag_t c_oflag
A bit mask specifying flags for output modes; see Section 17.4.5 [Output Modes], page 439.
tcflag_t c_cflag
A bit mask specifying flags for control modes; see Section 17.4.6 [Control Modes], page 439.
tcflag_t c_lflag
A bit mask specifying flags for local modes; see Section 17.4.7 [Local Modes], page 441.
cc_t c_cc[NCCS]
An array specifying which characters are associated with various control
functions; see Section 17.4.9 [Special Characters], page 445.

like this: settings.c_cflag & CSIZE.
[Macro] tcflag_t CSIZE
This is a mask for the number of bits per character.
[Macro] tcflag_t CS5
This specifi es fi ve bits per byte.
[Macro] tcflag_t CS6
This specifi es six bits per byte.
[Macro] tcflag_t CS7
This specifi es seven bits per byte.
[Macro] tcflag_t CS8
This specifi es eight bits per byte.



The open and create functions are declared in the header file fcntl.h, while close is declared in unistd.h.

int open (const char *filename, int flags[, mode_t mode])
The normal return value from open is a non-negative integer file descriptor.
In the case of an error, a value of -1 is returned instead.

int O_RDONLY  Macro Open the file for read access.
int O_WRONLY  Macro Open the file for write access.
int O_RDWR  Macro Open the file for both reading and writing

int close (int filedes)
These functions are declared in the header file unistd.h.
ssize_t read (int filedes, void *buffer, size_t size)
ssize_t write (int filedes, const void *buffer, size_t size)


*/

