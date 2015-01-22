#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "cmd_line.h"
#include "md5_globals.h"
#include <omp.h>
using namespace std;

// #define UNROLLED

int main(int argc, char *argv[])
{


    /*
        // Grab password input.
        char infile[20];
        cmd_line(argc, argv, infile, NULL);
        FILE *IN = fopen(infile, "rb"); // Read in file.
        fread(in_block._8, 50, 1, IN);

        // Determine password length and pad
        register uint64_t length = strlen((char *)in_block._8);
    */



    // Write password length to md5.
    register uint8_t length = 1;

    // padding and length insertion is performed in constructor
    union Block in_block (length); 
    // in_block._64[7] = length << 3;
    // in_block._8[length] = 0x80;

    union Hash hash; // hashes are initialized in constructor

    #pragma omp parallel for firstprivate(in_block,hash) num_threads(27)
    /*
        parallel required to make multiple threads

        for looks at the following and parallelizes the for loop

        firstprivate uses the initial values of the variable and 
        makes it private.

        num_threads determines the number of parallel instances. 
        if no value is used here, it defaults to 5. this causes 
        the first 5 hashes to be accurate, but the final hashes
        are garbage (sharing resources). 
    
        We need to test every lowercase alpha from 1 to 10
        0x0 then 0x61 to 0x7A
    */
    for (int i = 0; i < 26; ++i)
    {
        in_block._8[0] = alph[i];
        F_MD5(&in_block, &hash);// Perform MD5 sum
        #pragma omp critical(print)
        /* printing needs to happen one thread at a time */
        {
            for (int i = 0; i < 16; i++)
                printf("%02x", hash._8[i]);
            printf("  %s\n", (char *)in_block._8);
        }
    }

    return 0;
}

void init(union Hash *ha)
/* This function is now obselete */
{
    ha->_32[0] = 0x67452301;
    ha->_32[1] = 0xefcdab89;
    ha->_32[2] = 0x98badcfe;
    ha->_32[3] = 0x10325476;
}

void F_MD5(union Block *bl, union Hash *ha)
{
    register uint32_t a, b, c, d;
    a = ha->_32[0]; 
    b = ha->_32[1];
    c = ha->_32[2];
    d = ha->_32[3];
    /*
        optimization. We aren't ever hashing multiple times. 
        This means that we can use constants here. Only assign
        the hash value at the very end. 
    */

    /* 
        Optimization. Instead of assign a=val; Just create a 
        FF1 function that has the values hard coded into it. 
    */


#ifdef UNROLLED
    /*
        Optimization. Our passwords will only have 2 things change:
            1. initial 10 characters + padding. bl->32[0-3]
            2. final 64 bits. Really just bl->32[14]
        Hardcode every other value as a 0. 
    */ 


    /* Round 1 */
    FF (a, b, c, d, bl->_32[ 0], S11, 0xd76aa478); /* 1 */
    FF (d, a, b, c, bl->_32[ 1], S12, 0xe8c7b756); /* 2 */
    FF (c, d, a, b, bl->_32[ 2], S13, 0x242070db); /* 3 */
    FF (b, c, d, a, bl->_32[ 3], S14, 0xc1bdceee); /* 4 */
    FF (a, b, c, d, bl->_32[ 4], S11, 0xf57c0faf); /* 5 */
    FF (d, a, b, c, bl->_32[ 5], S12, 0x4787c62a); /* 6 */
    FF (c, d, a, b, bl->_32[ 6], S13, 0xa8304613); /* 7 */
    FF (b, c, d, a, bl->_32[ 7], S14, 0xfd469501); /* 8 */
    FF (a, b, c, d, bl->_32[ 8], S11, 0x698098d8); /* 9 */
    FF (d, a, b, c, bl->_32[ 9], S12, 0x8b44f7af); /* 10 */
    FF (c, d, a, b, bl->_32[10], S13, 0xffff5bb1); /* 11 */
    FF (b, c, d, a, bl->_32[11], S14, 0x895cd7be); /* 12 */
    FF (a, b, c, d, bl->_32[12], S11, 0x6b901122); /* 13 */
    FF (d, a, b, c, bl->_32[13], S12, 0xfd987193); /* 14 */
    FF (c, d, a, b, bl->_32[14], S13, 0xa679438e); /* 15 */
    FF (b, c, d, a, bl->_32[15], S14, 0x49b40821); /* 16 */

    /* Round 2 */
    GG (a, b, c, d, bl->_32[ 1], S21, 0xf61e2562); /* 17 */
    GG (d, a, b, c, bl->_32[ 6], S22, 0xc040b340); /* 18 */
    GG (c, d, a, b, bl->_32[11], S23, 0x265e5a51); /* 19 */
    GG (b, c, d, a, bl->_32[ 0], S24, 0xe9b6c7aa); /* 20 */
    GG (a, b, c, d, bl->_32[ 5], S21, 0xd62f105d); /* 21 */
    GG (d, a, b, c, bl->_32[10], S22,  0x2441453); /* 22 */
    GG (c, d, a, b, bl->_32[15], S23, 0xd8a1e681); /* 23 */
    GG (b, c, d, a, bl->_32[ 4], S24, 0xe7d3fbc8); /* 24 */
    GG (a, b, c, d, bl->_32[ 9], S21, 0x21e1cde6); /* 25 */
    GG (d, a, b, c, bl->_32[14], S22, 0xc33707d6); /* 26 */
    GG (c, d, a, b, bl->_32[ 3], S23, 0xf4d50d87); /* 27 */
    GG (b, c, d, a, bl->_32[ 8], S24, 0x455a14ed); /* 28 */
    GG (a, b, c, d, bl->_32[13], S21, 0xa9e3e905); /* 29 */
    GG (d, a, b, c, bl->_32[ 2], S22, 0xfcefa3f8); /* 30 */
    GG (c, d, a, b, bl->_32[ 7], S23, 0x676f02d9); /* 31 */
    GG (b, c, d, a, bl->_32[12], S24, 0x8d2a4c8a); /* 32 */

    /* Round 3 */
    HH (a, b, c, d, bl->_32[ 5], S31, 0xfffa3942); /* 33 */
    HH (d, a, b, c, bl->_32[ 8], S32, 0x8771f681); /* 34 */
    HH (c, d, a, b, bl->_32[11], S33, 0x6d9d6122); /* 35 */
    HH (b, c, d, a, bl->_32[14], S34, 0xfde5380c); /* 36 */
    HH (a, b, c, d, bl->_32[ 1], S31, 0xa4beea44); /* 37 */
    HH (d, a, b, c, bl->_32[ 4], S32, 0x4bdecfa9); /* 38 */
    HH (c, d, a, b, bl->_32[ 7], S33, 0xf6bb4b60); /* 39 */
    HH (b, c, d, a, bl->_32[10], S34, 0xbebfbc70); /* 40 */
    HH (a, b, c, d, bl->_32[13], S31, 0x289b7ec6); /* 41 */
    HH (d, a, b, c, bl->_32[ 0], S32, 0xeaa127fa); /* 42 */
    HH (c, d, a, b, bl->_32[ 3], S33, 0xd4ef3085); /* 43 */
    HH (b, c, d, a, bl->_32[ 6], S34, 0x04881d05); /* 44 */
    HH (a, b, c, d, bl->_32[ 9], S31, 0xd9d4d039); /* 45 */
    HH (d, a, b, c, bl->_32[12], S32, 0xe6db99e5); /* 46 */
    HH (c, d, a, b, bl->_32[15], S33, 0x1fa27cf8); /* 47 */
    HH (b, c, d, a, bl->_32[ 2], S34, 0xc4ac5665); /* 48 */

    /* Round 4 */
    II (a, b, c, d, bl->_32[ 0], S41, 0xf4292244); /* 49 */
    II (d, a, b, c, bl->_32[ 7], S42, 0x432aff97); /* 50 */
    II (c, d, a, b, bl->_32[14], S43, 0xab9423a7); /* 51 */
    II (b, c, d, a, bl->_32[ 5], S44, 0xfc93a039); /* 52 */
    II (a, b, c, d, bl->_32[12], S41, 0x655b59c3); /* 53 */
    II (d, a, b, c, bl->_32[ 3], S42, 0x8f0ccc92); /* 54 */
    II (c, d, a, b, bl->_32[10], S43, 0xffeff47d); /* 55 */
    II (b, c, d, a, bl->_32[ 1], S44, 0x85845dd1); /* 56 */
    II (a, b, c, d, bl->_32[ 8], S41, 0x6fa87e4f); /* 57 */
    II (d, a, b, c, bl->_32[15], S42, 0xfe2ce6e0); /* 58 */
    II (c, d, a, b, bl->_32[ 6], S43, 0xa3014314); /* 59 */
    II (b, c, d, a, bl->_32[13], S44, 0x4e0811a1); /* 60 */
    II (a, b, c, d, bl->_32[ 4], S41, 0xf7537e82); /* 61 */
    II (d, a, b, c, bl->_32[11], S42, 0xbd3af235); /* 62 */
    II (c, d, a, b, bl->_32[ 2], S43, 0x2ad7d2bb); /* 63 */
    II (b, c, d, a, bl->_32[ 9], S44, 0xeb86d391); /* 64 */
#endif

#ifndef UNROLLED
    uint32_t temp, F, g;
    for (uint32_t i = 0; i < 64; i++)
    {
        if (i < 16)
        {
            F = (b & c) | (~b & d);
            g = i;
        }
        else if (i < 32)
        {
            F = (b & d) | (c & ~d);
            g = (5 * i + 1) % 16;
        }
        else if (i < 48)
        {
            F = b ^ c ^ d;
            g = (3 * i + 5) % 16;
        }
        else
        {
            F = c ^ (b | ~d);
            g = (7 * i) % 16;
        }
        temp = d;
        d = c;
        c = b;
        // precompute (a+K[i]+bl->_32[g])
        b = b + ROTATE_LEFT(a + F + K[i] + bl->_32[g], S[i]);
        a = temp;
    }
#endif

    ha->_32[0] += a;
    ha->_32[1] += b;
    ha->_32[2] += c;
    ha->_32[3] += d;

    /* 
        Optimization
        Test if it matches the default hash. Then we can 
        return a boolean value or just output and kill here
    */

}

