
#include "fft.h"

#define FFT_SIZE 256 // Размер FFT (должен быть 2^N)

#define SAMPLE_RATE 12800 // Частота дискретизации

float magnitude[FFT_SIZE / 2]; // Амплитудный спектр

arm_rfft_fast_instance_f32 fftInstance; // Экземпляр RFFT

float *ComputeFFT(float *fftInput, float *fftOutput)
{
    // Инициализация RFFT
    arm_rfft_fast_init_f32(&fftInstance, FFT_SIZE);

    // Выполнение прямого БПФ (RFFT)
    arm_rfft_fast_f32(&fftInstance, fftInput, fftOutput, 0);

    // Вычисление амплитуды спектра (модуль комплексных значений)
    // Вычисление амплитуды спектра (модуль комплексных значений)
    for (uint32_t i = 0; i <= 128; i++)
    {
        float real = fftOutput[2 * i];                                    // Реальная часть
        float imag = fftOutput[2 * i + 1];                                // Мнимая часть
        magnitude[i] = sqrtf(real * real + imag * imag) / (FFT_SIZE / 2); // Вычисление модуля
    }
}

void PrintHarmonics(float *fftOutput, uint32_t fftSize, float sampleRate)
{
    printf("Частота (Гц)\tАмплитуда\n");

    for (uint32_t i = 1; i < fftSize / 2; i++)
    {                                      // Пропускаем DC-компонент (нулевую частоту)
        float real = fftOutput[2 * i];     // Реальная часть
        float imag = fftOutput[2 * i + 1]; // Мнимая часть
                                           //    float magnitude = sqrtf(real * real + imag * imag);

        float freq = (sampleRate * i) / fftSize; // Вычисляем частоту

        float magnitude = sqrtf(real * real + imag * imag) / (fftSize / 2);
        printf("%8.2f Гц\t%8.4f\n", freq, magnitude);
        HAL_Delay(50);
    }
}