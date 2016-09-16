#pragma config(Motor,  port2,           driveL,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           arm,           tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           scooper,       tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           clawL,         tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           cart,          tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           cart2,         tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           box,           tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           driveR,        tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*WARNING DON'T FIX THE FORMATTING

    /***********************************\
	 /                  The                \
  /           Home of Programming         \
 /             (I Lost the Game)           \
/                                           \
| Right joystick =  Drive                   |
|                                           |
| Button 6U + left joystick = arm up & down |
|                                           |
| Button 8L = open, Button 8R = Close       |
|                                           |
|                                           |
|*******************************************/

/*********************************************************\
|This is the best code ;) for the 2015 BEST competition.  |
|Written by: Programmers. If you need help programming,   |
|ask the main programmers(Dalton,and George).             |
|They would be happy to help you, but if they cannot help |
|for any reason they will assign a subordinate to assist  |
|you.                                                     |
|                                               Thank You.|
\*********************************************************/


int leftX = 0;
int leftY = 0;
int rightY = 0;
int rightX = 0;
int thresh = 15;
bool macro = false;
const bool on = true;

task drive() {
	while(on) {
		motor[driveL] = -rightY - rightX;
		motor[driveR] = rightY - rightX;
	}
}

task manipulator() {
	while(on) {
		if(vexRT[Btn6U]) {
			if(vexRT[Btn6D]) {
				motor[arm] = leftY + 20;
				} else {
				motor[arm] = leftY;
				}
			} else if(vexRT[Btn6D]) {
				motor[arm] = 20;
			} else {
			motor[arm] = 0;
		}

		if(vexRT[Btn8L]) {

			motor[clawL] = motor[clawL] + 1;
			wait1Msec(1);
			} else if(vexRT[Btn8R]) {
			motor[clawL] = motor[clawL] - 1;
			wait1Msec(1);
		}

		if(vexRT[Btn7L]) {

			motor[scooper] = motor[scooper] + 1;
			wait1Msec(1);
			} else if(vexRT[Btn7R]) {
			motor[scooper] = motor[scooper] - 1;
			wait1Msec(1);
		}

		if(vexRT[Btn8U]) {
			motor[cart] = motor[cart] + 1;
			wait1Msec(1);
			} else if(vexRT[Btn8D]) {
			motor[cart] = motor[cart] - 1;
			wait1Msec(1);
		}

		if(vexRT[Btn7U]) {
			motor[cart2] = motor[cart2] - 1;
			wait1Msec(1);
			} else if(vexRT[Btn7D]) {
			motor[cart2] = motor[cart2] + 1;
			wait1Msec(1);
		}

		if(vexRT[Btn5D]) {
			motor[box] = 70;
		} else if(vexRT[Btn5U]) {
			motor[box] = -70;
		} else {
			motor[box] = 0;
		}

		if(vexRT[Btn8D] && macro == false) {
			macro = true;
			motor[arm] = 100;
			wait1Msec(80);
			motor[arm] = 0;
		} else if(vexRT[Btn8U] && macro == false) {
			macro = true;
			motor[arm] = 75;
			wait1Msec(80);
			motor[arm] = 0;
		} else if(macro == true && !vexRT[Btn8D] && !vexRT[Btn8U]) {
			macro = false;
		}
	}
}

task main() {
	startTask(drive);
	startTask(manipulator);
	while(on) {
		rightX = vexRT(Ch1);
		if(abs(rightX)<thresh){
			rightX = 0;
		}
		rightY = vexRT(Ch2);
		if(abs(rightY)<thresh){
			rightY = 0;
		}
		leftY = vexRT(Ch3);
		if(abs(leftY)<thresh){
			leftY = 0;
		}
		leftX = vexRT(Ch4);
		if(abs(leftX)<thresh){
			leftX = 0;
		}
	}
}
//BANG!!!