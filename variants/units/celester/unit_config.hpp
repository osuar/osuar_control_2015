#ifndef UNIT_CONFIG_HPP_
#define UNIT_CONFIG_HPP_

namespace unit_config {

const float DT = 0.001;

const double PI = 3.14159265358979323846;

// Maximum angular position in the roll and pitch axes (rad)
const float MAX_PITCH_ROLL_POS = 30.0 * PI / 180.0;

// Maximum angular velocity in the roll and pitch axes (rad/s)
const float MAX_PITCH_ROLL_VEL = 100.0 * PI / 180.0;

// Maximum angular acceleration (rad/s^2)
const float MAX_PITCH_ROLL_ACC = 4.0;   // TODO: calculate properly

// Sensor offsets
const float GYR_X_OFFSET = -0.033;
const float GYR_Y_OFFSET =  0.011;
const float GYR_Z_OFFSET =  0.023;
const float ACC_X_OFFSET =  0.026;
const float ACC_Y_OFFSET = -0.005;
const float ACC_Z_OFFSET =  0.025;

// Initial angular position controller gains
const float ANGPOS_X_KP = 1.0;
const float ANGPOS_X_KI = 0.0;
const float ANGPOS_X_KD = 0.0;
const float ANGPOS_Y_KP = 1.0;
const float ANGPOS_Y_KI = 0.0;
const float ANGPOS_Y_KD = 0.0;
const float ANGPOS_Z_KP = 1.0;
const float ANGPOS_Z_KI = 0.0;
const float ANGPOS_Z_KD = 0.0;

// Initial angular velocity controller gains
const float ANGVEL_X_KP = 1.0;
const float ANGVEL_X_KI = 0.0;
const float ANGVEL_X_KD = 0.0;
const float ANGVEL_Y_KP = 1.0;
const float ANGVEL_Y_KI = 0.0;
const float ANGVEL_Y_KD = 0.0;
const float ANGVEL_Z_KP = 1.0;
const float ANGVEL_Z_KI = 0.0;
const float ANGVEL_Z_KD = 0.0;

// Initial angular acceleration controller gains
const float ANGACC_X_KP = 1.0;
const float ANGACC_X_KI = 0.0;
const float ANGACC_X_KD = 0.0;
const float ANGACC_Y_KP = 1.0;
const float ANGACC_Y_KI = 0.0;
const float ANGACC_Y_KD = 0.0;
const float ANGACC_Z_KP = 1.0;
const float ANGACC_Z_KI = 0.0;
const float ANGACC_Z_KD = 0.0;

// Pin configuration
const uint8_t PIN_MAIN_CH   = 1;   // PA5
const uint8_t PIN_DROGUE_CH = 2;   // PC4
const uint8_t PIN_EXT_TEMP_THERM_CH = 1;   // PC1

// Unused config
// TODO(yoos): This is a hack to make rocket and payload build.
const uint8_t PIN_FIN_SWITCH_CH = 255;
const uint8_t PIN_MOTOR_CH = 255;
const uint8_t PIN_ESC_TEMP_THERM_CH = 255;
const uint8_t PIN_SHUTTLE2_CH = 255;
const uint8_t PIN_SHUTTLE1_CH = 255;


}

#endif // UNIT_CONFIG_HPP_
