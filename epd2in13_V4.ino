#include <SPI.h>

#include "epd2in13_V4.h"
#include "epdpaint.h"
#include "imagedata.h"

#define COLORED     1
#define UNCOLORED   0

/**
  * Due to RAM not enough in Arduino UNO, a frame buffer is not allowed.
  * In this case, a smaller image buffer is allocated and you have to 
  * update a partial display several times.
  * 1 byte = 8 pixels, therefore you have to set 8*N pixels at a time.
  */
unsigned char image[1050];
Paint paint(image, 0, 0);
Epd epd;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Power On");
  epd.Init(FAST);
 


  epd.Init(FULL);
  Paint paint(image, epd.bufwidth*8, epd.bufheight);    //width should be the multiple of 8
  

  paint.SetRotate(ROTATE_90);
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(20, 50, "FIRMWARE-LOADING", &Font24, COLORED);
  //paint.DrawStringAt(8, 80, "JakeLofthouse", &Font16, COLORED);
  epd.Display1(image);
  

  paint.Clear(UNCOLORED);
  epd.Display1(image);
  paint.Clear(UNCOLORED);
  epd.Display1(image);
  paint.Clear(UNCOLORED);
  epd.Display1(image);

}


void loop()
{

}

