/*
 Name:		rc_leonardo.ino
 Created:	02.06.2018 17:01:28
 Author:	zinjk
*/


// the setup function runs once when you press reset or power the board

#include "leonardo.h"

leonardo m_leonardo;

void setup() {
	m_leonardo.init();
}

void loop() {
	m_leonardo.run();
	m_leonardo.commit();
  if (Serial.available()) {
    m_leonardo.nanopi_event();
  }
  if (Serial1.available()) {
    m_leonardo.esp_event();
  }
}

//void serialEvent() {
//  Serial.println("asdfasfd");
//	m_leonardo.nanopi_event();
//}
//
//void serialEvent1() {
//	m_leonardo.esp_event();
//}
