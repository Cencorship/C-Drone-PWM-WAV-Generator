/*
Author: Stefan Kos
Projectname: PWM-Signal_Generator
*/

#include <stdlib.h>
#include <stdio.h>

#include "wav_header.h"
#include "calculation.h"
#include "configuration.h"
#include "output.h"

#define SAMPLE_RATE 20000

int main(int argc, char* argv[]) {
    Config cfg;
    parse_args(argc, argv, &cfg);

    uint32_t frame_count = cfg.duration * SAMPLE_RATE;

    float *channel1 = NULL, *channel2 = NULL, *channel3 = NULL, *channel4 = NULL;

    if (!allocate_channels(&channel1, &channel2, &channel3, &channel4, frame_count)) {
        fprintf(stderr, "Error while Allocating Memory.\n");
        return EXIT_FAILURE;
    }

	#if DEBUG == 1
    printf("Main/DEBUG: Allocated memory: %u frames per channel.\n\n", frame_count);
	#endif

    generate_pwm(channel1, frame_count, SAMPLE_RATE,cfg.freq, cfg.rpm[0], cfg.value);
    generate_pwm(channel2, frame_count, SAMPLE_RATE,cfg.freq, cfg.rpm[1], cfg.value);
    generate_pwm(channel3, frame_count, SAMPLE_RATE,cfg.freq, cfg.rpm[2], cfg.value);
    generate_pwm(channel4, frame_count, SAMPLE_RATE,cfg.freq, cfg.rpm[3], cfg.value);

	#if DEBUG == 1
    printf("Main/DEBUG: PWM signals generated.\n\n");
	#endif

    write_output(cfg.output, channel1, channel2, channel3, channel4, SAMPLE_RATE, frame_count);

	#if DEBUG == 1
    printf("Main/DEBUG: File \"%s\" written successfully.\n\n", cfg.output);
	#endif

    free(channel1);
    free(channel2);
    free(channel3);
    free(channel4);

	#if DEBUG == 1
    printf("Main/DEBUG: Memory freed. Program finished.\n\n");
	#endif

    return EXIT_SUCCESS;
}

