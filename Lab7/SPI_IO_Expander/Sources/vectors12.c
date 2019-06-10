  /****************************************************************************************
* Type definitions
****************************************************************************************/
typedef void (*tIsrFunc)(void);                                   /* ISR function type */


/****************************************************************************************
* Function prototypes
****************************************************************************************/
extern __interrupt void IRQISR(void); 

/****************************************************************************************
* Global constants
****************************************************************************************/
const tIsrFunc _vectab[] @0x3e00 =
{
  (tIsrFunc)0,                                        /* Reserved 0xFF80               */
  (tIsrFunc)0,                                        /* Reserved 0xFF82               */
  (tIsrFunc)0,                                        /* Reserved 0xFF84               */
  (tIsrFunc)0,                                        /* Reserved 0xFF86               */
  (tIsrFunc)0,                                        /* Reserved 0xFF88               */
  (tIsrFunc)0,                                        /* Reserved 0xFF8A               */
  (tIsrFunc)0,                                        /* PWM Emergency Shutdown 0xFF8C */
  (tIsrFunc)0,                                        /* PortP Interrupt 0xFF8E        */
  (tIsrFunc)0,                                        /* MSCAN4 Transmit 0xFF90        */
  (tIsrFunc)0,                                        /* MSCAN4 Receive 0xFF92         */
  (tIsrFunc)0,                                        /* MSCAN4 Errors 0xFF94          */
  (tIsrFunc)0,                                        /* MSCAN4 WakeUp 0xFF96          */
  (tIsrFunc)0,                                        /* MSCAN3 Transmit 0xFF98        */
  (tIsrFunc)0,                                        /* MSCAN3 Receive 0xFF9A         */
  (tIsrFunc)0,                                        /* MSCAN3 Errors 0xFF9C          */
  (tIsrFunc)0,                                        /* MSCAN3 WakeUp 0xFF9E          */
  (tIsrFunc)0,                                        /* MSCAN2 Transmit 0xFFA0        */
  (tIsrFunc)0,                                        /* MSCAN2 Receive 0xFFA2         */
  (tIsrFunc)0,                                        /* MSCAN2 Errors 0xFFA4          */
  (tIsrFunc)0,                                        /* MSCAN2 WakeUp 0xFFA6          */
  (tIsrFunc)0,                                        /* MSCAN1 Transmit 0xFFA8        */
  (tIsrFunc)0,                                        /* MSCAN1 Receive 0xFFAA         */
  (tIsrFunc)0,                                        /* MSCAN1 Errors 0xFFAC          */
  (tIsrFunc)0,                                        /* MSCAN1 WakeUp 0xFFAE          */
  (tIsrFunc)0,                                        /* MSCAN0 Transmit 0xFFB0        */
  (tIsrFunc)0,                                        /* MSCAN0 Receive 0xFFB2         */
  (tIsrFunc)0,                                        /* MSCAN0 Errors 0xFFB4          */
  (tIsrFunc)0,                                        /* MSCAN0 WakeUp 0xFFB6          */
  (tIsrFunc)0,                                        /* Flash 0xFFB8                  */
  (tIsrFunc)0,                                        /* Eeprom WakeUp 0xFFBA          */
  (tIsrFunc)0,                                        /* SPI2  0xFFBC                  */
  (tIsrFunc)0,                                        /* SPI1  0xFFBE                  */
  (tIsrFunc)0,                                        /* IIC Bus 0xFFC0                */
  (tIsrFunc)0,                                        /* DLC 0xFFC2                    */
  (tIsrFunc)0,                                        /* SCME 0xFFC4                   */
  (tIsrFunc)0,                                        /* CRG Lock 0xFFC6               */
  (tIsrFunc)0,                                        /* Pulse AccB Overflow 0xFFC8    */
  (tIsrFunc)0,                                        /* Mod Down Cnt Underflow 0xFFCA */
  (tIsrFunc)0,                                        /* PortH Interrupt 0xFFCC        */
  (tIsrFunc)0,                                        /* PortJ Interrupt 0xFFCE        */
  (tIsrFunc)0,                                        /* ATD1 0xFFD0                   */
  (tIsrFunc)0,                                        /* ATD0 0xFFD2                   */
  (tIsrFunc)0,                                        /* SCI1 0xFFD4                   */
  (tIsrFunc)0,                                        /* SCI0 0xFFD6                   */
  (tIsrFunc)0,                                        /* SPI0 0xFFD8                   */
  (tIsrFunc)0,                                        /* Pulse AccA Input Edge 0xFFDA  */
  (tIsrFunc)0,                                        /* Pulse AccA Overflow 0xFFDC    */
  (tIsrFunc)0,                                        /* Timer Overflow 0xFFDE         */
  (tIsrFunc)0,                                        /* Timer 7 0xFFE0                */ 
  (tIsrFunc)0,                                        /* Timer 6 0xFFE2                */
  (tIsrFunc)0,                                        /* Timer 5 0xFFE4                */
  (tIsrFunc)0,                                        /* Timer 4 0xFFE6                */
  (tIsrFunc)0,                                        /* Timer 3 0xFFE8                */
  (tIsrFunc)0,                                        /* Timer 2 0xFFEA                */
  (tIsrFunc)0,                                        /* Timer 1 0xFFEC                */
  (tIsrFunc)0,                                        /* Timer 0 0xFFEE                */
  (tIsrFunc)0,                                        /* RTI 0xFFF0                    */
  (tIsrFunc)IRQISR,                                   /* IRQ 0xFFF2                    */
  (tIsrFunc)0,                                        /* XIRQ 0xFFF4                   */
  (tIsrFunc)0,                                        /* SWI 0xFFF6                    */
  (tIsrFunc)0,                                        /* Unimpl Instr Trap 0xFFF8      */
  (tIsrFunc)0,                                        /* COP Failure Reset(N/A) 0xFFFA */
  (tIsrFunc)0,                                        /* COP Clk Mon Fail(N/A) 0xFFFC  */
  (tIsrFunc)0                                         /* Reset(N/A) 0xFFFE             */
};


/************************************ end of vectors.c *********************************/


