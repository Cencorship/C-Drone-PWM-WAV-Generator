/*
Author: Stefan Kos
Projectname: PWM-Signal_Generator
*/

#include <string.h>

#include "wav_header.h"

void write_wav_header(FILE *fp, uint32_t sample_rate, uint32_t num_samples) {
    WAVHeader header;

    // Basestruct
    memcpy(header.riff, "RIFF", 4);
    memcpy(header.wave, "WAVE", 4);
    memcpy(header.fmt,  "fmt ", 4);
    memcpy(header.data, "data", 4);

	//fmt-Chunk
    header.subchunk1_size = 16;
    header.audio_format = 1;  // PCM
    header.num_channels = 4;
    header.sample_rate = sample_rate;
    header.bits_per_sample = 8;
    header.byte_rate = sample_rate * header.num_channels * header.bits_per_sample / 8;
    header.block_align = header.num_channels * header.bits_per_sample / 8;
    header.data_size = num_samples * header.block_align;
    header.chunk_size = 36 + header.data_size;

	#if DEBUG == 1
    printf("DEBUG:  WAV-Header:\n");
    printf("DEBUG:  Sample Rate:     %u\n", header.sample_rate);
    printf("DEBUG:  Num Samples:     %u\n", num_samples);
    printf("DEBUG:  Channels:        %u\n", header.num_channels);
    printf("DEBUG:  Bits/Sample:     %u\n", header.bits_per_sample);
    printf("DEBUG:  Byte Rate:       %u\n", header.byte_rate);
    printf("DEBUG:  Block Align:     %u\n", header.block_align);
    printf("DEBUG:  Data Size:       %u\n", header.data_size);
    printf("DEBUG:  Chunk Size:      %u\n", header.chunk_size);
	#endif

    // Write Headers
    fwrite(&header, sizeof(WAVHeader), 1, fp);
}
