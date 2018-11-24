
# Typing-Tutor  🎮 

[![MIT](https://img.shields.io/cocoapods/l/AFNetworking.svg?style=style&label=License&maxAge=2592000)](../master/LICENSE)
[![GitHub Forks](https://img.shields.io/github/forks/harismuneer/Typing-Tutor.svg?style=social&label=Fork&maxAge=2592000)](https://www.github.com/harismuneer/Typing-Tutor/fork)
[![GitHub Issues](https://img.shields.io/github/issues/harismuneer/Typing-Tutor.svg?style=flat&label=Issues&maxAge=2592000)](https://www.github.com/harismuneer/Typing-Tutor/issues)




A visually appealing and interactive Typing Tutor game made using C++. 

It was made as a final project for my course Introduction to Computing CS101 during my 1st Semester at [National University of Computer and Emerging Sciences](http://nu.edu.pk/).

## How to Run

There's a file named "Typing Tutor.exe". Just run it and the game will start.

If "Typing Tutor.exe" isn't working then the game can be compiled using any of the two ways:

1) The project is compiled using Code Blocks. So, there is a file named "Typing Tutor.cbp". Open it in Code Blocks and the whole project will load up with all files. Then just click "Build and Run" and the game will start. {Add the libgdi32 library in Code Blocks using project->build options->linker settings-> add button (find libgdi32 for your compiler)} 

2) To have the best experience it is HIGHLY RECOMMENDED to compile the main.cpp file of the game using G++
using the command:
 ```g++ -o main.exe mygraphics.cpp myconsole.cpp main.cpp - lgdi32```

## Screenshot
![Game Play Screenshot](../master/interface.png)

Instructions to Play the Game                      
-----------------------------
The rules of my game "Typing Tutor" are :

--  You are provided with a Typing Box . A Box is shown moving vertically on the screen with a
    word in it.There are five still boxes containing words.
 
--  If you type the word shown in the moving box , correctly, then the moving box will
    start to move leftwards otherwise if you have entered an incorrect word in the Typing
    Box then you will lose one life .
 
--  When the moving Box collides with a still box (after the moving box has completely
    moved leftwards) , then if the words in both boxes are same , then your score
    will increase by one , otherwise you will lose one life. 

--  When the word you entered in the Typing Box do no match with that of the word in the Moving Box
    then your no. of lives will reduce by one .    

--  In order to win the game , you need to attain a score of 10 i.e by matching
    Ten times correctly .

--  You have a total of 5 lives in the beginning and if you lose all your lives i.e when you have
    0 lives , then you will lose the game and the game will end.

--  Once you have typed a character in the typing box , it cannot be removed by using
    BACKSPACE or DELETE key . So be careful while playing ;)

--  There are a total of four levels . Choose which ever level you want to play. Each one is more difficult than previous one.

Enjoy !!!!!!!


## Contact
You can get in touch with me on my LinkedIn Profile: [![LinkedIn Link](https://img.shields.io/badge/Connect-harismuneer-blue.svg?logo=linkedin&longCache=true&style=social&label=Connect
)](https://www.linkedin.com/harismuneer)

## Issues
If you face any issue, you can create a new issue in the Issues Tab and I will be glad to help you out.

## License
[![MIT](https://img.shields.io/dub/l/vibe-d.svg?style=style&label=License&maxAge=2592000)](../master/LICENSE)
Copyright (c) 2018-present, harismuneer


                                                          
