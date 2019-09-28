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
         * @param _Kp - gain value Kp 
         */
        void setKp(double _Kp);

        /**
         * @brief setKd sets the derivative gain Kd for the PID controller
         * @param _Kd - gain value Kd 
         */        
        void setKd(double _Kd);

        /**
         * @brief setKi sets the integral gain Ki for the PID controller
         * @param _Ki - gain value Ki 
         */        
        void setKi(double _Ki);

        /**
         * @brief setDt sets the discretization time-step dt for the PID.         
         * @param _dt - discretization time-step dt 
         */
        void setDt(double _dt);

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
        double kp;                  // proportianal gain term
        double kd;                  // derivative gain term
        double ki;                  // integral gain term
        double dt;                  // discretization time-step
        double prevErr;             // error in the previous time step
        double errSum;              // cumulative error term
};

#endif  // INCLUDE_CONTROLLER_HPP_
