# DHT11_MQTT

Using the ESO8266 and its WIFI-capabilities with Blech.
This example uses the same Blech-code as the
[DHT11-example](https://github.com/mschlund/blechexamples_arduino/tree/main/DHT11)
to read values from the DHT11-sensor and it publishes
them to an MQTT-broker under the topic "sensor/dht11" (defined in MQTT_Config.h)


## Building

First rename the "MQTT_Config_TEMPLATE.h" to "MQTT_Config.h" and adapt the file according to your WIFI-settings etc.

Then as always
```
$ cd esp8266_DHT11_MQTT
$ make
```

and then build and flash the sketch with your favorite Arduino-IDE.

Blogpost: https://maximilianschlund.wordpress.com/2021/01/24/lesson-7-blech-on-the-esp8266-measuring-temperature-humidity-and-sending-via-mqtt/
