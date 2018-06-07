/*****************************************************************************
 *                    Multifunctional Arduino button timer                   *
 *                 Autor: Vyacheslav Azarov <slavaza63@gmail.com>            *
 *                  Licensed by GNU GPL V3 from 29 June 2007                 *
 * ***************************************************************************/
#ifndef _COUNTDOWN_HPP_
#define _COUNTDOWN_HPP_

#include "Arduino.h"

// The asynchronous real timeout counter based on system tick
// Function remain() return remain of timeout initialised by function begin()
// Function end() canceled counting by setup zero timeout

class Countdown {
	uint16_t counter; long lasttime;
public:
	Countdown(void) { begin(0); };
  
	uint16_t remain(void) 
	{
		if (counter) 
		{
			long newtime = millis();

			if (newtime - lasttime > counter) counter = 0;
			else 
				counter -= newtime - lasttime;

			lasttime = newtime;
		}
		return counter;
	};
      
	void begin(unsigned int timeout_ms) 
	{
		counter = timeout_ms; lasttime = millis();
	};
      
	void end(void) { counter = 0; };
};

#endif //_COUNTDOWN_HPP_

/* Developed in Zaporizhzhya 2017 */
