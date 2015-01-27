#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "cmd_line.h"
#include "md5_globals_vectors.h"
#include <omp.h>


#include <iostream>

#include <time.h>
using namespace std;

//#define N D7
#define N (uint64_t) 2088270645 //D7/4
#define _threads_ 16


// password to crack


#define passwd1 0x5d793fc5b00a2348
#define passwd2 0xc3fb9ab59e5ca98a

void vectorPrint(string s, vec4 vec)
{
	uint32_t * vec_P = (uint32_t*) &vec;
	std::cout << "Vector Print : " << s << std::endl;
	for(int i = 0; i < 4; i++)
	{
		std::cout << "  " << i << " : " << (uint32_t) vec_P[i] << std::endl;
	}
}

void vectorTest()
{
//	typedef uint32_t v4si __attribute__ ((vector_size (32)));
	vec4 a, b, c, d;
	a = (vec4){2147483647, 4294967295, 4294967295, 4294967295};
	b = (vec4){2147483647, 2, 2, 2};
	d = (vec4){2147483647, 2, 4, 8};
	c = (vec4){0, 0, 0, 0};
	
	uint32_t * Pa = (uint32_t*) &a;
	uint32_t * Pb = (uint32_t*) &b;
	uint32_t * Pd = (uint32_t*) &d;
	uint32_t * Pc = (uint32_t*) &c;
	
	c = a+b+d;
	
//	for(int i = 0; i < 4; i++)
//	{
//		std::cout << i << " : " << (uint32_t) Pc[i] << " = " << (uint32_t) Pa[i] << " + " 
//				<< (uint32_t)Pb[i] << " + " << (uint32_t)Pd[i] << std::endl;
//	}
//	
//	vectorPrint(" a ", a);
//	vectorPrint(" b ", b);
//	vectorPrint(" c ", c);
//	vectorPrint(" d ", d);
}

void basicTest()
{
	uint32_t a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, c3, c4, d1, d2, d3, d4;
	a1 = 2147483647;
	a2 = 4294967295;
	a3 = 4294967295;
	a4 = 4294967295;
	
	b1 = 2147483647;
	b2 = 2;
	b3 = 2;
	b4 = 2;
	
	d1 = 2147483647;
	d2 = 2;
	d2 = 4;
	d2 = 8;
	
	c1 = a1+b1+d1;
	c2 = a2+b2+d2;
	c3 = a3+b3+d3;
	c4 = a4+b4+d4;
}
int main(int argc, char *argv[])
{

	printf("hello!!!");
    transform_password(passwd1, passwd2);

    union Block in_block0, in_block1, in_block2, in_block3;
    union Hash hash; // hashes are initialized in constructor

    // For loop parameters
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
    #pragma omp parallel sections num_threads(_threads_) firstprivate(in_block0, in_block1, in_block2, in_block3) private(hash,i)
    {
        #pragma omp section
        {
//            for (i = D6; i < D6+1; i++)
            for (i = 0; i < N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);

                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        // for 1 thread, comment after here.
        #pragma omp section
        {
            for (i = N / _threads_; i < 2 * N / _threads_; i++)
            {
              write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
              F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
              }
        }
        // for 2 threads, comment after here.
        #pragma omp section
        {
            for (i = 2 * N / _threads_; i < 3 * N / _threads_; i++)
            {
				write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        #pragma omp section
        {
            for (i = 3 * N / _threads_; i < 4 * N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        // for 4 threads, comment after here
        
        #pragma omp section
        {
            for (i = 4 * N / _threads_; i < 5 * N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        #pragma omp section
        {
            for (i = 5 * N / _threads_; i < 6 * N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        #pragma omp section
        {
            for (i = 6 * N / _threads_; i < 7 * N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        
        #pragma omp section
        {
            for (i = 7 * N / _threads_; i < 8 * N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        // for 8 threads, comment after here
        #pragma omp section
        {
            for (i = 8 * N / _threads_; i < 9 * N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        #pragma omp section
        {
            for (i = 9 * N / _threads_; i < 10 * N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        #pragma omp section
        {
            for (i = 10 * N / _threads_; i < 11 * N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        #pragma omp section
        {
            for (i = 11 * N / _threads_; i < 12 * N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        #pragma omp section
        {
            for (i = 12 * N / _threads_; i < 13 * N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        #pragma omp section
        {
            for (i = 13 * N / _threads_; i < 14 * N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        #pragma omp section
        {
            for (i = 14 * N / _threads_; i < 15 * N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        #pragma omp section
        {
            for (i = 15 * N / _threads_; i < 16 * N / _threads_; i++)
            {
                write_pass(&in_block0, &in_block1, &in_block2, &in_block3, i);
  //              init(&hash);
                F_MD5(&in_block0, &in_block1, &in_block2, &in_block3);// Perform MD5 sum
            }
        }
        // 
    }
    final_time = clock();

    double hashpersec = N / ((final_time - start_time) / 1000000);
    printf("%lu hashes\n", N);
    printf("%f milliseconds\n", (int)(final_time - start_time) / 1000.0);
    printf("%f hashes/sec.\n", hashpersec);
	printf("%s\n%s\n%s\n%s", in_block0._64, in_block1._64, in_block2._64, in_block3._64);
    // printf("Speed: %.1f MiB/s\n", (double)N * 64 / (clock() - start_time) * CLOCKS_PER_SEC / 1048576.0);
    return 0;
}

void write_pass(union Block *in_block0, union Block *in_block1, union Block *in_block2, union Block *in_block3, uint64_t i)
{
    int len;
	
    in_block0->_8[0] = alph((i - D6) % E1);
    in_block0->_8[1] = alph((((i - D6) / E1) % E1));
    in_block0->_8[2] = alph((((i - D6) / E2) % E1));
    in_block0->_8[3] = alph((((i - D6) / E3) % E1));
    in_block0->_8[4] = alph((((i - D6) / E4) % E1));
    in_block0->_8[5] = alph((((i - D6) / E5) % E1));
    in_block0->_8[6] = alph((((i - D6) / E6) % E1));
    len = 7;
    in_block0->_8[len] = 0x80;
    memset(&in_block0->_8[len + 1], 0, 63 - len);
    in_block0->_64[7] = len * 8;
	
    in_block1->_8[0] = alph((i + IFACTOR1 - D6) % E1);
    in_block1->_8[1] = alph((((i + IFACTOR1 - D6) / E1) % E1));
    in_block1->_8[2] = alph((((i + IFACTOR1 - D6) / E2) % E1));
    in_block1->_8[3] = alph((((i + IFACTOR1 - D6) / E3) % E1));
    in_block1->_8[4] = alph((((i + IFACTOR1 - D6) / E4) % E1));
    in_block1->_8[5] = alph((((i + IFACTOR1 - D6) / E5) % E1));
    in_block1->_8[6] = alph((((i + IFACTOR1 - D6) / E6) % E1));
    len = 7;
    in_block1->_8[len] = 0x80;
    memset(&in_block1->_8[len + 1], 0, 63 - len);
    in_block1->_64[7] = len * 8;
	
    in_block2->_8[0] = alph((i + IFACTOR2 - D6) % E1);
    in_block2->_8[1] = alph((((i + IFACTOR2 - D6) / E1) % E1));
    in_block2->_8[2] = alph((((i + IFACTOR2 - D6) / E2) % E1));
    in_block2->_8[3] = alph((((i + IFACTOR2 - D6) / E3) % E1));
    in_block2->_8[4] = alph((((i + IFACTOR2 - D6) / E4) % E1));
    in_block2->_8[5] = alph((((i + IFACTOR2 - D6) / E5) % E1));
    in_block2->_8[6] = alph((((i + IFACTOR2 - D6) / E6) % E1));
    len = 7;
    in_block2->_8[len] = 0x80;
    memset(&in_block2->_8[len + 1], 0, 63 - len);
    in_block2->_64[7] = len * 8;
	
    in_block3->_8[0] = alph((i + IFACTOR3 - D6) % E1);
    in_block3->_8[1] = alph((((i + IFACTOR3 - D6) / E1) % E1));
    in_block3->_8[2] = alph((((i + IFACTOR3 - D6) / E2) % E1));
    in_block3->_8[3] = alph((((i + IFACTOR3 - D6) / E3) % E1));
    in_block3->_8[4] = alph((((i + IFACTOR3 - D6) / E4) % E1));
    in_block3->_8[5] = alph((((i + IFACTOR3 - D6) / E5) % E1));
    in_block3->_8[6] = alph((((i + IFACTOR3 - D6) / E6) % E1));
    len = 7;
    in_block3->_8[len] = 0x80;
    memset(&in_block3->_8[len + 1], 0, 63 - len);
    in_block3->_64[7] = len * 8;

}
void init(union Hash *ha)
/* This function is now obselete */
{
    ha->_32[0] = 0x67452301;
    ha->_32[1] = 0xefcdab89;
    ha->_32[2] = 0x98badcfe;
    ha->_32[3] = 0x10325476;
}

void F_MD5(union Block *b0, union Block *b1, union Block *b2, union Block *b3)
{
	vec4 a_vec, b_vec, c_vec, d_vec;
	a_vec = (vec4) {0x67452301, 0x67452301, 0x67452301, 0x67452301};
	b_vec = (vec4) {0xefcdab89, 0xefcdab89, 0xefcdab89, 0xefcdab89};
	c_vec = (vec4) {0x98badcfe, 0x98badcfe, 0x98badcfe, 0x98badcfe};
	d_vec = (vec4) {0x10325476, 0x10325476, 0x10325476, 0x10325476};
	
    /*
        optimization. We aren't ever hashing multiple times. 
        This means that we can use constants here. Only assign
        the hash value at the very end. 
    */

    /* 
        Optimization. Instead of assign a=val; Just create a 
        FF1 function that has the values hard coded into it. 
    */


//#ifdef UNROLLED
    /*
        Optimization. Our passwords will only have 2 things change:
            1. initial 10 characters + padding. bl->32[0-3]
            2. final 64 bits. Really just bl->32[14]
        Hardcode every other value as a 0. 
    */ 


    /* Round 1 */
    FF (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[ 0], b1->_32[ 0], b2->_32[ 0], b3->_32[ 0]}), S11, 0xd76aa478); /* 1 */
    FF (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[ 1], b1->_32[ 1], b2->_32[ 1], b3->_32[ 1]}), S12, 0xe8c7b756); /* 2 */
    FF (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[ 2], b1->_32[ 2], b2->_32[ 2], b3->_32[ 2]}), S13, 0x242070db); /* 3 */
    FF (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[ 3], b1->_32[ 3], b2->_32[ 3], b3->_32[ 3]}), S14, 0xc1bdceee); /* 4 */
    FF (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[ 4], b1->_32[ 4], b2->_32[ 4], b3->_32[ 4]}), S11, 0xf57c0faf); /* 5 */
    FF (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[ 5], b1->_32[ 5], b2->_32[ 5], b3->_32[ 5]}), S12, 0x4787c62a); /* 6 */
    FF (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[ 6], b1->_32[ 6], b2->_32[ 6], b3->_32[ 6]}), S13, 0xa8304613); /* 7 */
    FF (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[ 7], b1->_32[ 7], b2->_32[ 7], b3->_32[ 7]}), S14, 0xfd469501); /* 8 */
    FF (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[ 8], b1->_32[ 8], b2->_32[ 8], b3->_32[ 8]}), S11, 0x698098d8); /* 9 */
    FF (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[ 9], b1->_32[ 9], b2->_32[ 9], b3->_32[ 9]}), S12, 0x8b44f7af); /* 10 */
    FF (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[10], b1->_32[10], b2->_32[10], b3->_32[10]}), S13, 0xffff5bb1); /* 11 */
    FF (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[11], b1->_32[11], b2->_32[11], b3->_32[11]}), S14, 0x895cd7be); /* 12 */
    FF (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[12], b1->_32[12], b2->_32[12], b3->_32[12]}), S11, 0x6b901122); /* 13 */
    FF (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[13], b1->_32[13], b2->_32[13], b3->_32[13]}), S12, 0xfd987193); /* 14 */
    FF (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[14], b1->_32[14], b2->_32[14], b3->_32[14]}), S13, 0xa679438e); /* 15 */
    FF (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[15], b1->_32[15], b2->_32[15], b3->_32[15]}), S14, 0x49b40821); /* 16 */

    /* Round 2 */
    GG (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[ 1], b1->_32[ 1], b2->_32[ 1], b3->_32[ 1]}), S21, 0xf61e2562); /* 17 */
    GG (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[ 6], b1->_32[ 6], b2->_32[ 6], b3->_32[ 6]}), S22, 0xc040b340); /* 18 */
    GG (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[11], b1->_32[11], b2->_32[11], b3->_32[11]}), S23, 0x265e5a51); /* 19 */
    GG (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[ 0], b1->_32[ 0], b2->_32[ 0], b3->_32[ 0]}), S24, 0xe9b6c7aa); /* 20 */
    GG (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[ 5], b1->_32[ 5], b2->_32[ 5], b3->_32[ 5]}), S21, 0xd62f105d); /* 21 */
    GG (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[10], b1->_32[10], b2->_32[10], b3->_32[10]}), S22,  0x2441453); /* 22 */
    GG (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[15], b1->_32[15], b2->_32[15], b3->_32[15]}), S23, 0xd8a1e681); /* 23 */
    GG (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[ 4], b1->_32[ 4], b2->_32[ 4], b3->_32[ 4]}), S24, 0xe7d3fbc8); /* 24 */
    GG (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[ 9], b1->_32[ 9], b2->_32[ 9], b3->_32[ 9]}), S21, 0x21e1cde6); /* 25 */
    GG (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[14], b1->_32[14], b2->_32[14], b3->_32[14]}), S22, 0xc33707d6); /* 26 */
    GG (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[ 3], b1->_32[ 3], b2->_32[ 3], b3->_32[ 3]}), S23, 0xf4d50d87); /* 27 */
    GG (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[ 8], b1->_32[ 8], b2->_32[ 8], b3->_32[ 8]}), S24, 0x455a14ed); /* 28 */
    GG (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[13], b1->_32[13], b2->_32[13], b3->_32[13]}), S21, 0xa9e3e905); /* 29 */
    GG (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[ 2], b1->_32[ 2], b2->_32[ 2], b3->_32[ 2]}), S22, 0xfcefa3f8); /* 30 */
    GG (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[ 7], b1->_32[ 7], b2->_32[ 7], b3->_32[ 7]}), S23, 0x676f02d9); /* 31 */
    GG (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[12], b1->_32[12], b2->_32[12], b3->_32[12]}), S24, 0x8d2a4c8a); /* 32 */

    /* Round 3 */
    HH (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[ 5], b1->_32[ 5], b2->_32[ 5], b3->_32[ 5]}), S31, 0xfffa3942); /* 33 */
    HH (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[ 8], b1->_32[ 8], b2->_32[ 8], b3->_32[ 8]}), S32, 0x8771f681); /* 34 */
    HH (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[11], b1->_32[11], b2->_32[11], b3->_32[11]}), S33, 0x6d9d6122); /* 35 */
    HH (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[14], b1->_32[14], b2->_32[14], b3->_32[14]}), S34, 0xfde5380c); /* 36 */
    HH (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[ 1], b1->_32[ 1], b2->_32[ 1], b3->_32[ 1]}), S31, 0xa4beea44); /* 37 */
    HH (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[ 4], b1->_32[ 4], b2->_32[ 4], b3->_32[ 4]}), S32, 0x4bdecfa9); /* 38 */
    HH (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[ 7], b1->_32[ 7], b2->_32[ 7], b3->_32[ 7]}), S33, 0xf6bb4b60); /* 39 */
    HH (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[10], b1->_32[10], b2->_32[10], b3->_32[10]}), S34, 0xbebfbc70); /* 40 */
    HH (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[13], b1->_32[13], b2->_32[13], b3->_32[13]}), S31, 0x289b7ec6); /* 41 */
    HH (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[ 0], b1->_32[ 0], b2->_32[ 0], b3->_32[ 0]}), S32, 0xeaa127fa); /* 42 */
    HH (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[ 3], b1->_32[ 3], b2->_32[ 3], b3->_32[ 3]}), S33, 0xd4ef3085); /* 43 */
    HH (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[ 6], b1->_32[ 6], b2->_32[ 6], b3->_32[ 6]}), S34, 0x04881d05); /* 44 */
    HH (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[ 9], b1->_32[ 9], b2->_32[ 9], b3->_32[ 9]}), S31, 0xd9d4d039); /* 45 */
    HH (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[12], b1->_32[12], b2->_32[12], b3->_32[12]}), S32, 0xe6db99e5); /* 46 */
    HH (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[15], b1->_32[15], b2->_32[15], b3->_32[15]}), S33, 0x1fa27cf8); /* 47 */
    HH (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[ 2], b1->_32[ 2], b2->_32[ 2], b3->_32[ 2]}), S34, 0xc4ac5665); /* 48 */

    /* Round 4 */
    II (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[ 0], b1->_32[ 0], b2->_32[ 0], b3->_32[ 0]}), S41, 0xf4292244); /* 49 */
    II (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[ 7], b1->_32[ 7], b2->_32[ 7], b3->_32[ 7]}), S42, 0x432aff97); /* 50 */
    II (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[14], b1->_32[14], b2->_32[14], b3->_32[14]}), S43, 0xab9423a7); /* 51 */
    II (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[ 5], b1->_32[ 5], b2->_32[ 5], b3->_32[ 5]}), S44, 0xfc93a039); /* 52 */
    II (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[12], b1->_32[12], b2->_32[12], b3->_32[12]}), S41, 0x655b59c3); /* 53 */
    II (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[ 3], b1->_32[ 3], b2->_32[ 3], b3->_32[ 3]}), S42, 0x8f0ccc92); /* 54 */
    II (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[10], b1->_32[10], b2->_32[10], b3->_32[10]}), S43, 0xffeff47d); /* 55 */
    II (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[ 1], b1->_32[ 1], b2->_32[ 1], b3->_32[ 1]}), S44, 0x85845dd1); /* 56 */
    II (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[ 8], b1->_32[ 8], b2->_32[ 8], b3->_32[ 8]}), S41, 0x6fa87e4f); /* 57 */
    II (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[15], b1->_32[15], b2->_32[15], b3->_32[15]}), S42, 0xfe2ce6e0); /* 58 */
    II (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[ 6], b1->_32[ 6], b2->_32[ 6], b3->_32[ 6]}), S43, 0xa3014314); /* 59 */
    II (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[13], b1->_32[13], b2->_32[13], b3->_32[13]}), S44, 0x4e0811a1); /* 60 */
    II (a_vec, b_vec, c_vec, d_vec, ((vec4){b0->_32[ 4], b1->_32[ 4], b2->_32[ 4], b3->_32[ 4]}), S41, 0xf7537e82); /* 61 */
    II (d_vec, a_vec, b_vec, c_vec, ((vec4){b0->_32[11], b1->_32[11], b2->_32[11], b3->_32[11]}), S42, 0xbd3af235); /* 62 */
    II (c_vec, d_vec, a_vec, b_vec, ((vec4){b0->_32[ 2], b1->_32[ 2], b2->_32[ 2], b3->_32[ 2]}), S43, 0x2ad7d2bb); /* 63 */
    II (b_vec, c_vec, d_vec, a_vec, ((vec4){b0->_32[ 9], b1->_32[ 9], b2->_32[ 9], b3->_32[ 9]}), S44, 0xeb86d391); /* 64 */
	
		
//	#pragma omp critical(vecPrint)
//	{
//		printf("\n%s\n%s\n%s\n%s", b0->_64, b1->_64, b2->_64, b3->_64);
//		vectorPrint("done a : ", a_vec);
//		vectorPrint("done b : ", b_vec);
//		vectorPrint("done c : ", c_vec);
//		vectorPrint("done d : ", d_vec);
//	}
	

//    ha->_32[0] += a_vec;
//    ha->_32[1] += b_vec;
//    ha->_32[2] += c_vec;
//    ha->_32[3] += d_vec;
//    ha->_32[0] += a;
//    ha->_32[1] += b;
//    ha->_32[2] += c;
//    ha->_32[3] += d;

    /* 
        Optimization
        Test if it matches the default hash. Then we can 
        return a boolean value or just output and kill here
    */

}

