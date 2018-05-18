EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
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
L Jack-DC J?
U 1 1 5AFD7EE6
P 2050 2000
F 0 "J?" H 2050 2210 50  0000 C CNN
F 1 "Jack-DC" H 2050 1825 50  0000 C CNN
F 2 "" H 2100 1960 50  0001 C CNN
F 3 "" H 2100 1960 50  0001 C CNN
	1    2050 2000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5AFD7F7B
P 2550 2250
F 0 "#PWR?" H 2550 2000 50  0001 C CNN
F 1 "GND" H 2550 2100 50  0000 C CNN
F 2 "" H 2550 2250 50  0001 C CNN
F 3 "" H 2550 2250 50  0001 C CNN
	1    2550 2250
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 5AFD7F98
P 2550 1800
F 0 "#PWR?" H 2550 1650 50  0001 C CNN
F 1 "VCC" H 2550 1950 50  0000 C CNN
F 2 "" H 2550 1800 50  0001 C CNN
F 3 "" H 2550 1800 50  0001 C CNN
	1    2550 1800
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x08_Female J?
U 1 1 5AFD7FB4
P 7300 4800
F 0 "J?" H 7300 5200 50  0000 C CNN
F 1 "Conn_01x08_Female" H 7300 4300 50  0000 C CNN
F 2 "" H 7300 4800 50  0001 C CNN
F 3 "" H 7300 4800 50  0001 C CNN
	1    7300 4800
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x08_Female J?
U 1 1 5AFD8243
P 8100 4800
F 0 "J?" H 8100 5200 50  0000 C CNN
F 1 "Conn_01x08_Female" H 8100 4300 50  0000 C CNN
F 2 "" H 8100 4800 50  0001 C CNN
F 3 "" H 8100 4800 50  0001 C CNN
	1    8100 4800
	-1   0    0    -1  
$EndComp
$Comp
L Conn_01x15_Female J?
U 1 1 5AFD8298
P 2900 5250
F 0 "J?" H 2900 6050 50  0000 C CNN
F 1 "Conn_01x15_Female" H 2900 4450 50  0000 C CNN
F 2 "" H 2900 5250 50  0001 C CNN
F 3 "" H 2900 5250 50  0001 C CNN
	1    2900 5250
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x15_Female J?
U 1 1 5AFD837D
P 3750 5250
F 0 "J?" H 3750 6050 50  0000 C CNN
F 1 "Conn_01x15_Female" H 3750 4450 50  0000 C CNN
F 2 "" H 3750 5250 50  0001 C CNN
F 3 "" H 3750 5250 50  0001 C CNN
	1    3750 5250
	-1   0    0    -1  
$EndComp
$Comp
L LM7805_TO220 U?
U 1 1 5AFD841A
P 6000 1750
F 0 "U?" H 5850 1875 50  0000 C CNN
F 1 "LM7805_TO220" H 6000 1875 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220_Vertical" H 6000 1975 50  0001 C CIN
F 3 "" H 6000 1700 50  0001 C CNN
	1    6000 1750
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5AFD84C3
P 5400 2150
F 0 "C?" H 5425 2250 50  0000 L CNN
F 1 "C" H 5425 2050 50  0000 L CNN
F 2 "" H 5438 2000 50  0001 C CNN
F 3 "" H 5400 2150 50  0001 C CNN
	1    5400 2150
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5AFD85A1
P 6600 2150
F 0 "C?" H 6625 2250 50  0000 L CNN
F 1 "C" H 6625 2050 50  0000 L CNN
F 2 "" H 6638 2000 50  0001 C CNN
F 3 "" H 6600 2150 50  0001 C CNN
	1    6600 2150
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 5AFD878C
P 3000 2000
F 0 "C?" H 3025 2100 50  0000 L CNN
F 1 "CP" H 3025 1900 50  0000 L CNN
F 2 "" H 3038 1850 50  0001 C CNN
F 3 "" H 3000 2000 50  0001 C CNN
	1    3000 2000
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 5AFD886B
P 7000 2100
F 0 "C?" H 7025 2200 50  0000 L CNN
F 1 "CP" H 7025 2000 50  0000 L CNN
F 2 "" H 7038 1950 50  0001 C CNN
F 3 "" H 7000 2100 50  0001 C CNN
	1    7000 2100
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 5AFD89BB
P 8750 4500
F 0 "C?" H 8775 4600 50  0000 L CNN
F 1 "100uF" H 8775 4400 50  0000 L CNN
F 2 "" H 8788 4350 50  0001 C CNN
F 3 "" H 8750 4500 50  0001 C CNN
	1    8750 4500
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5AFD8D7F
P 6000 2450
F 0 "#PWR?" H 6000 2200 50  0001 C CNN
F 1 "GND" H 6000 2300 50  0000 C CNN
F 2 "" H 6000 2450 50  0001 C CNN
F 3 "" H 6000 2450 50  0001 C CNN
	1    6000 2450
	1    0    0    -1  
$EndComp
$Comp
L CP C?
U 1 1 5AFD8DA6
P 4900 2100
F 0 "C?" H 4925 2200 50  0000 L CNN
F 1 "CP" H 4925 2000 50  0000 L CNN
F 2 "" H 4938 1950 50  0001 C CNN
F 3 "" H 4900 2100 50  0001 C CNN
	1    4900 2100
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x04_Female J?
U 1 1 5AFD8E73
P 10050 1950
F 0 "J?" H 10050 2150 50  0000 C CNN
F 1 "Conn_01x04_Female" H 10050 1650 50  0000 C CNN
F 2 "" H 10050 1950 50  0001 C CNN
F 3 "" H 10050 1950 50  0001 C CNN
	1    10050 1950
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 5AFD947A
P 4900 1650
F 0 "#PWR?" H 4900 1500 50  0001 C CNN
F 1 "VCC" H 4900 1800 50  0000 C CNN
F 2 "" H 4900 1650 50  0001 C CNN
F 3 "" H 4900 1650 50  0001 C CNN
	1    4900 1650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5AFD97A2
P 8850 5600
F 0 "#PWR?" H 8850 5350 50  0001 C CNN
F 1 "GND" H 8850 5450 50  0000 C CNN
F 2 "" H 8850 5600 50  0001 C CNN
F 3 "" H 8850 5600 50  0001 C CNN
	1    8850 5600
	1    0    0    -1  
$EndComp
Text GLabel 7100 1750 2    60   Input ~ 0
VCC_5V
$Comp
L GND #PWR?
U 1 1 5AFD9FFE
P 9000 4500
F 0 "#PWR?" H 9000 4250 50  0001 C CNN
F 1 "GND" H 9000 4350 50  0000 C CNN
F 2 "" H 9000 4500 50  0001 C CNN
F 3 "" H 9000 4500 50  0001 C CNN
	1    9000 4500
	0    -1   -1   0   
$EndComp
Text GLabel 9450 2150 0    60   Input ~ 0
White_B'
Text GLabel 9450 2050 0    60   Input ~ 0
Green_B
Text GLabel 9450 1950 0    60   Input ~ 0
Red_A'
Text GLabel 9450 1850 0    60   Input ~ 0
Brown_A
Text GLabel 9000 4700 2    60   Input ~ 0
Brown_A
Text GLabel 9000 4800 2    60   Input ~ 0
Red_A'
Text GLabel 9000 4900 2    60   Input ~ 0
Green_B
Text GLabel 9000 5000 2    60   Input ~ 0
White_B'
$Comp
L VCC #PWR?
U 1 1 5AFDAC35
P 8500 4200
F 0 "#PWR?" H 8500 4050 50  0001 C CNN
F 1 "VCC" H 8500 4350 50  0000 C CNN
F 2 "" H 8500 4200 50  0001 C CNN
F 3 "" H 8500 4200 50  0001 C CNN
	1    8500 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5AFDB15F
P 8400 5200
F 0 "#PWR?" H 8400 4950 50  0001 C CNN
F 1 "GND" H 8400 5050 50  0000 C CNN
F 2 "" H 8400 5200 50  0001 C CNN
F 3 "" H 8400 5200 50  0001 C CNN
	1    8400 5200
	0    -1   -1   0   
$EndComp
$Comp
L CP C?
U 1 1 5AFDB238
P 8850 5350
F 0 "C?" H 8875 5450 50  0000 L CNN
F 1 "CP" H 8875 5250 50  0000 L CNN
F 2 "" H 8888 5200 50  0001 C CNN
F 3 "" H 8850 5350 50  0001 C CNN
	1    8850 5350
	1    0    0    -1  
$EndComp
Text GLabel 6700 4600 0    60   Input ~ 0
MS1
Text GLabel 6700 4700 0    60   Input ~ 0
MS2
Text GLabel 6700 4800 0    60   Input ~ 0
MS3
Text GLabel 6700 5100 0    60   Input ~ 0
STEP
Text GLabel 6700 5200 0    60   Input ~ 0
DIR
Text GLabel 2300 4550 0    60   Input ~ 0
VCC_3V3
Text GLabel 9000 5100 2    60   Input ~ 0
VCC_3V3
$Comp
L GND #PWR?
U 1 1 5AFDBDB5
P 2450 4650
F 0 "#PWR?" H 2450 4400 50  0001 C CNN
F 1 "GND" H 2450 4500 50  0000 C CNN
F 2 "" H 2450 4650 50  0001 C CNN
F 3 "" H 2450 4650 50  0001 C CNN
	1    2450 4650
	0    1    1    0   
$EndComp
Text GLabel 2300 5950 0    60   Input ~ 0
MS1
Text GLabel 2300 5850 0    60   Input ~ 0
MS2
Text GLabel 2300 5750 0    60   Input ~ 0
MS3
Text GLabel 2300 5250 0    60   Input ~ 0
STEP
Text GLabel 2300 5150 0    60   Input ~ 0
DIR
Text GLabel 4250 4550 2    60   Input ~ 0
VCC_5V
$Comp
L GND #PWR?
U 1 1 5AFDC2CF
P 4250 4650
F 0 "#PWR?" H 4250 4400 50  0001 C CNN
F 1 "GND" H 4250 4500 50  0000 C CNN
F 2 "" H 4250 4650 50  0001 C CNN
F 3 "" H 4250 4650 50  0001 C CNN
	1    4250 4650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2350 2100 2750 2100
Wire Wire Line
	2550 2100 2550 2250
Wire Wire Line
	2350 1900 2750 1900
Wire Wire Line
	2550 1900 2550 1800
Wire Wire Line
	9450 1850 9850 1850
Wire Wire Line
	9450 1950 9850 1950
Wire Wire Line
	9450 2050 9850 2050
Wire Wire Line
	9450 2150 9850 2150
Wire Wire Line
	8600 4500 8300 4500
Wire Wire Line
	4900 1750 5700 1750
Wire Wire Line
	4900 1650 4900 1950
Connection ~ 4900 1750
Wire Wire Line
	5400 2000 5400 1750
Connection ~ 5400 1750
Wire Wire Line
	6000 2450 6000 2050
Wire Wire Line
	6300 1750 7100 1750
Wire Wire Line
	6600 1750 6600 2000
Connection ~ 6600 1750
Wire Wire Line
	4900 2350 7000 2350
Wire Wire Line
	5400 2350 5400 2300
Connection ~ 6000 2350
Wire Wire Line
	6600 2350 6600 2300
Wire Wire Line
	7000 2350 7000 2250
Connection ~ 6600 2350
Wire Wire Line
	4900 2350 4900 2250
Connection ~ 5400 2350
Wire Wire Line
	7100 5000 7000 5000
Wire Wire Line
	7000 5000 7000 4900
Wire Wire Line
	7000 4900 7100 4900
Wire Wire Line
	6700 5200 7100 5200
Wire Wire Line
	6700 5100 7100 5100
Wire Wire Line
	6700 4800 7100 4800
Wire Wire Line
	6700 4700 7100 4700
Wire Wire Line
	6700 4600 7100 4600
Wire Wire Line
	7000 1750 7000 1950
Connection ~ 7000 1750
Wire Wire Line
	8500 4200 8500 4500
Connection ~ 8500 4500
Wire Wire Line
	8900 4500 9000 4500
Wire Wire Line
	8300 4700 9000 4700
Wire Wire Line
	8300 4800 9000 4800
Wire Wire Line
	8300 4900 9000 4900
Wire Wire Line
	8300 5000 9000 5000
Wire Wire Line
	8300 4600 8950 4600
Wire Wire Line
	8950 4600 8950 4500
Connection ~ 8950 4500
Wire Wire Line
	8850 5500 8850 5600
Wire Wire Line
	8300 5100 9000 5100
Wire Wire Line
	8850 5100 8850 5200
Connection ~ 8850 5100
Wire Wire Line
	8300 5200 8400 5200
Wire Wire Line
	2300 4550 2700 4550
Wire Wire Line
	2450 4650 2700 4650
Wire Wire Line
	2300 5150 2700 5150
Wire Wire Line
	2300 5250 2700 5250
Wire Wire Line
	2300 5950 2700 5950
Wire Wire Line
	2300 5850 2700 5850
Wire Wire Line
	2300 5750 2700 5750
Wire Wire Line
	3950 4550 4250 4550
Wire Wire Line
	3950 4650 4250 4650
Wire Wire Line
	3000 1850 3000 1800
Wire Wire Line
	3000 1800 2750 1800
Wire Wire Line
	2750 1800 2750 1900
Connection ~ 2550 1900
Wire Wire Line
	3000 2150 3000 2200
Wire Wire Line
	3000 2200 2750 2200
Wire Wire Line
	2750 2200 2750 2100
Connection ~ 2550 2100
$EndSCHEMATC
