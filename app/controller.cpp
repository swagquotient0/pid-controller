/**@file controller.cpp
 * @brief Source file for PID controller.
 *        Contains method implementations declared in the included header files.
 *
 * Detailed description follows here.
 * @author     : Abhinav Modi
 * @created on : Sep 24, 2019
 * @copyright  : This code is developed for programming exercises in the 
 *               course ENPM808X. Do not use without citation.
 */
#include "../include/controller.hpp"

/**
 * @brief default constructor
 */
PID::PID()
    : kp(0.0),
      kd(0.0),
      ki(0.0),
      dt(1.0),
      prevErr(0.0),
      errSum(0.0) {
}

/**
 * @brief default destructor
 */
PID::~PID() {
}

/**
 * @brief setKp sets the proportional gain Kp for the PID controller
 * @param Kp - gain value Kp 
 */
void PID::setKp(double _kp) {
    this->kp = _kp;  // assign given value to the private variable kp
}

/**
 * @brief setKd sets the derivative gain Kd for the PID controller
 * @param Kd - gain value Kd 
 */ 
void PID::setKd(double _kd) {
    this->kd = _kd;  // assign given value to the private variable kd
}

/**
 * @brief setKi sets the integral gain Ki for the PID controller
 * @param Ki - gain value Ki 
 */ 
void PID::setKi(double _ki) {
    this->ki = _ki;  // assign given value to the private variable ki
}

/**
 * @brief setDt sets the discretization time-step dt for the PID.         
 * @param dt - discretization time-step dt 
 */
void PID::setDt(double _dt) {
    this->dt = _dt;  // assign given value to the private variable dt
}

/**
 * @brief getKp provides access to private variable Kp.         
 * @return Kp  
 */
double PID::getKp() {
    return this->kp;
}

/**
 * @brief getKd provides access to private variable Kd.         
 * @return Kd  
 */
double PID::getKd() {
    return this->kd;
}

/**
 * @brief getKi provides access to private variable Ki.         
 * @return Ki  
 */
double PID::getKi() {
    return this->ki;
}

/**
 * @brief getDt provides access to private variable dt.         
 * @return dt  
 */
double PID::getDt() {
    return this->dt;
}

/**
 * @brief computePID outputs the control input required to reach a
 *        given setpoint velocity from the current actual velocity.
 * @param setpointVel - desired velocity to be tracked. 
 * @param actualVel - current/actual velocity of the system
 * @return double control input required to reach the 
 *         given setpoint value within a set rise-time.
 */
double PID::computePID(double setpointVel,  double actualVel) {
    double err = setpointVel - actualVel;
    double errDot = (err - prevErr) / dt;
    errSum += err * dt;

    double ctrlInput = kp * err + kd * errDot + ki * errSum;

    return ctrlInput;
}
