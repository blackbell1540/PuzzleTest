#ifndef __DATASETTING_H__
#define __DATASETTING_H__

// sprite z value
#define BACKGROUND_Z 0
#define PUZZLE_Z 2
#define PARTNER_Z 1

//puzzle game scene ending condition
static int correctPuzzleCount = 0;

int getCorrectPuzzleCount(){
	return correctPuzzleCount;
}

#endif //__DATASETTING_H__