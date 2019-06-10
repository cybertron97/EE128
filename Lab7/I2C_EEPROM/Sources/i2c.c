/* ************************************************* *
 *         I2C Library for EEPROM 24LC01B            *
 * ************************************************* */

#include <hidef.h>
#include <stdio.h>
#include <mc9s12dg256.h>
#include "i2c.h"

/* OpenI2C */
void Init_I2C (char ibc, char I2C_ID)
{
#ifdef DBG_ON
     printf("9S12: Configure I2C\r\n");
#endif
     IBCR |= IBEN;          /* enable I2C module */
     IBFD = ibc;            /* set up I2C baud rate */
     IBAD = I2C_ID;         /* set up I2C slave address */
     IBCR &= ~IBIE;         /* disable I2C interrupt */
     IBCR |= IBSWAI;        /* disable i2C in wait mode */
}

/* SendSlaveID */
void SendSlaveID(char cx)
{

#ifdef DBG_ON
     printf("I2C: 9S12 Send Slave ID\r\n");
#endif
     while(IBSR & IBB);     /* wait until I2C bus is idle */

#ifdef DBG_ON
     printf("I2C:     Bus is Idle\r\n");
#endif

#ifdef DBG_ON
     printf("I2C: 9S12 Generate Start condition\r\n");
#endif

     IBCR |= TXRX + MSSL;   /* generate a start condition */
     IBDR = cx;             /* send out slace ID with R/W set to 0 */
     while(!(IBSR & IBIF)); /* wait for completion of transmission */

#ifdef DBG_ON
     printf("I2C: 9S12 Start condition ... OK\r\n");
#endif
    
     IBSR = IBIF;           /* clear IBIF flag */

#ifdef DBG_ON
     printf("I2C: 9S12 Send Slave ID ... done\r\n");
#endif
}

/* EERandomRead */
char EErandomRead(char ID, char addr)
{
     char dummy;

#ifdef DBG_ON
     printf("I2C: 9S12 Read a byte from EEPROM\r\n");
#endif
     
     SendSlaveID(ID);
     
#ifdef DBG_ON
     printf("I2C:9S12 Wait for Transmission Acknowledgment\r\n");
#endif
     if (IBSR & RXAK)       /* wait for transmission acknowledgment */
        return -1;
#ifdef DBG_ON
     printf("I2C:EEPROM ... Ack\r\n");
#endif
     
#ifdef DBG_ON
     printf("I2C: 9S12 Send Address\r\n");
#endif
     IBDR = addr;           /* send out EEPROM address */

     while(!(IBSR & IBIF)); /* wait util the address is sent out */

     IBSR = IBIF;           /* clear IBIF flag */

     if (IBSR & RXAK)
        return -1;
     
#ifdef DBG_ON
     printf("I2C: EEPROM ... Ack\r\n");
#endif
     
#ifdef DBG_ON
     printf("I2C: 9S12 Generate Restart condition and prepare to read\r\n");
#endif
     IBCR |= RSTA;          /* generate restart condition */
     IBDR = ID | 0x01;      /* prepare to read */

     while (!(IBSR & IBIF));

     IBSR = IBIF;
     if (IBSR & RXAK)
        return -1;
#ifdef DBG_ON
     printf("I2C: EEPROM ... Ack\r\n");
#endif

     IBCR |= TXAK;  /* prepare to send NACK */
     IBCR &= ~TXRX; /* perform reception */
#ifdef DBG_ON
     printf("I2C:9S12 Trigger 9 clock pulses to read\r\n");
#endif
     dummy = IBDR;  /* dummy read to trigger 9 clock pulses */
     while(!(IBSR & IBIF)); /* wait for data to shift in */
#ifdef DBG_ON
     printf("I2C: EEPROM Send Byte... OK"\r\n);
#endif
     IBSR = IBIF;
     IBCR &= ~MSSL; /* generate a stop condition */
#ifdef DBG_ON
     printf("I2C: 9S12 Generate Stop condition and finish reading a byte\r\n");
#endif
     return IBDR;
}

/* EEbyteWrite */
char EEbyteWrite(char ID, char addr, char data)
{

#ifdef DBG_ON
     printf("I2C: 9S12 Write a byte to EEPROM\r\n");
#endif

#ifdef DBG_ON
     printf("I2C: 9S12 Wait for Acknowledgment\r\n");
#endif
     SendSlaveID(ID);
     
     if (IBSR & RXAK) /* error if EEPROM does not acknowledge */
        return -1;
#ifdef DBG_ON
     printf("I2C: EEPROM ... Ack\r\n");
#endif

#ifdef DBG_ON
     printf("I2C: 9S12 Send Address\r\n");
#endif
     IBDR = addr;     /* send out address of the location to be written */
     while(!(IBSR & IBIF));
     IBSR = IBIF;     /* clear the IBIF flag */
     if (IBSR & RXAK) /* error if EEPROM does not acknowledge */
        return -1;
#ifdef DBG_ON
     printf("I2C: EEPROM ... Ack\r\n");
#endif

#ifdef DBG_ON
     printf("I2C: 9S12 Send Data\r\n");
#endif
     IBDR = data;     /* send out the data byte */
     while(!(IBSR&IBIF));
     IBSR = IBIF;     /* clear the IBIF flag */
     if (IBSR & RXAK) /* error if EEPROM does not respond */
        return -1;
#ifdef DBG_ON
     printf("I2C: EEPROM ... Ack\r\n");
#endif     

     IBCR &= ~MSSL;   /* generate a stop condition */
#ifdef DBG_ON
     printf("I2C: 9S12 Generate Stop condition and finish reading a byte\r\n");
#endif
     return 0;        /* normal write code */
}

/* eeAckPoll */
void eeAckPoll(char ID)
{
     SendSlaveID(ID);
     while(IBSR & RXAK){
        IBCR |= RSTA;   /* generate a restart condition */
        IBDR = ID;      /* send out EEPROM ID */
        while(!(IBSR & IBIF));
        IBSR = IBIF;    /* clear the IBIF flag */
     } ; /* continue if EEPROM did not acknowledge */
     IBCR &= ~MSSL;     /* generate a stop condition */
}

/* EEbyteWrite */
char EEPageWrite(char ID, char addr, char *data)
{
    int i =0;
#ifdef DBG_ON
     printf("I2C: 9S12 Write a byte to EEPROM\r\n");
#endif

#ifdef DBG_ON
     printf("I2C: 9S12 Wait for Acknowledgment\r\n");
#endif
     SendSlaveID(ID);
     
     if (IBSR & RXAK) /* error if EEPROM does not acknowledge */
        return -1;
#ifdef DBG_ON
     printf("I2C: EEPROM ... Ack\r\n");
#endif

#ifdef DBG_ON
     printf("I2C: 9S12 Send Address\r\n");
#endif

     IBDR = addr;     /* send out address of the location to be written */
     while(!(IBSR & IBIF));
     IBSR = IBIF;     /* clear the IBIF flag */
     if (IBSR & RXAK) /* error if EEPROM does not acknowledge */
        return -1;
#ifdef DBG_ON
     printf("I2C: EEPROM ... Ack\r\n");
#endif

#ifdef DBG_ON
     printf("I2C: 9S12 Send Data\r\n");
#endif

  for (i = 0 ; i <8 ; i++){
    
     IBDR = *data;     /* send out the data byte */
     data ++; 
     while(!(IBSR&IBIF));
     IBSR = IBIF;
     //data++;     /* clear the IBIF flag */
  }
     
     if (IBSR & RXAK) /* error if EEPROM does not respond */
        return -1;
#ifdef DBG_ON
     printf("I2C: EEPROM ... Ack\r\n");
#endif     

     IBCR &= ~MSSL;   /* generate a stop condition */
     
     
#ifdef DBG_ON
     printf("I2C: 9S12 Generate Stop condition and finish reading a byte\r\n");
#endif
     return 0;        /* normal write code */
}
