
#include <FastLED.h>

#define LED_PIN 7
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];
int lay = 10;
int lay2 = 1200;
int b1 = 55;

//_______________________________________________colours
//______________________hue red: 0, green: 85, blue: 170;
CHSV pink(250, 150, b1); // pink 250,150,255
CHSV warm(20, 255, b1);  // warm
CHSV white(0, 0, b1);    // white

void solidRGBA(int x, int y, int z, int a)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(x, y, z);
  }
  FastLED.setBrightness(a);
  FastLED.show();
}
// solid[show,r,g,b]
void solidSRGB(bool s, int x, int y, int z)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(x, y, z);
  }
  if (s == true)
  {
    FastLED.show();
  }
}
void colorTesting(char correctionType, int hue)
{
  /*
  correctionType {
    UncorrectedColor, TypicalLEDStrip,
    TypicalPixelString, TypicalSMD5050
  }
  color {
    [set color via any named HTML web color]
    examples:
    Red,
      DarkMagenta, DeepPink, DarkOrange, Orange, OrangeRed,
    Green,
      DarkGreen, Gold, Goldenrod, SeaGreen, LightSeaGreen, Teal, Yellow,
    Blue,
      BlueViolet, DodgerBlue, Aqua, DarkViolet, Indigo, MidnightBlue
    white
  }
  */

  hue = hue * (32 * 1.7);
  FastLED.setCorrection(correctionType);
  // white
  for (int i = 0; i < NUM_LEDS / 6; i++)
  {
    leds[i] = white;
  }
  leds[0] = CHSV(hue, 255, b1);
  FastLED.show();
  delay(lay2);
}
void setupTest()
{
  // test each led with white
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = white;
    FastLED.show();
    delay(lay);
  }
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(lay / 2);
  }
}

void setup()
{
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  // test each led with white
  setupTest();
}

//_______________________body__________________________
void loop()
{
}
