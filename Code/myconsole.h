#ifndef MYCONSOLE_H
#define MYCONSOLE_H


const int UPKEY = 38;
const int DOWNKEY = 40;
const int RIGHTKEY = 39;
const int LEFTKEY = 37;
const int ESCKEY = 27;


//this function will place the cursor at a certain position on the screen
void PlaceCursor(int x,int y);

//this function will clear the screen
void ClearScreen();



//this function outputs a string str at position (x,y) of the screen 
void OutputString(int x,int y,char *str);

//this function is an alternative to ClearScreen(), when ClearScreen() does not work on windows 7
void ClearScreen1();



//this function checks if a key is pressed and if a key is pressed
//then it returns the ascii code of the key pressed
//the parameter waitTime specifies how long we have to wait for an input
//the default value is 20 millisecond.  If within the wait time no key is pressed
//the function returns zero.
int CheckKeyPressed(int waitTime = 20);


//this function checks if a key is pressed and if a key is pressed
//then it returns the ascii code of the key pressed
//there is no wait time like in the above CheckKeyPressed function
//you can use it if CheckKeyPressed gives you problems
int CheckKeyPressed1();


//this will change the window size to width and height as specified in the function
//will not work for greater than a certain width and greater than a certain height
//depeding upon the system you are using
void SetWindowSize(int width,int height);


//changes the color of a certain co-ordinate
//changes the color of a certain co-ordinate
//color can be BACKGROUND_GREEN, BACKGROUND_BLUE,BACKGROUND_RED or a combination of these using | operator
//e.g. you can send as parameter BACKGROUND_GREEN|BACKGROUND_BLUE
//the following combinations are possible:
//FOREGROUND_BLUE    Text color contains blue.
//FOREGROUND_GREEN    Text color contains green.
//FOREGROUND_RED    Text color contains red.
//FOREGROUND_INTENSITY    Text color is intensified.
//BACKGROUND_BLUE    Background color contains blue.
//BACKGROUND_GREEN    Background color contains green.
//BACKGROUND_RED    Background color contains red.
//BACKGROUND_INTENSITY    Background color is intensified.
//An example of usage:
//    PlaceCursor(0,0);
//    cout << '*';
//    SetColorAtPoint(0,0,BACKGROUND_RED|FOREGROUND_BLUE);
bool SetColorAtPoint(int x,int y,int color);


//set the title of the window
void SetWindowTitle(char Title[]);

//will get the maximum and minimum x and y coordinates of the current window
void GetMaxWindowCoordinates(int &x,int &y);


#endif

