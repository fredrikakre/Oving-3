#include "Simple_window.h"
#include "std_lib_facilities.h"

#include "utilities.h"
#include "cannonball_viz.h"
#include "cannonball.h"
// Pass på sirkulær headerinkludering.

void cannonBallViz(double targetPosition, int fieldLength, double velocityX, double velocityY,
	int timeSteps)
{
	Point tl{ 100, 100 }; // top-left corner of our window
	constexpr int w_width = 800;
	constexpr int w_height = 500;
	Simple_window window{ tl, w_width, w_height, "Cannonball Visualizer" };
	window.resizable(nullptr);
	window.size_range(w_width, w_height, w_width, w_height);

	// Plot target. targetPosition is in [100, 1000] in main program
	// this function handles target in range 0 to fieldLength, map 0 to 0, and fieldLength to
	// w_width
	int target_x = static_cast<int>((targetPosition * w_width) / fieldLength);
	Rectangle target{ Point{target_x - 10, w_height - 20}, 20, 20 };
	target.set_fill_color(Color::dark_green);
	window.attach(target);

	// first timestep at time 0
	Vector_ref<Circle> trajectory;
	for (int i = 0; i <= timeSteps; ++i) {
		double time = i * (Flyvetid(velocityY) / timeSteps);

		// must scale x to window-width, as described above
		int xPos = static_cast<int>(posX(0, velocityX, time) * w_width) / fieldLength;
		trajectory.push_back(
			new Circle{ Point{xPos, static_cast<int>(w_height - posY(0, velocityY, time))}, 8 });
		trajectory[trajectory.size() - 1].set_color(Color::red);
		trajectory[trajectory.size() - 1].set_fill_color(Color::black);
		window.attach(trajectory[trajectory.size() - 1]);

		window.wait_for_button();
	}
}


void playCannonball() {
	double theta, absVelocity, velocityX, velocityY;
	double distanceToTarget = randomWithLimits(100, 1000);

	for (int k = 0; k < 10; ++k) {
		get_User_input(theta, absVelocity);
		getVelocityVector(theta, absVelocity, velocityX, velocityY);
		double bom = targetPractice(velocityX, velocityY, distanceToTarget);
		int Flight_time = Flyvetid(velocityY);
		int diff = 2;
		bool score = ca_like(bom, 0, diff);
		cannonBallViz(distanceToTarget, 1000, velocityX, velocityY, 6);
		cout << "Tid i lufta: \n"; tid(Flight_time);
		if (score) {
			cout << "Du traff med feil p� mindre enn " << diff << " meter! \n Maalet var " << distanceToTarget << " meter unna.\n";
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