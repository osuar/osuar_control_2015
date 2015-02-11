#ifndef ATTITUDE_ESTIMATOR_HPP_
#define ATTITUDE_ESTIMATOR_HPP_

#include "sensors/sensor_measurements.hpp"

struct AttitudeEstimate {
  float roll;
  float pitch;
  float yaw;

  float rollVel;
  float pitchVel;
  float yawVel;

  float rollAcc;
  float pitchAcc;
  float yawAcc;
};

class AttitudeEstimator {
public:
  /**
   * Runs the estimator on the latest sensor readings, producing a new attitude
   * estimate.
   */
  virtual AttitudeEstimate update(const SensorMeasurements& meas) = 0;
};

#endif
