# Camera Battle Transitions Research
This project was developed by [Luis González](https://github.com/punto16) , a second year student of the [University degree Video Game Design and Development](<https://www.citm.upc.edu/ing/estudis/graus-videojocs/>) in year 2022-2023.

## About this project
The goal of this research is to produce a functional camera battle transition system in C++.

You can visit the official [Webpage of mine](<https://punto16.github.io/Camera-Battle-Transitions/>)

**Software used to develop this project**

* [Visual Studio 2019](<https://visualstudio.microsoft.com/es/vs/?rr=https%3A%2F%2Fwww.google.com%2F>)
* [SDL](<https://www.libsdl.org/>) & [STL](<http://www.cplusplus.com/reference/stl/>) Libraries
* [Tiled](<https://www.mapeditor.org/>)
* [Online Converter](<https://www.onlineconverter.com/video-to-gif>)
  
## Controls

- From 1 to 8 - Do a transition
- Left click - A small baunce to move camera
- Right click - Zoom in/out transition
- Esc - Close the program

## Research

### 1. Introduction to the topic / problem to solve
When we develop a game, generally we have a world to explore with some enemies. When we are about to fight any enemy to start a battle, we have 2 different scenes:
- The world we can explore
- The fight scene

The problem to solve is how should we combine these 2 scenes?

### 2. Market study showing other games approaches (use animated gifs!)
But, what did already created games about this? Do they just... swap the 2 scenes? Let's find out.

*add gifs*

<iframe width="560" height="315" src="https://www.youtube-nocookie.com/embed/a35WO_iHVT4" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

We can see that the main result of many games is to add cool transition, I couldn't find any camera battle transition in any game that is just a simply cut, from scene 1 to scene 2 in just a frame

### 3. Selected approach, describe and present it in detail
So, the solution is to switch scenes in the middle of a cool transition, this can be a cut, fade in/fade out, some bars going from left to right, a big black square moving from right to left, etc.

### 4. Possible improvements of the presented solution
This is a complicated project, and even having tried I only could develop some simple transitions.
So a possible improvement could be that, instead of black figures on top of the screen going in and out, another good option would be to modify the last render to the screen itself as an independent and modificable image. Here an example of what I'm talking about:

![](https://tenor.com/view/mr-krabs-spongebob-bruh-spongebob-bruh-mr-krabs-bruh-gif-22437248)

### 5. Examples: VS Project in the repository


### 6. Exercises: VS Project with TODOs to complete (Handout + Solution)


### 7. Documentation and References links


## Developer

 - Lluís González - [_punto16_](https://github.com/punto16)

## [Click to Download the Practice!](https://github.com/punto16/Camera-Battle-Transitions/releases/download/Release/Camera-Battle-Transitions.zip)

## License

This project is licensed under an unmodified MIT license, which is an OSI-certified license that allows static linking with closed source software. Check [LICENSE](../LICENSE) for further details.
