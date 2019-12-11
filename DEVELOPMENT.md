#Week 1

- Test openframework addons funcntionalities.
- Set up SFML external library for sprite sheets.
- Create main, ofApp, Player, Platforms classes.
- Tested setup, update, and draw methods in ofApp to run the game.
  * Had problem with updating gamestates.[RESOLVED]
- Draw background images (ceiling, walls).
  * Couldn't make walls keep scrolling, either disappear or jump to other position.
  * [RESOLVED]: Adjusted with width and height of the window and extend the length of the wall.

#Week 2

- Test ofxActionManager to control player's movement. 
  * Keep jumping if keep pressing the key. 
  * [RESOLVED]: changed the distance of every movement, updated according to frame rate.
  * Player's movement updated slowly, completely disapper or stuck in certain position if collided sides. 
    * [RESOLVED]: Set player's movement boarders, keep posistion within the ceiling and walls.
- Implement the falling feature.
  * Test the falling movement in ofxActionManager, didn't work.
  * Used ofxVec2f to control player's position.
  * Player is falling but too fast, distance don't changed inconsistently (used falling object formulas) 
    * [RESOLVED]: Update y position only with mulitple of the frame rate.
- Test animation with sprite sheets.
  * Unable to use ofxSpriteSheetRenderer(built in function had different types of parameters)[UNRESOLVE]
  
 #Week 3

- Add Background class, move ceiling and walls movement into Background class.
- Update Platform class(only normal)
  * Test platform movement (going up).
  * Add method to generate platform with random x position from the bottom, unable to trace generated platform.
    * ~~[RESOLVED]:Use vector to store generated platforms~~ (amount grow infinitely)
    * [RESOLVED]:Use deque to store platforms and keep track of their positions, delete when out of screen.
  * Add the rest of platforms (nails, conveyor_left, conveyor_right, fake, trampoline)
    * Randomly generate different type of platforms, but the ratio is uneven
    * [RESOLVED]: Control random number with time.
  * Make player stay on platforms when collide, but player keep jumping or go through. (unstable y position.)
    * ~~[RESOLVED]: Adjust y position with platform's y position and player's size~~ 
      (player stop jumping only on some platforms and moving too slow)
    * [RESOLVED]: Adjust y position with platform's y position and different multiples of player's size.
     
#Week 4

- Add different platforms' features.
- Add life and level features.
- Integrate classes and finish management of switching game state.
- Seperate classes. [UNRESOLVED: Player class take care of too many things]
  * Thingking of moving life and level management into playerStatus class.
  
