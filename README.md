## WebServer_ESP32_ENC

[![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_ENC.svg?)](https://www.ardu-badge.com/WebServer_ESP32_ENC)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/WebServer_ESP32_ENC.svg)](https://github.com/khoih-prog/WebServer_ESP32_ENC/releases)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/WebServer_ESP32_ENC.svg)](http://github.com/khoih-prog/WebServer_ESP32_ENC/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>


---
---

## Table of Contents

* [Why do we need this WebServer_ESP32_ENC library](#why-do-we-need-this-WebServer_ESP32_ENC-library)
  * [Features](#features)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Libraries' Patches](#libraries-patches)
  * [1. For fixing ESP32 compile error](#1-for-fixing-esp32-compile-error)
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [Usage](#usage)
  * [Class Constructor](#class-constructor)
  * [Basic Operation](#basic-operations)
  * [Advanced Options](#advanced-options)
  * [Other Function Calls](#other-function-calls)
* [How to connect ENC28J60 to ESP32](#How-to-connect-ENC28J60-to-ESP32)
* [Examples](#examples)
  * [Original Examples](#original-examples)
    * [ 1. AdvancedWebServer](examples/AdvancedWebServer)
    * [ 2. HelloServer](examples/HelloServer)
    * [ 3. HelloServer2](examples/HelloServer2)
    * [ 4. HttpBasicAuth](examples/HttpBasicAuth)
    * [ 5. **MQTTClient_Auth**](examples/MQTTClient_Auth)
    * [ 6. **MQTTClient_Basic**](examples/MQTTClient_Basic)
    * [ 7. **MQTT_ThingStream**](examples/MQTT_ThingStream)
    * [ 8. PostServer](examples/PostServer)
    * [ 9. SimpleAuthentication](examples/SimpleAuthentication)
    * [10. UdpNTPClient](examples/UdpNTPClient)
    * [11. UdpSendReceive](examples/UdpSendReceive)
    * [12. WebClient](examples/WebClient)
    * [13. WebClientRepeating](examples/WebClientRepeating)
    * [14. WebServer](examples/WebServer)
    * [15. **multiFileProject**](examples/multiFileProject)
* [Example AdvancedWebServer](#example-advancedwebserver)
  * [File AdvancedWebServer.ino](#file-advancedwebserverino)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [ 1. AdvancedWebServer on ESP32_DEV with ESP32_ENC28J60](#1-AdvancedWebServer-on-ESP32_DEV-with-ESP32_ENC28J60)
  * [ 2. MQTT_ThingStream on ESP32_DEV with ESP32_ENC28J60](#3-MQTT_ThingStream-on-ESP32_DEV-with-ESP32_ENC28J60)
  * [ 3. MQTTClient_Auth on ESP32_DEV with ESP32_ENC28J60](#4-MQTTClient_Auth-on-ESP32_DEV-with-ESP32_ENC28J60)
  * [ 4. MQTTClient_Basic on ESP32_DEV with ESP32_ENC28J60](#5-MQTTClient_Basic-on-ESP32_DEV-with-ESP32_ENC28J60)
  * [ 6. WebClient on ESP32_DEV with ESP32_ENC28J60](#6-WebClient-on-ESP32_DEV-with-ESP32_ENC28J60)
  * [ 7. UDPSendReceive on ESP32_DEV with ESP32_ENC28J60](#7-UDPSendReceive-on-ESP32_DEV-with-ESP32_ENC28J60)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Releases](#releases)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)


---
---

### Why do we need this [WebServer_ESP32_ENC library](https://github.com/khoih-prog/WebServer_ESP32_ENC)

#### Features

This [**WebServer_ESP32_ENC library**](https://github.com/khoih-prog/WebServer_ESP32_ENC) is a simple yet complete WebServer wrapper library for **ESP32-based** boards using LwIP ENC28J60 Ethernet. The functions are similar and compatible to those of [`ESP32 WebServer`](https://github.com/espressif/arduino-esp32/tree/master/libraries/WebServer) and [`ESP8266WebServer`](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer) libraries to make life much easier to port sketches from ESP8266/ESP32.

This [**WebServer_ESP32_ENC library**](https://github.com/khoih-prog/WebServer_ESP32_ENC) also provides high-level **HTTP(S), MQTT(S) and WebSockets Client** by using the functions from ESP32's [**HTTPClient Library**](https://github.com/espressif/arduino-esp32/tree/master/libraries/HTTPClient)

The library provides these features:

1. TCP Server and Client
2. UDP Server and Client
3. HTTP(S) Server and Client
4. HTTP(S) GET and POST requests, provides argument parsing, handles one client at a time.
5. **High-level HTTP(S) (GET, POST, PUT, PATCH, DELETE), MQTT(S) and WebSocket Client**.

Library is just a wrapper for:

1. [Ivan Grokhotkov's ESP32 WebServer](https://github.com/espressif/arduino-esp32/tree/master/libraries/WebServer)
2. [HTTPClient Library](https://github.com/espressif/arduino-esp32/tree/master/libraries/HTTPClient)


#### Currently supported Boards

This [**WebServer_ESP32_ENC** library](https://github.com/khoih-prog/WebServer_ESP32_ENC) currently supports these following boards:

 1. **ESP32_DEV with ENC28J60 boards** using ESP32-based boards and LwIP ENC28J60 Ethernet


---


#### ENC28J60

`FULL_DUPLEX, 10Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/WebServer_ESP32_ENC/raw/main/pics/ENC28J60.png">
</p>
 
 
 
---
---


## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`ESP32 Core 2.0.6+`](https://github.com/espressif/arduino-esp32) for ESP32-based ESP32_DEV with ENC28J60 boards using release `v1.3.0+`. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)


---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for `WebServer_ESP32_ENC`, then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_ENC.svg?)](https://www.ardu-badge.com/WebServer_ESP32_ENC) for more detailed instructions.

### Manual Install

1. Navigate to [WebServer_ESP32_ENC](https://github.com/khoih-prog/WebServer_ESP32_ENC) page.
2. Download the latest release `WebServer_ESP32_ENC-main.zip`.
3. Extract the zip file to `WebServer_ESP32_ENC-main` directory 
4. Copy the whole `WebServer_ESP32_ENC-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**WebServer_ESP32_ENC** library](https://registry.platformio.org/libraries/khoih-prog/WebServer_ESP32_ENC) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/WebServer_ESP32_ENC/installation). Search for WebServer_ESP32_ENC in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---


### Libraries' Patches

#### 1. For fixing ESP32 compile error

To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.16/hardware/espressif/cores/esp32) to overwrite the old file:
- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)


---
---


### HOWTO Fix `Multiple Definitions` Linker Error

The current library implementation, using `xyz-Impl.h` instead of standard `xyz.cpp`, possibly creates certain `Multiple Definitions` Linker error in certain use cases.

You can include this `.hpp` file

```cpp
// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include "WebServer_ESP32_ENC.hpp"     //https://github.com/khoih-prog/WebServer_ESP32_ENC
```

in many files. But be sure to use the following `.h` file **in just 1 `.h`, `.cpp` or `.ino` file**, which must **not be included in any other file**, to avoid `Multiple Definitions` Linker Error

```cpp
// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include "WebServer_ESP32_ENC.h"           //https://github.com/khoih-prog/WebServer_ESP32_ENC
```

Check the new [**multiFileProject** example](examples/multiFileProject) for a `HOWTO` demo.


---
---

### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- `ADC1` controls ADC function for pins **GPIO32-GPIO39**
- `ADC2` controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In ADC2, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the ADC2, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the ADC is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the ADC2, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use `ADC2` for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use `ADC2` with WiFi/BlueTooth (BT/BLE).
- Use `ADC1`, and pins GPIO32-GPIO39
- If somehow it's a must to use those pins serviced by `ADC2` (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE).


---
---

#### Usage


#### Class Constructor

```cpp
WebServer server(80);
```

Creates the WebServer_ESP32_ENC class object.

*Parameters:* 
 
host port number: ``int port`` (default is the standard HTTP port 80)

#### Basic Operations

**Starting the server**

```cpp
void begin();
```

**Handling incoming client requests**

```cpp
void handleClient();
```

**Disabling the server**

```cpp
void close();
void stop();
```

Both methods function the same

**Client request handlers**

```cpp
void on();
void addHandler();
void onNotFound();
void onFileUpload();	
```

Example:

```cpp
server.on("/", handlerFunction);
server.onNotFound(handlerFunction);   // called when handler is not assigned
server.onFileUpload(handlerFunction); // handle file uploads
```

**Sending responses to the client**

```cpp
void send();
void send_P();
```

`Parameters:`

`code` - HTTP response code, can be `200` or `404`, etc.

`content_type` - HTTP content type, like `"text/plain"` or `"image/png"`, etc.

`content` - actual content body

#### Advanced Options

**Getting information about request arguments**

```cpp
const String & arg();
const String & argName();
int args();
bool hasArg();
```

`Function usage:`

`arg` - get request argument value, use `arg("plain")` to get POST body
	
`argName` - get request argument name
	
`args` - get arguments count
	
`hasArg` - check if argument exist


**Getting information about request headers**

```cpp
const String & header();
const String & headerName();
const String & hostHeader();
int headers();
bool hasHeader();
``` 
`Function usage:`

`header` - get request header value

`headerName` - get request header name

`hostHeader` - get request host header if available, else empty string
  
`headers` - get header count
	
`hasHeader` - check if header exist


**Authentication**

```cpp
bool authenticate();
void requestAuthentication();
```

`Function usage:`

`authenticate` - server authentication, returns true if client is authenticated else false

`requestAuthentication` - sends authentication failure response to the client

`Example Usage:`

```cpp
if(!server.authenticate(username, password))
{
  server.requestAuthentication();
}
```

#### Other Function Calls

```cpp
const String & uri();     // get the current uri
HTTPMethod  method();     // get the current method 
WiFiClient client();      // get the current client
HTTPUpload & upload();    // get the current upload
void setContentLength();  // set content length
void sendHeader();        // send HTTP header
void sendContent();       // send content
void sendContent_P(); 
void collectHeaders();    // set the request headers to collect
void serveStatic();
size_t streamFile();
```

---
---

### How to connect ENC28J60 to ESP32

You can change the `INT` pin to another one. Default is `GPIO4`

```cpp
// Must connect INT to GPIOxx or not working
#define INT_GPIO            4
```

---

#### ENC28J60

`FULL_DUPLEX, 10Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/WebServer_ESP32_W5500/raw/main/pics/ENC28J60.png">
</p>
 

---


#### ESP32_DEV


|ENC28J60|<--->|ESP32|
|:-:|:-:|:-:|
|MOSI|<--->|GPIO23|
|MISO|<--->|GPIO19|
|SCK|<--->|GPIO18|
|SS/CS|<--->|GPIO5|
|INT|<--->|GPIO4|
|RST|<--->|RST|
|GND|<--->|GND|
|3.3V|<--->|3.3V|


---
---

### Examples:

#### Original Examples

 1. [AdvancedWebServer](examples/AdvancedWebServer)
 2. [HelloServer](examples/HelloServer)
 3. [HelloServer2](examples/HelloServer2)
 4. [HttpBasicAuth](examples/HttpBasicAuth)
 5. [**MQTTClient_Auth**](examples/MQTTClient_Auth)
 6. [**MQTTClient_Basic**](examples/MQTTClient_Basic)
 7. [**MQTT_ThingStream**](examples/MQTT_ThingStream)
 8. [PostServer](examples/PostServer)
 9. [SimpleAuthentication](examples/SimpleAuthentication)
10. [UdpNTPClient](examples/UdpNTPClient)
11. [UdpSendReceive](examples/UdpSendReceive)
12. [WebClient](examples/WebClient)
13. [WebClientRepeating](examples/WebClientRepeating)
14. [WebServer](examples/WebServer)
15. [**multiFileProject**](examples/multiFileProject) **New**


---
---

### Example [AdvancedWebServer](examples/AdvancedWebServer)

#### File [AdvancedWebServer.ino](examples/AdvancedWebServer/AdvancedWebServer.ino)


https://github.com/khoih-prog/WebServer_ESP32_ENC/blob/7b3055e675c859f066eae34fc58b7857f86c192d/examples/AdvancedWebServer/AdvancedWebServer.ino#L41-L273

---
---

### Debug Terminal Output Samples

#### 1. AdvancedWebServer on ESP32_DEV with ESP32_ENC28J60

The following are debug terminal output and screen shot when running example [AdvancedWebServer](examples/AdvancedWebServer) on ESP32_DEV with ESP32_ENC28J60

<p align="center">
    <img src="https://github.com/khoih-prog/WebServer_ESP32_ENC/raw/main/pics/AdvancedWebServer.png">
</p>

```cpp
Start AdvancedWebServer on ESP32_DEV with ESP32_ENC28J60
WebServer_ESP32_ENC v1.5.3 for core v2.0.0+
[EWS] Default SPI pinout:
[EWS] MOSI: 23
[EWS] MISO: 19
[EWS] SCK: 18
[EWS] CS: 5
[EWS] INT: 4
[EWS] SPI Clock (MHz): 20
[EWS] =========================

ETH Started
ETH Connected
ETH MAC: 98:F4:AB:09:0A:DF, IPv4: 192.168.2.80
FULL_DUPLEX, 10Mbps
HTTP EthernetWebServer is @ IP : 192.168.2.80
..
```

---

#### 2. MQTT_ThingStream on ESP32_DEV with ESP32_ENC28J60

The terminal output of **ESP32_DEV with ENC28J60** running [MQTT_ThingStream example](examples/MQTT_ThingStream)


```cpp
Start MQTT_ThingStream on ESP32_DEV with ESP32_ENC28J60
WebServer_ESP32_ENC v1.5.3 for core v2.0.0+
[EWS] Default SPI pinout:
[EWS] MOSI: 23
[EWS] MISO: 19
[EWS] SCK: 18
[EWS] CS: 5
[EWS] INT: 4
[EWS] SPI Clock (MHz): 20
[EWS] =========================

ETH Started
ETH Connected
ETH MAC: 98:F4:AB:09:0A:DF, IPv4: 192.168.2.80
FULL_DUPLEX, 10Mbps
***************************************
ESP32_Pub
***************************************
Attempting MQTT connection to broker.emqx.io
...connected
Published connection message successfully!
Subscribed to: ESP32_Sub
MQTT Message Send : ESP32_Pub => Hello from MQTT_ThingStream on ESP32_DEV with ESP32_ENC28J60
MQTT Message receive [ESP32_Pub] Hello from MQTT_ThingStream on ESP32_DEV with ESP32_ENC28J60
MQTT Message Send : ESP32_Pub => Hello from MQTT_ThingStream on ESP32_DEV with ESP32_ENC28J60
MQTT Message receive [ESP32_Pub] Hello from MQTT_ThingStream on ESP32_DEV with ESP32_ENC28J60
```

---

#### 4. MQTTClient_Auth on ESP32_DEV with ESP32_ENC28J60

The terminal output of **ESP32_DEV with ENC28J60** running [MQTTClient_Auth example](examples/MQTTClient_Auth)


```cpp
Start MQTTClient_Auth on ESP32_DEV with ESP32_ENC28J60
WebServer_ESP32_ENC v1.5.3 for core v2.0.0+
[EWS] Default SPI pinout:
[EWS] MOSI: 23
[EWS] MISO: 19
[EWS] SCK: 18
[EWS] CS: 5
[EWS] INT: 4
[EWS] SPI Clock (MHz): 20
[EWS] =========================

ETH Started
ETH Connected
ETH MAC: 98:F4:AB:09:0A:DF, IPv4: 192.168.2.80
FULL_DUPLEX, 10Mbps
Attempting MQTT connection to broker.emqx.io...connected
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on ESP32_DEV with ESP32_ENC28J60
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on ESP32_DEV with ESP32_ENC28J60
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on ESP32_DEV with ESP32_ENC28J60
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on ESP32_DEV with ESP32_ENC28J60
Message Send : MQTT_Pub => Hello from MQTTClient_Auth on ESP32_DEV with ESP32_ENC28J60
Message arrived [MQTT_Pub] Hello from MQTTClient_Auth on ESP32_DEV with ESP32_ENC28J60
```

---

#### 5. MQTTClient_Basic on ESP32_DEV with ESP32_ENC28J60

The terminal output of **ESP32_DEV with ENC28J60** running [MQTTClient_Basic example](examples/MQTTClient_Basic)

```cpp
Start MQTTClient_Basic on ESP32_DEV with ESP32_ENC28J60
WebServer_ESP32_ENC v1.5.3 for core v2.0.0+
[EWS] Default SPI pinout:
[EWS] MOSI: 23
[EWS] MISO: 19
[EWS] SCK: 18
[EWS] CS: 5
[EWS] INT: 4
[EWS] SPI Clock (MHz): 20
[EWS] =========================

ETH Started
ETH Connected
ETH MAC: 98:F4:AB:09:0A:DF, IPv4: 192.168.2.80
FULL_DUPLEX, 10Mbps
Attempting MQTT connection to broker.emqx.io...connected
Message Send : MQTT_Pub => Hello from MQTTClient_Basic on ESP32_DEV with ESP32_ENC28J60
Message arrived [MQTT_Pub] Hello from MQTTClient_Basic on ESP32_DEV with ESP32_ENC28J60
Message Send : MQTT_Pub => Hello from MQTTClient_Basic on ESP32_DEV with ESP32_ENC28J60
Message arrived [MQTT_Pub] Hello from MQTTClient_Basic on ESP32_DEV with ESP32_ENC28J60
Message Send : MQTT_Pub => Hello from MQTTClient_Basic on ESP32_DEV with ESP32_ENC28J60
Message arrived [MQTT_Pub] Hello from MQTTClient_Basic on ESP32_DEV with ESP32_ENC28J60
```

---


#### 6. WebClient on ESP32_DEV with ESP32_ENC28J60

The terminal output of **ESP32_DEV with ENC28J60** running [WebClient example](examples/WebClient)

```cpp
Start WebClient on ESP32_DEV with ESP32_ENC28J60
WebServer_ESP32_ENC v1.5.3 for core v2.0.0+
[EWS] Default SPI pinout:
[EWS] MOSI: 23
[EWS] MISO: 19
[EWS] SCK: 18
[EWS] CS: 5
[EWS] INT: 4
[EWS] SPI Clock (MHz): 20
[EWS] =========================

ETH Started
ETH Connected
ETH MAC: 98:F4:AB:09:0A:DF, IPv4: 192.168.2.80
FULL_DUPLEX, 10Mbps

Starting connection to server...
Connected to server
HTTP/1.1 200 OK
Date: Wed, 11 Jan 2023 07:19:54 GMT
Content-Type: text/plain
Content-Length: 2263
Connection: close
x-amz-id-2: qR2tgUitLlEtvxtzz5ykW5+hzZOcHvP8nZ+1qOmO+AS5vCd4ZDcoGw5TlvCYrZNAhdn0fhUaMeM=
x-amz-request-id: 9VCVV5AA6JMYCRPR
Last-Modified: Wed, 23 Feb 2022 14:56:42 GMT
ETag: "667cf48afcc12c38c8c1637947a04224"
CF-Cache-Status: DYNAMIC
Report-To: {"endpoints":[{"url":"https:\/\/a.nel.cloudflare.com\/report\/v3?s=wxwP9QplgHRCsxL23AHzg8oovKcdd69dDrOZH18uG0MyrXRtGH8re3%2BPfbV0VemrMcJ4YG1vVzGeOt8I8daMB5rcp4K%2BR2kQqHxbDm3f9BNkcGpI4h241rMKGIhLpns%3D"}],"group":"cf-nel","max_age":604800}
NEL: {"success_fraction":0,"report_to":"cf-nel","max_age":604800}
Server: cloudflare
CF-RAY: 77117c69f87d3fd8-YYZ
alt-svc: h3=":443"; ma=86400, h3-29=":443"; ma=86400


           `:;;;,`                      .:;;:.           
        .;;;;;;;;;;;`                :;;;;;;;;;;:     TM 
      `;;;;;;;;;;;;;;;`            :;;;;;;;;;;;;;;;      
     :;;;;;;;;;;;;;;;;;;         `;;;;;;;;;;;;;;;;;;     
    ;;;;;;;;;;;;;;;;;;;;;       .;;;;;;;;;;;;;;;;;;;;    
   ;;;;;;;;:`   `;;;;;;;;;     ,;;;;;;;;.`   .;;;;;;;;   
  .;;;;;;,         :;;;;;;;   .;;;;;;;          ;;;;;;;  
  ;;;;;;             ;;;;;;;  ;;;;;;,            ;;;;;;. 
 ,;;;;;               ;;;;;;.;;;;;;`              ;;;;;; 
 ;;;;;.                ;;;;;;;;;;;`      ```       ;;;;;`
 ;;;;;                  ;;;;;;;;;,       ;;;       .;;;;;
`;;;;:                  `;;;;;;;;        ;;;        ;;;;;
,;;;;`    `,,,,,,,,      ;;;;;;;      .,,;;;,,,     ;;;;;
:;;;;`    .;;;;;;;;       ;;;;;,      :;;;;;;;;     ;;;;;
:;;;;`    .;;;;;;;;      `;;;;;;      :;;;;;;;;     ;;;;;
.;;;;.                   ;;;;;;;.        ;;;        ;;;;;
 ;;;;;                  ;;;;;;;;;        ;;;        ;;;;;
 ;;;;;                 .;;;;;;;;;;       ;;;       ;;;;;,
 ;;;;;;               `;;;;;;;;;;;;                ;;;;; 
 `;;;;;,             .;;;;;; ;;;;;;;              ;;;;;; 
  ;;;;;;:           :;;;;;;.  ;;;;;;;            ;;;;;;  
   ;;;;;;;`       .;;;;;;;,    ;;;;;;;;        ;;;;;;;:  
    ;;;;;;;;;:,:;;;;;;;;;:      ;;;;;;;;;;:,;;;;;;;;;;   
    `;;;;;;;;;;;;;;;;;;;.        ;;;;;;;;;;;;;;;;;;;;    
      ;;;;;;;;;;;;;;;;;           :;;;;;;;;;;;;;;;;:     
       ,;;;;;;;;;;;;;,              ;;;;;;;;;;;;;;       
         .;;;;;;;;;`                  ,;;;;;;;;:         
                                                         
                                                         
                                                         
                                                         
    ;;;   ;;;;;`  ;;;;:  .;;  ;; ,;;;;;, ;;. `;,  ;;;;   
    ;;;   ;;:;;;  ;;;;;; .;;  ;; ,;;;;;: ;;; `;, ;;;:;;  
   ,;:;   ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;,`;, ;;  ;;  
   ;; ;:  ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;;`;, ;;  ;;. 
   ;: ;;  ;;;;;:  ;;  ;; .;;  ;;   ,;,   ;;`;;;, ;;  ;;` 
  ,;;;;;  ;;`;;   ;;  ;; .;;  ;;   ,;,   ;; ;;;, ;;  ;;  
  ;;  ,;, ;; .;;  ;;;;;:  ;;;;;: ,;;;;;: ;;  ;;, ;;;;;;  
  ;;   ;; ;;  ;;` ;;;;.   `;;;:  ,;;;;;, ;;  ;;,  ;;;;   

Disconnecting from server...
```

---

#### 7. UDPSendReceive on ESP32_DEV with ESP32_ENC28J60

The terminal output of **ESP32_DEV with ENC28J60** running [UDPSendReceive example](examples/UDPSendReceive)

```cpp
Start UDPSendReceive on ESP32_DEV with ESP32_ENC28J60
WebServer_ESP32_ENC v1.5.3 for core v2.0.0+
[EWS] Default SPI pinout:
[EWS] MOSI: 23
[EWS] MISO: 19
[EWS] SCK: 18
[EWS] CS: 5
[EWS] INT: 4
[EWS] SPI Clock (MHz): 20
[EWS] =========================

ETH Started
ETH Connected
ETH MAC: 98:F4:AB:09:0A:DF, IPv4: 192.168.2.80
FULL_DUPLEX, 10Mbps

Starting connection to server...
Listening on port 2390
UDP Packet received, size 48
From 132.163.97.6, port 123
Seconds since Jan 1 1900 = 3882459421
Unix time = 1673470621
The UTC time is 20:57:01
UDP Packet received, size 48
From 132.163.97.6, port 123
Seconds since Jan 1 1900 = 3882459433
Unix time = 1673470633
The UTC time is 20:57:13
```

---
---

### Debug

Debug is enabled by default on Serial. Debug Level from 0 to 4. To disable, change the _ETHERNET_WEBSERVER_LOGLEVEL_ to 0

```cpp
// Use this to output debug msgs to Serial
#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial
// Use this to disable all output debug msgs
// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       0
```

---

## Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the board's core, applying Libraries' Patches, Packages' Patches or this library latest version.

---
---


### Issues ###

Submit issues to: [WebServer_ESP32_ENC issues](https://github.com/khoih-prog/WebServer_ESP32_ENC/issues)

---

### TO DO

1. Bug Searching and Killing

### DONE

 1. Add support to ESP32-based **ESP32_DEV with ENC28J60** using LwIP ENC28J60 Ethernet
 2. Using `built-in ESP32 MAC Address`
 3. Increase default `SPI_CLOCK_MHZ` clock to 20MHz from 8MHz


---
---

### Contributions and Thanks


Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Based on the [Ivan Grokhotkov's ESP32 WebServer](https://github.com/espressif/arduino-esp32/tree/master/libraries/WebServer) and [HTTPClient Library](https://github.com/espressif/arduino-esp32/tree/master/libraries/HTTPClient) libraries.
2. Thanks to [tobozo](https://github.com/tobozo) to make the library [ESP32-ENC28J60](https://github.com/tobozo/ESP32-ENC28J60) from which this library uses some ideas and codes


<table>
  <tr>
    <td align="center"><a href="https://github.com/igrr"><img src="https://github.com/igrr.png" width="100px;" alt="igrr"/><br /><sub><b>⭐️ Ivan Grokhotkov</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tobozo"><img src="https://github.com/tobozo.png" width="100px;" alt="tobozo"/><br /><sub><b>tobozo</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [GPLv3](https://github.com/khoih-prog/WebServer_ESP32_ENC/blob/main/LICENSE)

---

## Copyright

- Copyright (c) 2016- Hristo Gochkov

- Copyright (c) 2022- Khoi Hoang


