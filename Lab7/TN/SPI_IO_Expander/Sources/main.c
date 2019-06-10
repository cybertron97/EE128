/* ********************************************************************** *
 *  Project:     SPI_IO_Expander                                          *
 *  Purpose:     EE128 Lab 7, SPI and I2C Communication                   *
 *                                                                        *
 *  Notes:       1. See Lab 7 manual for a detailed testbench schematic   *
 *               2. Switches are supposed to be initially ALL OFF         *
 * ********************************************************************** */

#include <hidef.h>         /* common defines and macros */
#include <mc9s12dg256.h>   /* derivative information */
#include "spi.h"           /* MC9S12 SPI Library */
#include "mcp23s08.h"      /* I/O Expander Registers and Bits */
 
#define  INPORT      0x00     /* INPUT  Port */
#define  OUTPORT     0xFF     /* OUTPUT Port */

extern void putcspi0(char);
extern void putsspi0(char*);
extern char getcspi0(void);
extern void getsspi0(char*, char);

void          SPI_SetIOXregister(unsigned char,unsigned char);
unsigned char SPI_GetIOXregister(unsigned char); 

__interrupt void IRQISR(void);

static unsigned char regByte; /* temporal variable for register data */

#define  IOX_WR_OP  0x40   /* R/W bit = 0, address is always hardware 00 (grounded) */
#define  IOX_RD_OP  0x41   /* R/W bit = 1, address is always hardware 00 (grounded) */

/* ****************************************************************** *
 *                                                                    *
 *                                 MAIN                               *
 *                                                                    *
 * ****************************************************************** */

void main(void) {

/* ****************************************************************** *
 *                                                                    *
 *                            SETUP                                   *
 *                                                                    *
 * ****************************************************************** */

  DDRA = OUTPORT;  /* control \CS pin of IOX chip */
  PORTA = 0x01;    /* initially deselect IOX chip */

/*** Setup MC9S12 Interrupt Service ***/

  PORTE = 0x02;    /* IRQ PIN PE1 PULL HIGH */
  INTCR = 0xC0;    /* enable IRQ interrupt on falling edge */
  asm("cli");      /* enable interrupt globally */

/*** Setup MC9S12 SPI Module ***/

  SPI0BR  = 0x77;  /* set baudrate to the minimum possible 11.719 kHz*/
  SPI0CR1 = 0x50;  /* enable SPI, master mode, disable interrupt, SCK idle low,
                         data shift on SCK's rising edge, CPHA=0 */
  SPI0CR2 = 0x02;  /* disable bidirectional mode, SPI stops in wait mode */
  WOMS    = 0;     /* enable Port S pull-up; otherwise use external resistors for pull-up */

/*** Setup MCP23S08 I/O Expander Registers ***/

  regByte = 0x1F;  /* GP7..GP5 - output (LED's); GP2..GP0 - input (switches) */
  SPI_SetIOXregister(IOX_IODIR,regByte);

  regByte = 0x07;  /* enable interrupt-on-change for GP2..GP0 */
  SPI_SetIOXregister(IOX_GPINTEN,regByte);
 
/*** Setup Initial Output in I/O output pins ***/

  regByte = 0x00;  /* set zero initial output values */
  SPI_SetIOXregister(IOX_GPIO,regByte);

/* ****************************************************************** *
 *                                                                    *
 *                             LOOP                                   *
 *                                                                    *
 * ****************************************************************** */

  for(;;){} // wait for interrupts caused by switch changes

}   /* main */

/* ****************************************************************** *
 *                                                                    *
 *                       INTERRUPT ROUTINES                           *
 *                                                                    *
 * ****************************************************************** */

__interrupt void IRQISR(void)
/* interrupt routine to set new LED/Oscilloscope outputs */
{
  regByte = SPI_GetIOXregister(IOX_GPIO);
  regByte <<= 5;
  SPI_SetIOXregister(IOX_GPIO,regByte);
}

/* ****************************************************************** *
 *                                                                    *
 *                    AUXILIARY SPI ROUTINES                          *
 *                                                                    *
 * ****************************************************************** */

void SPI_SetIOXregister(unsigned char ioxAddress,
                        unsigned char regValue   ) {
/* Write-Op to set registers,
   and using PTA0 pin of PORTA to control CS pin of IOX */

  PORTA = 0x00;          /* chip select, using PORTA */
  putcspi0(IOX_WR_OP);   /* schedule a writing op to a register */
  putcspi0(ioxAddress);  /* write to the address of IODIR register */
  putcspi0(regValue);    /* write to IODIR register */  
  PORTA = 0x01;          /* chip diselect */

}
  
unsigned char SPI_GetIOXregister(unsigned char ioxAddress) {
/* Read-Op to read registers,
   and using PTA0 pin of PORTA to control CS pin of IOX */

  unsigned char regValue;
  
  PORTA = 0x00;          /* chip select using PORTA */
  putcspi0(IOX_RD_OP);   /* schedule a writing op to a register */
  putcspi0(ioxAddress);  /* write to the address of IODIR register */
  regValue = getcspi0(); /* write to IODIR register */  
  PORTA = 0x01;          /* chip diselect */
  
  return regValue;
}
