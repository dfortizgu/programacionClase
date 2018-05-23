#include "md-simul.h"

int main(void)
{
  Particle ball1;

  // start system
  initial_conditions(ball1);
  compute_force(ball1);
  start_integration(ball1, DT);
  print(ball1, 0.0);

  // evolve
  for(int istep = 0; istep < NSTEPS; ++istep) {
    time_integration(ball1, DT);
    compute_force(ball1);
    print(ball1, istep*DT);
  }


  return 0;
}
