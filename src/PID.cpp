#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  prev_cte = 0;
  int_cte = 0;
}

void PID::UpdateError(double cte) {
  int_cte += cte;
  p_error = -Kp * cte;
  d_error = -Kd * (cte - prev_cte);
  i_error = -Ki * int_cte; 
  prev_cte = cte;
}

double PID::TotalError() {
  double total_error = p_error + d_error + i_error;

  if (total_error > 1) {
    total_error = 1;
  }
  else if (total_error < -1) {
    total_error = -1;
  }

  return total_error;
}

