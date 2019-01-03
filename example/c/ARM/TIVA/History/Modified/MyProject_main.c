/*
 * Project name:
     MyProject.mcpar
 * Generated by:
     Visual TFT
 * Date of creation
     20-Dec-17
 * Test configuration:
     MCU:             LM3S9B95
                      http://www.ti.com/product/LM3S9B95
     Dev.Board:       EasyMx_PRO_v7_for_Stellaris_ARM
                      http://www.mikroe.com/easymx-pro/stellaris/
     Oscillator:      80000000 Hz
     SW:              mikroC PRO for ARM
                      http://www.mikroe.com/mikroc/arm/
 */

#include "MyProject_objects.h"

void main() {

  Start_TP();

  while (1) {
    Check_TP();
  }
}