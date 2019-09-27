/**@file controller.hpp
 * @brief Header file for PID controller.
 *        Contains required headers and methods.
 *
 * Detailed description follows here.
 * @author     : Abhinav Modi
 * @created on : Sep 24, 2019
 * @copyright  : This code is developed for programming exercises in the 
 *               course ENPM808X. Do not use without citation.
 */
#ifndef INCLUDE_CONTROLLER_HPP_
#define INCLUDE_CONTROLLER_HPP_

#include <iostream>
#include <memory>

using std :: cout;
using std :: cin;
using std :: endl;

class PID {
 public:
        /**
         * @brief default constructor
         */
        PID();

        /**
         * @brief computePID outputs the control input required to reach a
         *        given setpoint velocity from the current actual velocity.
         * @param setpointVel - desired velocity to be tracked. 
         * @param actualVel - current/actual velocity of the system
         * @return double control input required to reach the 
         *         given setpoint value within a set rise-time.
         */
        double computePID(double setpointVel, double actualVel);

        /**
         * @brief setKp sets the proportional gain Kp for the PID controller
         * @param Kp - gain value Kp 
         */
        void setKp(double Kp);

        /**
         * @brief setKd sets the derivative gain Kd for the PID controller
         * @param Kd - gain value Kd 
         */        
        void setKd(double Kd);

        /**
         * @brief setKi sets the integral gain Ki for the PID controller
         * @param Ki - gain value Ki 
         */        
        void setKi(double Ki);

        /**
         * @brief setDt sets the discretization time-step dt for the PID.         
         * @param dt - discretization time-step dt 
         */
        void setDt(double dt);

        /**
         * @brief getKp provides access to private variable Kp.         
         * @return Kp  
         */
        double getKp();

        /**
         * @brief getKd provides access to private variable Kd.         
         * @return Kd  
         */
        double getKd();

        /**
         * @brief getKi provides access to private variable Ki.         
         * @return Ki  
         */
        double getKi();

        /**
         * @brief getDt provides access to private variable dt.         
         * @return dt  
         */
        double getDt();

        /**
         * @brief default destructor
         */
        ~PID();

 private:
        double kp = 0.0;                  // proportianal gain term
        double kd = 0.0;                  // derivative gain term
        double ki = 0.0;                  // integral gain term
        double dt = 1.0;                // discretization time-step
        double prevErr = 0.0;           // error in the previous time step
        double errSum = 0.0;            // cumulative error term
};

#endif  // INCLUDE_CONTROLLER_HPP_
