#include "utilities.h"
#include "std_lib_facilities.h"
#include "cannonball_viz.h"

int randomWithLimits(int nedre_grense, int ovre_grense) {
	//cout << time(nullptr) << endl;
	int helt_tilfeldig_tall = rand();
	ovre_grense = ovre_grense - nedre_grense + 1;
	int tilfeldig_tall_med_grense = (helt_tilfeldig_tall % ovre_grense) + nedre_grense;
	return tilfeldig_tall_med_grense;
}

