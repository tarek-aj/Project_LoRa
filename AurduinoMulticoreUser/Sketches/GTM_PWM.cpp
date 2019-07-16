#include "arduino.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


typedef struct
{
    float32 sysFreq;                /**< \brief Actual SPB frequency */
    float32 cpuFreq;                /**< \brief Actual CPU frequency */
    float32 pllFreq;                /**< \brief Actual PLL frequency */
    float32 stmFreq;                /**< \brief Actual STM frequency */
} AppInfo;

/** \brief Application information */
typedef struct
{
    AppInfo info;                               /**< \brief Info object */
} App_Cpu0;


App_Cpu0 g_AppCpu0;

union freq { uint16 accumulator  ;
             uint8 acc_bytes[2] ; } ;



union freq freq0, freq1, freq2 ;

uint32 volatile NextCycle;
float ThisSineValue;
uint16 motor_frequency = 2000;
uint8 rxdata;

uint32 IntCounter = 0u;

// Defined at the bottom of this file
extern sint16 const ref_sine_table[4][256];

/*** Core 0 ***/

void SynthTimebase(void);

void setup() {
  // put your setup code for core 0 here, to run once:

	// 10 bit resolution
	analogWriteResolution(10);

	/* Set 120 phase angles */
	freq0.acc_bytes[1] = 0   ;   /* 0 deg   */
	freq1.acc_bytes[1] = 85  ;   /* 120 deg */
	freq2.acc_bytes[1] = 170 ;   /* 240 deg */

	// Make a continuous interrupt, period = 10000u => 100us
	CreateTimerInterrupt(ContinuousTimerInterrupt, 10000u , SynthTimebase);

	// Enable the LED pin
	pinMode(13, OUTPUT);

}



void loop() {
  // put your main code for core 0 here, to run repeatedly:

}


/* Called every 100us */
void SynthTimebase(void)
{

	analogWrite(2, (512 + ref_sine_table[1][freq0.acc_bytes[1]]));
	analogWrite(3, (512 + ref_sine_table[1][freq1.acc_bytes[1]]));
	analogWrite(4, (512 + ref_sine_table[1][freq2.acc_bytes[1]]));

	freq0.accumulator += motor_frequency ;
	freq1.accumulator += motor_frequency ;
	freq2.accumulator += motor_frequency ;

    digitalWrite(13,(IntCounter++ & 0x01u));

}


/*** Core 1 ***/
void setup1() {
  // put your setup code for core 1 here, to run once:


	}


void loop1() {
  // put your main code core 1 here, to run repeatedly:


}



/*** Core 2 ***/
void setup2() {
  // put your setup code for core 2 here, to run once:


}

void loop2() {
  // put your main code core 2 here, to run repeatedly:




}


/*** Automatically Generated Table ***/
/* 11, 10, 8, 7 bit resolutions */

sint16 const ref_sine_table[4][256] = {
    {
     0,
     27,
     54,
     81,
     107,
     134,
     161,
     187,
     213,
     239,
     265,
     291,
     316,
     341,
     366,
     391,
     415,
     439,
     462,
     486,
     508,
     531,
     553,
     574,
     595,
     616,
     636,
     656,
     675,
     694,
     712,
     730,
     747,
     763,
     780,
     795,
     810,
     825,
     839,
     852,
     865,
     878,
     890,
     901,
     912,
     922,
     932,
     941,
     949,
     958,
     965,
     972,
     979,
     985,
     990,
     995,
     999,
     1003,
     1007,
     1010,
     1012,
     1014,
     1015,
     1016,
     1016,
     1016,
     1015,
     1014,
     1012,
     1010,
     1007,
     1003,
     999,
     995,
     990,
     985,
     979,
     972,
     965,
     958,
     949,
     941,
     932,
     922,
     912,
     901,
     890,
     878,
     865,
     852,
     839,
     825,
     810,
     795,
     780,
     763,
     747,
     730,
     712,
     694,
     675,
     656,
     636,
     616,
     595,
     574,
     553,
     531,
     508,
     486,
     462,
     439,
     415,
     391,
     366,
     341,
     316,
     291,
     265,
     239,
     213,
     187,
     161,
     134,
     107,
     81,
     54,
     27,
     0,
     -27,
     -54,
     -81,
     -107,
     -134,
     -161,
     -187,
     -213,
     -239,
     -265,
     -291,
     -316,
     -341,
     -366,
     -391,
     -415,
     -439,
     -462,
     -486,
     -508,
     -531,
     -553,
     -574,
     -595,
     -616,
     -636,
     -656,
     -675,
     -694,
     -712,
     -730,
     -747,
     -763,
     -780,
     -795,
     -810,
     -825,
     -839,
     -852,
     -865,
     -878,
     -890,
     -901,
     -912,
     -922,
     -932,
     -941,
     -949,
     -958,
     -965,
     -972,
     -979,
     -985,
     -990,
     -995,
     -999,
     -1003,
     -1007,
     -1010,
     -1012,
     -1014,
     -1015,
     -1016,
     -1016,
     -1016,
     -1015,
     -1014,
     -1012,
     -1010,
     -1007,
     -1003,
     -999,
     -995,
     -990,
     -985,
     -979,
     -972,
     -965,
     -958,
     -949,
     -941,
     -932,
     -922,
     -912,
     -901,
     -890,
     -878,
     -865,
     -852,
     -839,
     -825,
     -810,
     -795,
     -780,
     -763,
     -747,
     -730,
     -712,
     -694,
     -675,
     -656,
     -636,
     -616,
     -595,
     -574,
     -553,
     -531,
     -508,
     -486,
     -462,
     -439,
     -415,
     -391,
     -366,
     -341,
     -316,
     -291,
     -265,
     -239,
     -213,
     -187,
     -161,
     -134,
     -107,
     -81,
     -54,
     -27,
    },
    {
     0,
     13,
     27,
     40,
     53,
     67,
     80,
     93,
     106,
     119,
     132,
     144,
     157,
     169,
     182,
     194,
     206,
     218,
     229,
     241,
     252,
     263,
     274,
     285,
     295,
     306,
     316,
     325,
     335,
     344,
     353,
     362,
     371,
     379,
     387,
     395,
     402,
     409,
     416,
     423,
     429,
     435,
     441,
     447,
     452,
     457,
     462,
     467,
     471,
     475,
     479,
     482,
     486,
     488,
     491,
     494,
     496,
     498,
     499,
     501,
     502,
     503,
     503,
     504,
     504,
     504,
     503,
     503,
     502,
     501,
     499,
     498,
     496,
     494,
     491,
     488,
     486,
     482,
     479,
     475,
     471,
     467,
     462,
     457,
     452,
     447,
     441,
     435,
     429,
     423,
     416,
     409,
     402,
     395,
     387,
     379,
     371,
     362,
     353,
     344,
     335,
     325,
     316,
     306,
     295,
     285,
     274,
     263,
     252,
     241,
     229,
     218,
     206,
     194,
     182,
     169,
     157,
     144,
     132,
     119,
     106,
     93,
     80,
     67,
     53,
     40,
     27,
     13,
     0,
     -13,
     -27,
     -40,
     -53,
     -67,
     -80,
     -93,
     -106,
     -119,
     -132,
     -144,
     -157,
     -169,
     -182,
     -194,
     -206,
     -218,
     -229,
     -241,
     -252,
     -263,
     -274,
     -285,
     -295,
     -306,
     -316,
     -325,
     -335,
     -344,
     -353,
     -362,
     -371,
     -379,
     -387,
     -395,
     -402,
     -409,
     -416,
     -423,
     -429,
     -435,
     -441,
     -447,
     -452,
     -457,
     -462,
     -467,
     -471,
     -475,
     -479,
     -482,
     -486,
     -488,
     -491,
     -494,
     -496,
     -498,
     -499,
     -501,
     -502,
     -503,
     -503,
     -504,
     -504,
     -504,
     -503,
     -503,
     -502,
     -501,
     -499,
     -498,
     -496,
     -494,
     -491,
     -488,
     -486,
     -482,
     -479,
     -475,
     -471,
     -467,
     -462,
     -457,
     -452,
     -447,
     -441,
     -435,
     -429,
     -423,
     -416,
     -409,
     -402,
     -395,
     -387,
     -379,
     -371,
     -362,
     -353,
     -344,
     -335,
     -325,
     -316,
     -306,
     -295,
     -285,
     -274,
     -263,
     -252,
     -241,
     -229,
     -218,
     -206,
     -194,
     -182,
     -169,
     -157,
     -144,
     -132,
     -119,
     -106,
     -93,
     -80,
     -67,
     -53,
     -40,
     -27,
     -13,
    },
    {
     0,
     6,
     13,
     19,
     26,
     32,
     39,
     45,
     51,
     58,
     64,
     70,
     76,
     82,
     88,
     94,
     100,
     106,
     112,
     117,
     123,
     128,
     134,
     139,
     144,
     149,
     154,
     159,
     163,
     168,
     172,
     177,
     181,
     185,
     189,
     193,
     197,
     200,
     204,
     207,
     210,
     213,
     216,
     219,
     222,
     224,
     227,
     229,
     231,
     233,
     235,
     237,
     239,
     240,
     241,
     243,
     244,
     245,
     246,
     246,
     247,
     247,
     248,
     248,
     248,
     248,
     248,
     247,
     247,
     246,
     246,
     245,
     244,
     243,
     241,
     240,
     239,
     237,
     235,
     233,
     231,
     229,
     227,
     224,
     222,
     219,
     216,
     213,
     210,
     207,
     204,
     200,
     197,
     193,
     189,
     185,
     181,
     177,
     172,
     168,
     163,
     159,
     154,
     149,
     144,
     139,
     134,
     128,
     123,
     117,
     112,
     106,
     100,
     94,
     88,
     82,
     76,
     70,
     64,
     58,
     51,
     45,
     39,
     32,
     26,
     19,
     13,
     6,
     0,
     -6,
     -13,
     -19,
     -26,
     -32,
     -39,
     -45,
     -51,
     -58,
     -64,
     -70,
     -76,
     -82,
     -88,
     -94,
     -100,
     -106,
     -112,
     -117,
     -123,
     -128,
     -134,
     -139,
     -144,
     -149,
     -154,
     -159,
     -163,
     -168,
     -172,
     -177,
     -181,
     -185,
     -189,
     -193,
     -197,
     -200,
     -204,
     -207,
     -210,
     -213,
     -216,
     -219,
     -222,
     -224,
     -227,
     -229,
     -231,
     -233,
     -235,
     -237,
     -239,
     -240,
     -241,
     -243,
     -244,
     -245,
     -246,
     -246,
     -247,
     -247,
     -248,
     -248,
     -248,
     -248,
     -248,
     -247,
     -247,
     -246,
     -246,
     -245,
     -244,
     -243,
     -241,
     -240,
     -239,
     -237,
     -235,
     -233,
     -231,
     -229,
     -227,
     -224,
     -222,
     -219,
     -216,
     -213,
     -210,
     -207,
     -204,
     -200,
     -197,
     -193,
     -189,
     -185,
     -181,
     -177,
     -172,
     -168,
     -163,
     -159,
     -154,
     -149,
     -144,
     -139,
     -134,
     -128,
     -123,
     -117,
     -112,
     -106,
     -100,
     -94,
     -88,
     -82,
     -76,
     -70,
     -64,
     -58,
     -51,
     -45,
     -39,
     -32,
     -26,
     -19,
     -13,
     -6,
    },
    {
     0,
     3,
     7,
     10,
     13,
     17,
     20,
     23,
     26,
     30,
     33,
     36,
     39,
     42,
     45,
     48,
     51,
     54,
     57,
     60,
     62,
     65,
     68,
     70,
     73,
     75,
     78,
     80,
     82,
     84,
     86,
     89,
     91,
     92,
     94,
     96,
     98,
     99,
     101,
     102,
     104,
     105,
     107,
     108,
     109,
     110,
     111,
     112,
     113,
     114,
     115,
     115,
     116,
     117,
     117,
     118,
     118,
     119,
     119,
     119,
     120,
     120,
     120,
     120,
     120,
     120,
     120,
     120,
     120,
     119,
     119,
     119,
     118,
     118,
     117,
     117,
     116,
     115,
     115,
     114,
     113,
     112,
     111,
     110,
     109,
     108,
     107,
     105,
     104,
     102,
     101,
     99,
     98,
     96,
     94,
     92,
     91,
     89,
     86,
     84,
     82,
     80,
     78,
     75,
     73,
     70,
     68,
     65,
     62,
     60,
     57,
     54,
     51,
     48,
     45,
     42,
     39,
     36,
     33,
     30,
     26,
     23,
     20,
     17,
     13,
     10,
     7,
     3,
     0,
     -3,
     -7,
     -10,
     -13,
     -17,
     -20,
     -23,
     -26,
     -30,
     -33,
     -36,
     -39,
     -42,
     -45,
     -48,
     -51,
     -54,
     -57,
     -60,
     -62,
     -65,
     -68,
     -70,
     -73,
     -75,
     -78,
     -80,
     -82,
     -84,
     -86,
     -89,
     -91,
     -92,
     -94,
     -96,
     -98,
     -99,
     -101,
     -102,
     -104,
     -105,
     -107,
     -108,
     -109,
     -110,
     -111,
     -112,
     -113,
     -114,
     -115,
     -115,
     -116,
     -117,
     -117,
     -118,
     -118,
     -119,
     -119,
     -119,
     -120,
     -120,
     -120,
     -120,
     -120,
     -120,
     -120,
     -120,
     -120,
     -119,
     -119,
     -119,
     -118,
     -118,
     -117,
     -117,
     -116,
     -115,
     -115,
     -114,
     -113,
     -112,
     -111,
     -110,
     -109,
     -108,
     -107,
     -105,
     -104,
     -102,
     -101,
     -99,
     -98,
     -96,
     -94,
     -92,
     -91,
     -89,
     -86,
     -84,
     -82,
     -80,
     -78,
     -75,
     -73,
     -70,
     -68,
     -65,
     -62,
     -60,
     -57,
     -54,
     -51,
     -48,
     -45,
     -42,
     -39,
     -36,
     -33,
     -30,
     -26,
     -23,
     -20,
     -17,
     -13,
     -10,
     -7,
     -3,
    },
} ;