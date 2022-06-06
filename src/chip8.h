#ifndef CHIP_8_H
#define CHIP_8_H

#include <stdint.h>

class Chip8
{
private:
    uint16_t opcode;
    uint16_t pc;
    uint16_t I;

    uint16_t stack[16];
    uint16_t sp;

    uint8_t memory[4096];
    uint8_t V[16];

    void init();

    // 60Hz timers
    uint8_t delay_timer;
    uint8_t sound_timer;

public:
    bool drawFlag;
    uint8_t gfx[64 * 32];
    uint8_t key[16];

    void emulate_cycle();
    bool load(const char* filepath);

    Chip8();
    ~Chip8();
};

#endif
