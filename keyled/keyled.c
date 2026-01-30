/*
 * File: keyled.c
 * Author: WenXing Tan
 * Date: 01/29/2026
 * Description: Controlling Num lock, Caps locks, Scroll locks with the key pad
 * In a bit pattern from 0 - 7
*/
#include <linux/kd.h>   //KDSETLED
#include <sys/ioctl.h>
#include <unistd.h> //sleep()
#include <stdio.h>

int main(int argc, char* argv[]) {
//  int keybitson = 0x2;
//  int keybitsoff = 0x0;
    int keybit[] = {0x00, 0x01, 0x04, 0x05, 0x02, 0x03, 0x06, 0x07};    //Leds in binary; 
    int argrumentNum = 2;

    //If there are not 2 arguments prints out invaloud input and rturn 1
    if (argc != argrumentNum) {
        printf("Invalid Input: 1-7\n");
            return 1;
    }
    
    char* arg = argv[1];
    int key = *arg - '0';

    if (key < 0 || key > 7) {
        fprintf(stderr, "Error: Invalid input\n1 - 7\n");
        
    }
    else {
        for (int i = 0; i < 8; i++){
            if (key == i){
                ioctl (1,KDSETLED, keybit[i]);
            }else{}
        }   
    }
    
}
