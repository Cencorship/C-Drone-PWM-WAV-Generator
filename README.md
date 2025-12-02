# C-Drone-PWM-WAV-Generator
WAV-Generator zur Rotorsteuerung via Kommandozeile

# PWM_Signal_Generator

This Project generates a Multichannel PWM Signal and saves it as a ".wav"-File
The File has 4 Channels with a 8 Bit resolution
The Parameters will be input via the CMD-Line

# Function

4-channel PWM signal generation

Output as 8-bit .wav file

Frequency, duration, per-channel duty cycle, and amplitude freely configurable

Robust argument validation with error messages

# How-To-Use

./PWM -f FREQUENCY -1 RPM1 -2 RPM2 -3 RPM3 -4 RPM4 -d DURATION -v AMPLITUDE -o FILENAME

	-f Frequency in Hz, Range 100-500 Hz
	-1...-4 Duty-Cycle for each channel, Range 0-100%
	-d Duration of the signal in Seconds, >0s
	-v Amplitude of the Signal, 0-255
	-o Name of the Output File, Filename as String
	-h help request
	
eg.:./PWM -f 250 -1 30 -2 40 -3 50 -4 60 -d 2 -v 255 -o out.wav

DEBUG INFO: For Debug Info, compile with -DDEBUG=1,


