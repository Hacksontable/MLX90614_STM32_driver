/*  Copyright 2023 Krisam Reinhard.
	All rights reserved.

	 Redistribution and use in source and binary forms, with or without modification,
	are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this
	list of conditions and the following disclaimer.

	2. Redistributions in binary form must reproduce the above copyright notice,
	this list of conditions and the following disclaimer in the documentation and/or
	other materials provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its contributors
	may be used to endorse or promote products derived from this software without
	specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
	ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
	ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
	ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Current state of the driver: in development
   v1.0 -> reading register value (temperature register) by using the STM32 I2C HAL
        -> The use of this driver is at your own risk. No guarantee for the correctness of the source or the defined values.
*/



#ifndef __MLX90614_H
#define __MLX90614_H





#include "stm32f1xx_hal.h"

/* EEPROM register */
#define eeprom_TOmax			0x00
#define	eeprom_TOmin			0x01
#define eeprom_PWMCTRL			0x02
#define eeprom_TaRange			0x03
#define eeprom_Emissivity		0x04
#define eeprom_config_1			0x05
#define eeprom_SMBusAddress		0x0E

/* RAM register */
#define ram_TA					0x06
#define ram_Tobj_1				0x07
#define ram_Tobj_2				0x08

/* basis commandBytes */
#define RAM_Access				0x00
#define EEPROM_Access			0x20
#define Flag_Access				0xF0
#define SLEEP_MODE				0xFF

#define addr_MLX90614			(0x5A << 1)


/* test function to read two temperature registers */
uint8_t MLX90614_Test_readTemp(I2C_HandleTypeDef *I2C_Module, uint16_t device_address, float* t_Ambient, float* t_Object);

/* read a register fo the MLX90614 */
uint8_t MLX90614_readRegister(I2C_HandleTypeDef *I2C_Module, uint16_t device_address, uint16_t reg_address, uint8_t *regValue);

/* this function is not implemented in current state */
uint8_t MLX90614_writeRegister(I2C_HandleTypeDef I2C_Module, uint16_t device_address, uint16_t reg_address, uint16_t regValue);



#endif
