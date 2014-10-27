#ifndef PWM_MOTOR_MAPPER_HPP_
#define PWM_MOTOR_MAPPER_HPP_

#include <hal.h>
#include <motor/motor_mapper.hpp>

template <int motor_count>
class PWMMotorMapper : public MotorMapper {
public:
  void init();
  virtual void run(struct controller_output_t& input) =0;

protected:
  PWMMotorMapper();

  void setMotorSpeed(int motor, float percent);

private:
  PWMDriver *pwm;
  pwmchannel_t channels[motor_count];
};

#include <motor/pwm_motor_mapper.tpp>

#endif