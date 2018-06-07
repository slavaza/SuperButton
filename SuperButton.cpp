/*****************************************************************************
 *                       Multifunctional Arduino button                      *
 *                 Autor: Vyacheslav Azarov <slavaza63@gmail.com>            *
 *                  Licensed by GNU GPL V3 from 29 June 2007                 *
 * ***************************************************************************/
#include "SuperButton.hpp"

SuperButton::SuperButton(uint8_t pin, uint8_t guardtime, 
			 uint16_t doubletime, uint16_t longertime):
	     Buttonkey(pin, guardtime)
{
	this->doubletime = doubletime; this->longertime = longertime;
	state = DETECT_SINGLE;
}

SuperButton::Press SuperButton::pressed(void)
{
	switch (state) 
	{
		case DETECT_SINGLE: if (Buttonkey::pressed())
			{
				timeout.begin(doubletime);
				state = DETECT_DOUBLE;
			}
		break;
		case DETECT_DOUBLE:
			if (Buttonkey::released()) state = DETECT_SECOND;
			else	
			        if (!timeout.remain())
				{
					timeout.begin(longertime);
					state = DETECT_LONGER;
				}
		break;
		case DETECT_SECOND:
			state = DETECT_SINGLE;
			if (Buttonkey::pressed()) 	return DOUBLE;
			if (!timeout.remain())	  	return SINGLE;
			state = DETECT_SECOND;
		break;
		case DETECT_LONGER:
			state = DETECT_SINGLE;
			if (Buttonkey::released())	return SINGLE;
			if (!timeout.remain()) 		return LONGER;
			state = DETECT_LONGER;
		break;
		default: state = DETECT_SINGLE;
	}
	return NO;
}

/* Developed in Zaporizhzhya 2017 */
