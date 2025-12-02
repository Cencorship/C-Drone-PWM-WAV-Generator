#ifndef _CALCULATION_
#define _CALCULATION_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "wav_header.h"

/*
	Allocate needed Memory, for Data-Arrays
*/

int allocate_channels(float **ch1, float **ch2, float **ch3, float **ch4, uint32_t frame_count);


/*
	Calulate pwm_Signal,
*/

void generate_pwm(float* buffer, uint32_t frame_count, uint32_t sample_rate, uint32_t freq, uint32_t duty_percent, uint32_t value);

/*
	Writing calculated PWM Samples
*/

void write_pwm_samples(FILE *fp, float* channel1, float* channel2, float* channel3, float* channel4, uint32_t frame_count);

#endif