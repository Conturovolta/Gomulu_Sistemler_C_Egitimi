#include <stdio.h>
#include <stdint.h>

// 1. Sanal Donanım Belleğimiz (Register)
uint32_t simulated_gpioa_odr = 0x00000001; // Başlangıçta Kırmızı YANIK (0000...0001)

// 2. Adres Tanımlamaları (Bugün öğrendiğimiz evin adresi ve şalteri)
#define GPIOA_ODR_ADDR    ((uintptr_t)&simulated_gpioa_odr)
#define GPIOA_ODR         (*((volatile uint32_t *) GPIOA_ODR_ADDR))

int main(void) {
    // Seviye 2'de öğrendiğimiz maske: 0. ve 1. pinleri hedef al (0000...0011)
    uint32_t maske = (1U << 0) | (1U << 1); 

    printf("Başlangıç Register Değeri: %d\n", GPIOA_ODR); // 1 çıkar

    // ÇAKAR HAMLESİ 1: Adresteki şaltere XOR atıyoruz!
    GPIOA_ODR ^= maske; 

    printf("1. Çakar Sonrası Register Değeri: %d\n", GPIOA_ODR); // 2 çıkar

    // ÇAKAR HAMLESİ 2: Bir daha XOR atıyoruz!
    GPIOA_ODR ^= maske; 

    printf("2. Çakar Sonrası Register Değeri: %d\n", GPIOA_ODR); // 1 çıkar

    return 0;
}
