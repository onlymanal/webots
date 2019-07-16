#include <webots/brake.h>
#include <webots/motor.h>
#include <webots/robot.h>

#include <stdio.h>

int main(int argc, char **argv) {
  wb_robot_init();

  int time_step = (int)wb_robot_get_basic_time_step();

  WbDeviceTag motor = wb_robot_get_device("motor");
  wb_motor_set_position(motor, INFINITY);
  wb_motor_set_velocity(motor, 1.0);

  WbDeviceTag brake = wb_robot_get_device("brake");

  while (wb_robot_step(time_step) != -1) {
    if (wb_robot_get_time() > 4.0) {
      printf("BRAKKKKE!!\n");
      wb_brake_set_damping_constant(brake, 100000.0);
    }
  };

  wb_robot_cleanup();

  return 0;
}
