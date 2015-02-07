/* 
 * MD5 Password testing
 * Samuel Mitchell and Nathaniel Weidler
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "md5_globals_vectors.h"
#include <omp.h>


#include <iostream>

#include <time.h>
using namespace std;

//#define N D7
#define N E7
#define _threads_ 16


// password to crack


#define passwd1 0xaebc994aa5b00a03
#define passwd2 0x08c9fd257bf63ebd
// zzzzzzz
// #define passwd1 0xf0e8fb430bbdde6a
// #define passwd2 0xe9c879a518fd895f



int main(int argc, char *argv[])
{

    printf("Seeking MD5 Password. \n\nTesting all length 7 passwords. \n");
    transform_password(passwd1, passwd2);

    union Block bl0, bl1, bl2, bl3;
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
        if no value is used here, it defaults to 5. this causes
        the first 5 hashes to be accurate, but the final hashes
        are garbage (sharing resources).

        We need to test every lowercase alpha from 1 to 10
        0x0 then 0x61 to 0x7A
    */
    #pragma omp parallel sections num_threads(_threads_) private(i,bl0, bl1, bl2, bl3)
    {
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 0; i < N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }
        // for 1 thread, comment after here.
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = N / _threads_; i < 2 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);

            }
        }
        // for 2 threads, comment after here.
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 2 * N / _threads_; i < 3 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);

            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 3 * N / _threads_; i < 4 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }
        // for 4 threads, comment after here

        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 4 * N / _threads_; i < 5 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 5 * N / _threads_; i < 6 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 6 * N / _threads_; i < 7 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }

        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 7 * N / _threads_; i < 8 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }
        // for 8 threads, comment after here
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 8 * N / _threads_; i < 9 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 9 * N / _threads_; i < 10 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 10 * N / _threads_; i < 11 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 11 * N / _threads_; i < 12 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 12 * N / _threads_; i < 13 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 13 * N / _threads_; i < 14 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 14 * N / _threads_; i < 15 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }
        #pragma omp section
        {
            uint64_t tmp = 0;
            for (i = 15 * N / _threads_; i < 16 * N / _threads_; i += 676)
            {
                write_first_pass(&bl0, &bl1, &bl2, &bl3, i); G_MD5(&bl0, &bl1, &bl2, &bl3, i );
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 4); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 4);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 8); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 8);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 12); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 12);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 16); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 16);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 20); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 20);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 24); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 24);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 28); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 28);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 32); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 32);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 36); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 36);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 40); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 40);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 44); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 44);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 48); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 48);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 52); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 52);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 56); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 56);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 60); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 60);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 64); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 64);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 68); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 68);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 72); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 72);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 76); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 76);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 80); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 80);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 84); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 84);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 88); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 88);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 92); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 92);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 96); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 96);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 100); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 100);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 104); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 104);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 108); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 108);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 112); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 112);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 116); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 116);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 120); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 120);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 124); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 124);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 128); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 128);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 132); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 132);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 136); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 136);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 140); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 140);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 144); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 144);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 148); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 148);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 152); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 152);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 156); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 156);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 160); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 160);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 164); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 164);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 168); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 168);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 172); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 172);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 176); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 176);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 180); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 180);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 184); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 184);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 188); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 188);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 192); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 192);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 196); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 196);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 200); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 200);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 204); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 204);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 208); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 208);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 212); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 212);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 216); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 216);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 220); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 220);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 224); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 224);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 228); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 228);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 232); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 232);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 236); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 236);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 240); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 240);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 244); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 244);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 248); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 248);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 252); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 252);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 256); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 256);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 260); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 260);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 264); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 264);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 268); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 268);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 272); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 272);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 276); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 276);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 280); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 280);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 284); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 284);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 288); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 288);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 292); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 292);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 296); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 296);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 300); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 300);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 304); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 304);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 308); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 308);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 312); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 312);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 316); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 316);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 320); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 320);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 324); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 324);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 328); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 328);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 332); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 332);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 336); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 336);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 340); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 340);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 344); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 344);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 348); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 348);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 352); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 352);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 356); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 356);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 360); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 360);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 364); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 364);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 368); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 368);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 372); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 372);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 376); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 376);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 380); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 380);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 384); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 384);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 388); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 388);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 392); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 392);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 396); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 396);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 400); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 400);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 404); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 404);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 408); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 408);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 412); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 412);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 416); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 416);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 420); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 420);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 424); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 424);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 428); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 428);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 432); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 432);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 436); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 436);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 440); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 440);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 444); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 444);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 448); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 448);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 452); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 452);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 456); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 456);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 460); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 460);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 464); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 464);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 468); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 468);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 472); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 472);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 476); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 476);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 480); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 480);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 484); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 484);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 488); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 488);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 492); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 492);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 496); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 496);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 500); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 500);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 504); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 504);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 508); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 508);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 512); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 512);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 516); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 516);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 520); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 520);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 524); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 524);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 528); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 528);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 532); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 532);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 536); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 536);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 540); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 540);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 544); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 544);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 548); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 548);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 552); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 552);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 556); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 556);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 560); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 560);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 564); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 564);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 568); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 568);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 572); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 572);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 576); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 576);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 580); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 580);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 584); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 584);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 588); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 588);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 592); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 592);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 596); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 596);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 600); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 600);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 604); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 604);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 608); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 608);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 612); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 612);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 616); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 616);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 620); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 620);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 624); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 624);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 628); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 628);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 632); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 632);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 636); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 636);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 640); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 640);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 644); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 644);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 648); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 648);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 652); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 652);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 656); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 656);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 660); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 660);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 664); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 664);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 668); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 668);
                write_pass(&bl0, &bl1, &bl2, &bl3, i + 672); F_MD5(&bl0, &bl1, &bl2, &bl3, i + 672);
            }
        }
    }

    printf("\n%lu hashes were calculated. \n\n", N);
    return 0;
}

void write_first_pass(union Block *in_block0, union Block *in_block1, union Block *in_block2, union Block *in_block3, uint64_t i)
{
    in_block0->_8[6] = alph(i % E1);
    in_block0->_8[5] = alph((i / E1) % E1);
    in_block1->_8[6] = alph(((i + 1)) % E1);
    in_block1->_8[5] = alph(((i + 1) / E1) % E1);
    in_block2->_8[6] = alph(((i + 2)) % E1);
    in_block2->_8[5] = alph(((i + 2) / E1) % E1);
    in_block3->_8[6] = alph(((i + 3)) % E1);
    in_block3->_8[5] = alph(((i + 3) / E1) % E1);

    in_block0->_8[4] = alph((i / E2) % E1);
    in_block0->_8[3] = alph((i / E3) % E1);
    in_block0->_8[2] = alph((i / E4) % E1);
    in_block0->_8[1] = alph((i / E5) % E1);
    in_block0->_8[0] = alph((i / E6) % E1);
    in_block0->_8[7] = 0x80;

    in_block1->_8[4] = in_block0->_8[4];
    in_block1->_8[3] = in_block0->_8[3];
    in_block1->_8[2] = in_block0->_8[2];
    in_block1->_8[1] = in_block0->_8[1];
    in_block1->_8[0] = in_block0->_8[0];
    in_block1->_8[7] = 0x80;

    in_block2->_8[4] = in_block0->_8[4];
    in_block2->_8[3] = in_block0->_8[3];
    in_block2->_8[2] = in_block0->_8[2];
    in_block2->_8[1] = in_block0->_8[1];
    in_block2->_8[0] = in_block0->_8[0];
    in_block2->_8[7] = 0x80;

    in_block3->_8[4] = in_block0->_8[4];
    in_block3->_8[3] = in_block0->_8[3];
    in_block3->_8[2] = in_block0->_8[2];
    in_block3->_8[1] = in_block0->_8[1];
    in_block3->_8[0] = in_block0->_8[0];
    in_block3->_8[7] = 0x80;
}
void write_pass(union Block *in_block0, union Block *in_block1, union Block *in_block2, union Block *in_block3, uint64_t i)
{
    in_block0->_8[6] = alph(i % E1);
    in_block0->_8[5] = alph((i / E1) % E1);
    in_block1->_8[6] = alph(((i + 1)) % E1);
    in_block1->_8[5] = alph(((i + 1) / E1) % E1);
    in_block2->_8[6] = alph(((i + 2)) % E1);
    in_block2->_8[5] = alph(((i + 2) / E1) % E1);
    in_block3->_8[6] = alph(((i + 3)) % E1);
    in_block3->_8[5] = alph(((i + 3) / E1) % E1);

    /*    int j = i;
        in_block0->_8[6] = alph(i % E1);
        in_block0->_8[5] = alph((i / E1) % E1);
        in_block0->_8[4] = alph((i / E2) % E1);
        in_block0->_8[3] = alph((i / E3) % E1);
        in_block0->_8[2] = alph((i / E4) % E1);
        in_block0->_8[1] = alph((i / E5) % E1);
        in_block0->_8[0] = alph((i / E6) % E1);
        in_block0->_8[7] = 0x80;

        i = j + 1;
        in_block1->_8[6] = alph((i) % E1);
        in_block1->_8[5] = alph((i / E1) % E1);
        in_block1->_8[4] = alph((i / E2) % E1);
        in_block1->_8[3] = alph((i / E3) % E1);
        in_block1->_8[2] = alph((i / E4) % E1);
        in_block1->_8[1] = alph((i / E5) % E1);
        in_block1->_8[0] = alph((i / E6) % E1);
        in_block1->_8[7] = 0x80;

        i = j + 2;
        in_block2->_8[6] = alph((i) % E1);
        in_block2->_8[5] = alph((i / E1) % E1);
        in_block2->_8[4] = alph((i / E2) % E1);
        in_block2->_8[3] = alph((i / E3) % E1);
        in_block2->_8[2] = alph((i / E4) % E1);
        in_block2->_8[1] = alph((i / E5) % E1);
        in_block2->_8[0] = alph((i / E6) % E1);
        in_block2->_8[7] = 0x80;

        i = j + 3;
        in_block3->_8[6] = alph((i) % E1);
        in_block3->_8[5] = alph((i / E1) % E1);
        in_block3->_8[4] = alph((i / E2) % E1);
        in_block3->_8[3] = alph((i / E3) % E1);
        in_block3->_8[2] = alph((i / E4) % E1);
        in_block3->_8[1] = alph((i / E5) % E1);
        in_block3->_8[0] = alph((i / E6) % E1);
        in_block3->_8[7] = 0x80;*/
}
void F_MD5(union Block *b0, union Block *b1, union Block *b2, union Block *b3, uint64_t i)
{
    vec4 a_vec, b_vec, c_vec, d_vec;
    a_vec = (vec4)
    {
        0x67452301, 0x67452301, 0x67452301, 0x67452301
    };
    b_vec = (vec4)
    {
        0xefcdab89, 0xefcdab89, 0xefcdab89, 0xefcdab89
    };
    c_vec = (vec4)
    {
        0x98badcfe, 0x98badcfe, 0x98badcfe, 0x98badcfe
    };
    d_vec = (vec4)
    {
        0x10325476, 0x10325476, 0x10325476, 0x10325476
    };

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
    // FF (a_vec, b_vec, c_vec, d_vec, ((vec4)
    // {
    //     b0->_32[ 0], b1->_32[ 0], b2->_32[ 0], b3->_32[ 0]
    // }), S11, 0xd76aa478); /* 1 */
    a_vec = (vec4)
    {
        b0->_32[3], b1->_32[3], b2->_32[3], b3->_32[3]
    };
    FF (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        b0->_32[ 1], b1->_32[ 1], b2->_32[ 1], b3->_32[ 1]
    }), S12, 0xe8c7b756); /* 2 */
    FF (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S13, 0x242070db); /* 3 */
    FF (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S14, 0xc1bdceee); /* 4 */
    FF (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S11, 0xf57c0faf); /* 5 */
    FF (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S12, 0x4787c62a); /* 6 */
    FF (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S13, 0xa8304613); /* 7 */
    FF (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S14, 0xfd469501); /* 8 */
    FF (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S11, 0x698098d8); /* 9 */
    FF (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S12, 0x8b44f7af); /* 10 */
    FF (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S13, 0xffff5bb1); /* 11 */
    FF (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S14, 0x895cd7be); /* 12 */
    FF (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S11, 0x6b901122); /* 13 */
    FF (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S12, 0xfd987193); /* 14 */
    FF (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        56, 56, 56, 56
    }), S13, 0xa679438e); /* 15 */
    FF (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S14, 0x49b40821); /* 16 */

    /* Round 2 */
    GG (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        b0->_32[1], b1->_32[1], b2->_32[1], b3->_32[1]
    }), S21, 0xf61e2562); /* 17 */
    GG (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S22, 0xc040b340); /* 18 */
    GG (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S23, 0x265e5a51); /* 19 */
    GG (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        b0->_32[0], b1->_32[0], b2->_32[0], b3->_32[0]
    }), S24, 0xe9b6c7aa); /* 20 */
    GG (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S21, 0xd62f105d); /* 21 */
    GG (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S22,  0x2441453); /* 22 */
    GG (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S23, 0xd8a1e681); /* 23 */
    GG (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S24, 0xe7d3fbc8); /* 24 */
    GG (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S21, 0x21e1cde6); /* 25 */
    GG (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        56, 56, 56, 56
    }), S22, 0xc33707d6); /* 26 */
    GG (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S23, 0xf4d50d87); /* 27 */
    GG (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S24, 0x455a14ed); /* 28 */
    GG (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S21, 0xa9e3e905); /* 29 */
    GG (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S22, 0xfcefa3f8); /* 30 */
    GG (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S23, 0x676f02d9); /* 31 */
    GG (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S24, 0x8d2a4c8a); /* 32 */

    /* Round 3 */
    HH (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S31, 0xfffa3942); /* 33 */
    HH (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S32, 0x8771f681); /* 34 */
    HH (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S33, 0x6d9d6122); /* 35 */
    HH (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        56, 56, 56, 56
    }), S34, 0xfde5380c); /* 36 */
    HH (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        b0->_32[1], b1->_32[1], b2->_32[1], b3->_32[1]
    }), S31, 0xa4beea44); /* 37 */
    HH (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S32, 0x4bdecfa9); /* 38 */
    HH (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S33, 0xf6bb4b60); /* 39 */
    HH (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S34, 0xbebfbc70); /* 40 */
    HH (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S31, 0x289b7ec6); /* 41 */
    HH (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        b0->_32[0], b1->_32[0], b2->_32[0], b3->_32[0]
    }), S32, 0xeaa127fa); /* 42 */
    HH (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S33, 0xd4ef3085); /* 43 */
    HH (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S34, 0x04881d05); /* 44 */
    HH (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S31, 0xd9d4d039); /* 45 */
    HH (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S32, 0xe6db99e5); /* 46 */
    HH (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S33, 0x1fa27cf8); /* 47 */
    HH (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S34, 0xc4ac5665); /* 48 */

    /* Round 4 */
    II (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        b0->_32[0], b1->_32[0], b2->_32[0], b3->_32[0]
    }), S41, 0xf4292244); /* 49 */
    II (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S42, 0x432aff97); /* 50 */
    II (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        56, 56, 56, 56
    }), S43, 0xab9423a7); /* 51 */
    II (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S44, 0xfc93a039); /* 52 */
    II (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S41, 0x655b59c3); /* 53 */
    II (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S42, 0x8f0ccc92); /* 54 */
    II (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S43, 0xffeff47d); /* 55 */
    II (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        b0->_32[1], b1->_32[1], b2->_32[1], b3->_32[1]
    }), S44, 0x85845dd1); /* 56 */
    II (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S41, 0x6fa87e4f); /* 57 */
    II (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S42, 0xfe2ce6e0); /* 58 */
    II (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S43, 0xa3014314); /* 59 */
    II (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S44, 0x4e0811a1); /* 60 */
    II (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S41, 0xf7537e82); /* 61 */
    II (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S42, 0xbd3af235); /* 62 */
    II (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S43, 0x2ad7d2bb); /* 63 */
    II (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S44, 0xeb86d391); /* 64 */

    a_vec += (vec4)
    {
        0x67452301, 0x67452301, 0x67452301, 0x67452301
    };
    b_vec += (vec4)
    {
        0xefcdab89, 0xefcdab89, 0xefcdab89, 0xefcdab89
    };
    c_vec += (vec4)
    {
        0x98badcfe, 0x98badcfe, 0x98badcfe, 0x98badcfe
    };
    d_vec += (vec4)
    {
        0x10325476, 0x10325476, 0x10325476, 0x10325476
    };

    uint32_t *vec_0 = (uint32_t *) &a_vec;
    uint32_t *vec_1 = (uint32_t *) &b_vec;
    uint32_t *vec_2 = (uint32_t *) &c_vec;
    uint32_t *vec_3 = (uint32_t *) &d_vec;


    if ((
                (vec_0[0] ^ enigma._32[0]) |
                (vec_1[0] ^ enigma._32[1]) |
                (vec_2[0] ^ enigma._32[2]) |
                (vec_3[0] ^ enigma._32[3])
            ) == 0)
    {
        printf("The password was found! \n");
        printf("\n%.7s\n", b0->_8);
    }
    else if ((
                (vec_0[1] ^ enigma._32[0]) |
                (vec_1[1] ^ enigma._32[1]) |
                (vec_2[1] ^ enigma._32[2]) |
                (vec_3[1] ^ enigma._32[3])
            ) == 0)
    {
        printf("The password was found! \n");
        printf("\n%.7s\n", b1->_8);
    }
    else if ((
                (vec_0[2] ^ enigma._32[0]) |
                (vec_1[2] ^ enigma._32[1]) |
                (vec_2[2] ^ enigma._32[2]) |
                (vec_3[2] ^ enigma._32[3])
            ) == 0)
    {
        printf("The password was found! \n");
        printf("\n%.7s\n", b2->_8);
    }
    else if ((
                (vec_0[3] ^ enigma._32[0]) |
                (vec_1[3] ^ enigma._32[1]) |
                (vec_2[3] ^ enigma._32[2]) |
                (vec_3[3] ^ enigma._32[3])
            ) == 0)
    {
        printf("The password was found! \n");
        printf("\n%.7s\n", b3->_8);
    }
}


void G_MD5(union Block *b0, union Block *b1, union Block *b2, union Block *b3, uint64_t i)
{
    vec4 a_vec, b_vec, c_vec, d_vec;
    a_vec = (vec4)
    {
        0x67452301, 0x67452301, 0x67452301, 0x67452301
    };
    b_vec = (vec4)
    {
        0xefcdab89, 0xefcdab89, 0xefcdab89, 0xefcdab89
    };
    c_vec = (vec4)
    {
        0x98badcfe, 0x98badcfe, 0x98badcfe, 0x98badcfe
    };
    d_vec = (vec4)
    {
        0x10325476, 0x10325476, 0x10325476, 0x10325476
    };

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
    FF (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        b0->_32[ 0], b1->_32[ 0], b2->_32[ 0], b3->_32[ 0]
    }), S11, 0xd76aa478); /* 1 */
    uint32_t *vec_0 = (uint32_t *) &a_vec;
    b0->_32[3] = vec_0[0];
    b1->_32[3] = vec_0[1];
    b2->_32[3] = vec_0[2];
    b3->_32[3] = vec_0[3];

    FF (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        b0->_32[ 1], b1->_32[ 1], b2->_32[ 1], b3->_32[ 1]
    }), S12, 0xe8c7b756); /* 2 */
    FF (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S13, 0x242070db); /* 3 */
    FF (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S14, 0xc1bdceee); /* 4 */
    FF (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S11, 0xf57c0faf); /* 5 */
    FF (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S12, 0x4787c62a); /* 6 */
    FF (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S13, 0xa8304613); /* 7 */
    FF (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S14, 0xfd469501); /* 8 */
    FF (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S11, 0x698098d8); /* 9 */
    FF (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S12, 0x8b44f7af); /* 10 */
    FF (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S13, 0xffff5bb1); /* 11 */
    FF (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S14, 0x895cd7be); /* 12 */
    FF (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S11, 0x6b901122); /* 13 */
    FF (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S12, 0xfd987193); /* 14 */
    FF (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        56, 56, 56, 56
    }), S13, 0xa679438e); /* 15 */
    FF (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S14, 0x49b40821); /* 16 */

    /* Round 2 */
    GG (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        b0->_32[1], b1->_32[1], b2->_32[1], b3->_32[1]
    }), S21, 0xf61e2562); /* 17 */
    GG (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S22, 0xc040b340); /* 18 */
    GG (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S23, 0x265e5a51); /* 19 */
    GG (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        b0->_32[0], b1->_32[0], b2->_32[0], b3->_32[0]
    }), S24, 0xe9b6c7aa); /* 20 */
    GG (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S21, 0xd62f105d); /* 21 */
    GG (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S22,  0x2441453); /* 22 */
    GG (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S23, 0xd8a1e681); /* 23 */
    GG (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S24, 0xe7d3fbc8); /* 24 */
    GG (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S21, 0x21e1cde6); /* 25 */
    GG (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        56, 56, 56, 56
    }), S22, 0xc33707d6); /* 26 */
    GG (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S23, 0xf4d50d87); /* 27 */
    GG (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S24, 0x455a14ed); /* 28 */
    GG (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S21, 0xa9e3e905); /* 29 */
    GG (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S22, 0xfcefa3f8); /* 30 */
    GG (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S23, 0x676f02d9); /* 31 */
    GG (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S24, 0x8d2a4c8a); /* 32 */

    /* Round 3 */
    HH (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S31, 0xfffa3942); /* 33 */
    HH (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S32, 0x8771f681); /* 34 */
    HH (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S33, 0x6d9d6122); /* 35 */
    HH (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        56, 56, 56, 56
    }), S34, 0xfde5380c); /* 36 */
    HH (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        b0->_32[1], b1->_32[1], b2->_32[1], b3->_32[1]
    }), S31, 0xa4beea44); /* 37 */
    HH (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S32, 0x4bdecfa9); /* 38 */
    HH (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S33, 0xf6bb4b60); /* 39 */
    HH (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S34, 0xbebfbc70); /* 40 */
    HH (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S31, 0x289b7ec6); /* 41 */
    HH (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        b0->_32[0], b1->_32[0], b2->_32[0], b3->_32[0]
    }), S32, 0xeaa127fa); /* 42 */
    HH (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S33, 0xd4ef3085); /* 43 */
    HH (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S34, 0x04881d05); /* 44 */
    HH (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S31, 0xd9d4d039); /* 45 */
    HH (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S32, 0xe6db99e5); /* 46 */
    HH (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S33, 0x1fa27cf8); /* 47 */
    HH (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S34, 0xc4ac5665); /* 48 */

    /* Round 4 */
    II (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        b0->_32[0], b1->_32[0], b2->_32[0], b3->_32[0]
    }), S41, 0xf4292244); /* 49 */
    II (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S42, 0x432aff97); /* 50 */
    II (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        56, 56, 56, 56
    }), S43, 0xab9423a7); /* 51 */
    II (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S44, 0xfc93a039); /* 52 */
    II (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S41, 0x655b59c3); /* 53 */
    II (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S42, 0x8f0ccc92); /* 54 */
    II (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S43, 0xffeff47d); /* 55 */
    II (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        b0->_32[1], b1->_32[1], b2->_32[1], b3->_32[1]
    }), S44, 0x85845dd1); /* 56 */
    II (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S41, 0x6fa87e4f); /* 57 */
    II (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S42, 0xfe2ce6e0); /* 58 */
    II (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S43, 0xa3014314); /* 59 */
    II (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S44, 0x4e0811a1); /* 60 */
    II (a_vec, b_vec, c_vec, d_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S41, 0xf7537e82); /* 61 */
    II (d_vec, a_vec, b_vec, c_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S42, 0xbd3af235); /* 62 */
    II (c_vec, d_vec, a_vec, b_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S43, 0x2ad7d2bb); /* 63 */
    II (b_vec, c_vec, d_vec, a_vec, ((vec4)
    {
        0, 0, 0, 0
    }), S44, 0xeb86d391); /* 64 */

    a_vec += (vec4)
    {
        0x67452301, 0x67452301, 0x67452301, 0x67452301
    };
    b_vec += (vec4)
    {
        0xefcdab89, 0xefcdab89, 0xefcdab89, 0xefcdab89
    };
    c_vec += (vec4)
    {
        0x98badcfe, 0x98badcfe, 0x98badcfe, 0x98badcfe
    };
    d_vec += (vec4)
    {
        0x10325476, 0x10325476, 0x10325476, 0x10325476
    };

    uint32_t *vec_1 = (uint32_t *) &b_vec;
    uint32_t *vec_2 = (uint32_t *) &c_vec;
    uint32_t *vec_3 = (uint32_t *) &d_vec;

    
    if ((
                (vec_0[0] ^ enigma._32[0]) |
                (vec_1[0] ^ enigma._32[1]) |
                (vec_2[0] ^ enigma._32[2]) |
                (vec_3[0] ^ enigma._32[3])
            ) == 0)
    {
        printf("The password was found! \n");
        printf("\n%.7s\n", b0->_8);
    }
    if ((
                (vec_0[1] ^ enigma._32[0]) |
                (vec_1[1] ^ enigma._32[1]) |
                (vec_2[1] ^ enigma._32[2]) |
                (vec_3[1] ^ enigma._32[3])
            ) == 0)
    {
        printf("The password was found! \n");
        printf("\n%.7s\n", b1->_8);
    }
    if ((
                (vec_0[2] ^ enigma._32[0]) |
                (vec_1[2] ^ enigma._32[1]) |
                (vec_2[2] ^ enigma._32[2]) |
                (vec_3[2] ^ enigma._32[3])
            ) == 0)
    {
        printf("The password was found! \n");
        printf("\n%.7s\n", b2->_8);
    }
    if ((
                (vec_0[3] ^ enigma._32[0]) |
                (vec_1[3] ^ enigma._32[1]) |
                (vec_2[3] ^ enigma._32[2]) |
                (vec_3[3] ^ enigma._32[3])
            ) == 0)
    {
        printf("The password was found! \n");
        printf("\n%.7s\n", b3->_8);
    }
    
/*
    return (i * ((
                     (vec_0[0] ^ enigma._32[0]) |
                     (vec_1[0] ^ enigma._32[1]) |
                     (vec_2[0] ^ enigma._32[2]) |
                     (vec_3[0] ^ enigma._32[3])
                 ) == 0)) |
           ((i + 1) * ((
                           (vec_0[1] ^ enigma._32[0]) |
                           (vec_1[1] ^ enigma._32[1]) |
                           (vec_2[1] ^ enigma._32[2]) |
                           (vec_3[1] ^ enigma._32[3])
                       ) == 0)) |
           ((i + 2) * ((
                           (vec_0[2] ^ enigma._32[0]) |
                           (vec_1[2] ^ enigma._32[1]) |
                           (vec_2[2] ^ enigma._32[2]) |
                           (vec_3[2] ^ enigma._32[3])
                       ) == 0)) |
           ((i + 3) * ((
                           (vec_0[3] ^ enigma._32[0]) |
                           (vec_1[3] ^ enigma._32[1]) |
                           (vec_2[3] ^ enigma._32[2]) |
                           (vec_3[3] ^ enigma._32[3])
                       ) == 0));
*/
    /*
        Optimization
        Test if it matches the default hash. Then we can
        return a boolean value or just output and kill here
    */

}

