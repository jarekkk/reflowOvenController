/************************************
*
* Menu Abstract Classes, used for embedded device menus 
* Two classes - Menu Item - Used to hold details of the linked list of menus
*             - Menu Display - Used to display the current item on the selected hardware.
* 
*************************************
* (C) Toby Wilkinson - tobes@tobestool.net - 2013.
************************************/
#ifndef MenuBase_h
#define MenuBase_h

#include "Arduino.h"
//#include <WProgram.h>

class MenuDisplay;

class MenuItem {
public:
  MenuItem *Previous;
  MenuItem *Next;
  MenuItem *Parent;
  char Name[22];
//  int afterName;

  virtual void getValueString (char *string) = 0;
  virtual void select(MenuDisplay *controller) = 0;
  virtual void exit(MenuDisplay *controller) = 0;
  virtual void inc(MenuDisplay *controller) = 0;
  virtual void dec(MenuDisplay *controller) = 0;
  void addItem(MenuItem *newItem);
};

class MenuDisplay {
public:
  MenuItem *Current; 
  MenuItem *Editing;

  virtual void showCurrent () = 0;
  virtual void showCurrentValue () = 0;
  void moveToNext ();
  void moveToPrev ();
  
  virtual void poll () = 0;
};
#endif
