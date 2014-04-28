
#ifndef _WILDFIRE_LIB_H
#define _WILDFIRE_LIB_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define WILDFIRE_V2 (2)
#define WILDFIRE_V3 (3)

class WildFire {
  private:
    uint8_t board_version;
  public:
	WildFire(uint8_t board_version);
	void begin(void);
};

#endif //_WILDFIRE_LIB_H

