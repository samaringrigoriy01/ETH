
#include "main.h"

#define FB_CURRENT_A 64
#define FB_CURRENT_B 72
#define FB_CURRENT_C 80
#define FB_CURRENT_0 88 

#define SMPCNT_ASDU_1 51
#define SMPCNT_ASDU_8 716


int32_t reverse_bytes(int32_t value);
int16_t reverse_bytes_16(int16_t value);
int32_t *get_data_sv_256(int32_t *buf, int8_t *data,int address, int8_t index);
int16_t get_value_int16(int8_t *data,int address);
int32_t *revers_bytes_buf(int32_t *buf);