set(SOURCES
    "main.c"
)

idf_component_register(SRCS ${SOURCES} 
                        INCLUDE_DIRS "." 
                        REQUIRES esp_driver_spi esp_driver_gpio)
