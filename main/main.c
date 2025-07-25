#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_err.h"

gpio_num_t LED_GPIO = GPIO_NUM_5;

void blink_task(void *pvParameter) {
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    ledc_timer_config_t timer = {
            .speed_mode = LEDC_LOW_SPEED_MODE,
            .duty_resolution = LEDC_TIMER_12_BIT,
            .timer_num = LEDC_TIMER_0,
            .freq_hz = 5000, // Frequency of the PWM signal
            .clk_cfg = LEDC_AUTO_CLK
        };
    ledc_channel_config_t channel = { 
            .speed_mode = LEDC_LOW_SPEED_MODE,
            .channel = LEDC_CHANNEL_0,
            .timer_sel = LEDC_TIMER_0,
            .intr_type = LEDC_INTR_DISABLE,
            .gpio_num = LED_GPIO,
            .duty = 0, // Initial duty cycle
            .hpoint = 0
        };

    ledc_timer_config(&timer);
    ledc_channel_config(&channel);
    
    int duty = 0;
    int increment = 64;
    
    while(1){
        ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, duty);
        ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
        duty += increment;
        if (duty >= 4095 || duty <= 0) {
            increment = -increment; // Reverse the direction of fading
        }
        vTaskDelay(pdMS_TO_TICKS(10)); // Wait for the specified delay time
    }

}

void app_main() {
    xTaskCreate(blink_task, "blink_task", 4096, NULL, 5, NULL);
}