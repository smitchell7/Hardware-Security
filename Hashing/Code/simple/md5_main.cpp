#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "cmd_line.h"
#include "md5_globals.h"
#include <omp.h>
#include <math.h>
#include <time.h>
using namespace std;

// password to crack
union Hash enigma;

// 

int main(int argc, char *argv[])
{
    // testing string zzzzz
    enigma._8[0x0] = 0x95;
    enigma._8[0x1] = 0xeb;
    enigma._8[0x2] = 0xc3;
    enigma._8[0x3] = 0xc7;
    enigma._8[0x4] = 0xb3;
    enigma._8[0x5] = 0xb9;
    enigma._8[0x6] = 0xf1;
    enigma._8[0x7] = 0xd2;
    enigma._8[0x8] = 0xc4;
    enigma._8[0x9] = 0x0f;
    enigma._8[0xa] = 0xec;
    enigma._8[0xb] = 0x14;
    enigma._8[0xc] = 0x41;
    enigma._8[0xd] = 0x5d;
    enigma._8[0xe] = 0x3c;
    enigma._8[0xf] = 0xb8;


    /*
        // Grab password input.
        char infile[20];
        cmd_line(argc, argv, infile, NULL);
        FILE *IN = fopen(infile, "rb"); // Read in file.
        fread(in_block._8, 50, 1, IN);

        // Determine password length and pad
        register uint64_t length = strlen((char *)in_block._8);
    */
    union Block in_block;
    union Hash hash; // hashes are initialized in constructor

    // For loop parameters
    uint64_t N = D6;
    uint8_t _threads_ = 4;
    uint64_t i;

    clock_t start_time, final_time;
    start_time = clock();
    
    /*
        parallel required to make multiple threads

        for looks at the following and parallelizes the for loop
        
        Discarded for loop and went for sections instead. 

        firstprivate uses the initial values of the variable and
        makes it private.

        num_threads determines the number of parallel instances.
        if no value is used here, it defaults to 5. this causes
        the first 5 hashes to be accurate, but the final hashes
        are garbage (sharing resources).

        We need to test every lowercase alpha from 1 to 10
        0x0 then 0x61 to 0x7A
    */
    #pragma omp parallel sections num_threads(_threads_) firstprivate(in_block, hash)
    {
        #pragma omp section
        {
            for (i = 0; i < D6/4; i++)
            {
                write_pass(&in_block, i);
                init(&hash);
                F_MD5(&in_block, &hash);// Perform MD5 sum
                // #pragma omp critical(print)
                /* printing needs to happen one thread at a time */
            }
        }
        #pragma omp section
        {
            for (i = D6/4; i < 2*D6/4; i++)
            {
                write_pass(&in_block, i);
                init(&hash);
                F_MD5(&in_block, &hash);// Perform MD5 sum
                // #pragma omp critical(print)
                /* printing needs to happen one thread at a time */
            }
        }
        #pragma omp section
        {
            for (i = D6/2; i < 3*D6/4; i++)
            {
                write_pass(&in_block, i);
                init(&hash);
                F_MD5(&in_block, &hash);// Perform MD5 sum
                // #pragma omp critical(print)
                /* printing needs to happen one thread at a time */
            }
        }
        #pragma omp section
        {
            for (i = 3*D6/4; i < D6; i++)
            {
                write_pass(&in_block, i);
                init(&hash);
                F_MD5(&in_block, &hash);// Perform MD5 sum
                // #pragma omp critical(print)
                /* printing needs to happen one thread at a time */
            }
        }
    }
    final_time = clock();

    double hashpersec = D6 / ((final_time - start_time) / 1000000);
    printf("%lu hashes\n", D6);
    printf("%f milliseconds\n", (int)(final_time - start_time) / 1000.0);
    printf("%f hashes/sec.\n", hashpersec);
    // printf("Speed: %.1f MiB/s\n", (double)N * 64 / (clock() - start_time) * CLOCKS_PER_SEC / 1048576.0);
    return 0;
}

void test_hash(union Hash *ha, union Hash *en, union Block *in_block)
{
    uint64_t cmp1, cmp2;
    cmp1 = ha->_64[0] ^ en->_64[0];
    cmp2 = ha->_64[1] ^ en->_64[1];

    if ((cmp1 | cmp2) == 0)
    {
        printf("Found the hash!\n");
        printf("  %s\n", (char *)in_block->_8);
    }
    // else if ((in_block->_8[0] == 'z') && (in_block->_8[4] == 'z'))
    // {
    //     printf("Blah\n");
    //     for (int i = 0; i < 16; i++)
    //         printf("%02x%02x\n", ha->_8[i], en->_8[i]);
    // }
}


void write_pass(union Block *in_block, uint64_t i)
{
    int len;
    if (i < D1)
    {
        in_block->_8[0] = alph[i];
        in_block->_8[1] = 0x80;
        len = 1;
        memset(&in_block->_8[len + 1], 0, 56 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D2)
    {
        in_block->_8[0] = alph[(i - D1) % E1];
        in_block->_8[1] = alph[(i - D1) / E1];
        in_block->_8[2] = 0x80;
        len = 2;
        memset(&in_block->_8[len + 1], 0, 56 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D3)
    {
        in_block->_8[0] = alph[(i - D2) % E1];
        in_block->_8[1] = alph[(((i - D2) / E1) % E1) ];
        in_block->_8[2] = alph[(((i - D2) / E2) % E1)];
        in_block->_8[3] = 0x80;
        len = 3;
        memset(&in_block->_8[len + 1], 0, 56 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D4)
    {
        in_block->_8[0] = alph[(i - D3) % E1];
        in_block->_8[1] = alph[(((i - D3) / E1) % E1)];
        in_block->_8[2] = alph[(((i - D3) / E2) % E1)];
        in_block->_8[3] = alph[(((i - D3) / E3) % E1)];
        in_block->_8[4] = 0x80;
        len = 4;
        memset(&in_block->_8[len + 1], 0, 56 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D5)
    {
        in_block->_8[0] = alph[(i - D4) % E1];
        in_block->_8[1] = alph[(((i - D4) / E1) % E1)];
        in_block->_8[2] = alph[(((i - D4) / E2) % E1)];
        in_block->_8[3] = alph[(((i - D4) / E3) % E1)];
        in_block->_8[4] = alph[(((i - D4) / E4) % E1)];
        in_block->_8[5] = 0x80;
        len = 5;
        memset(&in_block->_8[len + 1], 0, 56 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D6)
    {
        in_block->_8[0] = alph[(i - D5) % E1];
        in_block->_8[1] = alph[(((i - D5) / E1) % E1)];
        in_block->_8[2] = alph[(((i - D5) / E2) % E1)];
        in_block->_8[3] = alph[(((i - D5) / E3) % E1)];
        in_block->_8[4] = alph[(((i - D5) / E4) % E1)];
        in_block->_8[5] = alph[(((i - D5) / E5) % E1)];
        in_block->_8[6] = 0x80;
        len = 6;
        memset(&in_block->_8[len + 1], 0, 56 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D7)
    {
        in_block->_8[0] = alph[(i - D6) % E1];
        in_block->_8[1] = alph[(((i - D6) / E1) % E1)];
        in_block->_8[2] = alph[(((i - D6) / E2) % E1)];
        in_block->_8[3] = alph[(((i - D6) / E3) % E1)];
        in_block->_8[4] = alph[(((i - D6) / E4) % E1)];
        in_block->_8[5] = alph[(((i - D6) / E5) % E1)];
        in_block->_8[6] = alph[(((i - D6) / E6) % E1)];
        in_block->_8[7] = 0x80;
        len = 7;
        memset(&in_block->_8[len + 1], 0, 56 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D8)
    {
        in_block->_8[0] = alph[(i - D7) % E1];
        in_block->_8[1] = alph[(((i - D7) / E1) % E1)];
        in_block->_8[2] = alph[(((i - D7) / E2) % E1)];
        in_block->_8[3] = alph[(((i - D7) / E3) % E1)];
        in_block->_8[4] = alph[(((i - D7) / E4) % E1)];
        in_block->_8[5] = alph[(((i - D7) / E5) % E1)];
        in_block->_8[6] = alph[(((i - D7) / E6) % E1)];
        in_block->_8[7] = alph[(((i - D7) / E7) % E1)];
        in_block->_8[8] = 0x80;
        len = 8;
        memset(&in_block->_8[len + 1], 0, 56 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D9)
    {
        in_block->_8[0] = alph[(i - D8) % E1];
        in_block->_8[1] = alph[(((i - D8) / E1) % E1)];
        in_block->_8[2] = alph[(((i - D8) / E2) % E1)];
        in_block->_8[3] = alph[(((i - D8) / E3) % E1)];
        in_block->_8[4] = alph[(((i - D8) / E4) % E1)];
        in_block->_8[5] = alph[(((i - D8) / E5) % E1)];
        in_block->_8[6] = alph[(((i - D8) / E6) % E1)];
        in_block->_8[7] = alph[(((i - D8) / E7) % E1)];
        in_block->_8[8] = alph[(((i - D8) / E8) % E1)];
        in_block->_8[9] = 0x80;
        len = 9;
        memset(&in_block->_8[len + 1], 0, 56 - len);
        in_block->_64[7] = len * 8;
    }
    else
    {
        in_block->_8[0] = alph[(i - D9) % E1];
        in_block->_8[1] = alph[(((i - D9) / E1) % E1)];
        in_block->_8[2] = alph[(((i - D9) / E2) % E1)];
        in_block->_8[3] = alph[(((i - D9) / E3) % E1)];
        in_block->_8[4] = alph[(((i - D9) / E4) % E1)];
        in_block->_8[5] = alph[(((i - D9) / E5) % E1)];
        in_block->_8[6] = alph[(((i - D9) / E6) % E1)];
        in_block->_8[7] = alph[(((i - D9) / E7) % E1)];
        in_block->_8[8] = alph[(((i - D9) / E8) % E1)];
        in_block->_8[9] = alph[(((i - D9) / E9) % E1)];
        in_block->_8[10] = 0x80;
        len = 10;
        memset(&in_block->_8[len + 1], 0, 56 - len);
        in_block->_64[7] = len * 8;
    }
}


void init(union Hash *ha)
/* This function is now obselete */
{
    ha->_32[0] = HASH_BASE_A;
    ha->_32[1] = HASH_BASE_B;
    ha->_32[2] = HASH_BASE_C;
    ha->_32[3] = HASH_BASE_D;
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

    ha->_32[0] += a;
    ha->_32[1] += b;
    ha->_32[2] += c;
    ha->_32[3] += d;

    uint64_t cmp1, cmp2;
    cmp1 = ha->_64[0] ^ enigma._64[0];
    cmp2 = ha->_64[1] ^ enigma._64[1];

    if ((cmp1 | cmp2) == 0)
    {
        printf("Found the hash!\n");
        printf("  %s\n", (char *)bl->_8);
    }

    /*
        Optimization
        Test if it matches the default hash. Then we can
        return a boolean value or just output and kill here
    */

}

