// Example program in TDT4102_Graphics template, from PPP page 415
#include "Graph.h"
#include "Simple_window.h" 
#include "cannonball.h"
#include "utilities.h"
#include "cannonball_viz.h"
#include "std_lib_facilities.h"


int main() {
	using namespace Graph_lib;
	srand(static_cast<unsigned int>(time(nullptr)));

	playCannonball();
	keep_window_open();
}

