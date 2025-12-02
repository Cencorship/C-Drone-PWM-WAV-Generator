#ifndef WAV_HEADER_H
#define WAV_HEADER_H

#include <stdint.h>
#include <stdio.h>

typedef struct {
	//Base Struct
    uint8_t  riff[4];            // "RIFF"
    uint32_t chunk_size;         // 36 + data_size
    uint8_t  wave[4];            // "WAVE"

    // fmt-Chunk
    uint8_t  fmt[4];             // "fmt "
    uint32_t subchunk1_size;     // 16 for PCM
    uint16_t audio_format;       // PCM = 1
    uint16_t num_channels;       // z.B. 4
    uint32_t sample_rate;        // z.B. 44100
    uint32_t byte_rate;          // sample_rate * num_channels * bits_per_sample/8
    uint16_t block_align;        // num_channels * bits_per_sample/8
    uint16_t bits_per_sample;    // z.B. 8

    // data chunk
    uint8_t  data[4];            // "data"
    uint32_t data_size;          // num_samples * num_channels * bits_per_sample/8
} WAVHeader;

/*
	write_wav_header:	Defining all needed Parametes for a WAV File, for PWM Signal,
	and Dumping it all into the File Header
*/

void write_wav_header(FILE *fp, uint32_t sample_rate, uint32_t num_samples);

#endif
