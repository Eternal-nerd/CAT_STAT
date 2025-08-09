#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/spi_common.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "esp_adc/adc_oneshot.h"

//ADC2 Channels
#define ADC_CHANNEL         ADC_CHANNEL_0

// accelerometer stuff

static const char *TAG = "CAT_STAT";

static int adc_raw;

void app_main(void) {
   
	//-------------ADC2 Init---------------//
    adc_oneshot_unit_handle_t adc_handle;
    adc_oneshot_unit_init_cfg_t init_config = { 
		.unit_id = ADC_UNIT_2,
		.ulp_mode = ADC_ULP_MODE_DISABLE,
	};
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config, &adc_handle));

	//-------------ADC2 Config---------------//
    adc_oneshot_chan_cfg_t config = {
        .atten = ADC_ATTEN_DB_12,
        .bitwidth = ADC_BITWIDTH_DEFAULT,
    };
    ESP_ERROR_CHECK(adc_oneshot_config_channel(adc_handle, ADC_CHANNEL, &config));

	for (;;) {
        // loops every 0.1 seconds
		ESP_ERROR_CHECK(adc_oneshot_read(adc_handle, ADC_CHANNEL, &adc_raw));
		
		printf("raw_adc: %d\n", adc_raw);
		
		// wait 4 ms per degree rotated (just setting to 600 tho)
        vTaskDelay(pdMS_TO_TICKS(600));
    }

}
