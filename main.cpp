#include <iostream>
#include "mygraphics.h"
#include "myconsole.h"
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int x = 600; ///this is basically a constant value which i used at different places for alignment of boxes
const int MAXSIZE = 500; /// this is the maximum size constant which i used for limiting the maximum size of an array
const COLORREF green = RGB(0,255,0) , blue = RGB(0,0,255) , black = RGB(0,0,0) , white = RGB(255,255,255) , red = RGB(255,0,0);
const COLORREF gold = RGB(255,215,0) , orange = RGB(255,140,0) , violet = RGB(199,21,133) , yellow = RGB(255,255,0);

/////These are the function prototypes

void BoxesAndLines_Builder(int X1, int Y1, int X2 ,int Y2,int& store ,int increment_Y);
void Middle_Points_of_Still_Boxes(int X1, int Y1, int X2 ,int Y2 ,int midCoordinates_Still[] , int& midSize,int increment_Y);
void Make_Typing_Box(int X1, int Y1, int X2 ,int Y2,int store,int midCoordinates_TBox[]);
void Moving_Box_Maintainer(int Sleep_Variable, int Add, int Total_Characters_of_Words_in_Still_Boxes , int Number_of_Characters , char Lives_Digit[] , char Lives[] , int Lives_Arr_Index , char Score_Digit[] , char Score[] , int& Score_Arr_Index , int X1 , int Y1 , int X2 , int Y2 , int midCoordinates_TBox[] , char Words_Displayed_in_Still_Boxes[] , int Words_Displayed_in_Still_Boxes_Size ,int increment_Y ,int midCoordinates_Move[] ,int midSize ,int store , char Word_Displayed_In_movingBox[] , char Typed_Word[] , int midCoordinates_Still[] );
void Words_Collector(char Words[] , char File[]);
void Words_Placer_in_Still_Boxes (int Number_of_Characters, int Total_Characters_of_Words_in_Still_Boxes, int TotalWords_Arr_Size , int midCoordinates_Still[] , int midSize , char Total_Words[] ,char Words_Displayed_in_Still_Boxes[] , int& Words_Displayed_in_Still_Boxes_Size);
void Word_Placer_in_Moving_Box(int Number_of_Characters , int k , int i , int decrement_X , int midCoordinates_Move[] , char Words_Displayed_in_Still_Boxes[] , char Word_Displayed_In_movingBox[] );
void Middle_Points_of_movingBox(int X2 , int Y1 ,int Y2 , int midCoordinates_Move[] ,int midSize , int increment_Y);
void Diplay_Characters_in_TypingBox(int midCoordinates_TBox[] , char character[] , int& Increment_X , int m , char Typed_Word[]);
bool Match_Typed_Word_And_Moving_Word(char Typed_Word[] , char Word_Displayed_In_movingBox[]);
void Score_And_Lives_Maintainer(int Add ,int Number_of_Characters , int Total_Characters_of_Words_in_Still_Boxes , char Lives_Digit[] , char Lives[] , int& Lives_Arr_Index ,char Score_Digit[] ,char Score[] ,int& Score_Arr_Index ,char character[] ,int& Increment_X ,int& count , int& m ,int X1 ,int Y1 ,int X2 ,int Y2 ,int store ,int  midCoordinates_TBox[] ,char Typed_Word[] ,char Word_Displayed_In_movingBox[] ,int &k ,int i ,int decrement_X ,int midCoordinates_Move[] ,char Words_Displayed_in_Still_Boxes[] ,int Words_Displayed_in_Still_Boxes_Size , int midCoordinates_Still[]  );
void Make_Score_Box(int store , int X2 , int X1 , int Score_Arr_Index , char Score[] , char Score_Digit[]);
void Word_Generator_For_Moving_Box(int  Words_Displayed_in_Still_Boxes_Size , int& k , int Number_of_Characters);
void Leftwards_Box_Mover (int Number_of_Characters , int Y1 , int Y2 , int X2 , int k , int i ,int decrement_X ,int midCoordinates_Move[] ,char Words_Displayed_in_Still_Boxes[] , char Word_Displayed_In_movingBox[] );
void Make_Lives_Box(int store , int X2 , int X1 , int Lives_Arr_Index , char Lives[] , char Lives_Digit[]);
bool Match_Moving_Word_And_Still_Word (int Number_of_Characters , int Add ,int i , char Word_Displayed_In_movingBox[] , char Words_Displayed_in_Still_Boxes[]);
void Highlight_Matched_Characters(int Number_of_Characters, int Add ,int i , char Word_Displayed_In_movingBox[] , char Words_Displayed_in_Still_Boxes[] , int midCoordinates_Still[] , char Un_Highlight_Character[]);
void De_Highlight_Matched_Characters(int i , char Un_Highlight_Character[] , int midCoordinates_Still[] );
void GameWon_Box( int Y1 , int Y2 , int X1 , int X2 );
void GameLost_Box(int Y1 , int Y2 , int X1 , int X2 );
void Game_Controller( int Sleep_Variable ,  int Add, int Total_Characters_of_Words_in_Still_Boxes , int Number_of_Characters , char File[]);





////This function will read the words from a file
void Words_Collector(char Total_Words[] , char File[] , int& TotalWords_Arr_Size)
{
  ifstream InputStream(File);
        if (InputStream.is_open())
        {
              int i=0;
                      while(InputStream >> Total_Words[i])
                          i++;

          TotalWords_Arr_Size = i ;
        }
  InputStream.close();
}





////This function will draw the Still Boxes and The Lines
void BoxesAndLines_Builder(int X1, int Y1, int X2 ,int Y2,int& store ,int increment_Y)
{
      for (int i=0 ; i < 5 ; i++)
      {
          myLine( X2 ,Y1 ,x ,Y1 ,violet );//this will draw the lines
          myRect( X1 ,Y1 ,X2 ,Y2 ,yellow ,red );//this will draw the still boxes
          Y1 = Y2;
          Y2 = Y2 + increment_Y;
      }

        store = Y2;

   myLine( X2 ,Y1 ,x ,Y1 ,violet );//this will draw the last line with respect to the fifth Still Box
}





//////This function will calculate the mid points of the Still Boxes which will later on help in alignment of boxes
void Middle_Points_of_Still_Boxes(int X1, int Y1, int X2 ,int Y2 ,int midCoordinates_Still[] , int& midSize ,int increment_Y)
{
  int mid_X = 0 , mid_Y = 0;

      for(int i=0 ; i < 10 ; i = i+2 )
      {
            mid_X = ( (X1+X2) / 2 ) - 15;///x coordinate of middle point
            mid_Y = ( (Y1+Y2) / 2 ) - 10;///y coordinate of middle point
            midCoordinates_Still [i] = mid_X;
            midCoordinates_Still [i+1] = mid_Y;

        midSize = midSize+2;////Size of the Array which is storing the Middle Coordinates of Still Boxes
        Y1 = Y2;
        Y2 = Y2 + increment_Y;
      }
}





///// This function will make the Typing Box for user
void Make_Typing_Box(int X1, int Y1, int X2 ,int Y2,int store,int midCoordinates_TBox[])
{
      myRect( x/2 + X1 , store-40 , x - X2 , store+10 , white , gold );
      midCoordinates_TBox [0] = ( (x/2 + X1) + (x - X2) ) / 2;//Storing the mid points of the typing box
      midCoordinates_TBox [1] = ( (store-40) + (store + 10) ) / 2;// in an array for further usage
}





/////This function will display the word in the typing box which has been entered by user
void Diplay_Characters_in_TypingBox(int midCoordinates_TBox[] , char character[] , int& Increment_X , int m , char Typed_Word[])
{
      myDrawText ( midCoordinates_TBox[0] - 20 + Increment_X  , midCoordinates_TBox [1] - 10 , 10 , character , black , gold);
      Typed_Word [m] = character [0];//This will store the typed word - character by character in an array
      Increment_X = Increment_X + 10 ;
}





//////This function will calculate the Middle points of the Moving Box in an array which will later on help in different things
void Middle_Points_of_movingBox(int X2 , int Y1 ,int Y2 , int midCoordinates_Move[] ,int midSize , int increment_Y)
{
///// Code for calculating middle points of Moving Box
  int mid_X = 0 , mid_Y = 0;

        for(int i=0 ; i < midSize ; i=i+2)
         {
                 mid_X = ( (x + (X2+x) ) / 2) - 15;//x coordinate of middle point of moving box
                 mid_Y = ( (Y1 + Y2) / 2 ) - 10;//y coordinate of middle point of moving box
                 midCoordinates_Move[i]=mid_X;
                 midCoordinates_Move[i+1]=mid_Y;
            Y1=Y2;
            Y2 = Y2 + increment_Y;
          }
}





///////This function will make the Score Box of the game
void Make_Score_Box(int store , int X2 , int X1 , int Score_Arr_Index , char Score[] , char Score_Digit[])
{
    Score_Digit[0] = Score [Score_Arr_Index];

    myRect( X1 , store - 40,  x/2 - X1 , store + 10 , white , green );
    myDrawText( X1 + 60  , store - 20  , 10 ,"Your Score : " , black , green);
    myDrawText( X1 + 160  , store - 20  , 10 , Score_Digit , black , green);///this will display the score digit in the Score Box
}





///////This function will show the Number of lives , the user has , in a Lives box
void Make_Lives_Box(int store , int X2 , int X1 , int Lives_Arr_Index , char Lives[] , char Lives_Digit[] )
{
    Lives_Digit[0] = Lives[Lives_Arr_Index];

    myRect (x - X2 + X1 + X1 ,store - 40 , x + X2 , store+10 , white , green );
    myDrawText ( x - X2 + 80  , store - 20  , 10  ,"Lives left :" , black , green);
    myDrawText ( x - X2 + 160  , store - 20  , 10 , Lives_Digit , black , green);
}





////This function will generate an index of the new word which is to be used by the next function of "Word_Placer_in_Moving_Box"
void Word_Generator_For_Moving_Box(int  Words_Displayed_in_Still_Boxes_Size , int& k , int Number_of_Characters)
{

   k = rand() % Words_Displayed_in_Still_Boxes_Size;

          while( k % Number_of_Characters != 0  )
                  k = rand() % Words_Displayed_in_Still_Boxes_Size;
}





////This function will use the index generated by the function "Word_Generator_For_Moving_Box" and generate a new word for the MovingBox
void Word_Placer_in_Moving_Box(int Number_of_Characters , int k , int i , int decrement_X , int midCoordinates_Move[] , char Words_Displayed_in_Still_Boxes[] , char Word_Displayed_In_movingBox[] )
{
  char character[MAXSIZE] ={};
  int  increment_X= 0 ;

      for (int j = 0 ; j < Number_of_Characters ; j++)
       {
              character[0] = Words_Displayed_in_Still_Boxes[k] ;

              myDrawText( midCoordinates_Move[i] - 5 + increment_X - decrement_X , midCoordinates_Move[i+1] + 3 , 10 , character , green , blue);
              Word_Displayed_In_movingBox [j] = Words_Displayed_in_Still_Boxes [k];///This will store the word, which is displayed in the moving box,
                                                                               /// to an array for further usage
        k++;
        increment_X = increment_X + 10;
      }
}





/////This function will place words in the Still Boxes
void Words_Placer_in_Still_Boxes (int Number_of_Characters, int Total_Characters_of_Words_in_Still_Boxes, int TotalWords_Arr_Size , int midCoordinates_Still[] , int midSize , char Total_Words[] ,char Words_Displayed_in_Still_Boxes[] , int& Words_Displayed_in_Still_Boxes_Size)
{
  //////Code for placing words in Still Boxes
  int increment_X = 0, m = 0 ;
  char character[MAXSIZE] = {} ;

  int k = rand() % TotalWords_Arr_Size ;////the mode is taken by a number which is equal to the total number of characters of all the words
                        ///in the file

    while (k % Number_of_Characters != 0 || k > (TotalWords_Arr_Size - Total_Characters_of_Words_in_Still_Boxes))////this condition is such that the Still Boxes always have a word in them
      k = rand() % (TotalWords_Arr_Size - Total_Characters_of_Words_in_Still_Boxes );//////**********

        for (int i = 0 ; i < midSize ; i=i+2)///midSize will always be 10 and the loop will run five times because of Five still boxes
        {
            increment_X = 0;

                for (int j = 0 ; j < Number_of_Characters ; j++)
                {
                      character[0] = Total_Words[k];
                      myDrawText( midCoordinates_Still [i] - 5 + increment_X ,  midCoordinates_Still[i+1] + 3 , 10 , character ,black ,red );
                      Words_Displayed_in_Still_Boxes [m]   =  Total_Words [k] ;//This will store the words , displayed in the stil boxes , to an Array for further usage
                  k++;
                  m++;
                  increment_X = increment_X + 10;
                }
        }

  Words_Displayed_in_Still_Boxes_Size = m;
}





/////This function will match the word typed by the user with the word being displayed in the Moving Box(Matching would be done character by character)
bool Match_Typed_Word_And_Moving_Word (char Typed_Word [] , char Word_Displayed_In_movingBox [] )
{
  bool same = true;

       for ( int i = 0 ; Typed_Word[i] != 0 && same ; i++)
        {
              if( Typed_Word [i] != Word_Displayed_In_movingBox [i] )
                      same = false;
        }


  return same;
}





/////This function will move the Moving Box leftwards after the typed word and the word in the moving box have been matched
void Leftwards_Box_Mover (int Number_of_Characters , int Y1 , int Y2 , int X2 , int k , int i ,int decrement_X ,int midCoordinates_Move[] ,char Words_Displayed_in_Still_Boxes[] , char Word_Displayed_In_movingBox[] )
{

            while( (x - decrement_X )  > X2 )////this is determining upto which distance the moving box will move leftward
            {
                   myRect( x - decrement_X , Y1 + 3 , X2 + x - decrement_X , Y2 - 3 ,white ,violet );
                   Word_Placer_in_Moving_Box(Number_of_Characters , k ,i , decrement_X , midCoordinates_Move ,Words_Displayed_in_Still_Boxes ,Word_Displayed_In_movingBox) ;
                   Sleep (100);
                   myRect( x - decrement_X , Y1 + 3, X2 + x - decrement_X , Y2 - 3 , black , black);
              decrement_X = decrement_X + 30;
            }

    myRect( x - decrement_X + 5  , Y1 + 3 , X2 + x - decrement_X - 5 , Y2 - 3 , white , violet );
    ///After moving the box has successfully been moved left , this will place the word in that box
   Word_Placer_in_Moving_Box(Number_of_Characters , k ,i , decrement_X - 5  , midCoordinates_Move , Words_Displayed_in_Still_Boxes , Word_Displayed_In_movingBox );
}





///////This function will higlights those characters of still box which are same as that of those in the moving box
void Highlight_Matched_Characters(int Number_of_Characters, int Add ,int i , char Word_Displayed_In_movingBox[] , char Words_Displayed_in_Still_Boxes[] , int midCoordinates_Still[] , char Un_Highlight_Character[])

{

  int increment_X = 0;
  int j = 0 ;
  char Highlighted_Character[MAXSIZE] = {};

               if(i == 0)
                 j = 3 +   Add;
               if(i == 2)
                 j = 6 +  (2*Add);
               if(i == 4)
                 j = 9 +  (3*Add);
               if(i == 6)
                 j = 12 + (4*Add);
               if(i == 8)
                 j = 15 + (5*Add);
               if(j == 10)
                 j = 15 + (5*Add);

  int m = j - Number_of_Characters;
  int store = m;

     for(int n = 0 ;  n < Number_of_Characters ; n++ )
        {
             for(store ; store < j ; store++  )
              {
                  if( Word_Displayed_In_movingBox [n] == Words_Displayed_in_Still_Boxes [store] )
                    {
                       Highlighted_Character[0] = Words_Displayed_in_Still_Boxes [store] ;

                      myDrawText( midCoordinates_Still [i] - 5 + increment_X ,  midCoordinates_Still[i+1] + 3 , 10 , Highlighted_Character ,black ,yellow );
                    }

              increment_X = increment_X + 10;
              }

          Un_Highlight_Character [n] = Words_Displayed_in_Still_Boxes [m+n] ;
          store =  m ;
          increment_X = 0;
        }

}





//////This function will de-highlight the matched characters after they have been highlighted
void De_Highlight_Matched_Characters(int i , char Un_Highlight_Character[] , int midCoordinates_Still[] )
{
  char temp[MAXSIZE] = {};
  int increment_X = 0;

         for( int n = 0 ; Un_Highlight_Character[n] != 0 ; n++ )
            {
                temp[0] = Un_Highlight_Character [n];
                myDrawText( midCoordinates_Still [i] - 5 + increment_X ,  midCoordinates_Still[i+1] + 3 , 10 , temp ,black ,red );
                increment_X = increment_X + 10;
            }
}




////This function will match the word in the moving box with the word in the still box(the box to which the moving box has been moved leftwards)
bool Match_Moving_Word_And_Still_Word (int Number_of_Characters , int Add ,int i , char Word_Displayed_In_movingBox[] , char Words_Displayed_in_Still_Boxes[])
{
  bool same = true ;
  int j = 0 ;

               if(i == 0)
                 j = 3 +   Add;
               if(i == 2)
                 j = 6 +  (2*Add);
               if(i == 4)
                 j = 9 +  (3*Add);
               if(i == 6)
                 j = 12 + (4*Add);
               if(i == 8)
                 j = 15 + (5*Add);
               if(j == 10)
                 j = 15 + (5*Add);

  int m = j - Number_of_Characters;

          for(int n = 0 ;  n < Number_of_Characters && same && m < j  ; n++ )
            {
                  if( Word_Displayed_In_movingBox [n] != Words_Displayed_in_Still_Boxes[m] )
                        same = false;

              m++;
            }

  return same;
}




//////////This Function will call the word matching functions and highlight the matched characters and after matching will maintain the score and lives accordingly
void Score_And_Lives_Maintainer(int Add ,int Number_of_Characters , int Total_Characters_of_Words_in_Still_Boxes , char Lives_Digit[] , char Lives[] , int& Lives_Arr_Index ,char Score_Digit[] ,char Score[] ,int& Score_Arr_Index ,char character[] ,int& Increment_X ,int& count , int& m ,int X1 ,int Y1 ,int X2 ,int Y2 ,int store ,int  midCoordinates_TBox[] ,char Typed_Word[] ,char Word_Displayed_In_movingBox[] ,int &k ,int i ,int decrement_X ,int midCoordinates_Move[] ,char Words_Displayed_in_Still_Boxes[] ,int Words_Displayed_in_Still_Boxes_Size , int midCoordinates_Still[]  )
{

 char Un_Highlight_Character [MAXSIZE] = {};

   /////Code to check if a key has been pressed by user and then display that character in the typing Box
   character[0] = CheckKeyPressed(0);
        if(character[0])
          {
              Diplay_Characters_in_TypingBox ( midCoordinates_TBox , character , Increment_X , m ,Typed_Word);
          m++;
          count++;
          }
    character[0]=0;


   //////Code to check if a complete word has been entered by user and then do the matching tasks
    if (count != 0 && count % Number_of_Characters == 0)
      {
        Increment_X = 0;
        count = 0;
        m = 0;

              if( Match_Typed_Word_And_Moving_Word (Typed_Word , Word_Displayed_In_movingBox ) )
                    {
                        Highlight_Matched_Characters (Number_of_Characters, Add , i , Word_Displayed_In_movingBox , Words_Displayed_in_Still_Boxes , midCoordinates_Still , Un_Highlight_Character );
                        Leftwards_Box_Mover (Number_of_Characters , Y1 , Y2 , X2 ,  k , i , decrement_X ,  midCoordinates_Move , Words_Displayed_in_Still_Boxes ,Word_Displayed_In_movingBox ) ;
                        De_Highlight_Matched_Characters ( i , Un_Highlight_Character , midCoordinates_Still );
                    }

              /////Code to check if the word in the moving box , matches with that of the word in the Still box and then maintain the score accordingly
              if ( Match_Moving_Word_And_Still_Word (Number_of_Characters, Add , i , Word_Displayed_In_movingBox , Words_Displayed_in_Still_Boxes) )
              {
                          Score_Arr_Index++;
                          Make_Score_Box(store , X2 , X1 ,Score_Arr_Index , Score  ,Score_Digit);//will make the score box again with the new Score
              }

              /////if the word in the moving box donot match with the typed word and the word in the still box then this code will decrease
              /////the number of lives the user has by one every time
              else
              {
                         Lives_Arr_Index--;
                         Make_Lives_Box(store , X2 , X1 , Lives_Arr_Index , Lives , Lives_Digit);//will make the Lives box again with the new no. of Lives
              }

          Make_Typing_Box( X1, Y1 , X2 , Y2, store , midCoordinates_TBox );

          ////this code will now generate a new for the moving box
          Word_Generator_For_Moving_Box (Words_Displayed_in_Still_Boxes_Size , k , Number_of_Characters );
          Word_Placer_in_Moving_Box (Number_of_Characters , k , i , decrement_X , midCoordinates_Move ,Words_Displayed_in_Still_Boxes , Word_Displayed_In_movingBox );
      }
}





////This function will show the Game Won message to the user after he has won the game
void GameWon_Box( int Y1 , int Y2 , int X1 , int X2 )
{
       myRect( x + X2 , Y2 , x + x , 2 * Y2 , red , yellow  );
       myDrawText( x + X2 + X2  , Y2 + 30 , 10 , "CONGRATS !!! YOU HAVE WON THE GAME  :) " , yellow , red  );
       myDrawText( x + X2 + X2  , Y2 + 50 , 10 , "AND YOUR AMAZING SCORE IS ' 10 '" , yellow , red  );
}





/////This function will show the Game Lose message to the user after he has loss the game
void GameLost_Box(int Y1 , int Y2 , int X1 , int X2)
{

       myRect( x + X2  , Y2 , x + x , 2 * Y2 , red , yellow  );
       myDrawText( x + X2 + X2  , Y2 + 30 , 10 , "OOOOPS !!! YOU LOST THE GAME  :(  " , yellow , red  );
}





/////This function mainly deals with the activities related to Moving Box like moving it , calling the score and lives maintainer
/////function and other similar functions related to the moving box
void Moving_Box_Maintainer(int Sleep_Variable, int Add, int Total_Characters_of_Words_in_Still_Boxes , int Number_of_Characters , char Lives_Digit[] , char Lives[] , int Lives_Arr_Index , char Score_Digit[] , char Score[] , int& Score_Arr_Index , int X1 , int Y1 , int X2 , int Y2 , int midCoordinates_TBox[] , char Words_Displayed_in_Still_Boxes[] , int Words_Displayed_in_Still_Boxes_Size ,int increment_Y ,int midCoordinates_Move[] ,int midSize ,int store , char Word_Displayed_In_movingBox[] , char Typed_Word[] , int midCoordinates_Still[] )
{

    Middle_Points_of_movingBox ( X2 , Y1 ,Y2 , midCoordinates_Move , midSize ,increment_Y );//calculating the middle points of MovingBox
                                                                                            //for further usage
    int k = 0 , i = 0 , Increment_X = 0 , count = 0 , m = 0 , decrement_X = 0 ;
    char character [MAXSIZE] = {} ;

    Word_Generator_For_Moving_Box ( Words_Displayed_in_Still_Boxes_Size , k , Number_of_Characters);

       while ( Score_Arr_Index < 10  &&  Lives_Arr_Index > 0)
       {

              ///////Code for maintaining the functions related to moving box while moving it Downwards
              for ( int j =0 ; j < 5 ; j++) //Moves the MatchingBox downwards
              {
                   myRect( x ,Y1 + 3 , X2 + x , Y2 - 3  ,green ,blue );
                   Word_Placer_in_Moving_Box(Number_of_Characters , k ,i ,decrement_X , midCoordinates_Move ,Words_Displayed_in_Still_Boxes ,Word_Displayed_In_movingBox);
                       Score_And_Lives_Maintainer(Add ,Number_of_Characters , Total_Characters_of_Words_in_Still_Boxes , Lives_Digit , Lives , Lives_Arr_Index ,Score_Digit,Score ,Score_Arr_Index ,character , Increment_X , count, m ,X1 ,Y1 ,X2 ,Y2 ,store , midCoordinates_TBox , Typed_Word , Word_Displayed_In_movingBox , k ,i ,decrement_X ,midCoordinates_Move ,Words_Displayed_in_Still_Boxes ,Words_Displayed_in_Still_Boxes_Size , midCoordinates_Still);
                   Sleep(Sleep_Variable);
                       Score_And_Lives_Maintainer(Add ,Number_of_Characters , Total_Characters_of_Words_in_Still_Boxes ,Lives_Digit , Lives , Lives_Arr_Index ,Score_Digit,Score ,Score_Arr_Index ,character , Increment_X , count, m,X1 ,Y1 ,X2 ,Y2 ,store, midCoordinates_TBox , Typed_Word , Word_Displayed_In_movingBox , k ,i ,decrement_X ,midCoordinates_Move ,Words_Displayed_in_Still_Boxes,Words_Displayed_in_Still_Boxes_Size , midCoordinates_Still);
                   myRect( x , Y1 + 3  , X2 + x , Y2 - 3 ,black , black);

               Y1 = Y2;
               Y2 = Y2 + increment_Y;
               i = i + 2;
              }


              ///////// Code for maintaining the functions related to moving box while moving it upwards
              for (int j = 5 ; j > 0 ; j--) //Moves the MatchingBox upwards
              {
               Y2 = Y1;
               Y1 = Y2 - increment_Y ;
               i = i -2 ;

                   myRect(x ,Y1 + 3 , X2 + x , Y2 - 3 , green ,blue);
                   Word_Placer_in_Moving_Box(Number_of_Characters , k ,i ,decrement_X , midCoordinates_Move ,Words_Displayed_in_Still_Boxes , Word_Displayed_In_movingBox);
                       Score_And_Lives_Maintainer(Add ,Number_of_Characters , Total_Characters_of_Words_in_Still_Boxes ,Lives_Digit , Lives , Lives_Arr_Index ,Score_Digit ,Score ,Score_Arr_Index,character , Increment_X , count, m , X1 ,Y1 ,X2 ,Y2 ,store , midCoordinates_TBox , Typed_Word , Word_Displayed_In_movingBox , k , i ,decrement_X , midCoordinates_Move , Words_Displayed_in_Still_Boxes , Words_Displayed_in_Still_Boxes_Size, midCoordinates_Still);
                   Sleep(Sleep_Variable);
                       Score_And_Lives_Maintainer(Add ,Number_of_Characters , Total_Characters_of_Words_in_Still_Boxes ,Lives_Digit , Lives , Lives_Arr_Index ,Score_Digit ,Score ,Score_Arr_Index,character , Increment_X , count, m , X1 ,Y1 ,X2 ,Y2 ,store , midCoordinates_TBox , Typed_Word , Word_Displayed_In_movingBox , k , i ,decrement_X , midCoordinates_Move , Words_Displayed_in_Still_Boxes , Words_Displayed_in_Still_Boxes_Size, midCoordinates_Still);
                   myRect( x , Y1 + 3 , X2 + x , Y2 - 3 ,black , black);
              }
        }
}





////This is the main game controller function which will control the game by calling other functions
void Game_Controller( int Sleep_Variable ,  int Add, int Total_Characters_of_Words_in_Still_Boxes , int Number_of_Characters , char File[])
{

   int X1 = 10 , Y1 = 10 , X2 = 120 , Y2 = 80 , midSize = 0 , store = 0 ;
   int  Score_Arr_Index = 0;
   int  Lives_Arr_Index = 5;

   int increment_Y= Y2 - Y1;
   int Words_Displayed_in_Still_Boxes_Size = 0;
   int TotalWords_Arr_Size = 0;
   srand(time(NULL));

   int midCoordinates_Still [MAXSIZE] = {} ;
   int midCoordinates_Move [MAXSIZE]  = {} ;
   int midCoordinates_TBox [MAXSIZE]  = {} ;

   char Lives [MAXSIZE] = {'0','1','2','3','4','5'} ;
   char Score [MAXSIZE] = {'0','1','2','3','4','5','6','7','8','9'} ;
   char Score_Digit [MAXSIZE] = {} ;
   char Lives_Digit [MAXSIZE] = {} ;
   char Words_Displayed_in_Still_Boxes [MAXSIZE] = {} ;
   char Word_Displayed_In_movingBox [MAXSIZE] = {} ;
   char Typed_Word [MAXSIZE] = {} ;
   char Total_Words [MAXSIZE] = {} ;


   Words_Collector ( Total_Words , File , TotalWords_Arr_Size);
   BoxesAndLines_Builder ( X1 ,Y1 ,X2 ,Y2 , store ,increment_Y);
   Middle_Points_of_Still_Boxes ( X1 ,Y1 ,X2 ,Y2, midCoordinates_Still , midSize , increment_Y );
   Words_Placer_in_Still_Boxes (Number_of_Characters, Total_Characters_of_Words_in_Still_Boxes ,TotalWords_Arr_Size ,midCoordinates_Still ,midSize , Total_Words , Words_Displayed_in_Still_Boxes , Words_Displayed_in_Still_Boxes_Size );
   Make_Typing_Box ( X1, Y1, X2 , Y2, store ,midCoordinates_TBox );
   Make_Score_Box ( store , X2 , X1 , Score_Arr_Index , Score , Score_Digit );
   Make_Lives_Box ( store , X2 , X1 , Lives_Arr_Index , Lives , Lives_Digit );
   Moving_Box_Maintainer (Sleep_Variable , Add, Total_Characters_of_Words_in_Still_Boxes , Number_of_Characters, Lives_Digit ,Lives , Lives_Arr_Index ,Score_Digit ,Score , Score_Arr_Index , X1 , Y1 , X2 , Y2 , midCoordinates_TBox , Words_Displayed_in_Still_Boxes , Words_Displayed_in_Still_Boxes_Size , increment_Y , midCoordinates_Move , midSize , store , Word_Displayed_In_movingBox , Typed_Word , midCoordinates_Still);


   if ( Score_Arr_Index == 10 )
        GameWon_Box(Y1 , Y2 , X1 ,X2);
   else
       GameLost_Box(Y1 , Y2, X1 ,X2);

}






int main()
{
    system("mode 650");
    SetWindowTitle("Welcome to TYPING TUTOR !!!!!!!!!!!!!!!!!!!!!  -  Made by HARIS MUNEER , 15L-4149 , CS - D");
    ClearScreen();

    //////Code to select different levels containing words of characters of different lengths like three , four , five
    int Level = 0;

    cout << "Enter '1' for LEVEL 1 with WORDS of THREE Characters "<<endl;
    cout << "Enter '2' for LEVEL 2 with WORDS of FOUR Characters  "<<endl;
    cout << "Enter '3' for LEVEL 3 with WORDS of FIVE Characters  "<<endl;
    cout << "Enter '4' for LEVEL 4 with WORDS of SIX Characters   "<<endl<<endl;
    cout << "Now enter either '1' or '2' or '3' or '4' :" ;
    cin >> Level;

    ClearScreen();

    int Number_of_Characters = 0;
    int Total_Characters_of_Words_in_Still_Boxes = 0;
    int Add = 0;
    int Sleep_Variable = 0;

     //////Declaration of some variables which will be used later on
      if ( Level == 1 )
        {
          Number_of_Characters = 3;
          Total_Characters_of_Words_in_Still_Boxes = 15;
          Add = 0;
          Sleep_Variable = 200 ;
          char File [MAXSIZE] = "Words_3.txt" ;
          Game_Controller(Sleep_Variable ,Add ,Total_Characters_of_Words_in_Still_Boxes , Number_of_Characters , File);
        }

      else if ( Level == 2 )
        {
          Number_of_Characters = 4;
          Total_Characters_of_Words_in_Still_Boxes = 20;
          Add = 1;
          Sleep_Variable = 150 ;
          char File [MAXSIZE] = "Words_4.txt" ;
          Game_Controller(Sleep_Variable ,Add ,Total_Characters_of_Words_in_Still_Boxes , Number_of_Characters , File);
       }

      else if ( Level == 3 )
       {
          Number_of_Characters = 5;
          Total_Characters_of_Words_in_Still_Boxes = 25;
          Add = 2;
          Sleep_Variable = 100 ;
          char File [MAXSIZE] = "Words_5.txt" ;
          Game_Controller(Sleep_Variable ,Add ,Total_Characters_of_Words_in_Still_Boxes , Number_of_Characters , File);
        }

      else if ( Level == 4 )
       {
          Number_of_Characters = 6;
          Total_Characters_of_Words_in_Still_Boxes = 30;
          Add = 3;
          Sleep_Variable = 50 ;
          char File [MAXSIZE] = "Words_6.txt" ;
          Game_Controller( Sleep_Variable , Add ,Total_Characters_of_Words_in_Still_Boxes , Number_of_Characters , File);
        }


    return 0;
}
