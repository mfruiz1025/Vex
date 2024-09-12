#include "vex.h"

using namespace vex;

// Configuración del cerebro y los motores
brain Brain;

// 4 motores del lado izquierdo
motor LeftMotor1=motor(PORT1, ratio18_1, false);
motor LeftMotor2=motor(PORT2, ratio18_1, false);
motor LeftMotor3=motor(PORT3, ratio18_1, false);
motor LeftMotor4=motor(PORT4, ratio18_1, false);

// 4 motores del lado derecho
motor RightMotor1=motor(PORT5, ratio18_1, true);
motor RightMotor2=motor(PORT6, ratio18_1, true);
motor RightMotor3=motor(PORT7, ratio18_1, true);
motor RightMotor4=motor(PORT8, ratio18_1, true);

// Grupo de motores para facilitar el control
motor_group LeftDrive=motor_group(LeftMotor1, LeftMotor2, LeftMotor3, LeftMotor4);
motor_group RightDrive=motor_group(RightMotor1, RightMotor2, RightMotor3, RightMotor4);

competition Competition;

// Función autónoma básica
void autonomous() {
    // Mover hacia adelante (a 50% de velocidad) durante 3 segundos
    LeftDrive.spin(forward, 50, percent);
    RightDrive.spin(forward, 50, percent);
    wait(3, seconds);
    
    // Detener los motores
    LeftDrive.stop();
    RightDrive.stop();

    // Girar a la derecha durante 2 segundos
    LeftDrive.spin(forward, 50, percent);
    RightDrive.spin(reverse, 50, percent);
    wait(2, seconds);
    
    // Detener los motores
    LeftDrive.stop();
    RightDrive.stop();
}

void usercontrol() {
    // No se implementa en este código
}

int main() {
    // Registrar las funciones para la competencia
    Competition.autonomous(autonomous);
    Competition.drivercontrol(usercontrol);

    // Mantener el programa en ejecución
    while (true) {
        wait(100, msec);
    }
}
