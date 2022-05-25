#pragma once
//0 low level, 1 any edge, 2 falling edge, 3 rising edge
class Interrupts
{
public:
    Interrupts();
    // INT0 ET INT1: SUR D2 ET D3
    void initINT0(uint8_t edgeType);
    void initINT1(uint8_t edgeType);
    void initINT2(uint8_t edgeType);
};