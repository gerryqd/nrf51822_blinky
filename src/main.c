#include "nrf_gpio.h"
#include "nrf_delay.h"

// LED0: P0.18
#define LED0_PIN_NUM    18

void led0_init(void)
{
    nrf_gpio_cfg_output(LED0_PIN_NUM);
}

void led0_on(void)
{
    nrf_gpio_pin_set(LED0_PIN_NUM);
}

void led0_off(void)
{
    nrf_gpio_pin_clear(LED0_PIN_NUM);
}

int main(void)
{
    led0_init();
    while(1)
    {
        led0_on();
        nrf_delay_ms(500);
        led0_off();
        nrf_delay_ms(500);
    }
}
