#include "se_resources.h"
const void *sound_pointer[] = {
    kushami1_wav, kushami2_wav, kushami3_wav, kushami4_wav, kushami5_wav, kushami6_wav, kushami7_wav, kushami8_wav, kushami9_wav, kushami10_wav, kushami11_wav
};

const void *sound_length_pointer[] = {
    &kushami1_wav_len, &kushami2_wav_len, &kushami3_wav_len, &kushami4_wav_len, &kushami5_wav_len, &kushami6_wav_len, &kushami7_wav_len, &kushami8_wav_len, 
    &kushami9_wav_len, &kushami10_wav_len, &kushami11_wav_len
};

extern const int soundArraySize = sizeof(sound_pointer)/sizeof(sound_pointer[0]);