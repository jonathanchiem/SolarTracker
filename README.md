# SolarTracker

### Table of Contents

> [Project Description](#project-description)

> [System Design](#system-design)

> [Implementation Details](#implementation-details)

> [Testing and Evaluation](#testing-and-evaluation)

> [Challenges and Limitations](#challenges-and-limitations)

> [Future Works](#future-works)

> [Roles and Responsibilities](#roles-and-responsibilities)

> [Conclusion](#conclusion)

## Project Description
We created a solar tracker that moves  a solar panel — using stepper motors, towards direction of the sun based on the analog input from a photoresistor array. In order to do so, we had to ensure that the stepper motors moved in the direction through our algorithm implemented on the Arduino Uno.

## System Design

<img src = "https://user-images.githubusercontent.com/42078356/54167608-d6393f00-4427-11e9-89ec-1d527e94fe28.png">

## Implementation Details

<img src = "https://user-images.githubusercontent.com/42078356/54168091-24e7d880-442a-11e9-8a5a-ede9ea1b2c4a.png">

### Parts List
- 4 photoresistors
- 2 4-phase stepper motors
- 1 Arduino UNO microcontroller

The location of the solar panel was based on the analog values returned by the four photoresistors. Depending on which of the four photoresistors received the most light, the steppers motors would position the panel accordingly. Both of the stepper motors were linked together in a pan and tilt configuration to move in both the x and y direction. The boundaries of the motors were based on the initial position the motor was set to, therefore the panel would not be obstructed by the structure it was attached to.

## Testing and Evaluation
Implementation of the solar tracker was tested with the use of a powerful light source, such as a flashlight. Due to surrounding light sources a condition was set that required the analog reading from the photoresistors to be at least 900 or greater was added to ensure that the solar tracker would not move prematurely.

The first step in testing was to ensure that each photoresistor was outputting a reasonable value to the serial monitor in the Arduino IDE. Next was to ensure that the stepper motors were properly wired and functional with the code. This was done by running example code that ran each stepper motor in a sweeping motion. Following was to run the photoresistors in conjunction with the stepper motors. This was done by driving one stepper motor to rotate the panel, while the other tilted the panel, in addition to tracking the x and y coordinates of the stepper motors on the serial monitor. The solar panel was set to an initial starting position at (0, 0) on an (x, y) coordinate grid. The photoresistors were set up to simulate each corner of the (x, y) coordinate grid. When a strong light source was applied to one of the photoresistors, the panel was expected to be rotated and tilted in the direction that of the photoresistor with the greatest reading.

After thoroughly testing and troubleshooting the code, the panel was able to move accordingly in each direction from the initial starting position. In addition, the panel was able to return to the starting position — as if the sun was directly above the panel, when all the photoresistors returned the same range of values — all getting the same amount of light.

### [Youtube Link](https://youtu.be/grmDIbj6y70)

## Challenges and Limitations
Challenges that encountered were:
- Getting the motor to turn in the counterclockwise direction
- Making the motors stop so that the panel would not be obstructed the structure (setting a boundary)

For making the stepper motor rotate in the desired direction, we referenced the datasheet for the motor. We discovered that the pin out in the datasheet was incorrect. 
The problem in boundary limitation was solved by implementing a counter that would track exactly where the motor was on the x and y direction from the initial position. After the counter implemented, we embedded a condition in the step function that would constantly check to see if the counter was at its maximum limit (+/- 128 on the x axis and +/- 256 on the y axis).

A major limitation of our project was that it would not be able to capture the maximum amount of the sunlight due to the structure. But from a realistic standpoint, there is not be a stationary solar panel with the ablility to be 100%, making our design ideal for higher solar efficiency.

## Future Works
A considered future implementation is to leave the solar tracker on a roof and allow it run for several days and collect data. After a number of days collecting data, the tracker would recall its previous positions based on time -- making the system independent of the photoresistors. Another future change would be to allow the panel to correct itself, meaing that all the photoresistors have a relatively simlar value, resulting in maximum power point tracking. 


## Roles and Responsibilities
### Jonathan Chiem
- Build structure of solar tracker
- Implement logic into code

### Kishen Nadasia
- Logic of solar tracker system
- Setting up and wiring circuit

## Conclusion
This project exemplified our knowledge of analog to digital conversion, stepper motors, and microcontroller applications. We were able to fully incorporate these concepts together to complete the solar tracker. As we progressed further into the project, we discovered that the stepper motor could step at any desired increment to achieve more accurate positioning. Also in programming the microcontroller, our ability to optimize the motor movements was tested, as well as to adjust and overcome manufacturing faults. In conclusion, this was a great test of our abilities as engineers, in addition to overcoming the various challenges through the use of our knowledge. 


