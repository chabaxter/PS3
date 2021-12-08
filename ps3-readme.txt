/**********************************************************************
 *  ps3-readme 
 *  Recursive Graphics (Triangle Fractal)                       
 **********************************************************************/

Your name: Charles Baxter

Hours to complete assignment: 2

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The Sierpinski fractal is implimented using SFML libraries. A Triangle class
is defined which conatains an sf::CircleShape member. The Triangle class
is responsible for a single triangle of the fractal. The Triangle class also
conatins member functions which allows tranformation of the triangle. The main
function generates a vector of Triangles which can then be easily accessed
through the vector.


 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
Recursion was necessary for creating the individual triangles. The fTree
function generates a single triangle from function arrguments, then recurses 
after calculating the coordinates of each next triangle.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
Two features were implimented. Firstly, because each triangle is stored as
a circle shape, each can be rotated about its origin. 
O: rotate ccw 20 degrees
P: rotate cw 20 degrees

Each color can also be adjusted for the triangle by setting the outline
color
Q: switch to color mode
W: switch to white mode

The program also utilizes the window view to adjust the zoom. By scrolling
the mouse, the window will zoom in at that point.
MouseWheelUp: zoom in
MouseWheelDown: zoom out


 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
I learned how to use the the sfml view window to cahgne what is displayed
on the screen without adjusting the global coordinates or moving any objects
along the coordinate plane.


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

This program shouldnt be run with any more than a depth of 12. After that,
the memory requirements for the progrma become obsurd and will not run.