/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <info@gerhard-bertelsmann.de> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return
 * Gerhard Bertelsmann
 * ----------------------------------------------------------------------------
 */

#include "can.h"

void init_can(const char * brgcon) {
    // enter CAN config mode
    //CANCONbits.REQOP2 = 1;
    CANCON = 0x80;
    while(!(CANSTATbits.OPMODE == 0x04));
    
    // using ECAN 0 mode aka legacy mode
    ECANCONbits.MDSEL = 0b00;
    // leaving CAN config mode
    //CANCONbits.REQOP2 = 0;
    CANCON = 0x00;

    BRGCON1 = *brgcon++;
    BRGCON2 = *brgcon++;
    BRGCON3 = *brgcon;
    CANSTATbits.OPMODE == 0x00;
}
 
    
