#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

static const char *TAG = "CAT_STAT";

void app_main(void) {
    
    while (1) {
        ESP_LOGI(TAG, "Hello world");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
