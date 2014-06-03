
#ifndef _WILDFIRE_LIB_H
#define _WILDFIRE_LIB_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class WildFire {
  private:
  public:
	WildFire();
	void begin(void);
};

#endif //_WILDFIRE_LIB_H

