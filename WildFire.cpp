#include "WildFire.h"
#include <inttypes.h>

WildFire::WildFire(uint8_t board_version){
  this->board_version = board_version;
}

void WildFire::begin(void){
  // These Pins are Hardware-Bound Outputs
  // Pin 10 and 4 should not be set LOW at the same time
  // because they control common-output buffers
  uint8_t pv2[6] = {4,    7,   9,    10,   11,  13}; 
  uint8_t pv3[10] = {6,    7,   14,  15,    16,   21,   23,   10,   11,   13};
  uint8_t p[10] = {0}; 
  uint8_t p_state[10] = {0};
  uint8_t num_output_pins = 0;
  
  memset(p_state, HIGH, 10);
  
  switch(board_version){
  case WILDFIRE_V2:
    num_output_pins = 6;
    memcpy(p, pv2, 6);
    break;
  case WILDFIRE_V3:
    num_output_pins = 10;
    memcpy(p, pv3, 10);  
    p_state[0] = LOW;     // initialize LED off
    break;
  }
  
  for(uint8_t i = 0; i < num_output_pins; i++){
    digitalWrite(p[i], p_state[i]);
    pinMode(p[i], OUTPUT);        
  }       
  
  switch(board_version){
  case WILDFIRE_V2:
    pinMode(8, INPUT_PULLUP);  // WiFi IRQ Signal    
    break;
  case WILDFIRE_V3:
    pinMode(22, INPUT_PULLUP);  // WiFi IRQ Signal    
    pinMode(2,  INPUT_PULLUP);  // RFM69 IRQ Signal
    break;
  }   
  
}
