#ifndef NRF_DELAY_H_
#define NRF_DELAY_H_

#include "nrf.h"

/*lint --e{438, 522} "Variable not used" "Function lacks side-effects" */
#if defined ( __CC_ARM   )
static __ASM void __INLINE nrf_delay_us(uint32_t volatile number_of_us)
{
    loop
    SUBS    R0, R0, #1
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    BNE    loop
    BX     LR
}
#elif defined ( __ICCARM__ )
static void __INLINE nrf_delay_us(uint32_t volatile number_of_us)
{
    __ASM(
        "loop:\n\t"
        " SUBS R0, R0, #1\n\t"
        " NOP\n\t"
        " NOP\n\t"
        " NOP\n\t"
        " NOP\n\t"
        " NOP\n\t"
        " NOP\n\t"
        " NOP\n\t"
        " NOP\n\t"
        " NOP\n\t"
        " NOP\n\t"
        " NOP\n\t"
        " NOP\n\t"
        " BNE loop\n\t");
}
#elif defined   (  __GNUC__  )
static void __INLINE nrf_delay_us(uint32_t volatile number_of_us)
{
    if (number_of_us > 50)
    {
        do
        {
            __ASM volatile(
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
            );
        }
        while (--number_of_us);
    }
    else if (number_of_us > 10)
    {
        do
        {
            __ASM volatile(
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
            );
        }
        while (--number_of_us);
    }
    else if (number_of_us > 6)
    {
        do
        {
            __ASM volatile(
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
            );
        }
        while (--number_of_us);
    }
    else if (number_of_us > 4)
    {
        do
        {
            __ASM volatile(
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
            );
        }
        while (--number_of_us);
    }
    else if (number_of_us > 2)
    {
        do
        {
            __ASM volatile(
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
            );
        }
        while (--number_of_us);
    }
    else if (number_of_us > 1)
    {
        do
        {
            __ASM volatile(
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
            );
        }
        while (--number_of_us);
    }
    else
    {
        do
        {
            __ASM volatile(
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
            );
        }
        while (--number_of_us);
    }
}
#endif

void nrf_delay_ms(uint32_t volatile number_of_ms);

#endif // NRF_DELAY_H_
