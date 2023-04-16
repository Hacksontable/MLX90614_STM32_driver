# MLX90614_STM32_driver
This project contains a I2C driver for the MLX90614. The STM32 HAL is used therefore. The development is currently ongoing. It just has started.

The project just serves as an example to get started with the MLX90614. After the initialization of the STM32 and the HAL, there is an endless loop in which the temperature of the MLX90614 gets read out each second.

The MLX90614 driver files are located under “\Drivers\IR_THERMOMETER”.

PINNING:
The project was made with a NUCLEO-F103RB board. The communication between the MLX90614 is done via I2C communication. Therefore, the NUCLEO-F103RB board is connected via PB8 (for SCL) and PB9 (for SDA) to the MLX90614.
If you use an other board, make sure to connect the MLX90614 to the correct pins on the board. The 


IMPORTANT NOTES:
- There might be a clean necessary before build.
- If there is an issue to open the .ioc file (CubeMX), just make sure that the name of the .ioc file is the same as the name of the project itself.



About the state of development:
Currently only the reading of the MLX90614 is implemented. The implementation of the writing functionality will be one of the next steps.



LICENSE:
Because this project is created with STM32CubeIDE (and CubeMX generator) the license of the STM32 parts can be found in the folders where the generated code of the STM32 parts is placed.

The files "MLX90614.c" and "MLX90614.h" (located in the folder "IR_THERMOMETER") contain the driver for the IR temp-sensor MLX90614. Please read the "MLX90614.h" for license details of this driver.

This project is currently under development. No guarantee for the correctness of the source or the defined values.
