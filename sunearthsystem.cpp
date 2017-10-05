#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <armadillo>
#include <cstring>
#include <string>
#include <math.h>
#include <vector>
#include <fstream>
#include <time.h>
#include <ctime>

using namespace std;
using namespace arma;

ofstream ofile;

void output(double, double, double, double, double);

int main(){

    int n = 1000;                           // number of steps
    double timef = 1;                       // final time (in years)
    double step = timef/ (double(n));
    double time = 0;
    double mearth = 6.0E24;                 // mass of the earth
    double msun = 2.0E30;                   // mass of the sun
    double d1 = 1.0;                        // distance from the earth to the sun in AU (1.5*10^11 m)
    double G = 6.67E-11;                    // value of the gravitational constant G

    double pi = acos(-1);
    double fpi2 = 4*pi*pi;

    double x = 1;                           // initial x value (1AU)
    double y = 0;                           // initial y value (0AU)
    double vx = 0;                          // initial x velocity
    double vy = 2*pi;                       // initial y velocity

    double r = sqrt(x*x + y*y);             // define the radius

    ofile.open("SunEarthTest.txt");

    while (time <= timef){
        x += step*vx;
        y += step*vy;
        vx -= step * fpi2 * x/(r*r*r);
        vy -= step * fpi2 * y/(r*r*r);
        r = sqrt(x*x + y*y);
        time += step;
        output(time, x, y, vx, vy);         // write to file
    }

    ofile.close();
}

void output(double time, double x, double y, double vx, double vy)
{
  ofile << setiosflags(ios::showpoint | ios::uppercase);
  ofile << setw(15) << setprecision(8) << time;
  ofile << setw(15) << setprecision(8) << x;
  ofile << setw(15) << setprecision(8) << y;
  ofile << setw(15) << setprecision(8) << vx;
  ofile << setw(15) << setprecision(8) << vy << endl;
}
