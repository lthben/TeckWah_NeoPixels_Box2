/* Author: Benjamin Low
 * 
 * Description: Teck Wah gallery NeoPixels Box 2 - Button x 2, Ring x 2,
 *              Display x 3, Panel x 3, Map x 2
 *
 * Last updated: 27 Jan 2016
 */

#include <Adafruit_NeoPixel.h> 

//USER DEFINED SETTINGS
bool DEBUG = true;
const int FADE_INTERVAL = 10; //lower number is higher speed for fade

enum  pattern { NONE, SCANNER, FADE };
enum  direction { FORWARD, REVERSE };

// NeoPattern Class - derived from the Adafruit_NeoPixel class
class NeoPatterns : public Adafruit_NeoPixel
{
    public:
 
    // Member Variables:  
    pattern  ActivePattern;  // which pattern is running
    direction Direction;     // direction to run the pattern
    
    unsigned long Interval;   // milliseconds between updates
    unsigned long lastUpdate; // last update of position
    
    uint32_t Color1, Color2;  // What colors are in use 
    uint16_t TotalSteps;  // total number of steps in the pattern
    int Index;  // current step within the pattern

    uint32_t pinkColor = Color(200, 40, 60);
    uint32_t greenColor = Color(10, 220, 20 );
    uint32_t blueColor = Color(20, 20, 220);
    uint32_t yellowColor = Color( 255, 255, 0); 
    uint32_t white50Color = Color(128, 128, 128);
    uint32_t whiteColor = Color(255,255,255);
    uint32_t warmWhiteColor = Color(255, 255, 200);
    uint32_t redColor = Color(255, 0, 0);
    uint32_t noColor = Color(0,0,0);
    
    void (*OnComplete)();  // Callback on completion of pattern
    
    // Constructor - calls base-class constructor to initialize strip
    NeoPatterns(uint16_t pixels, uint8_t pin, uint8_t type, void (*callback)())
    :Adafruit_NeoPixel(pixels, pin, type)
    {
        OnComplete = callback;
    }
    
    // Update the pattern
    void Update()
    {
        if((millis() - lastUpdate) > Interval) // time to update
        {
            lastUpdate = millis();
            
            switch(ActivePattern)
            {
                case SCANNER:
                    ScannerUpdate();
                    break;
                case FADE:
                    FadeUpdate();
                break;
                default:
                    break;
            }
        }
    }
  
    // Increment the Index and reset at the end
    void Increment()
    {
        if (Direction == FORWARD)
        {
           Index++;
           
           if (Index >= TotalSteps) 
            {
                Index = 0;
                
                if (OnComplete != NULL)
                {
                    OnComplete(); 
                }
            }
        }
        else // Direction == REVERSE
        {
            --Index;
            
            if (Index < 0)
            {
                Index = TotalSteps-1;
                
                if (OnComplete != NULL)
                {
                    OnComplete();
                }
            }
        }
    }

    void TurnOff() {
        ColorSet(Color(0,0,0));
        ActivePattern = NONE;
    }
    
    void Scanner(uint32_t color1, uint8_t interval, int my_dir)
    {
        ActivePattern = SCANNER;
        Interval = interval;
        TotalSteps = numPixels();
        Color1 = color1;
        
        if (my_dir == 1) 
        {
            Direction = FORWARD;
            Index = 0;
        } 
        else if (my_dir == -1) 
        {
            Direction = REVERSE;
            Index = numPixels() - 1;
        }
    }
 
    // Update the Scanner Pattern
    void ScannerUpdate()
    { 
        for (int i = 0; i < numPixels(); i++)
        {
            if (i == Index)  // Scan Pixel to the right
            {
//                 setPixelColor(i, Wheel( ( (i * 256 / numPixels() ) + Index ) & 255) );
//                byte my_index = ( (i + Index) * 256 / numPixels() ) & 255;

//                Serial.println(my_index);
                
//                setPixelColor(i, Wheel(my_index) );

                    setPixelColor(i, Color1);
            }
           /*else if (i == TotalSteps - Index) // Scan Pixel to the left
            {
                 setPixelColor(i, Color1);
            }*/
            else // Fading tail
            {
                 setPixelColor(i, DimColor(getPixelColor(i)));
            }
        }
        show();
        Increment();
    }

     // Initialize for a Fade
    void Fade(uint32_t _color1, uint16_t steps, uint8_t interval, int state)
    {   //state is 1 for fade on, 0 for fade off
        
        ActivePattern = FADE;
        Interval = interval;
        TotalSteps = steps;
        Color1 = noColor;
        Color2 = _color1;
        
        if (state == 1) //turn on 
        {      
            Index = 0;
            Direction = FORWARD;
            
        } else if (state == 0) //turn off
        {
            Index = TotalSteps - 1;
            Direction = REVERSE;
        }
    }
    
    // Update the Fade Pattern
    void FadeUpdate()
    {
        // Calculate linear interpolation between Color1 and Color2
        // Optimise order of operations to minimize truncation error

        uint8_t red = ((Red(Color1) * (TotalSteps - Index)) + (Red(Color2) * Index)) / TotalSteps;
        uint8_t green = ((Green(Color1) * (TotalSteps - Index)) + (Green(Color2) * Index)) / TotalSteps;
        uint8_t blue = ((Blue(Color1) * (TotalSteps - Index)) + (Blue(Color2) * Index)) / TotalSteps;
            
        ColorSet(Color(red, green, blue));
        show();
        Increment();
    }
   
    // Calculate 50% dimmed version of a color (used by ScannerUpdate)
    uint32_t DimColor(uint32_t color)
    {
        // Shift R, G and B components one bit to the right
        uint32_t dimColor = Color(Red(color) >> 1, Green(color) >> 1, Blue(color) >> 1);
        return dimColor;
    }
 
    // Set all pixels to a color (synchronously)
    void ColorSet(uint32_t color)
    {
        for (int i = 0; i < numPixels(); i++)
        {
            setPixelColor(i, color);
        }
        show();
    }
 
    // Returns the Red component of a 32-bit color
    uint8_t Red(uint32_t color)
    {
        return (color >> 16) & 0xFF;
    }
 
    // Returns the Green component of a 32-bit color
    uint8_t Green(uint32_t color)
    {
        return (color >> 8) & 0xFF;
    }
 
    // Returns the Blue component of a 32-bit color
    uint8_t Blue(uint32_t color)
    {
        return color & 0xFF;
    }
    
    // Input a value 0 to 255 to get a color value.
    
    // The colours are a transition r - g - b - back to r.
    uint32_t Wheel(byte WheelPos)
    {
        WheelPos = 255 - WheelPos;
        
        if(WheelPos < 85)
        {
            return Color( 255 - WheelPos * 3, 0, WheelPos * 3);
        }
        else if(WheelPos < 170)
        {
            WheelPos -= 85;
            return Color(0, WheelPos * 3, 255 - WheelPos * 3);
        }
        else
        {
            WheelPos -= 170;
            return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
        }
    }

}; //end of class definition

// ------------------------------------------------------
// Function prototypes for completion callback routines 
// ------------------------------------------------------
void Strip1Complete(); void Strip2Complete(); void Strip3Complete(); void Strip4Complete();
void Strip5Complete(); void Strip6Complete(); void Strip7Complete(); void Strip8Complete();
void Strip9Complete(); void Strip10Complete(); void Strip11Complete(); void Strip12Complete();

// -----------------------------
// Object declarations
// -----------------------------
NeoPatterns Strip1(16, 2, NEO_GRB + NEO_KHZ800, &Strip1Complete); //button1
NeoPatterns Strip2(18, 3, NEO_GRB + NEO_KHZ800, &Strip2Complete); //button2
NeoPatterns Strip3(60, 4, NEO_GRB + NEO_KHZ800, &Strip3Complete); //ring1
NeoPatterns Strip4(60, 5, NEO_GRB + NEO_KHZ800, &Strip4Complete); //ring2
NeoPatterns Strip5(150, 6, NEO_GRB + NEO_KHZ800, &Strip5Complete); //panel1
NeoPatterns Strip6(150, 7, NEO_GRB + NEO_KHZ800, &Strip6Complete); //panel2
NeoPatterns Strip7(150, 8, NEO_GRB + NEO_KHZ800, &Strip7Complete); //panel3
NeoPatterns Strip8(150, 9, NEO_GRB + NEO_KHZ800, &Strip8Complete); //display1
NeoPatterns Strip9(150, 12, NEO_GRB + NEO_KHZ800, &Strip9Complete); //display2
NeoPatterns Strip10(150, 13, NEO_GRB + NEO_KHZ800, &Strip10Complete); //display3
NeoPatterns Strip11(150, A0, NEO_GRB + NEO_KHZ800, &Strip11Complete); //map1
NeoPatterns Strip12(4, A1, NEO_GRB + NEO_KHZ800, &Strip12Complete); //map2 - 4 single pixels

//------------------------------
// setup
//------------------------------
void setup() {
  Serial.begin(9600);

  Strip1.begin(); Strip2.begin(); Strip3.begin(); Strip4.begin(); 
  Strip5.begin(); Strip6.begin(); Strip7.begin(); Strip8.begin(); 
  Strip9.begin(); Strip10.begin(); Strip11.begin(); Strip12.begin();
}

//-------------------------
// The main loop
//-------------------------

void loop() {

  Strip1.Update(); Strip2.Update(); Strip3.Update(); Strip4.Update();
  Strip5.Update(); Strip6.Update(); Strip7.Update();Strip8.Update(); 
  Strip9.Update(); Strip10.Update(); Strip11.Update();Strip12.Update();  
  
  read_from_serial();
}

//-----------------------
// supporting functions
//-----------------------

void read_from_serial() { //refer to other tab for command list

  int incoming = 0;

  if (Serial.available() > 0) {
        
    incoming = Serial.read();
    
    process_command(incoming);
  }
}








