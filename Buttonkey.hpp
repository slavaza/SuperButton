/*****************************************************************************
 *                       Multifunctional Arduino button                      *
 *                 Autor: Vyacheslav Azarov <slavaza63@gmail.com>            *
 *                  Licensed by GNU GPL V3 from 29 June 2007                 *
 * ***************************************************************************/
#ifndef _BUTTONKEY_HPP_
#define _BUTTONKEY_HPP_

#include "Arduino.h"
#include "Countdown.hpp"

//  Unbuffered input from single button with bypass of bounce 
//  Will rerurn true on port input transition from high to low.
//  Functions need to periodically call in arduino super-cycle

class Buttonkey {
	uint8_t pin; bool waspressed; uint8_t guardtime; Countdown guard;       
public:
	Buttonkey(uint8_t pin, uint8_t guardtime) 
	{
		this->guardtime = guardtime; this->pin = pin; 
		waspressed = false; pinMode(pin, INPUT_PULLUP);
	};
      
	bool pressed(void)
	{
		bool newpressed = (digitalRead(pin) == HIGH) ? false : true;

		if (newpressed)
		{
			guard.begin(guardtime);

			if (!waspressed) return waspressed = true;
		}
		else 
			if (!guard.remain()) waspressed = false;

		return false;
	};

        bool released(void)
        {
                if (digitalRead(pin) == LOW) guard.begin(guardtime);
                else if (!guard.remain()) 
                                        return true;
                return false;
        }
};

#endif //_BUTTONKEY_HPP_

/* Developed in Zaporizhzhya 2017 */
