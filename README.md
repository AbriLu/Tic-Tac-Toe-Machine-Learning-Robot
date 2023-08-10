This repository contains the work involved in the Learner Subsystem Team of the Tic Tac Toe Machine Learning Robot Project.
This project consisted in designing and building a Robot Capable to play the Tic Tac Toe game against a human. Each time the 
robot lost or won a game, reinforcement learning algorithms were implemented to penalise the robot (after losing) or reward it (after winning)
such that the winning moves were encouraged, but the losing ones were less likely to be made by the robot.

Note that five subsystems in total made up the system of the robot, but only one subsystem's work is implemented in this repository; the Learner Subsystem's
implementation, since I was part of the Learner Subsystem Team (and Interface Specification Team).

The Leaner Sub-system was an autonomous subsystem capable of making it possible for the whole system to learn how to play the Tic Tac Toe game, 
utilising reinforcement strategies to determine the best possible moves for a win. The sub-system was able to interact with the user to define 
the learner laws that were to be utilised to optimise the probability of success for each move.
