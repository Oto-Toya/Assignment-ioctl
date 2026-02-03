/*
 * File: keyled.c
 * Author: WenXing Tan
 * Date: 01/29/2026
 * Description: Controlling Num lock, Caps lock, Scroll lock with the keypad
 *              by setting LED states through ioctl syscall
 * 
 * LED bit patterns (0-7):
 *   0 = 0x00 (all LEDs off)
 *   1 = 0x01 (Num Lock)
 *   2 = 0x04 (Scroll Lock)
 *   3 = 0x05 (Num Lock + Scroll Lock)
 *   4 = 0x02 (Caps Lock)
 *   5 = 0x03 (Num Lock + Caps Lock)
 *   6 = 0x06 (Caps Lock + Scroll Lock)
 *   7 = 0x07 (All LEDs on)
*/

#include <linux/kd.h>   // KDSETLED ioctl command
#include <sys/ioctl.h>  // ioctl syscall
#include <unistd.h>     // Standard Unix definitions
#include <stdio.h>      // Standard I/O functions

int main(int argc, char* argv[]) {
    // LED state bit patterns for each combination (0-7)
    int keybit[] = {0x00, 0x01, 0x04, 0x05, 0x02, 0x03, 0x06, 0x07};
    
    // Expected number of command-line arguments
    int argumentNum = 2;

    // Validate: must provide exactly 2 arguments (program name + LED state)
    if (argc != argumentNum) {
        fprintf(stderr, "Invalid Input: Please provide a value between 0-7\n");
        return 1;
    }
    
    // Convert argument string to integer
    char* arg = argv[1];
    int key = *arg - '0';

    // Validate: LED state must be between 0 and 7
    if (key < 0 || key > 7) {
        fprintf(stderr, "Error: Invalid input\nPlease enter a value between 0-7\n");
        return 1;
    }
    
    // Set the LED state using ioctl syscall
    ioctl(1, KDSETLED, keybit[key]);
    
    return 0;
}
