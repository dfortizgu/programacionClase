#include "md-simul.h"

void initial_conditions(Particle & body)
{
  body.Rx = 2;
  body.Ry = 2;
  body.Rz = 2;

  body.Vx = 0.1;
  body.Vy = 0.1;
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

  //Wall x 5
  double deltawx5  = body.rad +body.Rx-5;
  if(deltawx5  > 0){
    body.Fx -=K*deltawx5 ;
  }

   //Wall x 0
  double deltawx0  = body.rad -body.Rx;
  if(deltawx0  > 0){
    body.Fx +=K*deltawx0 ;
  }

    //Wall y 5
  double deltawy5  = body.rad +body.Ry-5;
  if(deltawy5  > 0){
    body.Fy -=K*deltawy5 ;
  }

   //Wall y 0
  double deltawy0  = body.rad -body.Ry;
  if(deltawy0  > 0){
    body.Fx +=K*deltawy0 ;
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
