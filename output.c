/*
Author: Stefan Kos
Projectname: PWM-Signal_Generator
*/

#include <stdlib.h>
#include <stdio.h>

#include "output.h"
#include "wav_header.h"
#include "calculation.h"

void write_output(const char *filename, float *channel1, float *channel2, float *channel3, float *channel4, uint32_t sample_rate, uint32_t frame_count) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error while opening the File");
        exit(EXIT_FAILURE);
    }

    write_wav_header(fp, sample_rate, frame_count);  // <- num_samples = frame_count
	
    write_pwm_samples(fp, channel1, channel2, channel3, channel4, frame_count);

    fclose(fp);
}
