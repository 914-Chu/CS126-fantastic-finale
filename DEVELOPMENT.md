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
  * test platform movement (going up).
  * add method to generate platform with random x position from the bottom, unable to trace generated platform.
   * ~~[RESOLVED]:use vector to store generated platforms~~ (amount grow infinitely)
   * [RESOLVED]:use deque to store platforms and keep track of their positions, delete when out of screen.
  * add the rest of platforms ()
#Week 4

- Seperate classes.
