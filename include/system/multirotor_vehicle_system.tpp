template <int num_rotors>
void MultirotorVehicleSystem<num_rotors>::init() {
}

template <int num_rotors>
void MultirotorVehicleSystem<num_rotors>::update() {
  // Poll the accelerometer and gyroscope
  struct accelerometer_reading_t accel_reading = getAccelerometer()->read();
  struct gyroscope_reading_t gyro_reading = getGyroscope()->read();

  // Update the attitude estimate
  struct attitude_estimate_t estimate = getAttitudeEstimator()->update(accel_reading, gyro_reading);

  // Poll for controller input
  struct controller_input_t input = getInputSource()->read();

  // Run the controllers
  struct controller_output_t controller_input = {
    .setpoints = {
      input.roll_sp,
      input.pitch_sp,
      input.yaw_sp,
      input.thrust_sp
    }
  };

  struct controller_output_t controller_output = getPipeline()->run(estimate, controller_input);

  // Update motor outputs
  getMotorMapper()->run(controller_output);
}