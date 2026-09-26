#include <stdio.h>
#include <stdint.h>


uint32_t simulated_gpioa_memory[6] = {0};

typedef struct {
    volatile uint32_t MODER;    // Offset: 0x00 (0. Oda)
    volatile uint32_t OTYPER;   // Offset: 0x04 (1. Oda)
    volatile uint32_t OSPEEDR;  // Offset: 0x08 (2. Oda)
    volatile uint32_t PUPDR;    // Offset: 0x0C (3. Oda)
    volatile uint32_t IDR;      // Offset: 0x10 (4. Oda)
    volatile uint32_t ODR;      // Offset: 0x14 (5. Oda)
    
} GPIOA_TypeDef;

#define GPIOA_BASE_ADDR ((uintptr_t)&simulated_gpioa_memory[0])

#define GPIOA ((GPIOA_TypeDef *) GPIOA_BASE_ADDR)

int main(void) {
    printf("=== FAZ 1.3: STRUCT ILE REGISTER GRUPLAMA ===\n\n");

    // Başlangıçta Kırmızı YANIK (1. bit 0, 0. bit 1 -> Binary: 0000 0001)
    GPIOA->ODR = 0x01; 
    
    printf("Başlangıç ODR Değeri: %d\n", GPIOA->ODR);

    // Maskemiz: 0. ve 1. bitleri hedef alıyoruz (Binary: 0000 0011 yani 3)
    uint32_t maske = (1U << 0) | (1U << 1);

    // GÖREV 3: GPIOA yapısı üzerinden ODR'ye ok işareti (->) ile erişip XOR ile maskeyi uygula
    GPIOA->ODR ^= maske;
    /* EKSİK 3: Buraya ODR değerini XOR ile değiştiren satırı yaz */
    printf("Çakar Hamlesi Sonrası ODR Değeri: %d\n", GPIOA->ODR);




    return 0;
}



