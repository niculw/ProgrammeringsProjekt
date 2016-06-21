#ifndef _LED_H_
#define _LED_H_

void LEDinit();
void initVideoBuffer( struct controlData * ctrlData  );
void LEDsetString( struct controlData * ctrlData);
void LEDupdate( struct controlData * ctrlData );

#endif 
