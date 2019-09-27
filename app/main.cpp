/**@file main.cpp
 * @brief Main file for PID controller.
 *       
 * Detailed description follows here.
 * @author     : Abhinav Modi
 * @created on : Sep 24, 2019
 * @copyright  : This code is developed for programming exercises in the 
 *               course ENPM808X. Do not use without citation.
 */
#include "../include/controller.hpp"

int main()
{
    std::shared_ptr<PID> pid = std::make_shared<PID>();
    pid->setKp(0.5);                   //set Kp value
    pid->setKd(0.01);                   //set Kd value 
    pid->setKi(0.001);                  //set Ki value
    pid->setDt(0.1);                    //set discretization time dt

    cout << "Kp is :" << pid->getKp() << endl;
    cout << "Kd is :" << pid->getKd() << endl;
    cout << "Ki is :" << pid->getKi() << endl;

    double actualVel = 10;
    double setpointVel = 20;

    double velInc = 0;                  //initialize velocity increment
    
    int count = 0; 
    while (count < 40) {
        velInc = pid->computePID(setpointVel, actualVel);
        count++;
        
        actualVel += velInc;            //increment velocity using PID output
        cout << "actual vel " << actualVel << endl;
    }

    return 0;
}
