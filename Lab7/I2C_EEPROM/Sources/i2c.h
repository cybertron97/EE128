/* ************************************************* *
 *                       i2c.h                       *
 *         I2C Library for EEPROM 24LC01B            *
 * ************************************************* */
 
#ifndef _I2C_H
#define _I2C_H

#define     IBEN         0x80
#define     IBIE         0x40
#define     MSSL         0x20
#define     TXRX         0x10
#define     TXAK         0x08
#define     RSTA         0x04
#define     IBSWAI       0x01
#define     TCF          0x80
#define     IAAS         0x40
#define     IBB          0x20
#define     IBAL         0x10
#define     SRW          0x04
#define     IBIF         0x02
#define     RXAK         0x01
#define     IMSG         0x80


void Init_I2C (char ibc, char i2c_ID);
void SendSlaveID(char cx);
char EErandomRead(char ID, char addr);
char EEbyteWrite(char ID, char addr, char data);
void eeAckPoll(char ID);
char EEPageWrite(char ID, char addr, char *data);

#endif /* _I2C_H */
