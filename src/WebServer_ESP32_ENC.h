/****************************************************************************************************************************
  WebServer_ESP32_ENC.h

  For Ethernet shields using ESP32_ENC (ESP32 + ENC28J60)

  WebServer_ESP32_ENC is a library for the ESP32 with Ethernet ENC28J60 to run WebServer

  Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Built by Khoi Hoang https://github.com/khoih-prog/WebServer_ESP32_ENC
  Licensed under GPLv3 license

  Version: 1.5.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.5.1   K Hoang      28/11/2022 Initial coding for ESP32_ENC (ESP32 + ENC28J60). Sync with WebServer_WT32_ETH01 v1.5.1
 *****************************************************************************************************************************/

#pragma once

#ifndef WEBSERVER_ESP32_ENC_H
#define WEBSERVER_ESP32_ENC_H

//////////////////////////////////////////////////////////////

//#if !defined(USING_CORE_ESP32_CORE_V200_PLUS)
#if ( ( defined(ESP_ARDUINO_VERSION_MAJOR) && (ESP_ARDUINO_VERSION_MAJOR >= 2) ) && ( ARDUINO_ESP32_GIT_VER != 0x46d5afb1 ) )
  #define USING_CORE_ESP32_CORE_V200_PLUS      true

  #if (_ETHERNET_WEBSERVER_LOGLEVEL_ > 2)
    #warning Using code for ESP32 core v2.0.0+ in WebServer_ESP32_ENC.h
  #endif

  #define WEBSERVER_ESP32_ENC_VERSION       "WebServer_ESP32_ENC v1.5.1 for core v2.0.0+"
#else
  #if (_ETHERNET_WEBSERVER_LOGLEVEL_ > 2)
    #warning Using code for ESP32 core v1.0.6- in WebServer_ESP32_ENC.h
  #endif

  #define WEBSERVER_ESP32_ENC_VERSION       "WebServer_ESP32_ENC v1.5.1 for core v1.0.6-"
#endif

#define WEBSERVER_ESP32_ENC_VERSION_MAJOR    1
#define WEBSERVER_ESP32_ENC_VERSION_MINOR    5
#define WEBSERVER_ESP32_ENC_VERSION_PATCH    1

#define WEBSERVER_ESP32_ENC_VERSION_INT      1005001

#if ESP32
  #warning Using ESP32 architecture for WebServer_ESP32_ENC
  #define BOARD_NAME      ARDUINO_BOARD
#else
  #error This code is designed to run on ESP32 platform! Please check your Tools->Board setting.
#endif

#include <Arduino.h>

#include "WebServer_ESP32_ENC_Debug.h"

//////////////////////////////////////////////////////////////

#include "enc28j60/esp32_enc28j60.h"

#include "WebServer_ESP32_ENC.hpp"
#include "WebServer_ESP32_ENC_Impl.h"

#endif    // WEBSERVER_ESP32_ENC_H
