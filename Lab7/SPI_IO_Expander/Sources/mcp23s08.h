/* ************************************************* *
 *             MCP23S08 I/O Expander                 *
 *                   Library                         *
 * ************************************************* */

#ifndef _MCP23S08_H
#define _MCP23S08_H

/* MCP23S08 REGISTER ADDRESSES */

#define  IOX_IODIR     0x00
#define  IOX_IPOL      0x01
#define  IOX_GPINTEN   0x02
#define  IOX_DEFVAL    0x03
#define  IOX_INTCON    0x04
#define  IOX_IOCON     0x05
#define  IOX_GPPU      0x06
#define  IOX_INTF      0x07
#define  IOX_INTCAP    0x08
#define  IOX_GPIO      0x09
#define  IOX_OLAT      0x0A

/* IODIR Register - Bit Locations */
#define  IOXB_IO7       0x80
#define  IOXB_IO6       0x40
#define  IOXB_IO5       0x20
#define  IOXB_IO4       0x10
#define  IOXB_IO3       0x08
#define  IOXB_IO2       0x04
#define  IOXB_IO1       0x02
#define  IOXB_IO0       0x01

/* IOPOL Register - Bit Locations */
#define  IOXB_IP7       0x80
#define  IOXB_IP6       0x40
#define  IOXB_IP5       0x20
#define  IOXB_IP4       0x10
#define  IOXB_IP3       0x08
#define  IOXB_IP2       0x04
#define  IOXB_IP1       0x02
#define  IOXB_IP0       0x01

/* GPINTEN Register - Bit Locations */
#define  IOXB_GPINT7    0x80
#define  IOXB_GPINT6    0x40
#define  IOXB_GPINT5    0x20
#define  IOXB_GPINT4    0x10
#define  IOXB_GPINT3    0x08
#define  IOXB_GPINT2    0x04
#define  IOXB_GPINT1    0x02
#define  IOXB_GPINT0    0x01

/* DEFVAL Register - Bit Locations */
#define  IOXB_DEF7      0x80
#define  IOXB_DEF6      0x40
#define  IOXB_DEF5      0x20
#define  IOXB_DEF4      0x10
#define  IOXB_DEF3      0x08
#define  IOXB_DEF2      0x04
#define  IOXB_DEF1      0x02
#define  IOXB_DEF0      0x01

/* INTCON Register - Bit Locations */
#define  IOXB_IOC7      0x80
#define  IOXB_IOC6      0x40
#define  IOXB_IOC5      0x20
#define  IOXB_IOC4      0x10
#define  IOXB_IOC3      0x08
#define  IOXB_IOC2      0x04
#define  IOXB_IOC1      0x02
#define  IOXB_IOC0      0x01

/* IOCON Register - Bit Locations */
#define  IOXB_SEQOP     0x20
#define  IOXB_SREAD     0x20
#define  IOXB_DISSLW    0x10
#define  IOXB_HAEN      0x08
#define  IOXB_ODR       0x04
#define  IOXB_INTPOL    0x02

/* GPPU Register - Bit Locations */
#define  IOXB_PU7       0x80
#define  IOXB_PU6       0x40
#define  IOXB_PU5       0x20
#define  IOXB_PU4       0x10
#define  IOXB_PU3       0x08
#define  IOXB_PU2       0x04
#define  IOXB_PU1       0x02
#define  IOXB_PU0       0x01

/* INTF Register - Bit Locations */
#define  IOXB_INT7      0x80
#define  IOXB_INT6      0x40
#define  IOXB_INT5      0x20
#define  IOXB_INT4      0x10
#define  IOXB_INT3      0x08
#define  IOXB_INT2      0x04
#define  IOXB_INT1      0x02
#define  IOXB_INT0      0x01

/* INTCAP Register - Bit Locations */
#define  IOXB_ICP7      0x80
#define  IOXB_ICP6      0x40
#define  IOXB_ICP5      0x20
#define  IOXB_ICP4      0x10
#define  IOXB_ICP3      0x08
#define  IOXB_ICP2      0x04
#define  IOXB_ICP1      0x02
#define  IOXB_ICP0      0x01

/* GPIO Register - Bit Locations */
#define  IOXB_GP7       0x80
#define  IOXB_GP6       0x40
#define  IOXB_GP5       0x20
#define  IOXB_GP4       0x10
#define  IOXB_GP3       0x08
#define  IOXB_GP2       0x04
#define  IOXB_GP1       0x02
#define  IOXB_GP0       0x01

/* OLAT Register - Bit Locations */
#define  IOXB_OL7       0x80
#define  IOXB_OL6       0x40
#define  IOXB_OL5       0x20
#define  IOXB_OL4       0x10
#define  IOXB_OL3       0x08
#define  IOXB_OL2       0x04
#define  IOXB_OL1       0x02
#define  IOXB_OL0       0x01

#endif  /* ifndef _MCS23S08_H */
