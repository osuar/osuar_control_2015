#ifndef I2C_PLATFORM_HPP_
#define I2C_PLATFORM_HPP_

class I2CPlatform {
public:
  I2CPlatform();

  /**
   * Get the singleton instance.
   */
  static I2CPlatform& getInstance() {
    static I2CPlatform platform;
    return platform;
  }
};

#endif
