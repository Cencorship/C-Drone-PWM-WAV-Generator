#ifndef _CONFIGURATION_
#define _CONFIGURATION_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
	Structure for Input
*/

typedef struct {
	uint32_t freq;
	uint32_t rpm[4];
	uint32_t duration;
	uint32_t value;
	char* output;
} Config;

/**********************************************************************
Setting Basic Settings

Passing CMD-Line Arguments

Setting struct-parameters

***********************************************************************/

void parse_args(int argc, char* argv[], Config *cfg);

/****************************************
* parse_int:
*	Converts a char string into a Integer	
*	and checks if valid input was made
*	used to protect against overflow
*
*****************************************/

uint32_t parse_int(const char *str, int *out);

#endif