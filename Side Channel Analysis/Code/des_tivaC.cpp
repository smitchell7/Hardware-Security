#include <stdint.h>
#include <lm4f120h5qr.h>

static const uint8_t Pc1[56] =
  {
   57, 49, 41, 33, 25, 17,  9,
    1, 58, 50, 42, 34, 26, 18,
   10,  2, 59, 51, 43, 35, 27,
   19, 11,  3, 60, 52, 44, 36,
   63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
   14,  6, 61, 53, 45, 37, 29,
   21, 13,  5, 28, 20, 12,  4
  };
  
static const uint8_t Pc2[48] =
  { 
  14, 17, 11, 24,  1,  5,
   3, 28, 15,  6, 21, 10,
  23, 19, 12,  4, 26,  8,
  16,  7, 27, 20, 13,  2,
  41, 52, 31, 37, 47, 55,
  30, 40, 51, 45, 33, 48,
  44, 49, 39, 56, 34, 53,
  46, 42, 50, 36, 29, 32
  };
  
static const uint8_t ipPermute[64] =
{
  58, 50, 42, 34, 26, 18, 10, 2,
  60, 52, 44, 36, 28, 20, 12, 4,
  62, 54, 46, 38, 30, 22, 14, 6,
  64, 56, 48, 40, 32, 24, 16, 8,
  57, 49, 41, 33, 25, 17,  9, 1,
  59, 51, 43, 35, 27, 19, 11, 3,
  61, 53, 45, 37, 29, 21, 13, 5,
  63, 55, 47, 39, 31, 23, 15, 7
};

static const uint8_t ePermute[48] =
{
  32,  1,  2,  3,  4,  5,
   4,  5,  6,  7,  8,  9,
   8,  9, 10, 11, 12, 13,
  12, 13, 14, 15, 16, 17,
  16, 17, 18, 19, 20, 21,
  20, 21, 22, 23, 24, 25,
  24, 25, 26, 27, 28, 29,
  28, 29, 30, 31, 32,  1
};

static const uint8_t sBox1[4][16] =
{
  14,  4, 13,  1,  2, 15,  11,  8,   3, 10,   6, 12,   5,  9,   0,  7,
   0, 15,  7,  4, 14,  2,  13,  1,  10,  6,  12, 11,   9,  5,   3,  8,
   4,  1, 14,  8, 13,  6,   2, 11,  15, 12,   9,  7,   3, 10,   5,  0,
  15, 12,  8,  2,  4,  9,   1,  7,   5, 11,   3, 14,  10,  0,   6, 13
};

static const uint8_t sBox2[4][16] =
{
  15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
   3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
   0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
  13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9
};

static const uint8_t sBox3[4][16] =
{  
  10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
  13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
  13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
   1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12
};

static const uint8_t sBox4[4][16] =
{
   7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
  13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
  10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
   3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14
};

static const uint8_t sBox5[4][16] =
{
   2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
  14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
   4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
  11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3
};

static const uint8_t sBox6[4][16] =
{
  12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
  10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
   9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
   4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13
};

static const uint8_t sBox7[4][16] =
{
   4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
  13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
   1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
   6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12
};

static const uint8_t sBox8[4][16] =
{
  13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
   1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
   7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
   2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
};

static const uint8_t p[32] =
{
  16,  7, 20, 21,
  29, 12, 28, 17,
   1, 15, 23, 26,
   5, 18, 31, 10,
   2,  8, 24, 14,
  32, 27,  3,  9,
  19, 13, 30,  6,
  22, 11,  4, 25
};

static const uint8_t inverseIP[64] =
{
  40, 8, 48, 16, 56, 24, 64, 32,
  39, 7, 47, 15, 55, 23, 63, 31,
  38, 6, 46, 14, 54, 22, 62, 30,
  37, 5, 45, 13, 53, 21, 61, 29,
  36, 4, 44, 12, 52, 20, 60, 28,
  35, 3, 43, 11, 51, 19, 59, 27,
  34, 2, 42, 10, 50, 18, 58, 26,
  33, 1, 41,  9, 49, 17, 57, 25
};

	
static const uint8_t mask[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
static const uint8_t shift[] = {7, 6, 5, 4, 3, 2, 1, 0};
	
void permute(uint8_t *src, uint8_t *dest, const uint8_t *map, const int size)
{
  for(int i = 0; i < (size/8); i++)
  {
    dest[i] = 0;
  }
  uint8_t tempByte = 0;
  uint8_t bitPos, srcPos, destPos, maskPos, destBitPos = 0;
	
  for(int i = 0; i < size; i++)
  {
    bitPos = map[i] -1 ;
    srcPos = bitPos/8;
    destPos = (i/8);
    maskPos = (bitPos%8);
    destBitPos = (i%8);
    tempByte = src[srcPos] & mask[maskPos];
    tempByte = ((!!tempByte) << shift[destBitPos]);
    
    dest[destPos] = dest[destPos] | tempByte;

  }

}

unsigned int rotate(unsigned int in, uint8_t times)
{
  unsigned int bit = 1 << 27;
  unsigned int rotateBit = 0;
  int ret = in;
  for(int i = 0; i < times; i++)
  {
    rotateBit = ret & bit;
    ret = (ret << 1) | (!!rotateBit);
    ret = ret & 0xFFFFFFF;
  }
  
  return ret;
  
}

void uintToArray2(unsigned int srcC, unsigned int srcD, uint8_t *dest)
{
  dest[0] = (srcC & 0xFF00000) >> 20;
  dest[1] = (srcC & 0xFF000)   >> 12;
  dest[2] = (srcC & 0xFF0)     >> 4;
  dest[3] = (srcC & 0x0F) << 4  | (srcD & 0xF000000) >> 24;
  dest[4] = (srcD & 0xFF0000) >> 16;
  dest[5] = (srcD & 0xFF00)   >> 8;
  dest[6] = srcD & 0xFF;
  
}

void uintToArray(unsigned int srcC, uint8_t *dest)
{
  dest[0] = (srcC & 0xFF000000) >> 24;
  dest[1] = (srcC & 0xFF0000)   >> 16;
  dest[2] = (srcC & 0xFF00)     >> 8;
  dest[3] = (srcC & 0xFF);
}

void xorArray(uint8_t * key, uint8_t * data, uint8_t * dest, int size)
{
  for(int i = 0; i < size; i++)
  {
    dest[i] = key[i] ^ data[i];
  }
}

unsigned int measure(unsigned int key, unsigned int data)
{
  unsigned int dest = 0;
  GPIOF->DATA = 0x00;
			__asm
		{
	  nop;
	  nop;
		}

  dest = key ^ data;
			__asm
		{
	  nop;
		}
  GPIOF->DATA = 0x02;
  return dest;
/*  __asm
	{
		POP           {r4-r6,pc}
    PUSH          {r4,lr}
    MOV           r2,r0
//   231:   unsigned int dest = 0; 
    MOVS          r0,#0x00
//   232:   GPIOF->DATA = 0x00; 
    MOVS          r3,#0x00
    LDR           r4,[pc,#1016]  ; @0x00000864
    STR           r3,[r4,#0x00]
//   233:   dest = key ^ data; 
    EOR           r0,r2,r1  //THIS IS ONE INSTRUCTION AFTER THE GPIO WRITE!
//   234:   GPIOF->DATA = 0x02; 
//   235:   return dest; 
    MOVS          r3,#0x02
    LDR           r4,[pc,#1008]  ; @0x00000868
    STR           r3,[r4,#0x3FC]
    }*/
}

void sBoxes(uint8_t * src, uint8_t * dest)
{
  uint8_t temp = 0;
  uint8_t col, row = 0;
    
  temp = (src[0] & 0xFC) >> 2;
  col = (temp & 0x1E) >> 1;
  row = ((temp & 0x20) >> 4) | (temp & 0x01);
  dest[0] = sBox1[row][col] << 4;
  
  temp = ((src[0] & 0x03) << 4) | ((src[1] & 0xF0) >> 4);
  col = (temp & 0x1E) >> 1;
  row = ((temp & 0x20) >> 4) | (temp & 0x01);
  dest[0] |= sBox2[row][col] ;
  
  temp = ((src[1] & 0x0F) << 2) | ((src[2] & 0xC0) >> 6);
  col = (temp & 0x1E) >> 1;
  row = ((temp & 0x20) >> 4) | (temp & 0x01);
  dest[1] = sBox3[row][col] << 4;
  
  temp = src[2] & 0x3F;
  col = (temp & 0x1E) >> 1;
  row = ((temp & 0x20) >> 4) | (temp & 0x01);
  dest[1] |= sBox4[row][col] ;
  
  temp = (src[3] & 0xFC) >> 2;
  col = (temp & 0x1E) >> 1;
  row = ((temp & 0x20) >> 4) | (temp & 0x01);
  dest[2] = sBox5[row][col] << 4;
  
  temp = ((src[3] & 0x03) << 4) | ((src[4] & 0xF0) >> 4);
  col = (temp & 0x1E) >> 1;
  row = ((temp & 0x20) >> 4) | (temp & 0x01);
  dest[2] |= sBox6[row][col];
  
  temp = ((src[4] & 0x0F) << 2) | ((src[5] & 0xC0) >> 6);
  col = (temp & 0x1E) >> 1;
  row = ((temp & 0x20) >> 4) | (temp & 0x01);
  dest[3] = sBox7[row][col] << 4;
  
  temp = src[5] & 0x3F;
  col = (temp & 0x1E) >> 1;
  row = ((temp & 0x20) >> 4) | (temp & 0x01);
  dest[3] |= sBox8[row][col];
  
}

void getNewData(uint8_t * data, int loc)
{
  int locDiv20 = loc/20;
  int locMod8 = locDiv20%8;
  if(loc == 40800 || loc == 81600)
  {
    data[0] = 0;
    data[1] = 0;
    data[2] = 0;
    data[3] = 0;
    data[4] = 0;
    data[5] = 0;
    data[6] = 0;
    data[7] = 0;
  }
  
  if(loc < 40800)
  {
    switch(locMod8)
    {
      case 0 :
      data[0] = data[7]+1;
      data[7] = 0;
      break;
    case 1 :
      data[1] = data[0];
      data[0] = 0;
      break;
    case 2	:
      data[2] = data[1];
      data[1] = 0;
      break;
    case 3 :
      data[3] = data[2];
      data[2] = 0;
      break;
    case 4 :
      data[4] = data[3];
      data[3] = 0;
      break;
    case 5 :
      data[5] = data[4];
      data[4] = 0;
      break;
    case 6 :
      data[6] = data[5];
      data[5] = 0;
      break;
    case 7 :
      data[7] = data[6];
      data[6] = 0;
      break;
    default:
      break;
    }
  }
  else if( loc < 81600)
  {
    switch(locMod8)
    {
    case 0 :
      data[0] = data[7]+1;
      break;
    case 1 :
      data[1] = data[0];
      break;
    case 2	:
      data[2] = data[1];
      break;
    case 3 :
      data[3] = data[2];
      break;
    case 4 :
      data[4] = data[3];
      break;
    case 5 :
      data[5] = data[4];
      break;
    case 6 :
      data[6] = data[5];
      break;
    case 7 :
      data[7] = data[6];
      break;
    default:
      break;
    }
  }
  else
  {
    for(int i = 0; i < 8; i++)
    {
      data[i] = data[i]+1;
    }
  }
}


int main()
{
  SYSCTL->RCGCGPIO = 0x20;  // set bit 5 to enable Port F (needed for the LEDS)
  GPIOF->DIR = 0xE; // setting the GPIO for the LEDS to be outputs bits 1, 2 and 3
  GPIOF->DEN = 0xE; //GPIOF digital enable 
  GPIOF->DATA = 0x2;
	//the key! 6a65786a65786a65
  uint8_t key[8] = {0x6a, 0x65, 0x78, 0x6a, 0x65, 0x78, 0x6a, 0x65};
  uint8_t pKey[7] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t data[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  uint8_t prePC2[7] = {0, 0, 0, 0, 0, 0, 0};
  uint8_t ip[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  uint8_t e[6] = {0, 0, 0, 0, 0, 0};
  uint8_t rArray[4] = {0, 0, 0, 0};
  uint8_t lArray[4] = {0, 0, 0, 0};
  uint8_t rotateNum[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
  
  uint8_t final[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  uint8_t preFinalPermute[8] =  {0, 0, 0, 0, 0, 0, 0, 0};
  
  uint8_t funcPart1[6] = {0, 0, 0, 0, 0, 0};
  uint8_t funcPart2[4] = {0, 0, 0, 0};
  uint8_t funcFinal[4] = {0, 0, 0, 0};
  
  unsigned int C = 0;
  unsigned int D = 0;
  unsigned int lLast, lNext = 0;
  unsigned int R = 0;
  
  unsigned int measureLArray, measureFuncFinal = 0;
	
  //initial delay to allow o-scope to setup to ensure it gets the first trace.
	for(unsigned i = 0; i < 0x7F0000; i++)
	{
		__asm
		{
	  nop;
		}
	}
	for(unsigned i = 0; i < 0x7F0000; i++)
	{
		__asm
		{
	  nop;
		}
	}
  
	for(int i = 0; i < 91840; i++)
	{
		if(i%20 == 0)
		{
		  getNewData(data, i);
		}
  
  uint8_t roundKey[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};	
  C = 0;
  D = 0;
  lLast = 0;
  lNext = 0;
  R = 0;

  permute(key, pKey, Pc1, 56);	
  
  C = (pKey[0] << 20) | (pKey[1] << 12) | (pKey[2] << 4) | (pKey[3] >> 4);
  D = ((pKey[3] & 0x0F) << 24) | (pKey[4] << 16) | (pKey[5] << 8) | (pKey[6]);
  		
  permute(data, ip, ipPermute, 64);	
  
  lLast = (ip[0] << 24) | (ip[1] << 16) | (ip[2] << 8) | (ip[3]);
  R = (ip[4] << 24) | (ip[5] << 16) | (ip[6] << 8) | (ip[7]);
  uintToArray(R, rArray);
  
  lNext =  R;
  
  //First 15 rounds
  for(int round = 0; round < 15; round++)
  {
    C = rotate(C, rotateNum[round]);
    D = rotate(D, rotateNum[round]);
  
    uintToArray2(C, D, prePC2);
    permute(prePC2, roundKey, Pc2, 48);
    
    permute(rArray, e, ePermute, 48);
    
    xorArray(roundKey, e, funcPart1, 6);
    
    sBoxes(funcPart1, funcPart2);
    
    permute(funcPart2, funcFinal, p, 32);
    
    uintToArray(lLast, lArray);
    xorArray(lArray, funcFinal, rArray, 4);
    
    R = (rArray[0] << 24) | (rArray[1] << 16) | (rArray[2] << 8) | rArray[3];
    lLast = lNext;
    lNext =  R;
  
  }
  
  //Last round
  C = rotate(C, rotateNum[15]);
  D = rotate(D, rotateNum[15]);
  
  uintToArray2(C, D, prePC2);
  permute(prePC2, roundKey, Pc2, 48);
  
  permute(rArray, e, ePermute, 48);
  
  xorArray(roundKey, e, funcPart1, 6);
  
  sBoxes(funcPart1, funcPart2);
  
  permute(funcPart2, funcFinal, p, 32);
  
  uintToArray(lLast, lArray);
  xorArray(lArray, funcFinal, rArray, 4);
  measureLArray = 0;
  measureFuncFinal = 0;
  measureLArray = (lArray[0] << 24) | (lArray[1] << 16) | (lArray[2] << 8) | lArray[3];
  measureFuncFinal = (funcFinal[0] << 24) | (funcFinal[1] << 16) | (funcFinal[2] << 8) | funcFinal[3];
  R = measure(measureLArray, measureFuncFinal);

  rArray[0] = ((R & 0xFF000000) >> 24);
  rArray[1] = ((R & 0x00FF0000) >> 16);
  rArray[2] = ((R & 0x0000FF00) >> 8);
  rArray[3] = ((R & 0x000000FF) >> 0);
  
  lLast = lNext;
  lNext =  R;
  
  preFinalPermute[0] = rArray[0], 
  preFinalPermute[1] = rArray[1], 
  preFinalPermute[2] = rArray[2], 
  preFinalPermute[3] = rArray[3], 
  preFinalPermute[4] = (lLast & 0xFF000000) >> 24,
  preFinalPermute[5] = (lLast & 0xFF0000) >> 16,
  preFinalPermute[6] = (lLast & 0xFF00) >> 8,
  preFinalPermute[7] = (lLast & 0xFF);
  
  
  permute(preFinalPermute, final, inverseIP, 64);  
	 
  //delay between each round to allow o-scope the re-arm
	for(unsigned i = 0; i < 0x440000; i++)
	{
		__asm
		{
	  nop;
		}
	}
}


}






















