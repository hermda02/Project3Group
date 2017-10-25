#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <random>
#include <chrono>
#include <time.h>
#include "planet.h"
#include "solver.h"

using namespace std;

void PrintInitialValues(int, double, double, double *, double *, int);
void PrintFinalValues(int, double *, double *);


int main()
{    
    int IntegrationPoints;  // No. of integration points
    double FinalTime;       // End time of calculation
    int Dimension;          // No. of spatial dimensions

        cout << "Earth-Sun binary system" << endl;
        Dimension = 3;

        IntegrationPoints = 10000;
        FinalTime = 100.;

        double TimeStep = FinalTime/((double) IntegrationPoints);
        double x[3],v[3];  // positions and velocities
        // initial position x = 1AU, y = z = 0, vx = 2pi, vy=0, vz=0
        planet planet1(0.000003,1.,0.0,0.0,0.0,6.3,0.);    // Earth: (mass,x,y,z,vx,vy,vz)
        planet planet2(0.00095,5.2,0.,0.,0.,2.75,0.);      // Jupiter: (mass,x,y,z,vx,vy,vz)
        planet planet3(0.000286,9.55,0.,0.,0.,2.04,0.);    // Saturn: (mass,x,y,z,vx,vy,vz)
        planet planet4(0.000000332,1.52,0.0,0.0,0.0,5.09,0.);  // Mars: (mass,x,y,z,vx,vy,vz)
        planet planet5(0.0000025,0.72,0.0,0.0,0.0,7.4,0.);     // Venus: (mass,x,y,z,vx,vy,vz)
        planet planet6(0.000000166,0.39,0.0,0.0,0.0,9.98,0.);  // Mercury: (mass,x,y,z,vx,vy,vz)
        planet planet7(0.000044,19.2,0.0,0.0,0.0,1.44,0.);     // Uranus: (mass,x,y,z,vx,vy,vz)
        planet planet8(0.00005,30.0,0.0,0.0,0.0,1.15,0.);      // Neptune: (mass,x,y,z,vx,vy,vz)
        planet planet9(0.0000000659,39.5,0.0,0.0,0.0,1.0,0.);  // Pluto: (mass,x,y,z,vx,vy,vz)
        planet planet10(1.,0.,0.,0.,0.,-0.00340911246,0.);     // Sun: (mass,x,y,z,vx,vy,vz)

    

        solver binary_vv(5.0);
        binary_vv.add(planet1);
        binary_vv.add(planet2);
        binary_vv.add(planet3);
        binary_vv.add(planet4);
        binary_vv.add(planet5);
        binary_vv.add(planet6);
        binary_vv.add(planet7);
        binary_vv.add(planet8);
        binary_vv.add(planet9);
        binary_vv.add(planet10);
    

        PrintInitialValues(Dimension,TimeStep,FinalTime,x,v,IntegrationPoints);

        cout << "Velocity Verlet results for the Sun-Earth system:" << endl;
        binary_vv.VelocityVerlet(Dimension,IntegrationPoints,FinalTime,1,0.);

        for(int j = 0; j < Dimension;j++){
            x[j] = binary_vv.all_planets[0].position[j];
            v[j] = binary_vv.all_planets[0].velocity[j];
        }
        PrintFinalValues(Dimension,x,v);
    return 0;
}



void PrintInitialValues(int Dimension,double TimeStep, double FinalTime,double *x_initial,double *v_initial, int N){
    // A function that prints out the set up of the calculation

    cout << "Time step = " << TimeStep << "; final time = " << FinalTime << "; integration points = " << N << endl;

    cout << "Initial position = ";
    for(int j=0;j<Dimension;j++) cout << x_initial[j] << " ";
    cout << endl;

    cout << "Initial velocity = ";
    for(int j=0;j<Dimension;j++) cout << v_initial[j] << " ";
    cout << endl;
}

void PrintFinalValues(int Dimension,double *x_final,double *v_final){
    // A function that prints out the final results of the calculation

    cout << "Final position = ";
    for(int j=0; j<Dimension; j++) cout << x_final[j] << " ";
    cout << endl;

    cout << "Final velocity = ";
    for(int j=0; j<Dimension; j++) cout << v_final[j] << " ";
    cout << endl;
}

