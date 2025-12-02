/*
Author: Stefan Kos
Projectname: PWM-Signal_Generator
*/

#include <stdlib.h>
#include <stdio.h>

#include "calculation.h"

int allocate_channels(float **ch1, float **ch2, float **ch3, float **ch4, uint32_t frame_count) {
    *ch1 = malloc(frame_count * sizeof(float));
    *ch2 = malloc(frame_count * sizeof(float));
    *ch3 = malloc(frame_count * sizeof(float));
    *ch4 = malloc(frame_count * sizeof(float));

    if (!*ch1 || !*ch2 || !*ch3 || !*ch4) {
        free(*ch1); free(*ch2); free(*ch3); free(*ch4);
        return 0;
    }
    return 1;
}

void generate_pwm(float* buffer, uint32_t frame_count, uint32_t sample_rate, uint32_t freq, uint32_t duty_percent, uint32_t value) {

	//Calculates how many Samples are in each period
    uint32_t samples_per_period = sample_rate / freq;

	//Calculates how many of the Samples have to be High on each cycle
	uint32_t samples_high = (uint32_t)((samples_per_period * (float)duty_percent) / 100.0f);
	
	//scales value to Fit 0.0-1.0 255 bc 8-Bit
	float scaled_value = (float)value / 255.0f;
	
	#if DEBUG == 1
    printf("DEBUG: PWM: freq=%u Hz, duty=%u%%, value=%u, period=%u, high_duration=%u\n", freq, duty_percent, value, samples_per_period, samples_high);
	#endif

    for (uint32_t i = 0; i < frame_count; i++) {
		//Calculate the position in the current Cycle
        uint32_t pos_in_period = i % samples_per_period;
			
			//if inside the high portion set high
			if (pos_in_period < samples_high) {
			buffer[i] = scaled_value; //value scaled 
			} else {
			buffer[i] = 0.0f;
			}
    }
	
}

void write_pwm_samples(FILE *fp, float* channel1, float* channel2, float* channel3, float* channel4, uint32_t frame_count) {
	
	//Write PWM-Signal into File
    for (uint32_t i = 0; i < frame_count; i++) {
		
        uint8_t sample[4];
		
        sample[0] = (uint8_t)(channel1[i] * 255);
        sample[1] = (uint8_t)(channel2[i] * 255);
        sample[2] = (uint8_t)(channel3[i] * 255);
        sample[3] = (uint8_t)(channel4[i] * 255);
		
        fwrite(sample, sizeof(uint8_t), 4, fp); // Write 4 bytes (1 per channel)
    }
	
	#if DEBUG == 1
    printf("DEBUG: Writing Complete\n");
	#endif
}
