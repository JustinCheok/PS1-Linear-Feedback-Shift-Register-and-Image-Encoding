PS1: Linear Feedback Shift Register and Image Encoding

What is this assignment:  
This assignment was broken up into two parts. In the first part the purpose of this was to write a
program that produces pseudo-random bits by simulating a linear feedback shift register. Which
is later used to implement a simple form of encryption for digital pictures. The second part of
this assignment was to build off of the first part and to use it to encrypt an image.

What was accomplished:  
What I accomplished from this assignment was creating a linear feedback shift register (LFSR).
Implementing the Fibonacci method into the linear feedback register. In the assignment the
constructor took an initial input seed as a string argument which the characters in the input
sequence were filled with 0’s and 1’s. What was also created was a step function. This function
was used to simulate one step/ iteration through the linear feedback shift register and returned the
right most bit as an 0 or 1. For this first part it was tested using unit tests from Boost test
frameworks. For the second part of this assignment it implements what we’ve made and we
created a transform function which takes an image and an Fibonacci linear feedback shift register
as its arguments. And then transforms the input image by the pixel.

Key algorithms:  
The key algorithm used was a mix of sorting and binary searching. This assignment uses sorting
because the linear feedback shift register uses a function created called step. And this function
simulates one step of the LFSR and returns the rightmost bit as an integer, which being a 0 or 1.

Data Structures:  
This assignment used a sorting structure. Which is relatively similar to a queue data structure
method. In a queue it uses a method first in, first out, but in this it was a sorting method which
took an initial seed and moved it along the linear feedback shift register.


![ps1](https://github.com/JustinCheok/PS1-Linear-Feedback-Shift-Register-and-Image-Encoding/assets/80936005/82d5539c-b5ec-4648-8535-cbb1b4ef3a64)

