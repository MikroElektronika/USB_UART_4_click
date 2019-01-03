/*
Example for USB_UART4 Click

    Date          : Dec 2017.
    Author        : MikroE Team

Test configuration CEC :
    
    MCU              : CEC1702
    Dev. Board       : Clicker 2 for CEC1702
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Intializes UART module
- Application Initialization - Driver intialization
- Application Task - (code snippet) - Checks if new data byte have received in rx buffer (ready for reading),
  and if ready than reads one byte from rx buffer. In second case aplication task writes
  message data via UART.


*/

#include "Click_USB_UART4_types.h"
#include "Click_USB_UART4_config.h"

const uint8_t MESSAGE_DATA[9] = { 'M', 'i', 'k', 'r', 'o', 'E', 13, 10, 0 };

void systemInit()
{
    mikrobus_uartInit( _MIKROBUS1, &_USB_UART4_UART_CFG[0] );
    mikrobus_logInit( _MIKROBUS1, 9600 );

    Delay_ms( 100 );
}

void applicationInit()
{
    usb_uart4_uartDriverInit( (T_USB_UART4_P)&_MIKROBUS1_GPIO, (T_USB_UART4_P)&_MIKROBUS1_UART );
    mikrobus_logWrite( "Initialized", _LOG_LINE );
    Delay_ms( 100 );
}

void applicationTask()
{
    uint8_t tmp;
	char rec;
    uint8_t rdyFlag;

// RECEIVER - UART polling

rdyFlag = usb_uart4_byteReady();

    if (1 == rdyFlag)
    {
        rec = usb_uart4_readByte();
        mikrobus_logWrite( &rec, _LOG_BYTE );
    }

// TRANSMITER - TX each 2 sec
/*for (tmp = 0; tmp < 9; tmp++)
    {
        usb_uart_writeByte( MESSAGE_DATA[tmp] );
    }
    mikrobus_logWrite( "MESSAGE SENT", _LOG_LINE );
    Delay_ms(2000);*/
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}