/* This driver was written by Reinhard Krisam in 2023. The license can be found in the header file "MLX90614.h" */

#include "MLX90614.h"


/* register addresses */
const uint8_t regTempAmbient = ram_TA;
const uint8_t regTempObject_1 = ram_Tobj_1;

/* buffer for reading the register */
uint8_t regBuffer[3] = { 0x00, 0x00, 0x00 };

/* variables for storing the register value and calculating the temperature */
uint16_t tempAmbj, tempObj;
float floatTemp_Amb, floatTemp_Object;



/* this function reads the temperature registers from the MLX90614 and calculates the temperature in celsius */
uint8_t MLX90614_Test_readTemp(I2C_HandleTypeDef *I2C_Module, uint16_t device_address, float* t_Ambient, float* t_Object)
{
	/* read the t_abmient */
	MLX90614_readRegister(I2C_Module, device_address, regTempAmbient, (uint8_t *) &regBuffer[0]);

	/* store the buffered register in an uint16_t variable (because the register value is actually 16 bit) */
	tempAmbj = 0x00;
	tempAmbj |= ((uint16_t) regBuffer[0]);
	tempAmbj |= ((uint16_t) regBuffer[1]) << 8;

	/* store the register value (uint16_t) in an float variable for the next conversation step */
	floatTemp_Amb = (float) tempAmbj;

	/* calculate the temperature in celsius */
	floatTemp_Amb *= 0.02;
	floatTemp_Amb -= 273.15;

	/* pass the calculated temperature value to the pointer */
	*t_Ambient = floatTemp_Amb;

	/* read the t_object */
	MLX90614_readRegister(I2C_Module, device_address, regTempObject_1, (uint8_t *) &regBuffer[0]);

	/* store the buffered register in an uint16_t variable (because the register value is actually 16 bit) */
	tempObj = 0x00;
	tempObj |= ((uint16_t) regBuffer[0]);
	tempObj |= ((uint16_t) regBuffer[1]) << 8;

	/* store the register value (uint16_t) in an float variable for the next conversation step */
	floatTemp_Object = (float) tempObj;

	/* calculate the temperature in celsius */
	floatTemp_Object *= 0.02;
	floatTemp_Object -= 273.15;

	/* pass the calculated temperature value to the pointer */
	*t_Object = floatTemp_Object;

	/* right now just return 0 -> error handling: tbd... */
    return 0;
}

/* this function reads the registers from the MLX90614 */
uint8_t MLX90614_readRegister(I2C_HandleTypeDef *I2C_Module, uint16_t device_address, uint16_t reg_address, uint8_t *regValue)
{

	/* start the I2C transmission (the STM32 is the MASTER that WRITES data) to send data to the MLX90614 without a STOP at the end of the transmission */
	HAL_I2C_Master_Seq_Transmit_IT(I2C_Module, device_address, (uint8_t *) &reg_address, (uint16_t) 0x0001, I2C_FIRST_FRAME);

	/* wait for the I2C module to be ready again (the I2C related interrupts will be handled by the I2C-HAL internal state-machine) */
    while (HAL_I2C_GetState(I2C_Module) != HAL_I2C_STATE_READY)
    {
    }

    /* restart the I2C transmission (STM32 is the MASTER that now READS data) to read data from the MLX90614 with a STOP at the end of the transmission */
	HAL_I2C_Master_Seq_Receive_IT(I2C_Module, device_address, (uint8_t *) &regValue[0], (uint16_t) 0x0003, I2C_LAST_FRAME);

	/* wait for the I2C module to be ready again (the I2C related interrupts will be handled by the I2C-HAL internal state-machine) */
    while (HAL_I2C_GetState(I2C_Module) != HAL_I2C_STATE_READY)
    {
    }
    /* right now just return 0 -> error handling: tbd... */
	return 0;
	
}
uint8_t MLX90614_writeRegister(I2C_HandleTypeDef I2C_Module, uint16_t device_address, uint16_t reg_address, uint16_t regValue)
{
	/* todo */
	return 0;
}

