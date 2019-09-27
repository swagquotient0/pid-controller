/**@file test.cpp
 * @brief Test source file for PID controller.
 *        Contains the required headers and methods.
 *
 * Detailed description follows here.
 * @author     : Abhinav Modi
 * @created on : Sep 24, 2019
 * @copyright  : This code is developed for programming exercises in the 
 *               course ENPM808X. Do not use without citation.
 */
#include <gtest/gtest.h>
#include "../include/controller.hpp"

/**
 *@brief Test for set params methods. 
 *       Tests that the PID gains are set to 0 in the defined object pid.  
 */
TEST(paramsZero, shouldPass) {
  std::shared_ptr<PID> pid = std::make_shared<PID>();
  pid->setKp(0.0);
  pid->setKd(0.0);
  pid->setKi(0.0);
  ASSERT_EQ(0.0, pid->getKp());
  ASSERT_EQ(0.0, pid->getKd());
  ASSERT_EQ(0.0, pid->getKi());
}

/**
 *@brief Test for computePID method. 
 *       Tests that output is 0 for setpoint value = actual value
 */
TEST(computeZero, shouldPass) {
  std::shared_ptr<PID> pid = std::make_shared<PID>();
  // expectedVal = 0.0 m/s,  setpointVel = 20 m/s, actualVel = 20 m/s
  ASSERT_EQ(0.0, pid->computePID(20, 20));
}

/**
 *@brief Test for computePID method. 
 *       Tests that output of PID is equal to the expected value,
 *       for a given setpoint and actual value.   
 */
TEST(computePID, shouldPass) {
  std::shared_ptr<PID> pid = std::make_shared<PID>();
  pid->setKp(1);
  pid->setKd(0.1);
  pid->setKi(0.01);
  pid->setDt(0.1);
  // expectedVal = 11.01 m/s, setpointVel = 20 m/s, actualVel = 20 m/s
  EXPECT_NEAR(11.01, pid->computePID(20, 10), 0.1);  // absErrTolerance = 0.1m/s
}
