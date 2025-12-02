/*
Author: Stefan Kos
Projectname: PWM-Signal_Generator
*/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "configuration.h"

void parse_args(int argc, char *argv[], Config *cfg) {
    // Standard Values
    *cfg = (Config){0};
    cfg->value = 255;
    cfg->output = "out.wav";

    int opt;
    int value;

    while ((opt = getopt(argc, argv, "f:1:2:3:4:d:v:o:h")) != -1) {
        switch (opt) {
            case 'f':
                if (!parse_int(optarg, &value)) {
                    fprintf(stderr, "Invalid input for -f: %s \n", optarg);
                    exit(EXIT_FAILURE);
                }
				if(value<100 || value> 500){
					fprintf(stderr, "Invalid Input for Frequnecy: %s Hz\n", optarg);
					exit(EXIT_FAILURE);
				}
                cfg->freq = value;
                break;
            case '1':
                if (!parse_int(optarg, &value)) {
                    fprintf(stderr, "Invalid input for -1: %s\n", optarg);
                    exit(EXIT_FAILURE);
                }
				if(value < 0 || value>100){
					fprintf(stderr, "Invalid Input for RPM1: %s Percent\n", optarg);
					exit(EXIT_FAILURE);
				}
                cfg->rpm[0] = value;
                break;
            case '2':
                if (!parse_int(optarg, &value)) {
                    fprintf(stderr, "Invalid input for -2: %s\n", optarg);
                    exit(EXIT_FAILURE);
                }
				if(value < 0 || value>100){
					fprintf(stderr, "Invalid Input for RPM2: %s Percent\n", optarg);
					exit(EXIT_FAILURE);
				}
                cfg->rpm[1] = value;
                break;
            case '3':
                if (!parse_int(optarg, &value)) {
                    fprintf(stderr, "Invalid input for -3: %s\n", optarg);
                    exit(EXIT_FAILURE);
                }
				if(value < 0 || value>100){
					fprintf(stderr, "Invalid Input for RPM3: %s Percent\n", optarg);
					exit(EXIT_FAILURE);
				}
                cfg->rpm[2] = value;
                break;
            case '4':
                if (!parse_int(optarg, &value)) {
                    fprintf(stderr, "Invalid input for -4: %s\n", optarg);
                    exit(EXIT_FAILURE);
                }
				if(value < 0 || value>100){
					fprintf(stderr, "Invalid Input for RPM4: %s Percent\n", optarg);
					exit(EXIT_FAILURE);
				}
                cfg->rpm[3] = value;
                break;
            case 'd':
                if (!parse_int(optarg, &value)) {
                    fprintf(stderr, "Invalid input for -d: %s\n", optarg);
                    exit(EXIT_FAILURE);
                }
				if (value == 0) {
					fprintf(stderr, "Error: duration (-d) must be > 0 s.\n");
					exit(EXIT_FAILURE);
				}
                cfg->duration = value;
                break;
            case 'v':
                if (!parse_int(optarg, &value)) {
                    fprintf(stderr, "Invalid input for -v: %s\n", optarg);
                    exit(EXIT_FAILURE);
                }
				if(value < 0 || value > 255){
					fprintf(stderr, "Invalid Input for Value: %s\n",optarg);
					exit(EXIT_FAILURE);
				}
                cfg->value = value;
                break;
            case 'o':
                cfg->output = optarg;
                break;
            case 'h':
                printf("Usage: ./PWM.exe [-f FREQUENCY -1 RPM1 -2 RPM2 -3 RPM3 -4 RPM4 -d DURATION -v VALUE -o FILE]\n");
                exit(EXIT_SUCCESS);
            default:
                fprintf(stderr, "Invalid Input. Try -h for help.\n");
                exit(EXIT_FAILURE);
        }
    }
}

uint32_t parse_int(const char *str, int *out) {
    char *end;
    errno = 0;

    long val = strtol(str, &end, 10);

    if (errno == ERANGE) {
        return 0;
    }
    if (end == str || *end != '\0') {
        return 0;
    }
	
	#if DEBUG == 1
    printf("DEBUG: Successful conversion: \"%s\" -> %ld\n", str, val);
	#endif
	
    *out = (int) val;
    return 1;
}