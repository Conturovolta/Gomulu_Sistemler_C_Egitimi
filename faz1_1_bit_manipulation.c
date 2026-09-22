#include <stdio.h>
#include <stdint.h>

// 32-bitlik Sanal Register (Başlangıçta tüm bitler 0: Tüm kapılar açık)
volatile uint32_t CONTROL_REGISTER = 0x00000000;

// Kapı Bit Pozisyonları (Maske Tanımları)
#define DRIVER_DOOR_BIT      0  // Sürücü Kapısı -> Bit 0
#define PASSENGER_DOOR_BIT   1  // Yolcu Kapısı  -> Bit 1
#define REAR_LEFT_DOOR_BIT   2  // Sol Arka     -> Bit 2
#define REAR_RIGHT_DOOR_BIT  3  // Sağ Arka     -> Bit 3

// Register Durumunu Yazdıran Yardımcı Fonksiyon
void print_register_status(void) {
    printf("CONTROL_REGISTER: 0x%08X\n", CONTROL_REGISTER);
}

// 1. GÖREV: İstenen biti SET (1) yap -> VEYA (OR) kapısı
void door_lock_set(uint8_t bit_pos) {
    CONTROL_REGISTER |= (1U << bit_pos);
}

// 2. GÖREV: İstenen biti CLEAR (0) yap -> VE NOT (AND NOT) kapısı
void door_lock_clear(uint8_t bit_pos) {
    CONTROL_REGISTER &= ~(1U << bit_pos);
}

// 3. GÖREV: İstenen biti TOGGLE (Tersine çevir) yap -> ÖZEL VEYA (XOR) kapısı
void door_lock_toggle(uint8_t bit_pos) {
    CONTROL_REGISTER ^= (1U << bit_pos);
}

int main(void) {
    printf("=== BCM KAPI KİLİT SİMÜLASYONU BAŞLADI ===\n");
    print_register_status(); // İlk durum: 0x00000000

    printf("\n1. Sürücü Kapısı (Bit 0) ve Sağ Arka Kapı (Bit 3) Kilitleniyor (SET)...\n");
    door_lock_set(DRIVER_DOOR_BIT);
    door_lock_set(REAR_RIGHT_DOOR_BIT);
    print_register_status(); // Beklenen: 0x00000009 (Bit 0 ve 3 = 1)

    printf("\n2. Sürücü Kapısı (Bit 0) Kilidi Açılıyor (CLEAR)...\n");
    door_lock_clear(DRIVER_DOOR_BIT);
    print_register_status(); // Beklenen: 0x00000008 (Bit 0 sıfırlandı, Bit 3 hala 1)

    printf("\n3. Yolcu Kapısı (Bit 1) Durumu Değiştiriliyor (TOGGLE)...\n");
    door_lock_toggle(PASSENGER_DOOR_BIT);
    print_register_status(); // Beklenen: 0x0000000A (Bit 1 kilitlendi)

    return 0;
}