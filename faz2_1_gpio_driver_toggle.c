#include <stdio.h>
#include <stdint.h>

// --- DONANIM KATMANI (Sanal Bellek) ---
uint32_t simulated_gpioa_memory[6] = {0};

typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
} GPIO_TypeDef;

#define GPIOA_BASE_ADDR ((uintptr_t)&simulated_gpioa_memory[0])
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE_ADDR)

// --- PIN MASKELERI (16 Bacak Icin Etiketler) ---
#define GPIO_PIN_0 (1U << 0) // 0. Bacak
#define GPIO_PIN_1 (1U << 1) // 1. Bacak

typedef enum
{
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET = 1
} GPIO_PinState;

void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    if (PinState == GPIO_PIN_SET)
    {
        GPIOx->ODR |= GPIO_Pin; // Set the pin
    }
    else
    {
        GPIOx->ODR &= ~GPIO_Pin; // Reset the pin
    }
}

int main(void)
{
    printf("=== FAZ 2.2: GPIO DRIVER - WRITE FUNKSIYONU ===\n\n");

    // 1. Başlangıçta tüm ODR sıfır
    printf("1. Başlangıç ODR: 0x%02X\n", GPIOA->ODR);

    GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    printf("2. GPIO_PIN_0 SET edildi. ODR: 0x%02X\n", GPIOA->ODR);

    GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
    printf("3. GPIO_PIN_1 SET edildi. ODR: 0x%02X\n", GPIOA->ODR);

    GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
    printf("4. GPIO_PIN_0 RESET edildi. ODR: 0x%02X\n", GPIOA->ODR);

    return 0;
}
