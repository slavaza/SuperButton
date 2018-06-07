/*****************************************************************************
 *                       Multifunctional Arduino button                      *
 *                 Autor: Vyacheslav Azarov <slavaza63@gmail.com>            *
 *                  Licensed by GNU GPL V3 from 29 June 2007                 *
 * ***************************************************************************/
#include "Arduino.h"
#include "Buttonkey.hpp"
#include "SuperButton.hpp"

SuperButton button(5,69,1000,1000);

void setup(void)
{
        Serial.begin(9600);
        pinMode(2,INPUT_PULLUP);
}

void loop(void)
{        
        switch (button.pressed())
        {
                case SuperButton::Press::SINGLE: Serial.println("single pressed"); break;
                case SuperButton::Press::DOUBLE: Serial.println("double pressed"); break;
                case SuperButton::Press::LONGER: Serial.println("longer pressed"); break;
                default:;
        }
}

/* Developed in Zaporizhzhya 2017 */
