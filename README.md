# blechexamples_arduino: A Collection of Blech-Projects on Arduino

See the [companion-blogpost](https://maximilianschlund.wordpress.com/2020/10/29/project-learning-blech-and-arduino/) for an intro.
Each project resides in a sub-directory and is equipped with a Makefile and README.

## Building

The workflow is (almost) the same for all projects.

```
$ cd PROJECTNAME_HERE
$ make
```

## Projects

All projects written for an Arduino-Board using [Blech](https://www.blech-lang.org).

1. blink: Blinking the onboard-LED. [Blogpost](https://maximilianschlund.wordpress.com/2020/10/29/lesson-1-blinking-onboard-led/)
2. RGB_LED: Cycling through the color-space of an RGB-LED. [Blogpost](https://maximilianschlund.wordpress.com/2020/10/31/lesson-2-cycling-through-rgb-space-with-a-fading-rgb-led/)
3. Digital_Inputs: Button controlling an LED. [Blogpost](https://maximilianschlund.wordpress.com/2020/11/05/lesson-3a-digital-input/)
4. Digital_Inputs\_2: Button-controlled LED with double-click detection. [Blogpost](https://maximilianschlund.wordpress.com/2020/11/13/lesson-3b-digital-input-double-click-detection/)
5. passive_buzzer: Playing sound via a passive buzzer. [Blogpost](https://maximilianschlund.wordpress.com/2020/11/20/lesson-4-passive-buzzer-and-tilt-ball-switch/)
6. Ultrasonic_Sensor: Reading echoes from an ultrasonic sensor. [Blogpost](https://maximilianschlund.wordpress.com/2020/11/27/lesson-5-ultrasonic-sensor/)
7. DHT11: Measure temperature/humidity via a DHT11-sensor. [Blogpost](https://maximilianschlund.wordpress.com/2020/12/05/lesson-6-measuring-temperature-and-humidity-using-the-dht11/)
8. DHT11_MQTT: Using the DHT11-sensor and sending its measurements to an MQTT-broker. [Blogpost](https://maximilianschlund.wordpress.com/2021/01/24/lesson-7-blech-on-the-esp8266-measuring-temperature-humidity-and-sending-via-mqtt/)
9. matrix2bytes: a small python-script used as helper for my next project. [Blogpost](https://maximilianschlund.wordpress.com/2021/08/25/generating-bytes-from-8x8-matrix-states-using-python-and-tkinter/)
10. LED_DotMatrix: controlling a MAX7219 LED-Display. [Blogpost](https://maximilianschlund.wordpress.com/2021/12/30/lesson-8-max7219-led-dot-matrix-display/)
