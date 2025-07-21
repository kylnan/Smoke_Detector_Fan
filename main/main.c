#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_GPIO GPIO_NUM_5

void setup(void) {
    // This function can be used to set up the GPIO or other peripherals if needed
    // Currently, it does nothing
}

void blink_task(void *pvParameter) {
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    while(1) {
        gpio_set_level(LED_GPIO, 1); // Turn LED on
        vTaskDelay(pdMS_TO_TICKS(500)); // Wait for 500 ms
        gpio_set_level(LED_GPIO, 0); // Turn LED off
        vTaskDelay(pdMS_TO_TICKS(500)); // Wait for 500 ms
    }
}

void normal_mode(void *pvParameter) {
    // This function can be used to implement a normal mode if needed
    // Currently, it does nothing
}

void exhaust_mode(void *pvParameter) {
    // This function can be used to implement an exhaust mode if needed
    // Currently, it does nothing
}
void app_main() {
    xTaskCreate(blink_task, "blink_task", 2048, NULL, 5, NULL);
}