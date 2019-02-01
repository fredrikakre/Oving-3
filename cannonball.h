#pragma once
#include "std_lib_facilities.h"

double acclY();
double velY(double initVel_Y, double time);
double posX(double initPos_X, double initVel_X, double time);
double posY(double initPos_Y, double initVel_Y, double time);
void tid(double time);
double Flyvetid(double initVel_Y);
bool ca_like(double sammenlign, double med, double max_feil);
void get_User_input(double& theta, double& absVelocity);
double degToRad(double deg);
double getVelocity_X(double theta, double absVelocity);
double getVelocity_Y(double theta, double absVelocity);
void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY);
double getDistanceTraveled(double velocityX, double velocityY);
double targetPractice(double velocityX, double velocityY, double distanceToTarget);
void playTargetPractice();

void cannonBallViz(double targetPosition,
	int fieldLength,
	double velocityX,
	double velocityY,
	int timeSteps);