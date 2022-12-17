EESchema Schematic File Version 4
EELAYER 30 0
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
L tft_spi:TFT_SPI HW?
U 1 1 6382FDBB
P 2700 900
F 0 "HW?" H 2833 265 50  0000 C CNN
F 1 "TFT_Touch-SPI" H 2833 174 50  0000 C CNN
F 2 "" H 2700 850 50  0001 C CNN
F 3 "" H 2700 850 50  0001 C CNN
	1    2700 900 
	1    0    0    -1  
$EndComp
$Comp
L sds011:SDS011 HW?
U 1 1 63830A2D
P 1250 1750
F 0 "HW?" H 1308 1915 50  0000 C CNN
F 1 "SDS011-UART" H 1308 1824 50  0000 C CNN
F 2 "" H 1250 1800 50  0001 C CNN
F 3 "" H 1250 1800 50  0001 C CNN
	1    1250 1750
	1    0    0    -1  
$EndComp
$Comp
L bmc280:BMC280 HW?
U 1 1 6383174B
P 2750 700
F 0 "HW?" H 2883 815 50  0000 C CNN
F 1 "BMC280-I²C" H 2883 724 50  0000 C CNN
F 2 "" H 2800 700 50  0001 C CNN
F 3 "" H 2800 700 50  0001 C CNN
	1    2750 700 
	1    0    0    -1  
$EndComp
$Comp
L ESP8266:NodeMCU_1.0_(ESP-12E) U?
U 1 1 638325AB
P 5850 4550
F 0 "U?" H 5850 5637 60  0000 C CNN
F 1 "NodeMCU_1.0_(ESP-12E)" H 5850 5531 60  0000 C CNN
F 2 "" H 5250 3700 60  0000 C CNN
F 3 "" H 5250 3700 60  0000 C CNN
	1    5850 4550
	1    0    0    -1  
$EndComp
NoConn ~ 3150 3100
NoConn ~ 3150 2600
NoConn ~ 1600 1850
NoConn ~ 1600 1950
NoConn ~ 1600 2150
Text GLabel 5050 4250 0    50   Input ~ 0
TFT-LED
Text GLabel 4950 2600 2    50   Input ~ 0
MISO
Text GLabel 6650 4650 2    50   Input ~ 0
MISO
Text GLabel 6650 4750 2    50   Input ~ 0
MOSI
Text GLabel 6650 4550 2    50   Input ~ 0
SCK
Text GLabel 4950 2300 2    50   Input ~ 0
MOSI
Text GLabel 4950 1900 2    50   Input ~ 0
GND
Text GLabel 4950 2100 2    50   Input ~ 0
RESET
Text GLabel 4950 1800 2    50   Input ~ 0
VCC-5V
Text GLabel 5050 5250 0    50   Input ~ 0
VCC-5V
Text GLabel 5050 5150 0    50   Input ~ 0
GND
Text GLabel 5050 5050 0    50   Input ~ 0
RESET
Text GLabel 3150 850  2    50   Input ~ 0
VCC-3.3V
Text GLabel 3150 950  2    50   Input ~ 0
GND
Text GLabel 1600 2050 2    50   Input ~ 0
VCC-5V
Text GLabel 1600 2250 2    50   Input ~ 0
GND
Text GLabel 1600 2350 2    50   Input ~ 0
ESP-TX
Text GLabel 1600 2450 2    50   Input ~ 0
ESP-RX
Text GLabel 4950 2400 2    50   Input ~ 0
SCK
Text GLabel 6650 4150 2    50   Input ~ 0
DC
Text GLabel 6650 4850 2    50   Input ~ 0
CS
Text GLabel 4950 2000 2    50   Input ~ 0
CS
Text GLabel 6650 4950 2    50   Input ~ 0
ESP-RX
Text GLabel 6650 5050 2    50   Input ~ 0
ESP-TX
$Comp
L ESP32:ESP32-WROOM-32 U?
U 1 1 639AF3AF
P 1850 5850
F 0 "U?" H 1850 7317 50  0000 C CNN
F 1 "ESP32-WROOM-32" H 1850 7226 50  0000 C CNN
F 2 "RF_Module:ESP32-WROOM-32" H 1850 4350 50  0001 C CNN
F 3 "https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf" H 1550 5900 50  0001 C CNN
	1    1850 5850
	1    0    0    -1  
$EndComp
Text GLabel 1250 5250 0    50   Input ~ 0
GND
Text GLabel 3650 5100 0    50   Input ~ 0
RESET
Text GLabel 3150 1050 2    50   Input ~ 0
BME_SCL
Text GLabel 2450 6150 2    50   Input ~ 0
BME_SCL
Text GLabel 3150 1150 2    50   Input ~ 0
BME_SDA
Text GLabel 2450 6050 2    50   Input ~ 0
BME_SDA
Text GLabel 6650 5250 2    50   Input ~ 0
VCC-3.3V
Text GLabel 1250 5150 0    50   Input ~ 0
VCC-3.3V
Text GLabel 1250 5050 0    50   Input ~ 0
VCC-5V
Text GLabel 2450 5650 2    50   Input ~ 0
ESP-RX
Text GLabel 2450 5750 2    50   Input ~ 0
ESP-TX
NoConn ~ 1250 5850
NoConn ~ 1250 5950
NoConn ~ 1250 6050
NoConn ~ 1250 6150
NoConn ~ 1250 6250
NoConn ~ 1250 6350
NoConn ~ 1250 4850
NoConn ~ 1250 4950
NoConn ~ 2450 4650
NoConn ~ 2450 4750
NoConn ~ 2450 5150
NoConn ~ 2450 5250
NoConn ~ 2450 5350
NoConn ~ 2450 5450
NoConn ~ 2450 6350
NoConn ~ 2450 6450
NoConn ~ 2450 6550
NoConn ~ 2450 6650
NoConn ~ 2450 6750
NoConn ~ 2450 6850
NoConn ~ 2450 6950
NoConn ~ 6650 3850
NoConn ~ 6650 3950
NoConn ~ 6650 4050
NoConn ~ 6650 4250
NoConn ~ 6650 4350
NoConn ~ 6650 4450
NoConn ~ 6650 5150
NoConn ~ 5050 4950
NoConn ~ 5050 4850
NoConn ~ 5050 4750
NoConn ~ 5050 4650
NoConn ~ 5050 4550
NoConn ~ 5050 4450
NoConn ~ 5050 4350
NoConn ~ 5050 4150
NoConn ~ 5050 4050
NoConn ~ 5050 3950
NoConn ~ 5050 3850
Wire Wire Line
	2450 4850 2850 4850
Wire Wire Line
	2950 5050 2450 5050
Text Label 2500 4850 0    50   ~ 0
TFT_DC
Text Label 2500 5050 0    50   ~ 0
TFT_LED
Text Label 2550 5550 0    50   ~ 0
CS
Text Label 2850 5850 0    50   ~ 0
SCK
Text Label 2600 5950 0    50   ~ 0
MISO
Text Label 2900 6250 0    50   ~ 0
MOSI
Text GLabel 3650 4900 0    50   Input ~ 0
GND
Text GLabel 4950 2500 2    50   Input ~ 0
TFT_LED
Text GLabel 4950 2200 2    50   Input ~ 0
TFT_DC
Text Label 3750 2200 0    50   ~ 0
TFT_DC
Text Label 3750 2500 0    50   ~ 0
TFT_LED
Text Label 3750 2000 0    50   ~ 0
CS
Text Label 3750 2400 0    50   ~ 0
SCK
Text Label 3850 2600 0    50   ~ 0
MISO
Text Label 3750 2300 0    50   ~ 0
MOSI
Text Label 3750 2100 0    50   ~ 0
RST
Wire Wire Line
	3150 1800 4550 1800
Wire Wire Line
	3150 2100 4550 2100
Wire Wire Line
	3150 2200 4550 2200
$Comp
L Connector:Conn_01x10_Female J?
U 1 1 639E8EB5
P 4750 2200
F 0 "J?" H 4700 2850 50  0000 L CNN
F 1 "Conn_01x10_Female" H 4350 2750 50  0000 L CNN
F 2 "" H 4750 2200 50  0001 C CNN
F 3 "~" H 4750 2200 50  0001 C CNN
	1    4750 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 2500 4550 2500
NoConn ~ 4550 2700
Text Label 3150 2700 0    50   ~ 0
SCK
Wire Wire Line
	3150 2400 3350 2400
Wire Wire Line
	3150 1900 3500 1900
Wire Wire Line
	3350 2700 3350 2400
Wire Wire Line
	3150 2700 3350 2700
Connection ~ 3350 2400
Wire Wire Line
	3350 2400 4550 2400
Wire Wire Line
	3150 2300 3650 2300
Wire Wire Line
	3150 2800 3500 2800
Text Label 3150 2800 0    50   ~ 0
CS
Wire Wire Line
	3650 2900 3650 2300
Wire Wire Line
	3150 2900 3650 2900
Connection ~ 3650 2300
Wire Wire Line
	3650 2300 4550 2300
Text Label 3150 2900 0    50   ~ 0
MOSI
Wire Wire Line
	3800 3000 3800 2600
Wire Wire Line
	3150 3000 3800 3000
Wire Wire Line
	3800 2600 4550 2600
$Comp
L Connector:Conn_01x10_Male J?
U 1 1 639FAC0C
P 3850 5200
F 0 "J?" H 4050 5850 50  0000 R CNN
F 1 "Conn_01x10_Male" H 4350 5750 50  0000 R CNN
F 2 "" H 3850 5200 50  0001 C CNN
F 3 "~" H 3850 5200 50  0001 C CNN
	1    3850 5200
	-1   0    0    -1  
$EndComp
Text GLabel 3650 4800 0    50   Input ~ 0
VCC-5V
Wire Wire Line
	3050 5550 2450 5550
Wire Wire Line
	3650 5000 3050 5000
Wire Wire Line
	3050 5000 3050 5550
Text GLabel 1250 4650 0    50   Input ~ 0
RESET
Wire Wire Line
	2850 4850 2850 5200
Wire Wire Line
	2850 5200 3650 5200
Wire Wire Line
	3650 5300 3400 5300
Wire Wire Line
	3400 5300 3400 6250
Wire Wire Line
	2450 6250 3400 6250
Wire Wire Line
	3200 5850 3200 5400
Wire Wire Line
	3200 5400 3650 5400
Wire Wire Line
	2450 5850 3200 5850
Wire Wire Line
	2950 5050 2950 5500
Wire Wire Line
	2950 5500 3650 5500
Wire Wire Line
	3300 5950 3300 5600
Wire Wire Line
	3300 5600 3650 5600
Wire Wire Line
	2450 5950 3300 5950
Text GLabel 3950 5600 2    50   Input ~ 0
MISO
Text GLabel 3950 5300 2    50   Input ~ 0
MOSI
Text GLabel 3950 5400 2    50   Input ~ 0
SCK
Text GLabel 3950 5500 2    50   Input ~ 0
TFT_LED
Text GLabel 3950 5200 2    50   Input ~ 0
TFT_DC
Text GLabel 3950 5000 2    50   Input ~ 0
CS
$Comp
L Device:CP C?
U 1 1 63A0C951
P 1550 3800
F 0 "C?" V 1805 3800 50  0000 C CNN
F 1 "CP" V 1714 3800 50  0000 C CNN
F 2 "" H 1588 3650 50  0001 C CNN
F 3 "~" H 1550 3800 50  0001 C CNN
	1    1550 3800
	0    -1   -1   0   
$EndComp
Text GLabel 1400 3800 0    50   Input ~ 0
VCC-5V
Text GLabel 1700 3800 2    50   Input ~ 0
GND
Wire Wire Line
	3150 2000 4550 2000
Wire Wire Line
	3500 2800 3500 1900
Connection ~ 3500 1900
Wire Wire Line
	3500 1900 4550 1900
$EndSCHEMATC
