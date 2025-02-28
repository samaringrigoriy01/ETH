
#include "string.h"
#include "parseSV.h"

int32_t reverse_bytes(int32_t value)
{
  return ((value & 0x000000FF) << 24) | // Берём младший байт и ставим в старший
         ((value & 0x0000FF00) << 8) |  // Второй байт смещаем влево
         ((value & 0x00FF0000) >> 8) |  // Третий байт смещаем вправо
         ((value & 0xFF000000) >> 24);  // Старший байт ставим в младший
}

int16_t reverse_bytes_16(int16_t value) {
    return ((value & 0x00FF) << 8) |  // Младший байт становится старшим
           ((value & 0xFF00) >> 8);   // Старший байт становится младшим
}


int32_t *get_data_sv_256(int32_t *buf, int8_t *data,int address, int8_t index)
{
    for (int g = 0; g < 8; g++)
    {
        memcpy(buf + g + 8 * index, data + address, sizeof(int32_t));
        data += 95;
    }
    return buf;
}

int16_t get_value_int16(int8_t *data,int address){
    int16_t value = 0;
    memcpy(&value, data + address, sizeof(int16_t));
    return value;
}


int32_t *revers_bytes_buf(int32_t *buf){
    for (int l = 0; l < 320; l++)
    {
      buf[l] = reverse_bytes(buf[l]);
    }
    return buf;
}