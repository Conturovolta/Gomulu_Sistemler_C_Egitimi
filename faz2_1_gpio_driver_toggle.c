#include <stdio.h>
#include <stdint.h>

// --- DONANIM KATMANI (Sanal Bellek) ---
uint32_t simulated_gpioa_memory[6] = {0};

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
} GPIO_TypeDef;

#define GPIOA_BASE_ADDR ((uintptr_t)&simulated_gpioa_memory[0])
#define GPIOA           ((GPIO_TypeDef *) GPIOA_BASE_ADDR)

// --- PIN MASKELERI ---
#define GPIO_PIN_0   (1U << 0)  // 0. Bacak
#define GPIO_PIN_1   (1U << 1)  // 1. Bacak

// --- PIN DURUM ENUM'I ---
typedef enum {
    GPIO_PIN_RESET = 0, // 0 Yap (Söndür)
    GPIO_PIN_SET   = 1  // 1 Yap (Yak)
} GPIO_PinState;

// --- SÜRÜCÜ KATMANI (Write Function) ---
void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) {
    if (PinState != GPIO_PIN_RESET) {
        GPIOx->ODR |= GPIO_Pin;
    } else {
        GPIOx->ODR &= ~GPIO_Pin;
    }
}

int main(void) {
    printf("=== FAZ 2.2: GPIO DRIVER - WRITE FUNKSIYONU ===\n\n");

    printf("1. Başlangıç ODR           : 0x%02X\n", GPIOA->ODR);

    GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    printf("2. Pin 0 SET Sonrası ODR  : 0x%02X\n", GPIOA->ODR);

    GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
    printf("3. Pin 1 SET Sonrası ODR  : 0x%02X\n", GPIOA->ODR);

    GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
    printf("4. Pin 0 RESET Sonrası ODR: 0x%02X\n", GPIOA->ODR);

    return 0;
}
