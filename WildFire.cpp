#include "WildFire.h"
#include <inttypes.h>
#include <Serial.h>

WildFire::WildFire(uint8_t board_version){
  this->board_version = board_version;
}

void WildFire::begin(){

  // These Pins are Hardware-Bound Outputs
  // Set them up as such
  
  if(board_version == WILDFIRE_V2){
    uint8_t p[] = {4,7,9,10,11,13}; 
    for(uint8_t i = 0; i < sizeof(p); i++){
      pinMode(p[i], OUTPUT);        
    }
          
    // Pin 10 and 4 should not be set LOW at the same time
    // because they control common-output buffers
    digitalWrite(10, HIGH);   // Slave Select for WiFi 
    digitalWrite(4, HIGH);    // Slave Select for SD Card
          
    pinMode(8, INPUT);        // WiFi IRQ Signal
    digitalWrite(8, HIGH);    // Pulled Up
          
    pinMode(12, INPUT);       // MISO 
    digitalWrite(12, HIGH);   // Pulled Up
  }
  else if(board_version == WILDFIRE_V3){
    uint8_t p[] = {6,7,14,15,16,21,23,11,13}; 
    for(uint8_t i = 0; i < sizeof(p); i++){
      pinMode(p[i], OUTPUT);        
    }
          
    // Pin 7, 15, 21 and 16 should not be set LOW at the same time
    // because they control common-output buffers
    digitalWrite(21, HIGH);   // Slave Select for WiFi 
    digitalWrite(16, HIGH);   // Slave Select for SD Card
    digitalWrite(7,  HIGH);   // Slave Select for RFM69 
    digitalWrite(15, HIGH);   // Slave Select for SPI Flash
          
    pinMode(22, INPUT);       // WiFi IRQ Signal
    digitalWrite(22, HIGH);   // Pulled Up
    
    pinMode(2, INPUT);        // RFM69 IRQ Signal
    digitalWrite(2, HIGH);    // Pulled Up
          
    pinMode(12, INPUT);       // MISO 
    digitalWrite(12, HIGH);   // Pulled Up   
  }
}
