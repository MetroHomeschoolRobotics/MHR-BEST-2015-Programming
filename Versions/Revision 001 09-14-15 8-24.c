#pragma config(Motor,  motor2,          driveL,        tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor3,          lifter,        tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor4,          clawR,         tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor5,          clawL,         tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor6,          cart,          tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor9,          driveR,        tmotorVexIQ, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int leftX = 0;
int leftY = 0;
int rightY = 0;
int rightX = 0;

task drive() {
	while(true) {

	}
}

task manipulator() {
	while(true) {

	}
}

task main() {
	startTask(drive);
	startTask(manipulator);
	while(true) {
		rightX = vexRT(Ch1);
		rightY = vexRT(Ch2);
		leftY = vexRT(Ch3);
		leftX = vexRT(Ch4);
	}
}