#include "sensor/sensors.hpp"

#include "unit_config.hpp"

Sensors::Sensors(optional<Accelerometer *> accelerometer,
                 optional<Accelerometer *> accelerometerHighRange,
                 optional<Gyroscope *> gyroscope,
                 optional<Barometer *> barometer,
                 optional<GPS *> gps,
                 optional<Magnetometer *> magnetometer)
  : gyroscope(gyroscope),
    accelerometer(accelerometer),
    accelerometerHighRange(accelerometerHighRange),
    barometer(barometer),
    gps(gps),
    magnetometer(magnetometer) {
  if (gyroscope) {
    (*gyroscope)->setAxisConfig(unit_config::GYR_AXES);
    (*gyroscope)->setOffsets(unit_config::GYR_OFFSETS);
  }
  if (accelerometer) {
    (*accelerometer)->setAxisConfig(unit_config::ACC_AXES);
    (*accelerometer)->setOffsets(unit_config::ACC_OFFSETS);
  }
  if (accelerometerHighRange) {
    (*accelerometerHighRange)->setAxisConfig(unit_config::ACCH_AXES);
    (*accelerometerHighRange)->setOffsets(unit_config::ACCH_OFFSETS);
  }
  // TODO(syoo): Add initial configs for other sensors. May want to rethink
  // this before adding too many new sensors, though.
}

SensorMeasurements Sensors::readAvailableSensors() {
  SensorMeasurements measurements;
  if(accelerometer) measurements.accel = (*accelerometer)->readAccel();
  if(accelerometerHighRange) measurements.accel = (*accelerometerHighRange)->readAccel();
  if(gyroscope) measurements.gyro = (*gyroscope)->readGyro();
  if(barometer) measurements.bar = (*barometer)->readBar();
  if(gps) measurements.gps = (*gps)->readGPS();
  if(magnetometer) measurements.mag = (*magnetometer)->readMag();

  return measurements;
}

void Sensors::calibrateStep() {
  if(accelerometer) (*accelerometer)->calibrateStep();
  if(accelerometerHighRange) (*accelerometerHighRange)->calibrateStep();
  if(gyroscope) (*gyroscope)->calibrateStep();
  if(barometer) (*barometer)->calibrateStep();
  if(gps) (*gps)->calibrateStep();
  if(magnetometer) (*magnetometer)->calibrateStep();
}

bool Sensors::healthy() {
  bool healthy = true;

  if(accelerometer) healthy &= (*accelerometer)->healthy();
  if(accelerometerHighRange) healthy &= (*accelerometerHighRange)->healthy();
  if(gyroscope) healthy &= (*gyroscope)->healthy();
  if(barometer) healthy &= (*barometer)->healthy();
  if(gps) healthy &= (*gps)->healthy();
  if(magnetometer) healthy &= (*magnetometer)->healthy();

  return healthy;
}

bool Sensors::calibrated() {
  bool calibrated = true;

  if(accelerometer) calibrated &= (*accelerometer)->calibrated();
  if(accelerometerHighRange) calibrated &= (*accelerometerHighRange)->calibrated();
  if(gyroscope) calibrated &= (*gyroscope)->calibrated();
  if(barometer) calibrated &= (*barometer)->calibrated();
  if(gps) calibrated &= (*gps)->calibrated();
  if(magnetometer) calibrated &= (*magnetometer)->calibrated();

  return calibrated;
}
