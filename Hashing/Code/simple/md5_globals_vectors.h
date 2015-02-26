#ifndef _MD5_CONST_
#define _MD5_CONST_

union Block
{
    uint64_t  _64[2];
    uint32_t  _32[4];
    uint8_t   _8[16];
    Block() { // empty constructor
        memset(this->_8, 0, 16);
        };
    // Block(uint8_t length) // initialization
    // {
    //     memset(&this->_8[length + 1], 0, 55 - length);
    //     this->_64[7] = length << 3;
    //     this->_8[length] = 0x80;
    // };
};
union Hash
{
    uint64_t _64[2];
    uint32_t _32[4];
    uint8_t  _8[16];
    Hash ()
    {
        this->_32[0] = 0x67452301;
        this->_32[1] = 0xefcdab89;
        this->_32[2] = 0x98badcfe;
        this->_32[3] = 0x10325476;
    }
};

union Hash enigma;
#define transform_password( a,  b) {\
        enigma._8[0x0] = (a>> 56) &0xff;\
        enigma._8[0x1] = (a>> 48) &0xff;\
        enigma._8[0x2] = (a>> 40) &0xff;\
        enigma._8[0x3] = (a>> 32) &0xff;\
        enigma._8[0x4] = (a>> 24) &0xff;\
        enigma._8[0x5] = (a>> 16) &0xff;\
        enigma._8[0x6] = (a>>  8) &0xff;\
        enigma._8[0x7] = (a     ) &0xff;\
        enigma._8[0x8] = (b>> 56) &0xff;\
        enigma._8[0x9] = (b>> 48) &0xff;\
        enigma._8[0xa] = (b>> 40) &0xff;\
        enigma._8[0xb] = (b>> 32) &0xff;\
        enigma._8[0xc] = (b>> 24) &0xff;\
        enigma._8[0xd] = (b>> 16) &0xff;\
        enigma._8[0xe] = (b>>  8) &0xff;\
        enigma._8[0xf] = (b     ) &0xff;}
#define alph(a) ('a'+(a%26))

//original
//#define ROTATE_LEFT(x,n) ((x<<n)|(x>>(32-n)))
//#define FF(a, b, c, d, x, s, ac) { \
//        (a) += F ((b), (c), (d)) + (x) + (uint32_t)(ac); \
//        (a) = ROTATE_LEFT ((a), (s)); \
//        (a) += (b); \
//    }
//#define GG(a, b, c, d, x, s, ac) { \
//        (a) += G ((b), (c), (d)) + (x) + (uint32_t)(ac); \
//        (a) = ROTATE_LEFT ((a), (s)); \
//        (a) += (b); \
//    }
//#define HH(a, b, c, d, x, s, ac) { \
//        (a) += H ((b), (c), (d)) + (x) + (uint32_t)(ac); \
//        (a) = ROTATE_LEFT ((a), (s)); \
//        (a) += (b); \
//    }
//#define II(a, b, c, d, x, s, ac) { \
//        (a) += I ((b), (c), (d)) + (x) + (uint32_t)(ac); \
//        (a) = ROTATE_LEFT ((a), (s)); \
//        (a) += (b); \
//    }

#define F(x, y, z) ((x&y) | (~x&z))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define ROTATE_LEFT(x,n) ((x<<(vec4){n, n, n, n})|(x>>(32-(vec4){n, n, n, n})))

#define FF(a, b, c, d, x, s, ac) { \
        (a) += F ((b), (c), (d)) + (x) + (vec4){ac, ac, ac, ac}; \
        (a) = ROTATE_LEFT ((a), s); \
        (a) += (b); \
    }

#define GG(a, b, c, d, x, s, ac) { \
        (a) += G ((b), (c), (d)) + (x) + (vec4){ac, ac, ac, ac}; \
        (a) = ROTATE_LEFT ((a), (s)); \
        (a) += (b); \
    }
#define HH(a, b, c, d, x, s, ac) { \
        (a) += H ((b), (c), (d)) + (x) + (vec4){ac, ac, ac, ac}; \
        (a) = ROTATE_LEFT ((a), (s)); \
        (a) += (b); \
    }
#define II(a, b, c, d, x, s, ac) { \
        (a) += I ((b), (c), (d)) + (x) + (vec4){ac, ac, ac, ac}; \
        (a) = ROTATE_LEFT ((a), (s)); \
        (a) += (b); \
    }
	
void F_MD5(union Block *b0, union Block *b1, union Block *b2, union Block *b3, uint64_t i);
void G_MD5(union Block *b0, union Block *b1, union Block *b2, union Block *b3, uint64_t i);

void init(union Hash *ha);
void write_pass(union Block *b0, union Block *bl, union Block *b2, union Block *b3, uint64_t i);
void write_first_pass(union Block *in_block0, union Block *in_block1, union Block *in_block2, union Block *in_block3, uint64_t i);
typedef uint32_t vec4 __attribute__ ((vector_size (16)));



#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

// E10 = 26^10
#define E10 (uint64_t) 141167095653376
#define  E9 (uint64_t) 5429503678976
#define  E8 (uint64_t) 208827064576
#define  E7 (uint64_t) 8031810176
#define  E6 (uint64_t) 308915776
#define  E5 (uint64_t) 11881376
#define  E4 (uint64_t) 456976
#define  E3 (uint64_t) 17576
#define  E2 (uint64_t) 676
#define  E1 (uint64_t) 26

// D2 = E2+E1
#define D10 (uint64_t) 146813779497086
#define  D9 (uint64_t) 5646683843710
#define  D8 (uint64_t) 21718164734
#define  D7 (uint64_t) 8353082582
#define  D6 (uint64_t) 321272406
#define  D5 (uint64_t) 12356630
#define  D4 (uint64_t) 474552
#define  D3 (uint64_t) 18278
#define  D2 (uint64_t) 702
#define  D1 (uint64_t) 26


#define IFACTOR1 (uint64_t)2007952544
#define IFACTOR2 (uint64_t)4015905088
#define IFACTOR3 (uint64_t)6023857632

uint8_t alph[] = {    "abcdefghijklmnopqrstuvwxyz"};
uint32_t K[64] =
{
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
};
uint32_t S[64] =
{
    7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
    5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
    4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
    6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
};

#endif