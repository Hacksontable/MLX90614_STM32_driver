# MLX90614_STM32_driver
This project contains a I2C driver for the MLX90614. The STM32 HAL is used therefore. The development is currently ongoing. It just has started.

PINNING:
The project was made with a NUCLEO-F103RB board. The communication between the MLX90614 is done via I2C communication. Therefore the NUCLEO-F103RB board is connected via PB8 (for SCL) and PB9 (for SDA) to the MLX90614.


LICENSE:
Because this project is created with STM32CubeIDE (and CubeMX genarator) the license of the STM32 parts can be found in the folders where the generated code of the STM32 parts is placed.

The files "MLX90614.c" and "MLX90614.h" (located in the folder "IR_THERMOMETER") contain the driver for the IR temp-sensor MLX90614. Please read the "MLX90614.h" for license details of this driver.

This project is currently under development. No guarantee for the correctness of the source or the defined values.
