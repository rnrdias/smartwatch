EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:user
LIBS:smartwatch-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L VCC #PWR01
U 1 1 5B0DA4C4
P 1200 800
F 0 "#PWR01" H 1200 650 50  0001 C CNN
F 1 "VCC" H 1200 950 50  0000 C CNN
F 2 "" H 1200 800 60  0000 C CNN
F 3 "" H 1200 800 60  0000 C CNN
	1    1200 800 
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5B0DA504
P 1200 1700
F 0 "C1" H 1225 1800 50  0000 L CNN
F 1 "10nF" H 1225 1600 50  0000 L CNN
F 2 "PCB:Cap_SMD" H 1238 1550 30  0001 C CNN
F 3 "" H 1200 1700 60  0000 C CNN
	1    1200 1700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5B0DA587
P 1200 1950
F 0 "#PWR02" H 1200 1700 50  0001 C CNN
F 1 "GND" H 1200 1800 50  0000 C CNN
F 2 "" H 1200 1950 60  0000 C CNN
F 3 "" H 1200 1950 60  0000 C CNN
	1    1200 1950
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 5B0DA77B
P 4850 1100
F 0 "C2" H 4875 1200 50  0000 L CNN
F 1 "100nF" H 4875 1000 50  0000 L CNN
F 2 "PCB:Cap_SMD" H 4888 950 30  0001 C CNN
F 3 "" H 4850 1100 60  0000 C CNN
	1    4850 1100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5B0DA7AC
P 4850 1300
F 0 "#PWR03" H 4850 1050 50  0001 C CNN
F 1 "GND" H 4850 1150 50  0000 C CNN
F 2 "" H 4850 1300 60  0000 C CNN
F 3 "" H 4850 1300 60  0000 C CNN
	1    4850 1300
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR04
U 1 1 5B0DA7EB
P 6750 950
F 0 "#PWR04" H 6750 800 50  0001 C CNN
F 1 "VCC" V 6750 1150 50  0000 C CNN
F 2 "" H 6750 950 60  0000 C CNN
F 3 "" H 6750 950 60  0000 C CNN
	1    6750 950 
	0    1    1    0   
$EndComp
$Comp
L VCC #PWR05
U 1 1 5B0DB91E
P 4200 2350
F 0 "#PWR05" H 4200 2200 50  0001 C CNN
F 1 "VCC" V 4200 2550 50  0000 C CNN
F 2 "" H 4200 2350 60  0000 C CNN
F 3 "" H 4200 2350 60  0000 C CNN
	1    4200 2350
	0    1    1    0   
$EndComp
Text GLabel 6100 7250 3    39   Input ~ 0
LCD_SCLK
Text GLabel 6000 7250 3    39   Input ~ 0
LCD_SDIN
Text GLabel 5900 7250 3    39   Input ~ 0
LCD_D/~C
Text GLabel 5800 7250 3    39   Input ~ 0
LCD_SCE
Text GLabel 5700 7250 3    39   Input ~ 0
LCD_REST
Text GLabel 3250 1000 2    39   Input ~ 0
LCD_REST
Text GLabel 5200 6650 1    39   Input ~ 0
LCD_SCE
$Comp
L GND #PWR06
U 1 1 5B0DE419
P 5200 6750
F 0 "#PWR06" H 5200 6500 50  0001 C CNN
F 1 "GND" H 5200 6600 50  0000 C CNN
F 2 "" H 5200 6750 60  0000 C CNN
F 3 "" H 5200 6750 60  0000 C CNN
	1    5200 6750
	1    0    0    -1  
$EndComp
Text GLabel 3250 900  2    39   Input ~ 0
LCD_D/~C
Text GLabel 3250 3200 2    39   Input ~ 0
LCD_SDIN
Text GLabel 3250 3100 2    39   Input ~ 0
LCD_SCLK
$Comp
L Crystal_Small Y1
U 1 1 5B0DACA9
P 1450 6650
F 0 "Y1" H 1350 6850 50  0000 C CNN
F 1 "32768hz" H 1450 6750 50  0000 C CNN
F 2 "PCB:crystal_tc-26_horiz" H 1450 6650 60  0001 C CNN
F 3 "" H 1450 6650 60  0000 C CNN
	1    1450 6650
	1    0    0    -1  
$EndComp
Text GLabel 3250 1500 2    39   Input ~ 0
CLOCK_1A
Text GLabel 3250 1600 2    39   Input ~ 0
CLOCK_1B
Text GLabel 1650 6650 2    39   Input ~ 0
CLOCK_1B
Text GLabel 1250 6650 0    39   Input ~ 0
CLOCK_1A
$Comp
L C C3
U 1 1 5B0E080E
P 1300 6900
F 0 "C3" H 1325 7000 50  0000 L CNN
F 1 "6pF" H 1325 6800 50  0000 L CNN
F 2 "PCB:Cap_SMD" H 1338 6750 30  0001 C CNN
F 3 "" H 1300 6900 60  0000 C CNN
	1    1300 6900
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 5B0E0861
P 1600 6900
F 0 "C4" H 1625 7000 50  0000 L CNN
F 1 "6pF" H 1625 6800 50  0000 L CNN
F 2 "PCB:Cap_SMD" H 1638 6750 30  0001 C CNN
F 3 "" H 1600 6900 60  0000 C CNN
	1    1600 6900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5B0E0A29
P 1300 7150
F 0 "#PWR07" H 1300 6900 50  0001 C CNN
F 1 "GND" H 1300 7000 50  0000 C CNN
F 2 "" H 1300 7150 60  0000 C CNN
F 3 "" H 1300 7150 60  0000 C CNN
	1    1300 7150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5B0E0AFB
P 1600 7150
F 0 "#PWR08" H 1600 6900 50  0001 C CNN
F 1 "GND" H 1600 7000 50  0000 C CNN
F 2 "" H 1600 7150 60  0000 C CNN
F 3 "" H 1600 7150 60  0000 C CNN
	1    1600 7150
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 5B0E212F
P 2700 6850
F 0 "SW1" H 2850 6960 50  0000 C CNN
F 1 "SW_PUSH" H 2700 6770 50  0000 C CNN
F 2 "PCB:Button_Horizontal_pin_mirror" H 2700 6850 60  0001 C CNN
F 3 "" H 2700 6850 60  0000 C CNN
	1    2700 6850
	0    -1   1    0   
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 5B0E272B
P 3100 6850
F 0 "SW2" H 3250 6960 50  0000 C CNN
F 1 "SW_PUSH" H 3100 6770 50  0000 C CNN
F 2 "PCB:Button_Horizontal_pin_mirror" H 3100 6850 60  0001 C CNN
F 3 "" H 3100 6850 60  0000 C CNN
	1    3100 6850
	0    -1   1    0   
$EndComp
$Comp
L SW_PUSH SW3
U 1 1 5B0E2771
P 3500 6850
F 0 "SW3" H 3650 6960 50  0000 C CNN
F 1 "SW_PUSH" H 3500 6770 50  0000 C CNN
F 2 "PCB:Button_Horizontal" H 3500 6850 60  0001 C CNN
F 3 "" H 3500 6850 60  0000 C CNN
	1    3500 6850
	0    -1   1    0   
$EndComp
$Comp
L SW_PUSH SW4
U 1 1 5B0E27AE
P 3850 6850
F 0 "SW4" H 4000 6960 50  0000 C CNN
F 1 "SW_PUSH" H 3850 6770 50  0000 C CNN
F 2 "PCB:Button_Horizontal" H 3850 6850 60  0001 C CNN
F 3 "" H 3850 6850 60  0000 C CNN
	1    3850 6850
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR09
U 1 1 5B0E2B68
P 2700 7250
F 0 "#PWR09" H 2700 7000 50  0001 C CNN
F 1 "GND" H 2700 7100 50  0000 C CNN
F 2 "" H 2700 7250 60  0000 C CNN
F 3 "" H 2700 7250 60  0000 C CNN
	1    2700 7250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 5B0E4882
P 3100 7250
F 0 "#PWR010" H 3100 7000 50  0001 C CNN
F 1 "GND" H 3100 7100 50  0000 C CNN
F 2 "" H 3100 7250 60  0000 C CNN
F 3 "" H 3100 7250 60  0000 C CNN
	1    3100 7250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 5B0E48B1
P 3500 7250
F 0 "#PWR011" H 3500 7000 50  0001 C CNN
F 1 "GND" H 3500 7100 50  0000 C CNN
F 2 "" H 3500 7250 60  0000 C CNN
F 3 "" H 3500 7250 60  0000 C CNN
	1    3500 7250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 5B0E48E0
P 3850 7250
F 0 "#PWR012" H 3850 7000 50  0001 C CNN
F 1 "GND" H 3850 7100 50  0000 C CNN
F 2 "" H 3850 7250 60  0000 C CNN
F 3 "" H 3850 7250 60  0000 C CNN
	1    3850 7250
	1    0    0    -1  
$EndComp
Text GLabel 2700 6450 1    39   Input ~ 0
BUT_A
Text GLabel 3850 6450 1    39   Input ~ 0
BUT_B
Text GLabel 3100 6450 1    39   Input ~ 0
BUT_C
Text GLabel 3500 6450 1    39   Input ~ 0
BUT_D
Text GLabel 3250 1100 2    39   Input ~ 0
BUT_A
$Comp
L E104-BT02 U1
U 1 1 5B3D7963
P 9850 5700
F 0 "U1" H 9500 6350 70  0000 C CNN
F 1 "E104-BT02" H 9850 5100 70  0000 C CNN
F 2 "PCB:E104-BT02" H 9850 5800 60  0001 C CNN
F 3 "" H 9850 5800 60  0000 C CNN
	1    9850 5700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 5B3D7DC7
P 9050 6250
F 0 "#PWR013" H 9050 6000 50  0001 C CNN
F 1 "GND" H 9050 6100 50  0000 C CNN
F 2 "" H 9050 6250 60  0000 C CNN
F 3 "" H 9050 6250 60  0000 C CNN
	1    9050 6250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 5B3D80FF
P 10650 6250
F 0 "#PWR014" H 10650 6000 50  0001 C CNN
F 1 "GND" H 10650 6100 50  0000 C CNN
F 2 "" H 10650 6250 60  0000 C CNN
F 3 "" H 10650 6250 60  0000 C CNN
	1    10650 6250
	1    0    0    -1  
$EndComp
NoConn ~ 10550 5550
NoConn ~ 10550 5350
NoConn ~ 10550 5150
Text GLabel 10650 5750 2    39   Input ~ 0
BLUE_TX
Text GLabel 10650 5650 2    39   Input ~ 0
BLUE_RX
Text GLabel 10650 5250 2    39   Input ~ 0
BLUE_D/C
Text GLabel 3250 2700 2    39   Input ~ 0
BLUE_D/C
Text GLabel 3250 2600 2    39   Input ~ 0
BLUE_RX
Text GLabel 3250 2500 2    39   Input ~ 0
BLUE_TX
$Comp
L C C7
U 1 1 5B3DA983
P 8750 5500
F 0 "C7" H 8775 5600 50  0000 L CNN
F 1 "100nF" H 8775 5400 50  0000 L CNN
F 2 "PCB:Cap_SMD" H 8788 5350 30  0001 C CNN
F 3 "" H 8750 5500 60  0000 C CNN
	1    8750 5500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 5B3DA989
P 8750 5750
F 0 "#PWR015" H 8750 5500 50  0001 C CNN
F 1 "GND" H 8750 5600 50  0000 C CNN
F 2 "" H 8750 5750 60  0000 C CNN
F 3 "" H 8750 5750 60  0000 C CNN
	1    8750 5750
	1    0    0    -1  
$EndComp
$Comp
L NOKIA_5110 P1
U 1 1 5B3DBAC3
P 6050 6600
F 0 "P1" H 5700 7000 50  0000 C CNN
F 1 "NOKIA_5110" H 6050 6850 50  0000 C CNN
F 2 "PCB:LCD_nokia5110" V 6050 6250 60  0001 C CNN
F 3 "" V 6050 6250 60  0000 C CNN
	1    6050 6600
	1    0    0    -1  
$EndComp
$Comp
L Battery BT1
U 1 1 5B3DC41B
P 1700 5600
F 0 "BT1" H 1550 5750 50  0000 L CNN
F 1 "3,8V/380mA" V 1850 5400 50  0000 L CNN
F 2 "PCB:Bat_3.8V" V 1700 5640 60  0001 C CNN
F 3 "" V 1700 5640 60  0000 C CNN
	1    1700 5600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 5B3DC68D
P 1700 5950
F 0 "#PWR016" H 1700 5700 50  0001 C CNN
F 1 "GND" H 1700 5800 50  0000 C CNN
F 2 "" H 1700 5950 60  0000 C CNN
F 3 "" H 1700 5950 60  0000 C CNN
	1    1700 5950
	1    0    0    -1  
$EndComp
$Comp
L MPU6050 P2
U 1 1 5B3E5FBE
P 7500 5700
F 0 "P2" H 7300 5950 50  0000 C CNN
F 1 "MPU6050" H 7450 5400 50  0000 C CNN
F 2 "PCB:MPU6050" H 7750 5500 60  0001 C CNN
F 3 "" H 7750 5500 60  0000 C CNN
	1    7500 5700
	1    0    0    -1  
$EndComp
NoConn ~ 7100 5550
NoConn ~ 7100 5750
NoConn ~ 7100 5850
Text GLabel 7950 5750 2    39   Input ~ 0
ACC_SCL
Text GLabel 7950 5850 2    39   Input ~ 0
ACC_SDA
$Comp
L GND #PWR017
U 1 1 5B3E67FB
P 8400 5700
F 0 "#PWR017" H 8400 5450 50  0001 C CNN
F 1 "GND" H 8400 5550 50  0000 C CNN
F 2 "" H 8400 5700 60  0000 C CNN
F 3 "" H 8400 5700 60  0000 C CNN
	1    8400 5700
	1    0    0    -1  
$EndComp
Text GLabel 3250 3000 2    39   Input ~ 0
BUZ
Text GLabel 4300 5550 0    39   Input ~ 0
BUZ
$Comp
L GND #PWR018
U 1 1 5B3EA46D
P 5000 5850
F 0 "#PWR018" H 5000 5600 50  0001 C CNN
F 1 "GND" H 5000 5700 50  0000 C CNN
F 2 "" H 5000 5850 60  0000 C CNN
F 3 "" H 5000 5850 60  0000 C CNN
	1    5000 5850
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 5B3EBA0E
P 6550 5650
F 0 "C6" H 6575 5750 50  0000 L CNN
F 1 "100nF" H 6575 5550 50  0000 L CNN
F 2 "PCB:Cap_SMD" H 6588 5500 30  0001 C CNN
F 3 "" H 6550 5650 60  0000 C CNN
	1    6550 5650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 5B3EBA14
P 6550 5900
F 0 "#PWR019" H 6550 5650 50  0001 C CNN
F 1 "GND" H 6550 5750 50  0000 C CNN
F 2 "" H 6550 5900 60  0000 C CNN
F 3 "" H 6550 5900 60  0000 C CNN
	1    6550 5900
	1    0    0    -1  
$EndComp
Text GLabel 10650 5450 2    39   Input ~ 0
BLUE_S/~M
Text GLabel 3250 2800 2    39   Input ~ 0
BLUE_S/~M
$Comp
L LED D2
U 1 1 5B56102D
P 6750 4150
F 0 "D2" H 6750 4250 50  0000 C CNN
F 1 "LED_POWER" H 6750 4050 50  0000 C CNN
F 2 "PCB:LED_H" H 6750 4150 60  0001 C CNN
F 3 "" H 6750 4150 60  0000 C CNN
	1    6750 4150
	-1   0    0    1   
$EndComp
$Comp
L R R5
U 1 1 5B561B2E
P 6350 4150
F 0 "R5" V 6430 4150 50  0000 C CNN
F 1 "100R" V 6350 4150 50  0000 C CNN
F 2 "PCB:R_SMD" V 6280 4150 30  0001 C CNN
F 3 "" H 6350 4150 30  0000 C CNN
	1    6350 4150
	0    1    1    0   
$EndComp
$Comp
L GND #PWR020
U 1 1 5B56235F
P 7050 4200
F 0 "#PWR020" H 7050 3950 50  0001 C CNN
F 1 "GND" H 7050 4050 50  0000 C CNN
F 2 "" H 7050 4200 60  0000 C CNN
F 3 "" H 7050 4200 60  0000 C CNN
	1    7050 4200
	1    0    0    -1  
$EndComp
Text GLabel 4550 4150 0    39   Input ~ 0
IR_LED
Text GLabel 3250 2050 2    39   Input ~ 0
IR_LED
$Comp
L CONN_01X02 P3
U 1 1 5B56424E
P 10300 3800
F 0 "P3" H 10300 3950 50  0000 C CNN
F 1 "VIRBRATOR" V 10400 3800 50  0000 C CNN
F 2 "PCB:Vibr" H 10300 3800 60  0001 C CNN
F 3 "" H 10300 3800 60  0000 C CNN
	1    10300 3800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR021
U 1 1 5B5647B9
P 10050 4350
F 0 "#PWR021" H 10050 4100 50  0001 C CNN
F 1 "GND" H 10050 4200 50  0000 C CNN
F 2 "" H 10050 4350 60  0000 C CNN
F 3 "" H 10050 4350 60  0000 C CNN
	1    10050 4350
	1    0    0    -1  
$EndComp
Text GLabel 9350 4100 0    39   Input ~ 0
VIBRA
Text GLabel 3250 2900 2    39   Input ~ 0
VIBRA
$Comp
L R R3
U 1 1 5B56E55A
P 4000 2350
F 0 "R3" V 4080 2350 50  0000 C CNN
F 1 "10K" V 4000 2350 50  0000 C CNN
F 2 "PCB:R_SMD" V 3930 2350 30  0001 C CNN
F 3 "" H 4000 2350 30  0000 C CNN
	1    4000 2350
	0    1    1    0   
$EndComp
Text GLabel 6150 4150 0    39   Input ~ 0
POWER_LED
Text GLabel 3250 1950 2    39   Input ~ 0
POWER_LED
Text GLabel 3250 2250 2    39   Input ~ 0
ACC_SCL
Text GLabel 3250 2150 2    39   Input ~ 0
ACC_SDA
Text GLabel 3250 1850 2    39   Input ~ 0
BAT_RECARGA
$Comp
L L_Small L1
U 1 1 5B5AF3E2
P 5800 5050
F 0 "L1" H 5830 5090 50  0000 L CNN
F 1 "15mH" H 5830 5010 50  0000 L CNN
F 2 "PCB:Indutor_15mH" H 5800 5050 60  0001 C CNN
F 3 "" H 5800 5050 60  0000 C CNN
	1    5800 5050
	0    -1   -1   0   
$EndComp
$Comp
L BC817-40 Q1
U 1 1 5B5AFA8F
P 4900 5550
F 0 "Q1" H 5100 5625 50  0000 L CNN
F 1 "BC337" H 5100 5550 50  0000 L CNN
F 2 "PCB:SOT23" H 5100 5475 50  0001 L CIN
F 3 "" H 4900 5550 50  0000 L CNN
	1    4900 5550
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5B5B1115
P 4500 5550
F 0 "R1" V 4580 5550 50  0000 C CNN
F 1 "470R" V 4500 5550 50  0000 C CNN
F 2 "PCB:R_SMD" V 4430 5550 30  0001 C CNN
F 3 "" H 4500 5550 30  0000 C CNN
	1    4500 5550
	0    1    1    0   
$EndComp
$Comp
L VCC #PWR022
U 1 1 5B5B1DE5
P 6150 5000
F 0 "#PWR022" H 6150 4850 50  0001 C CNN
F 1 "VCC" H 6150 5150 50  0000 C CNN
F 2 "" H 6150 5000 60  0000 C CNN
F 3 "" H 6150 5000 60  0000 C CNN
	1    6150 5000
	1    0    0    -1  
$EndComp
$Comp
L BC817-40 Q2
U 1 1 5B5B80BC
P 9950 4100
F 0 "Q2" H 10150 4175 50  0000 L CNN
F 1 "BC337" H 10150 4100 50  0000 L CNN
F 2 "PCB:SOT23" H 10150 4025 50  0001 L CIN
F 3 "" H 9950 4100 50  0000 L CNN
	1    9950 4100
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5B5B9855
P 9550 4100
F 0 "R6" V 9630 4100 50  0000 C CNN
F 1 "470R" V 9550 4100 50  0000 C CNN
F 2 "PCB:R_SMD" V 9480 4100 30  0001 C CNN
F 3 "" H 9550 4100 30  0000 C CNN
	1    9550 4100
	0    1    1    0   
$EndComp
$Comp
L VCC #PWR023
U 1 1 5B5BA4DD
P 10050 3700
F 0 "#PWR023" H 10050 3550 50  0001 C CNN
F 1 "VCC" H 10050 3850 50  0000 C CNN
F 2 "" H 10050 3700 60  0000 C CNN
F 3 "" H 10050 3700 60  0000 C CNN
	1    10050 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 5B5C1625
P 6400 7250
F 0 "#PWR024" H 6400 7000 50  0001 C CNN
F 1 "GND" V 6400 7050 50  0000 C CNN
F 2 "" H 6400 7250 60  0000 C CNN
F 3 "" H 6400 7250 60  0000 C CNN
	1    6400 7250
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR025
U 1 1 5B5C2BF0
P 6200 7250
F 0 "#PWR025" H 6200 7100 50  0001 C CNN
F 1 "VCC" V 6200 7450 50  0000 C CNN
F 2 "" H 6200 7250 60  0000 C CNN
F 3 "" H 6200 7250 60  0000 C CNN
	1    6200 7250
	-1   0    0    1   
$EndComp
$Comp
L R R2
U 1 1 5B5CBAB2
P 5200 5300
F 0 "R2" V 5280 5300 50  0000 C CNN
F 1 "100R" V 5200 5300 50  0000 C CNN
F 2 "PCB:R_SMD" V 5130 5300 30  0001 C CNN
F 3 "" H 5200 5300 30  0000 C CNN
	1    5200 5300
	0    1    1    0   
$EndComp
Text GLabel 3800 850  2    39   Input ~ 0
BUT_B
Text GLabel 3800 950  2    39   Input ~ 0
BUT_C
Text GLabel 3800 1050 2    39   Input ~ 0
BUT_D
Wire Wire Line
	1300 900  1200 900 
Wire Wire Line
	1200 800  1200 1200
Wire Wire Line
	1200 1550 1200 1500
Wire Wire Line
	1200 1500 1300 1500
Wire Wire Line
	1200 1950 1200 1850
Wire Wire Line
	1250 3000 1250 3250
Wire Wire Line
	1250 3100 1300 3100
Wire Wire Line
	1300 3200 1250 3200
Connection ~ 1250 3200
Wire Wire Line
	1200 1200 1300 1200
Connection ~ 1200 900 
Wire Wire Line
	4850 1300 4850 1250
Wire Wire Line
	4850 950  4850 900 
Wire Wire Line
	5700 7200 5700 7250
Wire Wire Line
	5800 7250 5800 7200
Wire Wire Line
	5900 7200 5900 7250
Wire Wire Line
	6000 7250 6000 7200
Wire Wire Line
	6100 7200 6100 7250
Wire Wire Line
	6200 7250 6200 7200
Wire Wire Line
	6300 7200 6300 7250
Wire Wire Line
	6400 7250 6400 7200
Wire Wire Line
	5200 6750 5200 6650
Wire Wire Line
	3250 1100 3200 1100
Wire Wire Line
	3250 1000 3200 1000
Wire Wire Line
	3250 900  3200 900 
Wire Wire Line
	3200 1500 3250 1500
Wire Wire Line
	3250 1600 3200 1600
Wire Wire Line
	1550 6650 1650 6650
Wire Wire Line
	1250 6650 1350 6650
Wire Wire Line
	1300 6750 1300 6650
Connection ~ 1300 6650
Wire Wire Line
	1600 6750 1600 6650
Connection ~ 1600 6650
Wire Wire Line
	1300 7150 1300 7050
Wire Wire Line
	1600 7150 1600 7050
Wire Wire Line
	2700 7250 2700 7150
Wire Wire Line
	3850 7250 3850 7150
Wire Wire Line
	3500 7150 3500 7250
Wire Wire Line
	3100 7150 3100 7250
Wire Wire Line
	3850 6450 3850 6550
Wire Wire Line
	3500 6550 3500 6450
Wire Wire Line
	3100 6450 3100 6550
Wire Wire Line
	2700 6550 2700 6450
Wire Wire Line
	3200 1750 3250 1750
Wire Wire Line
	3250 1850 3200 1850
Wire Wire Line
	3200 1950 3250 1950
Wire Wire Line
	3250 2050 3200 2050
Wire Wire Line
	9050 6250 9050 6150
Wire Wire Line
	9050 6150 9150 6150
Wire Wire Line
	10650 5950 10650 6250
Wire Wire Line
	10650 6050 10550 6050
Wire Wire Line
	10550 6150 10650 6150
Connection ~ 10650 6150
Wire Wire Line
	10550 5950 10650 5950
Connection ~ 10650 6050
Wire Wire Line
	9050 6050 9150 6050
Wire Wire Line
	10550 5750 10650 5750
Wire Wire Line
	10650 5650 10550 5650
Wire Wire Line
	10550 5250 10650 5250
Wire Wire Line
	3250 2250 3200 2250
Wire Wire Line
	3250 2600 3200 2600
Wire Wire Line
	3250 2500 3200 2500
Wire Wire Line
	3250 2150 3200 2150
Wire Wire Line
	8750 5750 8750 5650
Wire Wire Line
	8750 5250 8750 5350
Wire Wire Line
	1700 5750 1700 5950
Wire Wire Line
	7950 5550 7900 5550
Wire Wire Line
	7900 5750 7950 5750
Wire Wire Line
	7950 5850 7900 5850
Wire Wire Line
	7900 5650 8400 5650
Wire Wire Line
	8400 5650 8400 5700
Wire Wire Line
	3250 3100 3200 3100
Wire Wire Line
	5350 5300 5500 5300
Wire Wire Line
	6150 5300 6100 5300
Wire Wire Line
	6150 5000 6150 5300
Wire Wire Line
	6550 5900 6550 5800
Wire Wire Line
	6550 5400 6550 5500
Wire Wire Line
	10650 5450 10550 5450
Wire Wire Line
	3250 2700 3200 2700
Wire Wire Line
	6950 4150 7050 4150
Wire Wire Line
	7050 4150 7050 4200
Wire Wire Line
	6500 4150 6550 4150
Wire Wire Line
	3250 2800 3200 2800
Wire Wire Line
	10050 3900 10050 3850
Wire Wire Line
	10050 3850 10100 3850
Wire Wire Line
	3250 2900 3200 2900
Wire Wire Line
	3250 3200 3200 3200
Wire Wire Line
	3200 1400 3800 1400
Wire Wire Line
	3200 1300 3800 1300
Wire Wire Line
	3200 1200 3800 1200
Wire Wire Line
	4200 2350 4150 2350
Wire Wire Line
	3200 2350 3850 2350
Wire Wire Line
	3250 3000 3200 3000
Wire Wire Line
	1450 5100 1450 5200
Wire Wire Line
	6150 5050 5900 5050
Wire Wire Line
	5700 5050 5450 5050
Wire Wire Line
	5450 5050 5450 5300
Connection ~ 5450 5300
Wire Wire Line
	5000 5350 5000 5300
Wire Wire Line
	5000 5850 5000 5750
Wire Wire Line
	4650 5550 4700 5550
Wire Wire Line
	4300 5550 4350 5550
Connection ~ 6150 5050
Wire Wire Line
	10050 4350 10050 4300
Wire Wire Line
	9350 4100 9400 4100
Wire Wire Line
	9700 4100 9750 4100
Wire Wire Line
	10100 3750 10050 3750
Wire Wire Line
	10050 3750 10050 3700
Wire Wire Line
	5000 5300 5050 5300
Wire Wire Line
	6150 4150 6200 4150
Wire Wire Line
	3800 1050 3750 1050
Wire Wire Line
	3750 1050 3750 1400
Connection ~ 3750 1400
Wire Wire Line
	3800 950  3700 950 
Wire Wire Line
	3700 950  3700 1300
Connection ~ 3700 1300
Wire Wire Line
	3800 850  3650 850 
Wire Wire Line
	3650 850  3650 1200
Connection ~ 3650 1200
$Comp
L R R7
U 1 1 5B5F8A61
P 1450 5350
F 0 "R7" V 1530 5350 50  0000 C CNN
F 1 "300K" V 1450 5350 50  0000 C CNN
F 2 "PCB:R_SMD" V 1380 5350 30  0001 C CNN
F 3 "" H 1450 5350 30  0000 C CNN
	1    1450 5350
	-1   0    0    1   
$EndComp
$Comp
L R R8
U 1 1 5B5F953D
P 1450 5750
F 0 "R8" V 1530 5750 50  0000 C CNN
F 1 "100K" V 1450 5750 50  0000 C CNN
F 2 "PCB:R_SMD" V 1380 5750 30  0001 C CNN
F 3 "" H 1450 5750 30  0000 C CNN
	1    1450 5750
	-1   0    0    1   
$EndComp
Wire Wire Line
	1450 5500 1450 5600
$Comp
L GND #PWR026
U 1 1 5B5F98F3
P 1450 5950
F 0 "#PWR026" H 1450 5700 50  0001 C CNN
F 1 "GND" H 1450 5800 50  0000 C CNN
F 2 "" H 1450 5950 60  0000 C CNN
F 3 "" H 1450 5950 60  0000 C CNN
	1    1450 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 5950 1450 5900
Connection ~ 1450 5150
Text GLabel 1150 5550 0    39   Input ~ 0
BAT_VOLT
Wire Wire Line
	1150 5550 1450 5550
Connection ~ 1450 5550
$Comp
L C C8
U 1 1 5B5FBE69
P 1200 5750
F 0 "C8" H 1225 5850 50  0000 L CNN
F 1 "100nF" H 1225 5650 50  0000 L CNN
F 2 "PCB:Cap_SMD" H 1238 5600 30  0001 C CNN
F 3 "" H 1200 5750 60  0000 C CNN
	1    1200 5750
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR027
U 1 1 5B5FC443
P 1200 5950
F 0 "#PWR027" H 1200 5700 50  0001 C CNN
F 1 "GND" H 1200 5800 50  0000 C CNN
F 2 "" H 1200 5950 60  0000 C CNN
F 3 "" H 1200 5950 60  0000 C CNN
	1    1200 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 5950 1200 5900
Wire Wire Line
	1200 5600 1200 5550
Connection ~ 1200 5550
$Comp
L R R9
U 1 1 5B61F6BF
P 1450 4950
F 0 "R9" V 1530 4950 50  0000 C CNN
F 1 "10R/0,5W" V 1350 4950 50  0000 C CNN
F 2 "PCB:RC03_SMD" V 1380 4950 30  0001 C CNN
F 3 "" H 1450 4950 30  0000 C CNN
	1    1450 4950
	-1   0    0    1   
$EndComp
Wire Wire Line
	1450 4650 1450 4800
$Comp
L D D3
U 1 1 5B62B323
P 1250 4200
F 0 "D3" H 1250 4300 50  0000 C CNN
F 1 "D" H 1250 4100 50  0000 C CNN
F 2 "PCB:D_SMD" H 1250 4200 60  0001 C CNN
F 3 "" H 1250 4200 60  0000 C CNN
	1    1250 4200
	-1   0    0    1   
$EndComp
$Comp
L LED D4
U 1 1 5B630D76
P 5150 4150
F 0 "D4" H 5150 4250 50  0000 C CNN
F 1 "LED_IR" H 5150 4050 50  0000 C CNN
F 2 "PCB:LED_H" H 5150 4150 60  0001 C CNN
F 3 "" H 5150 4150 60  0000 C CNN
	1    5150 4150
	-1   0    0    1   
$EndComp
$Comp
L R R10
U 1 1 5B630D7C
P 4750 4150
F 0 "R10" V 4830 4150 50  0000 C CNN
F 1 "100R" V 4750 4150 50  0000 C CNN
F 2 "PCB:R_SMD" V 4680 4150 30  0001 C CNN
F 3 "" H 4750 4150 30  0000 C CNN
	1    4750 4150
	0    1    1    0   
$EndComp
$Comp
L GND #PWR028
U 1 1 5B630D82
P 5450 4200
F 0 "#PWR028" H 5450 3950 50  0001 C CNN
F 1 "GND" H 5450 4050 50  0000 C CNN
F 2 "" H 5450 4200 60  0000 C CNN
F 3 "" H 5450 4200 60  0000 C CNN
	1    5450 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 4150 5450 4150
Wire Wire Line
	5450 4150 5450 4200
Wire Wire Line
	4900 4150 4950 4150
Wire Wire Line
	4550 4150 4600 4150
$Comp
L VCC #PWR029
U 1 1 5B638FBF
P 6950 5600
F 0 "#PWR029" H 6950 5450 50  0001 C CNN
F 1 "VCC" H 6950 5750 50  0000 C CNN
F 2 "" H 6950 5600 60  0000 C CNN
F 3 "" H 6950 5600 60  0000 C CNN
	1    6950 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 5550 7950 5500
$Comp
L VCC #PWR030
U 1 1 5B639337
P 9050 6000
F 0 "#PWR030" H 9050 5850 50  0001 C CNN
F 1 "VCC" H 9050 6150 50  0000 C CNN
F 2 "" H 9050 6000 60  0000 C CNN
F 3 "" H 9050 6000 60  0000 C CNN
	1    9050 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 6050 9050 6000
$Comp
L VCC #PWR031
U 1 1 5B56775A
P 8750 5250
F 0 "#PWR031" H 8750 5100 50  0001 C CNN
F 1 "VCC" H 8750 5400 50  0000 C CNN
F 2 "" H 8750 5250 60  0000 C CNN
F 3 "" H 8750 5250 60  0000 C CNN
	1    8750 5250
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR032
U 1 1 5B567AA9
P 6550 5400
F 0 "#PWR032" H 6550 5250 50  0001 C CNN
F 1 "VCC" H 6550 5550 50  0000 C CNN
F 2 "" H 6550 5400 60  0000 C CNN
F 3 "" H 6550 5400 60  0000 C CNN
	1    6550 5400
	1    0    0    -1  
$EndComp
Text GLabel 3250 1750 2    39   Input ~ 0
LCD_LAMP
$Comp
L GND #PWR033
U 1 1 5B589482
P 1250 3250
F 0 "#PWR033" H 1250 3000 50  0001 C CNN
F 1 "GND" H 1250 3100 50  0000 C CNN
F 2 "" H 1250 3250 60  0000 C CNN
F 3 "" H 1250 3250 60  0000 C CNN
	1    1250 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 1000 1200 1000
Connection ~ 1200 1000
Wire Wire Line
	1300 3000 1250 3000
Connection ~ 1250 3100
Text GLabel 1200 2250 0    39   Input ~ 0
BAT_VOLT
Wire Wire Line
	1300 2250 1200 2250
Text GLabel 6300 7250 3    39   Input ~ 0
LCD_LAMP
$Comp
L Buzz X1
U 1 1 5B5B8295
P 5800 5300
F 0 "X1" H 5800 5450 50  0000 C CNN
F 1 "Buzz" H 5800 5150 50  0000 C CNN
F 2 "PCB:pin_socket_2_smd" H 5800 5300 60  0001 C CNN
F 3 "" H 5800 5300 60  0000 C CNN
	1    5800 5300
	1    0    0    -1  
$EndComp
$Comp
L BC817-40 Q4
U 1 1 5B5C7BEB
P 2150 5150
F 0 "Q4" H 2050 5400 50  0000 L CNN
F 1 "BC337" H 1900 5300 50  0000 L CNN
F 2 "PCB:SOT23" H 2350 5075 50  0001 L CIN
F 3 "" H 2150 5150 50  0000 L CNN
	1    2150 5150
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR034
U 1 1 5B5C865F
P 2050 5400
F 0 "#PWR034" H 2050 5150 50  0001 C CNN
F 1 "GND" H 2050 5250 50  0000 C CNN
F 2 "" H 2050 5400 60  0000 C CNN
F 3 "" H 2050 5400 60  0000 C CNN
	1    2050 5400
	1    0    0    -1  
$EndComp
Text GLabel 2750 5150 2    39   Input ~ 0
BAT_RECARGA
$Comp
L Q_PNP_BCE Q3
U 1 1 5B5CAC0F
P 1750 4500
F 0 "Q3" H 1650 4300 50  0000 R CNN
F 1 "BC237" H 1700 4400 50  0000 R CNN
F 2 "PCB:SOT23" H 1950 4600 29  0001 C CNN
F 3 "" H 1750 4500 60  0000 C CNN
	1    1750 4500
	-1   0    0    1   
$EndComp
$Comp
L R R13
U 1 1 5B5D0155
P 2050 4750
F 0 "R13" V 2130 4750 50  0000 C CNN
F 1 "470R" V 2050 4750 50  0000 C CNN
F 2 "PCB:R_SMD" V 1980 4750 30  0001 C CNN
F 3 "" H 2050 4750 30  0000 C CNN
	1    2050 4750
	-1   0    0    1   
$EndComp
$Comp
L R R12
U 1 1 5B5D319E
P 1850 4200
F 0 "R12" V 1930 4200 50  0000 C CNN
F 1 "1K" V 1850 4200 50  0000 C CNN
F 2 "PCB:R_SMD" V 1780 4200 30  0001 C CNN
F 3 "" H 1850 4200 30  0000 C CNN
	1    1850 4200
	0    1    -1   0   
$EndComp
Wire Wire Line
	1400 4200 1700 4200
Wire Wire Line
	2000 4200 2050 4200
Wire Wire Line
	2050 4200 2050 4600
Connection ~ 2050 4500
Connection ~ 1650 4200
$Comp
L R R11
U 1 1 5B5E4CA2
P 1450 4500
F 0 "R11" V 1530 4500 50  0000 C CNN
F 1 "270R" V 1450 4500 50  0000 C CNN
F 2 "PCB:R_SMD" V 1380 4500 30  0001 C CNN
F 3 "" H 1450 4500 30  0000 C CNN
	1    1450 4500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1450 4350 1450 4200
Wire Wire Line
	1150 4750 1650 4750
Wire Wire Line
	1650 4750 1650 4700
Connection ~ 1450 4750
$Comp
L R R14
U 1 1 5B5F7A0C
P 2550 5150
F 0 "R14" V 2630 5150 50  0000 C CNN
F 1 "470R" V 2550 5150 50  0000 C CNN
F 2 "PCB:R_SMD" V 2480 5150 30  0001 C CNN
F 3 "" H 2550 5150 30  0000 C CNN
	1    2550 5150
	0    1    1    0   
$EndComp
Wire Wire Line
	2050 4500 1950 4500
Wire Wire Line
	2050 5400 2050 5350
Wire Wire Line
	2050 4950 2050 4900
Wire Wire Line
	2400 5150 2350 5150
Wire Wire Line
	1050 4200 1100 4200
Connection ~ 1450 4200
Wire Wire Line
	1650 4300 1650 4200
Wire Wire Line
	2750 5150 2700 5150
Text GLabel 1050 4200 0    39   Input ~ 0
BAT_POWER
Text GLabel 2800 4550 2    39   Input ~ 0
BAT_POWER
Wire Wire Line
	2750 4550 2800 4550
$Comp
L GND #PWR035
U 1 1 5B62E33E
P 2800 4700
F 0 "#PWR035" H 2800 4450 50  0001 C CNN
F 1 "GND" H 2800 4550 50  0000 C CNN
F 2 "" H 2800 4700 60  0000 C CNN
F 3 "" H 2800 4700 60  0000 C CNN
	1    2800 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 4700 2800 4650
Wire Wire Line
	2800 4650 2750 4650
Wire Wire Line
	1700 5150 1700 5450
Wire Wire Line
	7100 5650 6950 5650
Wire Wire Line
	6950 5650 6950 5600
$Comp
L +BATT #PWR036
U 1 1 5B5BB7E0
P 7950 5500
F 0 "#PWR036" H 7950 5350 50  0001 C CNN
F 1 "+BATT" H 7950 5640 50  0000 C CNN
F 2 "" H 7950 5500 60  0000 C CNN
F 3 "" H 7950 5500 60  0000 C CNN
	1    7950 5500
	1    0    0    -1  
$EndComp
$Comp
L +BATT #PWR037
U 1 1 5B5BBB78
P 1150 4700
F 0 "#PWR037" H 1150 4550 50  0001 C CNN
F 1 "+BATT" H 1150 4840 50  0000 C CNN
F 2 "" H 1150 4700 60  0000 C CNN
F 3 "" H 1150 4700 60  0000 C CNN
	1    1150 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 4750 1150 4700
Wire Wire Line
	1450 5150 1700 5150
Text Notes 7100 6150 0    39   ~ 0
Reutilizando fonte 3.3V interna
Connection ~ 3750 2350
Wire Wire Line
	3750 2250 3750 2350
Wire Wire Line
	3800 2250 3750 2250
Text GLabel 3800 2250 2    39   Input ~ 0
FIRM_UPDADE_RESET
Text GLabel 3800 1400 2    39   Input ~ 0
FIRM_UPDADE_SCK
Text GLabel 3800 1300 2    39   Input ~ 0
FIRM_UPDADE_MISO
Text GLabel 3800 1200 2    39   Input ~ 0
FIRM_UPDADE_MOSI
$Comp
L CONN_01X06 P4
U 1 1 5B5CD6A6
P 6500 1100
F 0 "P4" H 6500 1450 50  0000 C CNN
F 1 "CONN_01X06" V 6600 1100 50  0000 C CNN
F 2 "" H 6500 1100 60  0001 C CNN
F 3 "" H 6500 1100 60  0000 C CNN
	1    6500 1100
	-1   0    0    -1  
$EndComp
Text GLabel 6750 850  2    39   Input ~ 0
FIRM_UPDADE_MISO
Text GLabel 6750 1050 2    39   Input ~ 0
FIRM_UPDADE_SCK
Text GLabel 6750 1250 2    39   Input ~ 0
FIRM_UPDADE_RESET
$Comp
L GND #PWR038
U 1 1 5B5D4531
P 6750 1350
F 0 "#PWR038" H 6750 1100 50  0001 C CNN
F 1 "GND" V 6750 1150 50  0000 C CNN
F 2 "" H 6750 1350 60  0000 C CNN
F 3 "" H 6750 1350 60  0000 C CNN
	1    6750 1350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6750 1350 6700 1350
Wire Wire Line
	6700 1250 6750 1250
Wire Wire Line
	6750 1150 6700 1150
Wire Wire Line
	6700 1050 6750 1050
Wire Wire Line
	6750 950  6700 950 
Wire Wire Line
	6700 850  6750 850 
Text GLabel 6750 1150 2    39   Input ~ 0
FIRM_UPDADE_MOSI
$Comp
L VCC #PWR039
U 1 1 5B5DD06D
P 4850 900
F 0 "#PWR039" H 4850 750 50  0001 C CNN
F 1 "VCC" H 4850 1050 50  0000 C CNN
F 2 "" H 4850 900 60  0000 C CNN
F 3 "" H 4850 900 60  0000 C CNN
	1    4850 900 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR040
U 1 1 5B5CCD85
P 10550 2800
F 0 "#PWR040" H 10550 2550 50  0001 C CNN
F 1 "GND" V 10550 2600 50  0000 C CNN
F 2 "" H 10550 2800 60  0000 C CNN
F 3 "" H 10550 2800 60  0000 C CNN
	1    10550 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 2750 10550 2750
$Comp
L ATMEGA328P-A IC1
U 1 1 5B58A5E0
P 2200 2000
F 0 "IC1" H 1450 3250 40  0000 L BNN
F 1 "ATMEGA328P-A" H 2600 600 40  0000 L BNN
F 2 "PCB:32A" H 2200 2000 30  0000 C CIN
F 3 "" H 2200 2000 60  0000 C CNN
	1    2200 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 2350 1300 2350
Text GLabel 9750 2650 1    39   Input ~ 0
IR_RECEPTOR
Wire Wire Line
	9650 2750 9900 2750
$Comp
L VCC #PWR041
U 1 1 5B5D7001
P 9300 2700
F 0 "#PWR041" H 9300 2550 50  0001 C CNN
F 1 "VCC" H 9300 2850 50  0000 C CNN
F 2 "" H 9300 2700 60  0000 C CNN
F 3 "" H 9300 2700 60  0000 C CNN
	1    9300 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 2750 9300 2750
Wire Wire Line
	9300 2750 9300 2700
Wire Wire Line
	9750 2650 9750 3000
Connection ~ 9750 2750
Wire Wire Line
	10550 2750 10550 2800
Wire Wire Line
	10200 3000 10350 3000
Wire Wire Line
	10350 3000 10350 2750
Connection ~ 10350 2750
Wire Wire Line
	9750 3000 9900 3000
Text GLabel 1200 2350 0    39   Input ~ 0
IR_RECEPTOR
$Comp
L R R4
U 1 1 5B5EE3DA
P 9500 2750
F 0 "R4" V 9580 2750 50  0000 C CNN
F 1 "300K" V 9500 2750 50  0000 C CNN
F 2 "" V 9430 2750 30  0000 C CNN
F 3 "" H 9500 2750 30  0000 C CNN
	1    9500 2750
	0    1    1    0   
$EndComp
$Comp
L D D1
U 1 1 5B5EF568
P 10050 2750
F 0 "D1" H 10050 2850 50  0000 C CNN
F 1 "D" H 10050 2650 50  0000 C CNN
F 2 "" H 10050 2750 60  0000 C CNN
F 3 "" H 10050 2750 60  0000 C CNN
	1    10050 2750
	-1   0    0    1   
$EndComp
$Comp
L C C5
U 1 1 5B5F0398
P 10050 3000
F 0 "C5" H 10075 3100 50  0000 L CNN
F 1 "100nF" H 10075 2900 50  0000 L CNN
F 2 "" H 10088 2850 30  0000 C CNN
F 3 "" H 10050 3000 60  0000 C CNN
	1    10050 3000
	0    1    1    0   
$EndComp
$Comp
L CONN_01X02 P5
U 1 1 5B5F35D1
P 2550 4600
F 0 "P5" H 2550 4750 50  0000 C CNN
F 1 "CONN_CARR" V 2650 4600 50  0000 C CNN
F 2 "" H 2550 4600 60  0000 C CNN
F 3 "" H 2550 4600 60  0000 C CNN
	1    2550 4600
	-1   0    0    1   
$EndComp
Text Notes 3200 3000 0    39   ~ 0
*
Text Notes 3200 2600 0    39   ~ 0
*
Text Notes 3200 2500 0    39   ~ 0
*
Text Notes 3200 2250 0    39   ~ 0
*
Text Notes 3200 2150 0    39   ~ 0
*
Text Notes 3200 1600 0    39   ~ 0
*
Text Notes 3200 1500 0    39   ~ 0
*
Text Notes 3200 1400 0    39   ~ 0
*
Text Notes 3200 1300 0    39   ~ 0
*
Text Notes 3200 1200 0    39   ~ 0
*
Text Notes 3200 2350 0    39   ~ 0
*
$EndSCHEMATC
