/*
    __usb_uart4_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __usb_uart4_driver.h
@brief    USB_UART4 Driver
@mainpage USB_UART4 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   USB_UART4
@brief      USB_UART4 Click Driver
@{

| Global Library Prefix | **USB_UART4** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Dec 2017.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _USB_UART4_H_
#define _USB_UART4_H_

/** 
 * @macro T_USB_UART4_P
 * @brief Driver Abstract type 
 */
#define T_USB_UART4_P    const uint8_t*

/** @defgroup USB_UART4_COMPILE Compilation Config */              /** @{ */

//  #define   __USB_UART4_DRV_SPI__                            /**<     @macro __USB_UART4_DRV_SPI__  @brief SPI driver selector */
//  #define   __USB_UART4_DRV_I2C__                            /**<     @macro __USB_UART4_DRV_I2C__  @brief I2C driver selector */                                          
  #define   __USB_UART4_DRV_UART__                           /**<     @macro __USB_UART4_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup USB_UART4_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup USB_UART4_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup USB_UART4_INIT Driver Initialization */              /** @{ */

#ifdef   __USB_UART4_DRV_SPI__
void usb_uart4_spiDriverInit(T_USB_UART4_P gpioObj, T_USB_UART4_P spiObj);
#endif
#ifdef   __USB_UART4_DRV_I2C__
void usb_uart4_i2cDriverInit(T_USB_UART4_P gpioObj, T_USB_UART4_P i2cObj, uint8_t slave);
#endif
#ifdef   __USB_UART4_DRV_UART__
void usb_uart4_uartDriverInit(T_USB_UART4_P gpioObj, T_USB_UART4_P uartObj);
#endif
                                                                       /** @} */
/** @defgroup USB_UART4_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Write Single Byte
 *
 * @param[in] input 
 *
 * Writes sinle byte.
 */
void usb_uart4_writeByte(uint8_t input);

/**
 * @brief Read Single Byte
 *
 * @return received byte
 *
 * Read received byte.
 */
uint8_t usb_uart4_readByte();

/**
 * @brief Check for new byte received
 *
 * @retval 0 - no new data / 1 - data ready
 *
 * Checks is there a new byte received.
 */
uint8_t usb_uart4_byteReady();
                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_USB_UART4_STM.c
    @example Click_USB_UART4_TIVA.c
    @example Click_USB_UART4_CEC.c
    @example Click_USB_UART4_KINETIS.c
    @example Click_USB_UART4_MSP.c
    @example Click_USB_UART4_PIC.c
    @example Click_USB_UART4_PIC32.c
    @example Click_USB_UART4_DSPIC.c
    @example Click_USB_UART4_AVR.c
    @example Click_USB_UART4_FT90x.c
    @example Click_USB_UART4_STM.mbas
    @example Click_USB_UART4_TIVA.mbas
    @example Click_USB_UART4_CEC.mbas
    @example Click_USB_UART4_KINETIS.mbas
    @example Click_USB_UART4_MSP.mbas
    @example Click_USB_UART4_PIC.mbas
    @example Click_USB_UART4_PIC32.mbas
    @example Click_USB_UART4_DSPIC.mbas
    @example Click_USB_UART4_AVR.mbas
    @example Click_USB_UART4_FT90x.mbas
    @example Click_USB_UART4_STM.mpas
    @example Click_USB_UART4_TIVA.mpas
    @example Click_USB_UART4_CEC.mpas
    @example Click_USB_UART4_KINETIS.mpas
    @example Click_USB_UART4_MSP.mpas
    @example Click_USB_UART4_PIC.mpas
    @example Click_USB_UART4_PIC32.mpas
    @example Click_USB_UART4_DSPIC.mpas
    @example Click_USB_UART4_AVR.mpas
    @example Click_USB_UART4_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __usb_uart4_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */

