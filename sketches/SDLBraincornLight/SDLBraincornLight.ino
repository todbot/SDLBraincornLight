
/**
 * SDLBraincornLight - Lights for Trey's braincorn
 *
 */

#define FASTLED_INTERNAL
#include <FastLED.h>
FASTLED_USING_NAMESPACE


const int pinLedStrip    = 23;  // D5 on Teensy 2.0

#define NUM_LEDS 16
#define LED_BRIGHTNESS 100
#define FRAMES_PER_SECOND  120
CRGB leds[NUM_LEDS];
uint8_t gHue;

void setup()
{
    FastLED.addLeds<WS2812, pinLedStrip,GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(LED_BRIGHTNESS);     // set master brightness control

}

void loop()
{
    EVERY_N_MILLISECONDS( 20 ) {

        raindrops();

    }

    FastLED.show();
    FastLED.delay(1000/FRAMES_PER_SECOND);
}


void raindrops()
{
    fadeToBlackBy( leds, NUM_LEDS, 10);
    EVERY_N_MILLISECONDS(50) {
        gHue++;
        // random colored speckles that blink in and fade smoothly
        int pos = random16(NUM_LEDS);
        leds[pos] += CHSV( gHue + random8(64), 200, 255);
        //blur1d( leds, NUM_LEDS, 64);  // blur things a bit
    }
}
