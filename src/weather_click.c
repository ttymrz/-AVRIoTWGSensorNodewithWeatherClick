/**
 * \file
 *
 *
 (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

#include "bme280.h"
#include "weather_click.h"
#include "clock_config.h"
#include "util/delay.h"

/**
  Section: Macro Declarations
 */

#define DEFAULT_STANDBY_TIME BME280_STANDBY_HALFMS
#define DEFAULT_FILTER_COEFF BME280_FILTER_COEFF_OFF
#define DEFAULT_TEMP_OSRS BME280_OVERSAMP_X1
#define DEFAULT_PRESS_OSRS BME280_OVERSAMP_X1
#define DEFAULT_HUM_OSRS BME280_OVERSAMP_X1
#define DEFAULT_SENSOR_MODE BME280_FORCED_MODE

/**
  Section: Variable Definitions
 */

static uint8_t weather_initialized = 0;

/**
  Section: Private function prototypes
 */

void Weather_initializeClick(void);

/**
  Section: Driver APIs
 */

void Weather_readSensors(void)
{
	if (!weather_initialized) {
		Weather_initializeClick();
	}

	if (DEFAULT_SENSOR_MODE == BME280_FORCED_MODE) {
		BME280_startForcedSensing();
	}

	while (BME280_isMeasuring())
		;
	BME280_readMeasurements();
}

float Weather_getTemperatureDegC(void)
{
	return BME280_getTemperature();
}

float Weather_getPressureKPa(void)
{
	return BME280_getPressure();
}

float Weather_getHumidityRH(void)
{
	return BME280_getHumidity();
}

void Weather_gotoSleep(void)
{
	BME280_sleep();
	weather_initialized = 0;
}

void Weather_initializeClick(void)
{
	BME280_reset();

	_delay_ms(5); // Startup delay for BME280 sensor

	BME280_readFactoryCalibrationParams();

	BME280_setStandbyTime(DEFAULT_STANDBY_TIME);
	BME280_setFilterCoefficient(DEFAULT_FILTER_COEFF);
	BME280_setOversamplingTemperature(DEFAULT_TEMP_OSRS);
	BME280_setOversamplingPressure(DEFAULT_PRESS_OSRS);
	BME280_setOversamplingHumidity(DEFAULT_HUM_OSRS);
	BME280_setSensorMode(DEFAULT_SENSOR_MODE);
	BME280_initializeSensor();

	weather_initialized = 1;
}
