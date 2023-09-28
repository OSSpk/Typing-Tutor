<p align=center>
 <img src="../master/gameplay.gif" width=700 height = 450/>
</p>

# Typing-Tutor  🎮 


<a href="https://github.com/harismuneer"><img alt="views" title="Github views" src="https://komarev.com/ghpvc/?username=harismuneer&style=flat-square" width="125"/></a>
[![Open Source Love svg1](https://badges.frapsoft.com/os/v1/open-source.svg?v=103)](#)
[![GitHub Forks](https://img.shields.io/github/forks/harismuneer/Typing-Tutor.svg?style=social&label=Fork&maxAge=2592000)](https://www.github.com/harismuneer/Typing-Tutor/fork)
[![GitHub Issues](https://img.shields.io/github/issues/harismuneer/Typing-Tutor.svg?style=flat&label=Issues&maxAge=2592000)](https://www.github.com/harismuneer/Typing-Tutor/issues)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat&label=Contributions&colorA=red&colorB=black	)](#)





A visually appealing and interactive Typing Tutor game made using C++. 

It was made as a final project for my course Introduction to Computing CS101 during my 1st Semester at [National University of Computer and Emerging Sciences](http://nu.edu.pk/).

## How to Run

If you would like to run the .exe directly from the file explorer:

Click the code dropdown and download the project folder.
Navigate to the download location and into the Code folder.
Right click on the "Typing Tutor.exe" file to run it.

If you would like to work on and run the project within an IDE:

Follow the same steps as previous to download the repository.
Open the project in your IDE.
Open a terminal window from within the Code folder.

Powershell:
Typing ```.\Typing Tutor.exe``` will not work as the name has a space.
Instead, type the command "& '.\Typing Tutor.exe'"
A faster way to type this is to start with ```.\Typing``` and then press TAB.
The TAB will autocomplete the command for you to the command shown above.
It may autocomplete to ```& '.\Typing Tutor.cbp'```, so just replace the cbp with exe afterwards.

Git Bash:
Git Bash does not recognize the ```&``` so you will just omit it to run the executable.
```'.\Typing Tutor.exe``` will start the game.
Note that TAB for autocomplete is not built into Git Bash.
If you would like to use autocomplete here, download the appropriate bash completion package.

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


<hr>

<h1 align="left">Hey there, I'm <a href="https://www.linkedin.com/in/harismuneer/">Haris </a><img src="https://media.giphy.com/media/hvRJCLFzcasrR4ia7z/giphy.gif" width="28"> 
 <a href="https://github.com/harismuneer/Ultimate-Facebook-Scraper"><img align="right" src="https://user-images.githubusercontent.com/30947706/79588950-17515780-80ee-11ea-8f66-e26da49fa052.png" alt="Ultimate Facebook Scraper (UFS)" width="200"/></a> - Maker of Things</h1> 


### Creator of <a href="https://github.com/harismuneer/Ultimate-Facebook-Scraper">Ultimate Facebook Scraper</a> (one of the best software to collect Facebook data for research & analysis) 

<hr>

<h2 align="left">🌐 Connect</h2>
<p align="left">
  <a href="https://www.linkedin.com/in/harismuneer/"><img title="Follow on LinkedIn" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/></a>
  <a href="https://www.facebook.com/harism99"><img title="Connect on Facebook" src="https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white"/></a>
  <a href="https://twitter.com/harismuneer99"><img title="Follow on Twitter" src="https://img.shields.io/badge/Twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white"/></a>
  <a href="mailto:haris.muneer5@gmail.com"><img title="Email" src="https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white"/></a>
  <a href="https://github.com/harismuneer"><img title="Follow on GitHub" src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"/></a>
  <a href="https://www.instagram.com/harismuneer99"><img title="Follow on Instagram" src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white"/></a>
  <a href="https://www.youtube.com/channel/UCZ-uBd7g0E2Bp-0tXtSlSjw?sub_confirmation=1"><img title="Subscribe on YouTube" src="https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white"/></a>
</p>


## 🤝 Consulting / Coaching
Stuck with some problem? Need help in solution development, guidance, training or capacity building? I am a Full Stack Engineer turned Project Manager with years of technical and leadership experience in a diverse range of technologies and domains. Let me know what problem you are facing at <b>haris.muneer5@gmail.com</b> and we can schedule a consultation meeting to help you get through it.

## 👨‍💻 Technical Skills & Expertise

- Development of Web Applications, Mobile Applications, and Desktop Applications
- Development of Machine Learning/Deep Learning models, and deployment 
- Web Scraping, Browser Automation, Python Scripting
<hr>


## ❤️ Support / Donations
If you or your company use any of my projects, like what I’m doing or have benefited from my projects in any way then kindly consider backing my efforts.

For donations, you can follow these simple steps:

<b>1)</b> Free signup at <b>[TransferWise](https://transferwise.com/invite/u/harism95)</b> using this link: https://transferwise.com/invite/u/harism95</li>. (Signing up through this link will save you from any transcation fee on the donation)

<b>2)</b> Select the amount e.g (15$) and choose the receiving/recipient's currency to be PKR. It supports multiple payment options (credit card, debit card, wire transfer etc)

<b>3)</b> Then it will show my info as the recipient, select it. If my name isn't shown, then type my email haris.muneer5@gmail.com in recipients.

<b>4)</b> Choose the reason for transfer to the one that suits you the most (in this case it could be 'General expenses') and in the reference section, you can mention 'Support'
 
If you face any issue in sending donation then feel free to get in touch with me at haris.muneer5@gmail.com 

Thank you for your contribution!



## Author
You can get in touch with me on my LinkedIn Profile: [![LinkedIn Link](https://img.shields.io/badge/Connect-harismuneer-blue.svg?logo=linkedin&longCache=true&style=social&label=Follow)](https://www.linkedin.com/in/harismuneer)

You can also follow my GitHub Profile to stay updated about my latest projects: [![GitHub Follow](https://img.shields.io/badge/Connect-harismuneer-blue.svg?logo=Github&longCache=true&style=social&label=Follow)](https://github.com/harismuneer)

If you liked the repo then kindly support it by giving it a star ⭐ and share in your circles so more people can benefit from the effort.


## Contributions Welcome
[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](#)

If you find any bug in the code or have any improvements in mind then feel free to generate a pull request.

## Issues
[![GitHub Issues](https://img.shields.io/github/issues/harismuneer/Typing-Tutor.svg?style=flat&label=Issues&maxAge=2592000)](https://www.github.com/harismuneer/Typing-Tutor/issues)

If you face any issue, you can create a new issue in the Issues Tab and I will be glad to help you out.

## License
[![MIT](https://img.shields.io/cocoapods/l/AFNetworking.svg?style=style&label=License&maxAge=2592000)](../master/LICENSE)

Copyright (c) 2018-present, harismuneer                                                        
