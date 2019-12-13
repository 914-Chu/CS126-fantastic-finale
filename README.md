# NS-SHAFT

## Dependencies

### Windows

#### Visual Studio

- [Visual Studio 2017](https://visualstudio.microsoft.com/)

#### OpenFrameWorks

- [OpenFramWorks 0.11.0](https://openframeworks.cc/)
  - [ofxGui](https://openframeworks.cc/documentation/ofxGui/)
    - Make sure to create the project through openFrameWorks's ProjectGenerator.
    - Put all related .png and .wav files inside \bin\data
  - [ofxActionManager](https://github.com/Furkanzmc/ofxActionManager)
  
## Game (Download demo.mp4 / demo.mov to see example)

### Rule

- Player will die when life is zero or fall out of the screen.

### States

- START
<img src="https://github.com/CS126FA19/fantastic-finale-914-Chu/blob/master/pics/start.PNG" alt="alt text" width="250" height="250">

- RUN
<img src="https://github.com/CS126FA19/fantastic-finale-914-Chu/blob/master/pics/Run.PNG" width="250" height="250">

- END
<img src="https://github.com/CS126FA19/fantastic-finale-914-Chu/blob/master/pics/End.PNG" width="250" height="250">

### Platforms

- NORMAL
  * No effect
<img src="https://github.com/CS126FA19/fantastic-finale-914-Chu/blob/master/pics/normal.png" alt="alt text" width="100" height="20">

- NAILS
  * Reduce life by 2
  * Ceiling is also a kind of NAILS and reduce life by 3
<img src="https://github.com/CS126FA19/fantastic-finale-914-Chu/blob/master/pics/nails.png" alt="alt text" width="100" height="20">

- CONVEYOR_LEFT
  * Shift player to left
  * Increase life by 1
<img src="https://github.com/CS126FA19/fantastic-finale-914-Chu/blob/master/pics/conveyor_left.png" alt="alt text" width="100" height="20">

- CONVEYOR_RIGHT
  * Shift player to right
  * Increase life by 1
<img src="https://github.com/CS126FA19/fantastic-finale-914-Chu/blob/master/pics/conveyor_right.png" alt="alt text" width="100" height="20">

- FAKE
  * Drop player
  * Reduce life by 2
<img src="https://github.com/CS126FA19/fantastic-finale-914-Chu/blob/master/pics/fake.png" alt="alt text" width="100" height="20">

- TRAMPOLINE
 * Make player bounce
 * Increase life by 2
<img src="https://github.com/CS126FA19/fantastic-finale-914-Chu/blob/master/pics/trampoline.png" alt="alt text" width="100" height="20">

### Keyboard

| Key      | Action                                                      |
|----------|-------------------------------------------------------------|
| `d`/`D`  | Move to the right                                           |
| `a`/`A`  | Move to the left                                            |
| `SPACE`  | Start game                                                  |


