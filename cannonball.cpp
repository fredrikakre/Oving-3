#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"
#include "cannonball_viz.h"
#include <math.h>

constexpr double pi = 3.14159;

double acclY() {
	return -9.81;
}
double velY(double initVel_Y, double time) {
	return (initVel_Y + time * acclY());
}
double posX(double initPos_X, double initVel_X, double time) {
	return (initPos_X + time * initVel_X);
}
double posY(double initPos_Y, double initVel_Y, double time) {
	return (initPos_Y + initVel_Y * time + 0.5 * (time * time) * acclY());
}
void tid(double time) {
	/*double double_time; int int_time;
	double_time = modf(time, &int_time);
	cout << double_time << endl << int_time << endl;*/
	int int_time = (int)time;
	int sekunder_til_min = int_time % 3600;
	//cout << "Sek to min: " << sekunder_til_min << endl;
	int sekunder = sekunder_til_min % 60;
	int minutter = (sekunder_til_min - sekunder) / 60;
	int timer = (time - sekunder_til_min) / 3600;
	cout << "Timer: " << timer << "  |  " << "Minutter: " << minutter << "  |  " << "Sekunder: " << sekunder << endl << endl;
}
double Flyvetid(double initVel_Y) {
	double time = -(2 * initVel_Y) / (acclY());
	return time;
}
bool ca_like(double sammenlign, double med, double max_feil) {
	double differanse = abs(sammenlign - med);
	//cout << differanse << endl;
	if (differanse <= max_feil) {
		return true;
	}
	else {
		return false;
	}
}

void get_User_input(double& theta, double& absVelocity) {
	cout << "\nAngle: "; cin >> theta;
	cout << "Velocity: "; cin >> absVelocity; cout << endl; 
}

double degToRad(double deg) {
	return deg * pi / 180;
}

double getVelocity_X(double theta, double absVelocity) {
	return absVelocity * cos(degToRad(theta));
}
double getVelocity_Y(double theta, double absVelocity) {
	return absVelocity * sin(degToRad(theta));
}

void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY) {
	velocityX = getVelocity_X(theta, absVelocity);
	velocityY = getVelocity_Y(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY) {
	return (velocityX * Flyvetid(velocityY));
}

double targetPractice(double velocityX, double velocityY, double distanceToTarget) {
	return (distanceToTarget - getDistanceTraveled(velocityX, velocityY));
}

void playTargetPractice() {
	double theta, absVelocity, velocityX, velocityY;
	int distanceToTarget = randomWithLimits(100, 1000);

	for (int k = 0; k < 10; ++k) {
		get_User_input(theta, absVelocity);
		getVelocityVector(theta, absVelocity, velocityX, velocityY);
		double bom = targetPractice(velocityX, velocityY, distanceToTarget);
		int Flight_time = Flyvetid(velocityY);
		int diff = 1;
		bool score = ca_like(bom, 0, diff);

		cout << "Tid i lufta: \n"; tid(Flight_time);
		if (score) {
			cout << "Du traff med feil på mindre enn " << diff << " meter! \n Maalet var " << distanceToTarget << " meter unna.\n";
			break;
		}
		else {
			if (bom > 0) {
				cout << bom << " meter for kort! \n";
			}
			else {
				cout << abs(bom) << " meter for langt! \n";
			}
			cout << (9 - k) << " forsok igjen.\n";
		}
	}
}