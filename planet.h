// Author - Daniel Herman 19.10.2017
#ifndef PLANET_H
#define PLANET_H
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
using std::vector;

class planet {

public:
	// Class Properties
	double mass;
	double position[3];
	double velocity[3];
	double potential;
	double kinetic;

	// Initializing
	
	planet();
	planet(double M,double x,double y,double z,double vx,double vy,double vz);

	// Planet functions
	double distance(planet otherPlanet);
	double GravForce(planet otherPlanet, double Gcon);
	double Acceleration(planet otherPlanet, double Gcon);
	double KineticE();
	double PotentialE(planet &otherPlanet, double Gcon, double epsil);

};

#endif
