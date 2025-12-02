#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdint.h>

/*
	Struct for Writing into the Output File
*/

void write_output(
    const char *filename,
    float *channel1,
    float *channel2,
    float *channel3,
    float *channel4,
    uint32_t sample_rate,
    uint32_t frame_count
);

/*
	Opens the Output File, Writes WAV_Header and PWM_Samples
*/

void write_output(const char *filename, float *channel1, float *channel2, float *channel3, float *channel4, uint32_t sample_rate, uint32_t frame_count);

#endif
