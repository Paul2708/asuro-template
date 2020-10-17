#include "asuro.h"

int main(void) {
    int i;
    Init();
    SerPrint("\r\nMyFirstTest\r\n");
    // Sound (500, 500, 70);				// 500 Hz-Ton, 0,5 s, 70 laut
    SerPrint("\r\nNun geht es los!\r\n");
    SerPrint("\r\nDer Blinkzyklus erfolgt 10x, dann wird das Programm beendet.\r\n");

    for (i = 0; i < 10; i++) {                /* Schleife 10x*/
        // PrintInt(i);					/* Drucken von i auf den Schirm */
        SerPrint("\r\n");                /* neue Zeile */

        BackLED(ON, OFF);                /* Rücklicht links an rechts aus */
        Msleep(250);                    /* 0,25 s warten */
        BackLED(ON, ON);                /* Rücklicht links an rechts an */
        Msleep(500);                    /* 0,25 s warten */
        FrontLED(ON);                    /* FrontLED an */
        Msleep(250);                    /* 0,5 s warten */
        StatusLED(RED);                    /* StatusLED rot */
        Msleep(250);                    /* 0,25 s warten */
        StatusLED(YELLOW);                /* StatusLED gelb */
        Msleep(250);                    /* 0,25 s warten */
        StatusLED(GREEN);                /* StatusLED grün */
        Msleep(250);                    /* 0,25 s warten */

        BackLED(OFF, OFF);                /* Rücklicht links aus rechts aus */
        FrontLED(OFF);                    /* FrontLED an */
        StatusLED(OFF);                    /* StatusLED grün */
        Msleep(250);                    /* 0,25 s warten */
    };

    // Sound (500, 500, 70);				// 500 Hz-Ton, 0,5 s, 70 laut
    return 0;
}
