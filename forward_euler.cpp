/////////////////////////////////////////////////////////////////////////////////
//Forward Euler Method

// new position for current planet Euler
for(int j=0; j<dimension; j++) {
    current.position[j] += current.velocity[j]*time_step;
}

// Loop over all other planets
for(int nr2=nr1+1; nr2<total_planets; nr2++){
    planet &other = all_planets[nr2];
    GravitationalForce(current,other,Fxnew,Fynew,Fznew,epsilon);
}

// Acceleration each dimension exerted for current planet
acceleration_new[nr1][0] = Fxnew/current.mass;
acceleration_new[nr1][1] = Fynew/current.mass;
acceleration_new[nr1][2] = Fznew/current.mass;

// new velocity for current planet Euler
for(int j=0; j<dimension; j++) {
    current.velocity[j] += time_step*acceleration_new[nr1][j];
}

/////////////////////////////////////////////////////////////////////////////////
