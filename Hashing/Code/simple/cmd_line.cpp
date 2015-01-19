#include "cmd_line.h"

void cmd_line(int argc, char *argv[], char *in,char *out)
{
    int i, m, len, ch_buf;

    for (i = 1; i < argc; i++)
    {
        switch ( (int)argv[i][0] )           /* Check for option character. */
        {
        case '-':
            len = strlen( argv[i] );
            for ( m = 1; m < len; ++m ) /* Scan through options. */
            {
                ch_buf = (char)argv[i][m];
                switch ( ch_buf )
                {
                case 'i':              /* String parameter. */
                case 'I':
                    i++;
                    strcpy( in, argv[i] );
                    break;

                case 'h':
                case 'H':
                    printf("Enter flags then the input and output files. Example:\n\n./fir_time -i hello.wav -o /dev/null");
                    break;

                case 'o':              /* String parameter. */
                case 'O':
                    i++;
                    strcpy( out, argv[i] );
                    break;
                    
                    
                default:
                    printf( "You broke it! = %c\n", ch_buf );
                    return;
                }
            }
            break;
        default:
            printf( "You broke it! = %c\n", ch_buf );
            return;
        }
    }

}

