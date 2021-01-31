#include <iostream>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

/**
* These are the following pages used within the documentation provided used to get he resulting code below.
* Raspberry Pi Pico Python SDK | Page 15
* RP2040 Datasheet | Page 572
* Raspberry Pi Pico C/C++ SDK | Page 69
*/

int main() {
    stdio_init_all();
    adc_init();
    adc_select_input(4);
    adc_set_temp_sensor_enabled(true);

    const float conversion_factor = 3.3f / (1<<12);
    while(true){
        uint16_t result = adc_read(); // integer with exactly 16 bits.
        // T = 27 - (ADC_Voltage - 0.706)/0.001721
        double temperature = 27 - ((result * conversion_factor) - 0.706)/0.001721;
        std::cout << "Voltage: " << (result*conversion_factor) <<", Temperature: " << temperature << std::endl;
    	sleep_ms(500);
    }
    return 0;
}