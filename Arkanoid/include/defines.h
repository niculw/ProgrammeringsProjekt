#ifndef _defines_h_
#define _defines_h_

#define RESOLUTION_X 171
#define RESOLUTION_Y 61
#define STRIKER_WIDTH 15		// skal kunne deles med 5
#define STRIKER_START_POSITION 77
//////////// number of total blocks
#define NUM_BLOCKS 200
//////////// for udregning af vektorer
#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / (b) )

#endif