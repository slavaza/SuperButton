/*****************************************************************************
 *                       Multifunctional Arduino button                      *
 *                 Autor: Vyacheslav Azarov <slavaza63@gmail.com>            *
 *                  Licensed by GNU GPL V3 from 29 June 2007                 *
 * ***************************************************************************/
#ifndef _SUPERBUTTON_HPP_
#define _SUPERBUTTON_HPP_

#include "Arduino.h"
#include "Countdown.hpp"
#include "Buttonkey.hpp"

//  Unbuffered input from single button with bypass of bounce 
//  Function  pressed() return value of the button operate behavior
//  It need to periodically call the pressed() in arduino super-cycle

class SuperButton: public Buttonkey {
	uint16_t doubletime, longertime;
        Countdown timeout;

 	typedef enum {
		DETECT_SINGLE = 0, DETECT_DOUBLE, 
		DETECT_SECOND,	   DETECT_LONGER
	}
                State;
              	
	State state;
    
public: 
	SuperButton(uint8_t pin, uint8_t guardtime, 
		    uint16_t doubletime, uint16_t longertime); 
	
	typedef enum {
		NO = 0, SINGLE, DOUBLE, LONGER
	}
	        Press;
	
	Press pressed(void);
};

#endif //_SUPERBUTTON_HPP_

/* Developed in Zaporizhzhya 2017 */
