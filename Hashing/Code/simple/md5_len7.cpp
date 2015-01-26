#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "cmd_line.h"
#include "md5_sam.h"
#include <omp.h>
#include <math.h>
#include <time.h>
using namespace std;

//
#define N E7
#define _threads_ 16
#define LEN7

// password to crack
// 'aaaaaaa'
// #define passwd1 0x5d793fc5b00a2348
// #define passwd2 0xc3fb9ab59e5ca98a

// 'zzzzzzz'
#define passwd1 0xf0e8fb430bbdde6a
#define passwd2 0xe9c879a518fd895f





int main(int argc, char *argv[])
{
    transform_password(passwd1, passwd2);

    union Block in_block;
    union Hash hash; // hashes are initialized in constructor

    // For loop parameters
    uint64_t i;



    /*
        parallel required to make multiple threads

        for looks at the following and parallelizes the for loop

        Discarded for loop and went for sections instead.

        firstprivate uses the initial values of the variable and
        makes it private.

        num_threads determines the number of parallel instances.
        This is controlled by the _threads_ macro.

        The N macro determines the simulation length.
    */
    #pragma omp parallel sections num_threads(_threads_) private(in_block,hash,i)
    {
        /* Optimization.
            Hard code in the values in the loop. Also choose the
            number of times we unwrap wisely (see write_pass)
        */
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 0; i < N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        // for 1 thread, comment after here.
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = N / _threads_; i < 2 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n\n", in_block._8);
            }
        }
        // for 2 threads, comment after here.
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 2 * N / _threads_; i < 3 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 3 * N / _threads_; i < 4 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        // for 4 threads, comment after here

        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 4 * N / _threads_; i < 5 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 5 * N / _threads_; i < 6 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 6 * N / _threads_; i < 7 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }

        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 7 * N / _threads_; i < 8 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        // for 8 threads, comment after here
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 8 * N / _threads_; i < 9 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 9 * N / _threads_; i < 10 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 10 * N / _threads_; i < 11 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 11 * N / _threads_; i < 12 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 12 * N / _threads_; i < 13 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 13 * N / _threads_; i < 14 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 14 * N / _threads_; i < 15 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 15 * N / _threads_; i < 16 * N / _threads_; i++)
            {
                write_pass(&in_block,   i); tmp += F_MD5(&in_block, &hash, i); // Perform MD5 sum
            }
            if (tmp != 0)
            {
                write_pass(&in_block, tmp);
                printf("found. %s\n", in_block._8);
            }
        }
        //
    }

    printf("%lu hashes\n", N);
    return 0;
}

/*
    Optimization.
    Use first block every time.
    456976 unique length 4 passwords.
    Each one will be used 17576 times. (vectorised 4394)
    Make each loop 17576 long. The first
    line of the loop calculates the value and stores it.
    The next 17575 iterations skip that one.

    This can also be used for the write_pass function.
    The only values that need to be updated are [4-6]
*/
#ifdef LEN7
void write_pass(union Block *in_block, uint64_t i)
{
    in_block->_8[6] = alph(i % E1);
    i /= E1;
    in_block->_8[5] = alph(i % E1);
    i /= E1;
    in_block->_8[4] = alph(i % E1);
    i /= E1;

    // these are updated rarely.
    in_block->_8[7] = 0x80;
    in_block->_8[3] = alph(i % E1);
    i /= E1;
    in_block->_8[2] = alph(i % E1);
    i /= E1;
    in_block->_8[1] = alph(i % E1);
    i /= E1;
    in_block->_8[0] = alph(i % E1);
    i /= E1;
    // memset(&in_block->_8[8], 0, 4); optimized out.
    // in_block->_32[3] = 56; optimized out.

}
#endif
#ifndef LEN7
/*
    Password generator.
    Accepts a block and iterator value,
    Outputs a password of length N (macro)

    Implemented as a binary search for speed.

    Future optimization: write in 32 bit words.

    Is there a better way to evenly generate these passwords?
*/
void write_pass(union Block *in_block, uint64_t i)
{
    int len;
    // if (i < D1)
    // else if (i < D2)
    // else if (i < D3)
    // else if (i < D4)
    // else if (i < D5)
    // else if (i < D6)
    // else if (i < D7)
    // else if (i < D8)
    // else if (i < D9)
    // else

    if (i < D5)
    {
        if (i < D2)
        {
            if (i < D1) // D1
            {
                in_block->_8[0] = alph(i);
                len = 1;
                in_block->_8[len] = 0x80;
                memset(&in_block->_8[len + 1], 0, 11 - len);
                in_block->_32[3] = len << 3;
            }
            else // D2
            {
                in_block->_8[0] = alph((i - D1) % E1);
                in_block->_8[1] = alph((i - D1) / E1);
                len = 2;
                in_block->_8[len] = 0x80;
                memset(&in_block->_8[len + 1], 0, 11 - len);
                in_block->_32[3] = len << 3;
            }

        }
        else
        {
            if (i < D4)
            {
                if (i < D3) // D3
                {
                    in_block->_8[0] = alph((i - D2) % E1);
                    in_block->_8[1] = alph((((i - D2) / E1) % E1) );
                    in_block->_8[2] = alph((((i - D2) / E2) % E1));
                    len = 3;
                    in_block->_8[len] = 0x80;
                    memset(&in_block->_8[len + 1], 0, 11 - len);
                    in_block->_32[3] = len << 3;
                }

                else // D4
                {
                    in_block->_8[0] = alph((i - D3) % E1);
                    in_block->_8[1] = alph((((i - D3) / E1) % E1));
                    in_block->_8[2] = alph((((i - D3) / E2) % E1));
                    in_block->_8[3] = alph((((i - D3) / E3) % E1));
                    len = 4;
                    in_block->_8[len] = 0x80;
                    memset(&in_block->_8[len + 1], 0, 11 - len);
                    in_block->_32[3] = len << 3;
                }

            }
            else      // D5
            {
                in_block->_8[0] = alph((i - D4) % E1);
                in_block->_8[1] = alph((((i - D4) / E1) % E1));
                in_block->_8[2] = alph((((i - D4) / E2) % E1));
                in_block->_8[3] = alph((((i - D4) / E3) % E1));
                in_block->_8[4] = alph((((i - D4) / E4) % E1));
                len = 5;
                in_block->_8[len] = 0x80;
                memset(&in_block->_8[len + 1], 0, 11 - len);
                in_block->_32[3] = len << 3;
            }

        }
    }
    else
    {
        if (i < D7)
        {
            if (i < D6) // D6
            {
                in_block->_8[0] = alph((i - D5) % E1);
                in_block->_8[1] = alph((((i - D5) / E1) % E1));
                in_block->_8[2] = alph((((i - D5) / E2) % E1));
                in_block->_8[3] = alph((((i - D5) / E3) % E1));
                in_block->_8[4] = alph((((i - D5) / E4) % E1));
                in_block->_8[5] = alph((((i - D5) / E5) % E1));
                len = 6;
                in_block->_8[len] = 0x80;
                memset(&in_block->_8[len + 1], 0, 11 - len);
                in_block->_32[3] = len << 3;
            }

            else // D7
            {
                in_block->_8[0] = alph((i - D6) % E1);
                in_block->_8[1] = alph((((i - D6) / E1) % E1));
                in_block->_8[2] = alph((((i - D6) / E2) % E1));
                in_block->_8[3] = alph((((i - D6) / E3) % E1));
                in_block->_8[4] = alph((((i - D6) / E4) % E1));
                in_block->_8[5] = alph((((i - D6) / E5) % E1));
                in_block->_8[6] = alph((((i - D6) / E6) % E1));
                len = 7;
                in_block->_8[len] = 0x80;
                memset(&in_block->_8[len + 1], 0, 11 - len);
                in_block->_32[3] = len << 3;
            }

        }
        else // D8-10
        {
            if (i < D9)
            {
                if (i < D8) // D8
                {
                    in_block->_8[0] = alph((i - D7) % E1);
                    in_block->_8[1] = alph((((i - D7) / E1) % E1));
                    in_block->_8[2] = alph((((i - D7) / E2) % E1));
                    in_block->_8[3] = alph((((i - D7) / E3) % E1));
                    in_block->_8[4] = alph((((i - D7) / E4) % E1));
                    in_block->_8[5] = alph((((i - D7) / E5) % E1));
                    in_block->_8[6] = alph((((i - D7) / E6) % E1));
                    in_block->_8[7] = alph((((i - D7) / E7) % E1));
                    len = 8;
                    in_block->_8[len] = 0x80;
                    memset(&in_block->_8[len + 1], 0, 11 - len);
                    in_block->_32[3] = len << 3;
                }

                else // D9
                {
                    in_block->_8[0] = alph((i - D8) % E1);
                    in_block->_8[1] = alph((((i - D8) / E1) % E1));
                    in_block->_8[2] = alph((((i - D8) / E2) % E1));
                    in_block->_8[3] = alph((((i - D8) / E3) % E1));
                    in_block->_8[4] = alph((((i - D8) / E4) % E1));
                    in_block->_8[5] = alph((((i - D8) / E5) % E1));
                    in_block->_8[6] = alph((((i - D8) / E6) % E1));
                    in_block->_8[7] = alph((((i - D8) / E7) % E1));
                    in_block->_8[8] = alph((((i - D8) / E8) % E1));
                    len = 9;
                    in_block->_8[len] = 0x80;
                    memset(&in_block->_8[len + 1], 0, 11 - len);
                    in_block->_32[3] = len << 3;
                }

            }
            else // D10
            {
                in_block->_8[0] = alph((i - D9) % E1);
                in_block->_8[1] = alph((((i - D9) / E1) % E1));
                in_block->_8[2] = alph((((i - D9) / E2) % E1));
                in_block->_8[3] = alph((((i - D9) / E3) % E1));
                in_block->_8[4] = alph((((i - D9) / E4) % E1));
                in_block->_8[5] = alph((((i - D9) / E5) % E1));
                in_block->_8[6] = alph((((i - D9) / E6) % E1));
                in_block->_8[7] = alph((((i - D9) / E7) % E1));
                in_block->_8[8] = alph((((i - D9) / E8) % E1));
                in_block->_8[9] = alph((((i - D9) / E9) % E1));
                len = 10;
                in_block->_8[len] = 0x80;
                memset(&in_block->_8[len + 1], 0, 11 - len);
                in_block->_32[3] = len << 3;
            }

        }
    }
}
#endif
uint64_t F_MD5(union Block *bl, union Hash *ha, uint64_t i)
{
    register uint32_t a, b, c, d;


    // a = HASH_BASE_A;
    // removed for optimization, see FF1 function

    b = HASH_BASE_B;
    c = HASH_BASE_C;
    d = HASH_BASE_D;


    /*
        Optimization. We aren't ever hashing multiple times.
        This means that we can use constants here. Only assign
        the hash value at the very end.
        Done.
    */

    /*
        Optimization. Instead of assign a=val; Just create a
        FF1 function that has the values hard coded into it.
        Done.
    */


    /*
        Optimization. Our passwords will only have 2 things change:
            1. initial 10 characters + padding. bl->32[0-3]
            2. final 64 bits. Really just bl->32[14]
        Hardcode every other value as a 0.
        Done.
    */

    {
        /* Round 1 */
        FF1 (a, b, c, d, bl->_32[ 0], S11, 0xd76aa478); /* 1 */
        FF (d, a, b, c, bl->_32[ 1], S12, 0xe8c7b756); /* 2 */
#ifndef LEN7
        FF (c, d, a, b, bl->_32[ 2], S13, 0x242070db); /* 3 */
#endif
#ifdef LEN7
        FF (c, d, a, b,           0, S13, 0x242070db); /* 3 */
#endif

        FF (b, c, d, a,           0, S14, 0xc1bdceee); /* 4 */
        FF (a, b, c, d,           0, S11, 0xf57c0faf); /* 5 */
        FF (d, a, b, c,           0, S12, 0x4787c62a); /* 6 */
        FF (c, d, a, b,           0, S13, 0xa8304613); /* 7 */
        FF (b, c, d, a,           0, S14, 0xfd469501); /* 8 */
        FF (a, b, c, d,           0, S11, 0x698098d8); /* 9 */
        FF (d, a, b, c,           0, S12, 0x8b44f7af); /* 10 */
        FF (c, d, a, b,           0, S13, 0xffff5bb1); /* 11 */
        FF (b, c, d, a,           0, S14, 0x895cd7be); /* 12 */
        FF (a, b, c, d,           0, S11, 0x6b901122); /* 13 */
        FF (d, a, b, c,           0, S12, 0xfd987193); /* 14 */
#ifndef LEN7
        FF (c, d, a, b, bl->_32[ 3], S13, 0xa679438e); /* 15 */
#endif
#ifdef LEN7
        FF (c, d, a, b,          56, S13, 0xa679438e); /* 15 */
#endif
        FF (b, c, d, a,           0, S14, 0x49b40821); /* 16 */

        /* Round 2 */
        GG (a, b, c, d, bl->_32[ 1], S21, 0xf61e2562); /* 17 */
        GG (d, a, b, c,           0, S22, 0xc040b340); /* 18 */
        GG (c, d, a, b,           0, S23, 0x265e5a51); /* 19 */
        GG (b, c, d, a, bl->_32[ 0], S24, 0xe9b6c7aa); /* 20 */
        GG (a, b, c, d,           0, S21, 0xd62f105d); /* 21 */
        GG (d, a, b, c,           0, S22,  0x2441453); /* 22 */
        GG (c, d, a, b,           0, S23, 0xd8a1e681); /* 23 */
        GG (b, c, d, a,           0, S24, 0xe7d3fbc8); /* 24 */
        GG (a, b, c, d,           0, S21, 0x21e1cde6); /* 25 */
#ifndef LEN7
        GG (d, a, b, c, bl->_32[ 3], S22, 0xc33707d6); /* 26 */
#endif
#ifdef LEN7
        GG (d, a, b, c,          56, S22, 0xc33707d6); /* 26 */
#endif
        GG (c, d, a, b,           0, S23, 0xf4d50d87); /* 27 */
        GG (b, c, d, a,           0, S24, 0x455a14ed); /* 28 */
        GG (a, b, c, d,           0, S21, 0xa9e3e905); /* 29 */
#ifndef LEN7
        GG (d, a, b, c, bl->_32[ 2], S22, 0xfcefa3f8); /* 30 */
#endif
#ifdef LEN7
        GG (d, a, b, c,           0, S22, 0xfcefa3f8); /* 30 */
#endif

        GG (c, d, a, b,           0, S23, 0x676f02d9); /* 31 */
        GG (b, c, d, a,           0, S24, 0x8d2a4c8a); /* 32 */

        /* Round 3 */
        HH (a, b, c, d,           0, S31, 0xfffa3942); /* 33 */
        HH (d, a, b, c,           0, S32, 0x8771f681); /* 34 */
        HH (c, d, a, b,           0, S33, 0x6d9d6122); /* 35 */
#ifndef LEN7
        HH (b, c, d, a, bl->_32[ 3], S34, 0xfde5380c); /* 36 */
#endif
#ifdef LEN7
        HH (b, c, d, a,          56, S34, 0xfde5380c); /* 36 */
#endif
        HH (a, b, c, d, bl->_32[ 1], S31, 0xa4beea44); /* 37 */
        HH (d, a, b, c,           0, S32, 0x4bdecfa9); /* 38 */
        HH (c, d, a, b,           0, S33, 0xf6bb4b60); /* 39 */
        HH (b, c, d, a,           0, S34, 0xbebfbc70); /* 40 */
        HH (a, b, c, d,           0, S31, 0x289b7ec6); /* 41 */
        HH (d, a, b, c, bl->_32[ 0], S32, 0xeaa127fa); /* 42 */
        HH (c, d, a, b,           0, S33, 0xd4ef3085); /* 43 */
        HH (b, c, d, a,           0, S34, 0x04881d05); /* 44 */
        HH (a, b, c, d,           0, S31, 0xd9d4d039); /* 45 */
        HH (d, a, b, c,           0, S32, 0xe6db99e5); /* 46 */
        HH (c, d, a, b,           0, S33, 0x1fa27cf8); /* 47 */
#ifndef LEN7
        HH (b, c, d, a, bl->_32[ 2], S34, 0xc4ac5665); /* 48 */
#endif
#ifdef LEN7
        HH (b, c, d, a,           0, S34, 0xc4ac5665); /* 48 */
#endif


        /* Round 4 */
        II (a, b, c, d, bl->_32[ 0], S41, 0xf4292244); /* 49 */
        II (d, a, b, c,           0, S42, 0x432aff97); /* 50 */
#ifndef LEN7
        II (c, d, a, b, bl->_32[ 3], S43, 0xab9423a7); /* 51 */
#endif
#ifdef LEN7
        II (c, d, a, b,          56, S43, 0xab9423a7); /* 51 */
#endif
        II (b, c, d, a,           0, S44, 0xfc93a039); /* 52 */
        II (a, b, c, d,           0, S41, 0x655b59c3); /* 53 */
        II (d, a, b, c,           0, S42, 0x8f0ccc92); /* 54 */
        II (c, d, a, b,           0, S43, 0xffeff47d); /* 55 */
        II (b, c, d, a, bl->_32[ 1], S44, 0x85845dd1); /* 56 */
        II (a, b, c, d,           0, S41, 0x6fa87e4f); /* 57 */
        II (d, a, b, c,           0, S42, 0xfe2ce6e0); /* 58 */
        II (c, d, a, b,           0, S43, 0xa3014314); /* 59 */
        II (b, c, d, a,           0, S44, 0x4e0811a1); /* 60 */
        II (a, b, c, d,           0, S41, 0xf7537e82); /* 61 */
        II (d, a, b, c,           0, S42, 0xbd3af235); /* 62 */
#ifndef LEN7
        II (c, d, a, b, bl->_32[ 2], S43, 0x2ad7d2bb); /* 63 */
#endif
#ifdef LEN7
        II (c, d, a, b,           0, S43, 0x2ad7d2bb); /* 63 */
#endif

        II (b, c, d, a,           0, S44, 0xeb86d391); /* 64 */
    }
    ha->_32[0] = a + HASH_BASE_A;
    ha->_32[1] = b + HASH_BASE_B;
    ha->_32[2] = c + HASH_BASE_C;
    ha->_32[3] = d + HASH_BASE_D;


    /*
        Optimization. Use the return-style sequence
        in order to save 2.6%. 2:30 compared to 2:26.
        uint64_t cmp1, cmp2;
        cmp1 = ha->_64[0] ^ enigma._64[0];
        cmp2 = ha->_64[1] ^ enigma._64[1];

        if ((cmp1 | cmp2) == 0)
        {
            printf("Found the hash!\n");
            printf("  %s\n", (char *)bl->_8);
        }


        Equivalent to 
        if( found )
            return i;
        else return 0;
        misses if the password is 'aaaaaaa'
    */

    return i*((
                (ha->_32[0] ^ enigma._32[0]) |
                (ha->_32[1] ^ enigma._32[1]) |
                (ha->_32[2] ^ enigma._32[2]) |
                (ha->_32[3] ^ enigma._32[3])
            ) == 0);
    /*
        Optimization
        Test if it matches the default hash. Then we can
        return a boolean value or just output and kill here
    */
    /*
        Optimization.
        Instead of testing, try the following sequence.
        tmp += i* ((ha^enigma)==0);
        return tmp;

        This removes all jumps, and gives an index at the end.
    */
}

