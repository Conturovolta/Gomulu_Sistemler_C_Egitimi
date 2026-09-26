#include <stdio.h>
#include <stdint.h>

// 1. Sanal Bellek
uint32_t simulated_gpioa_memory[6] = {0};

// 2. Struct Tanımı
typedef struct {
    volatile uint32_t MODER;    // Offset: 0x00
    volatile uint32_t OTYPER;   // Offset: 0x04
    volatile uint32_t OSPEEDR;  // Offset: 0x08
    volatile uint32_t PUPDR;    // Offset: 0x0C
    volatile uint32_t IDR;      // Offset: 0x10
    volatile uint32_t ODR;      // Offset: 0x14
} GPIOA_TypeDef;

// 3. Adres Tanımlamaları (MÜHİM: main'den ÖNCE durmalı!)
#define GPIOA_BASE_ADDR ((uintptr_t)&simulated_gpioa_memory[0])
#define GPIOA           ((GPIOA_TypeDef *) GPIOA_BASE_ADDR)

// 4. Main Fonksiyonu
int main(void) {
    printf("=== FAZ 1.3: STRUCT ILE REGISTER GRUPLAMA ===\n\n");

    GPIOA->ODR = 0x01; 
    printf("Başlangıç ODR Değeri: %d\n", GPIOA->ODR);

    uint32_t maske = (1U << 0) | (1U << 1);

    GPIOA->ODR ^= maske;
    printf("Çakar Hamlesi Sonrası ODR Değeri: %d\n", GPIOA->ODR);

    return 0;
}
