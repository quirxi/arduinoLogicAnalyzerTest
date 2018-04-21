/*
  LogicTester

  Switches on and off 8 digital pins in a specific pattern. This can be used to test a logic analyzer.

 see also: 
  https://iamzxlee.wordpress.com/2015/09/15/usb-logic-analyzer-review/
*/

// Pins used for arduino nano are pins 5 to 12: 
// see http://www.circuitstoday.com/arduino-nano-tutorial-pinout-schematics
const unsigned short START_PIN=5;
const unsigned short END_PIN=12;
const unsigned short PIN_RANGE=END_PIN-START_PIN+1;

const unsigned long ULONG_MAX=4294967295;
const unsigned int time2wait=100;


void setup()
{
  for ( unsigned short pin=START_PIN; pin<=END_PIN; ++pin )
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
}

void loop()
{
    unsigned long counter = 1;
    unsigned short channel = 1;
    unsigned short pin = 0;
    for(  counter=1; counter<=ULONG_MAX; ++counter )
    {
        delay(time2wait);
        for(channel=1; channel<=PIN_RANGE; ++channel)
        {
            if (counter%channel == 0)
            {
                pin=channel+START_PIN-1;                // calculate output pin from channel
                digitalWrite(pin, !digitalRead(pin));   // toggle output pin
            }
        }
    }
}

