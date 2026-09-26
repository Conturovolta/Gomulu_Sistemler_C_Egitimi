#include <stdio.h>
#include <stdint.h>

// Sanal donanım alanımız (RAM'de bir adres simülasyonu)
uint32_t simulated_hardware_memory = 0x00000000;

// ADRES VE POINTER TANIMLARI
#define GPIOA_MODER_ADDR    ((uintptr_t)&simulated_hardware_memory)
#define GPIOA_MODER         (*((volatile uint32_t *) GPIOA_MODER_ADDR))

int main(void) {
    printf("=== FAZ 1.2: POINTER & MEMORY-MAPPED I/O ===\n");
    printf("Başlangıç Register Değeri: 0x%08X\n", GPIOA_MODER);

    // Pointer ile adrese ulaşıp 10. biti 1 yapıyoruz (PA5 Output Modu)
    GPIOA_MODER |= (1U << 10);

    printf("10. Bit 1 Yapıldıktan Sonra: 0x%08X\n", GPIOA_MODER);

    return 0;
}
