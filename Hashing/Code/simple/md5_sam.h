#ifndef _MD5_CONST_
#define _MD5_CONST_


/* 
    Block was formerly the full 512-bit MD5. 
    This was illogical, as a 10-byte password 
    will generate a total of 11-bytes plus a 
    1-byte length value. 

    The 1-byte length value _32[3] is written as 
    a 32 bit type for simplicity in writing. 

    The block is now 128 bits. 
*/
union Block
{
    // uint64_t  _64[8];
    uint32_t  _32[4];
    uint8_t   _8[16];
    Block() // initialization
    {
        // memset(&this->_8[0], 0, 64);
    };
};
union Hash
{
    uint64_t _64[2];
    uint32_t _32[4];
    uint8_t  _8[16];
    Hash (){};
};
void F_MD5(union Block *bl, union Hash *ha);
void init(union Hash *ha);
void write_pass(union Block *bl, uint64_t i);
void test_hash(union Hash *ha, union Hash *en, union Block *in_block);

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
#define alph(a) ('a'+a)

#define ROTATE_LEFT(x,n) ((x<<n)|(x>>(32-n)))

#define F(x, y, z) ((x&y) | (~x&z))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define FF1(a, b, c, d, x, s, ac) { \
        (a) = HASH_BASE_A + (F ((HASH_BASE_B), (HASH_BASE_C), (HASH_BASE_D)) + (x) + (uint32_t)(ac)); \
        (a) = ROTATE_LEFT ((a), (s)); \
        (a) += (b); \
    }
#define FF(a, b, c, d, x, s, ac) { \
        (a) += F ((b), (c), (d)) + (x) + (uint32_t)(ac); \
        (a) = ROTATE_LEFT ((a), (s)); \
        (a) += (b); \
    }
#define GG(a, b, c, d, x, s, ac) { \
        (a) += G ((b), (c), (d)) + (x) + (uint32_t)(ac); \
        (a) = ROTATE_LEFT ((a), (s)); \
        (a) += (b); \
    }
#define HH(a, b, c, d, x, s, ac) { \
        (a) += H ((b), (c), (d)) + (x) + (uint32_t)(ac); \
        (a) = ROTATE_LEFT ((a), (s)); \
        (a) += (b); \
    }
#define II(a, b, c, d, x, s, ac) { \
        (a) += I ((b), (c), (d)) + (x) + (uint32_t)(ac); \
        (a) = ROTATE_LEFT ((a), (s)); \
        (a) += (b); \
    }

// initial values for the hash. 
#define HASH_BASE_A 0x67452301
#define HASH_BASE_B 0xefcdab89
#define HASH_BASE_C 0x98badcfe
#define HASH_BASE_D 0x10325476

// The rotate parameters
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

/*
uint8_t alph[] =
{
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
    'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};
*/
#endif