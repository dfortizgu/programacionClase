#include "md-simul.h"

void initial_conditions(Particle & body)
{
  body.Rx = 0;
  body.Ry = 0;
  body.Rz = 2;

  body.Vx = 0.1;
  body.Vy = 0;
  body.Vz = 0;

  body.rad = 0.235;
  body.mass = 0.29698;
}

void compute_force(Particle & body)
{
  // reset force
  body.Fx = body.Fy = body.Fz = 0.0;

  // gravitational force
  body.Fz += body.mass*G;

  // force with ground
  double deltag = body.rad - body.Rz;
  if (deltag > 0) {
    body.Fz += K*deltag;
    //body.Fy -= 1.9876*body.Vy;
  }

  double deltawx1 = body.rad + body.Rx - 5;
  if(deltawx1 < 0){
    body.Fx-=K*deltawx1;
  }

  double deltawy1 = body.rad + body.Ry - 5;
  if(deltawy1 > 0){
    body.Fy-=K*deltawy1;
  }
}

void start_integration(Particle & body, const double & dt)
{
  body.Vx -= body.Fx*dt/(2*body.mass);
  body.Vy -= body.Fy*dt/(2*body.mass);
  body.Vz -= body.Fz*dt/(2*body.mass);
}

  void time_integration(Particle & body, const double & dt)
{
  // leap-frog
  body.Vx += body.Fx*dt/(body.mass);
  body.Vy += body.Fy*dt/(body.mass);
  body.Vz += body.Fz*dt/(body.mass);
  body.Rx += body.Vx*dt;
  body.Ry += body.Vy*dt;
  body.Rz += body.Vz*dt;
}

void print(Particle & body, double time)
{
  std::cout << body.Rx << "  "
            << body.Ry << "  "
            << body.Rz << "  "
            << body.Vx << "  "
            << body.Vy << "  "
            << body.Vz << "  "
            << time << "  "
            << "\n";
}
