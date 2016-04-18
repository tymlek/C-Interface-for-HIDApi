#ifndef MY_USB_H
#define MY_USB_H

#include <cstdlib>
#include <cstdio>
#include <exception>

#ifdef WIN32
	// Windows
	#include <Windows.h>
	#include <sys/types.h>
#else
	// Linux
	#include <unistd.h>
	#define Sleep(v) usleep(v*1000)
#endif

#include "hidapi.h"


//instructions
#define _mod_ver  "0.51x0.01"	// python HKUSBIO module version
#define _mod_date "2/25/2013x11/16/2013/"	// module date
#define u_ad0 0x37	// read ADC value from RA0
#define u_ad1 0x38	// read ADC value from RA1
#define u_i2c_init 0x40	// i2c_init(void)
#define u_i2c_idle 0x41	// i2c_idle(void)
#define u_i2c_strt 0x42	// i2c_start(uchar)
#define u_i2c_stop 0x43	// i2c_stop(void)
#define u_i2c_slak 0x44	// uchar i2c_slave_ack(void)
#define u_i2c_writ 0x45	// void i2c_write(uchar)
#define u_i2c_mack 0x46	// void i2c_master_ack(uchar)
#define u_i2c_read 0x47	// uchar i2c_read(void)
#define u_i2c_dtrd 0x48	// uchar i2c_isdatardy(void)
#define u_spi_init 0x50	// void spi_init(mode, baud, sample)
#define u_spi_tran 0x51	// uchar spi_transfer(regAddr)
#define u_spi_cs 0x52	// void spi_cs(enable|disable)
#define u_rom 0x85	// get PIC rom version
#define u_led 0x80	// toggle LED 
#define u_swc 0x81	// get switch pressed or not
#define u_gpd 0x84	// configure GPIO direction on a pin
#define u_gpi 0x82	// read value on GPIO pin
#define u_gpo 0x83	// write value to GPIO pin
#define u_uss 0x86	// send a string to the UART
#define u_tst 0x87	// test if UART has a char available
#define u_urc 0x88	// read a single char from UART
#define u_usc 0x89	// send a single char to the UART
#define h_getr 0x98	// SFR register to read
#define h_setr 0x99	// SFR register to set
#define h_getb 0x9a	// SFR read register bit
#define h_setb 0x9b	// SFR set register bit

//registers
#define INTCON 0xf2   
#define INTCON2 0xf1  
#define INTCON3 0xf0 
#define SSP1CON3 0xcb 
#define SSP1MSK 0xca  
#define SSP1BUF 0xc9  
#define SSP1ADD 0xc8 
#define SSP1STAT 0xc7
#define SSP1CON1 0xc6 
#define SSP1CON2 0xc5 
#define TMR2 0xbc    
#define T2CON 0xba    
#define PSTR1CON 0xb9 
#define BAUDCON1 0xb8 
#define PWM1CON 0xb7 
#define SPBRGH1 0xb0
#define TRISE 0x96    
#define TRISD 0x95    
#define TRISC 0x94   
#define TRISB 0x93    
#define TRISA 0x92    
#define LATE 0x8d     
#define LATD 0x8c    
#define LATC 0x8b 
#define LATB 0x8a     
#define LATA 0x89     
#define PORTE 0x84   
#define PORTD 0x83    
#define PORTC 0x82   
#define PORTB 0x81    
#define PORTA 0x80   
#define ANSELE 0x5f
#define ANSELD 0x5e   
#define ANSELC 0x5d   
#define ANSELB 0x5c  
#define ANSELA 0x5b   
#define GP_RAM1 0x52  
#define GP_RAM2 0x51  
#define GP_RAM3 0x50 
#define GP_RAM4 0x4f
#define SPBRG1 0xaf   
#define CCPTMRS 0x59  
#define CCP1CON 0xbd 
#define CCPR1H 0xbf   
#define CCPR1L 0xbe   
#define T2CON 0xba    
#define PR2 0xbb 
#define VREFCON1 0x7c
#define VREFCON2 0x7b 
#define VREFCON0 0x7d 
#define ADCON0  0xc2

//bits
#define SSP1STAT_SMP 7 
#define SSP1STAT_CKE 6 
#define SSP1STAT_BF 0 
#define SSP1CON1_WCOL 7 
#define SSP1CON1_SSPOV 6 
#define SSP1CON1_SSPEN 5 
#define SSP1CON1_CKP 4
#define VREFCON1_DACEN 7 
#define VREFCON1_DACLPS 6 
#define VREFCON1_DACOE 5 
#define VREFCON1_DACNSS 0 
#define VREFCON1_DACPSS1 3 
#define VREFCON1_DACPSS0 2

//constants
#define rd4 1		// GPIO pin rd4	def=input
#define rd5 2		// GPIO pin rd5	def=input
#define rd6 3		// GPIO pin rd6	def=output
#define rd7 4		// GPIO pin rd7	def=output
#define pwm_rd5 2
#define pwm_rd6 3
#define pwm_rd7 4
#define pwm_rc1 5
#define dir_output 0	// control GPIO pin direction
#define dir_input 1
#define SPI_LOW_BAUD 0// 750khz
#define SPI_MED_BAUD 1// 3mhz
#define SPI_HI_BAUD  2// 12mhz
#define SPI_SAMP_MID 0// sample input in middle data input time
#define SPI_SAMP_END 1// sample input at end of data input
#define SPI_MODE0 0
#define SPI_MODE1 1
#define SPI_MODE2 2
#define SPI_MODE3 3
#define SPI_CS_ENABLE 0
#define SPI_CS_DISABLE 1
#define I2C_DATA_ACK 0	// i2c constants
#define I2C_DATA_NOACK 1
#define I2C_WRITE_CMD 0
#define I2C_READ_CMD 1
#define I2C_START_CMD 0
#define I2C_REP_START_CMD 1
#define I2C_REQ_ACK 0
#define I2C_REQ_NOACK 0

class DeviceNotDetected : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Device not detected";
	}
} DEVICE_NOT_DETECTED;

class OperatioinNotSuccessfull : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Operation not successfull";
	}
} OPERATION_NOT_SUCCESSFULL;

//buffer
#define MAX_STR 65

class HID_Device
{
private:
	hid_device* device;
public:
	HID_Device();
	HID_Device(unsigned short vendor_id, unsigned short product_id, const wchar_t* serial_number);
	~HID_Device();

	void gpio_init(unsigned char pin, unsigned char pdir);
	unsigned char gpio_in(char pin);
	void gpio_out(char pin, char state);

	void toggle_led();
	char read_switch();

	unsigned int adc_ra0();
	unsigned int adc_ra1();

	unsigned char sfr_get_reg(unsigned char reg);
	unsigned char sfr_set_reg(unsigned char reg, unsigned char rval);
	unsigned char sfr_get_regbit(unsigned char reg, unsigned char rbit);
	unsigned char sfr_set_regbit(unsigned char reg, unsigned char rbit, unsigned char bval);

	unsigned char ser_test();
	void ser_putc(char schar);
	void ser_puts(const char * strval);
	unsigned char ser_getc();

	void i2c_init();
	void i2c_idle();
	void i2c_start(char cval);
	void i2c_stop();
	unsigned char i2c_slave_ack();
	void i2c_write(char cval);
	void i2c_master_ack(char cval);
	unsigned char i2c_read();
	unsigned char i2c_isdatardy();

	void spi_init(unsigned char mode, unsigned char baud, unsigned char sample);
	unsigned char spi_transfer(unsigned char value);
	void spi_cs(unsigned char select);
};

//-----------------------------------------------------------------------------

HID_Device::HID_Device()
{
	device = hid_open(0x04D8, 0x003F, NULL);

	if (device) {
		hid_set_nonblocking(device, true);
	}
	else {
		throw DEVICE_NOT_DETECTED;
	}

}

//-----------------------------------------------------------------------------

HID_Device::HID_Device(unsigned short vendor_id, unsigned short product_id, const wchar_t* serial_number)
{
	device = hid_open(vendor_id, product_id, serial_number);

	if (device) {
		hid_set_nonblocking(device, true);
	}
	else {
		throw DEVICE_NOT_DETECTED;
	}
}

//-----------------------------------------------------------------------------

HID_Device::~HID_Device()
{
	hid_close(device);
}

//-----------------------------------------------------------------------------

void HID_Device::gpio_init(unsigned char pin, unsigned char pdir)
{
	unsigned char o_buf[MAX_STR];
	
	o_buf[0] = 0x00;
	o_buf[1] = u_gpd;
	o_buf[2] = pin;
	o_buf[3] = pdir;
	
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) {
		throw OPERATION_NOT_SUCCESSFULL;
	}
}

//-----------------------------------------------------------------------------

unsigned char HID_Device::gpio_in(char pin) {	// read value on GPIO pin
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_gpi;
	o_buf[2] = pin;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	return i_buf[1];
}

//-----------------------------------------------------------------------------

void HID_Device::gpio_out(char pin, char state) {	// otuput a value on GPIO pin
	unsigned char o_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_gpo;
	o_buf[2] = pin;
	o_buf[3] = state;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
}

//-----------------------------------------------------------------------------

void HID_Device::toggle_led() {	// toggle LED
	unsigned char o_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_led;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
}

//-----------------------------------------------------------------------------

char HID_Device::read_switch() {	// read switch press
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	char ret;
	o_buf[0] = 0x00;
	o_buf[1] = u_swc;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	if (i_buf[1] == 0) { ret = TRUE; }
	else { ret = FALSE; }
	return ret;
}

//-----------------------------------------------------------------------------


unsigned int HID_Device::adc_ra0() { // do ADC conversion on RA0
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	unsigned int a;
	o_buf[0] = 0x00;
	o_buf[1] = u_ad0;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	a = i_buf[2] << 8;
	a |= i_buf[1];
	return a;
}

//-----------------------------------------------------------------------------

unsigned int HID_Device::adc_ra1() {	// do ADC conversion on RA1
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	unsigned int a;
	o_buf[0] = 0x00;
	o_buf[1] = u_ad1;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	a = i_buf[2] << 8;
	a |= i_buf[1];
	return a;
}

//-----------------------------------------------------------------------------

unsigned char HID_Device::sfr_get_reg(unsigned char reg) {	// get a SFR register
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = h_getr;
	o_buf[11] = reg;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	return i_buf[1];
}

//-----------------------------------------------------------------------------

unsigned char HID_Device::sfr_set_reg(unsigned char reg, unsigned char rval) {	// set a SFR register
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = h_setr;
	o_buf[11] = reg;	// register to select
	o_buf[12] = rval;	// value to set
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	return i_buf[1];
}

//-----------------------------------------------------------------------------

unsigned char HID_Device::sfr_get_regbit(unsigned char reg, unsigned char rbit) {	// get a SFR register bit
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = h_getb;
	o_buf[11] = reg;	// register to select
	o_buf[12] = rbit;	// bit value to get
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	return i_buf[1];
}

//-----------------------------------------------------------------------------

unsigned char HID_Device::sfr_set_regbit(unsigned char reg, unsigned char rbit, unsigned char bval) {	// set a SFR register bit
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = h_setb;
	o_buf[11] = reg;	// register to select
	o_buf[12] = rbit;	// bit to set
	o_buf[13] = bval;	// bit value to set
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	return i_buf[1];
}

//-----------------------------------------------------------------------------

unsigned char HID_Device::ser_test() {	// check if a char available on serial port
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_tst;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	return i_buf[1];
}

//-----------------------------------------------------------------------------

void HID_Device::ser_putc(char schar) {	// send a char to the serial port
	unsigned char o_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_usc;
	o_buf[2] = schar;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
}

//-----------------------------------------------------------------------------

void HID_Device::ser_puts(const char * strval) {	// send a string to the serial port
	unsigned char o_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_uss;
	strcat((char*)o_buf, strval);
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
}

//-----------------------------------------------------------------------------

unsigned char HID_Device::ser_getc() { // get a single char from the serial port
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_urc;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	return i_buf[1];
}

//-----------------------------------------------------------------------------

void HID_Device::i2c_init() {	// init i2c
	unsigned char o_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_i2c_init;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
}

void HID_Device::i2c_idle() {	// i2c idle
	unsigned char o_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_i2c_idle;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
}

//-----------------------------------------------------------------------------

void HID_Device::i2c_start(char cval) {	// i2c start	
	unsigned char o_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_i2c_strt;
	o_buf[2] = cval;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
}

//-----------------------------------------------------------------------------

void HID_Device::i2c_stop() {	// i2c stop
	unsigned char o_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_i2c_stop;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
}

//-----------------------------------------------------------------------------

unsigned char HID_Device::i2c_slave_ack() {	// i2c slave ack
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_i2c_slak;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	return i_buf[1];	// 1=no ack, 0=ack
}

//-----------------------------------------------------------------------------

void HID_Device::i2c_write(char cval) {	// i2c write
	unsigned char o_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_i2c_writ;
	o_buf[2] = cval;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
}

//-----------------------------------------------------------------------------

void HID_Device::i2c_master_ack(char cval) {	// 1=nack, 0=ack
	unsigned char o_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_i2c_mack;
	o_buf[2] = cval;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
}

//-----------------------------------------------------------------------------

unsigned char HID_Device::i2c_read() {	// i2c read
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_i2c_read;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	return i_buf[1];	//i2c_read char

}

//-----------------------------------------------------------------------------

unsigned char HID_Device::i2c_isdatardy() {	// check if i2c char avail
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_i2c_dtrd;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	return i_buf[1]; //i2c_read char
}

//-----------------------------------------------------------------------------

void HID_Device::spi_init(unsigned char mode, unsigned char baud, unsigned char sample) {	// SPI init
	unsigned char o_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_spi_init;
	o_buf[2] = mode;
	o_buf[3] = baud;
	o_buf[4] = sample;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
}

//-----------------------------------------------------------------------------

unsigned char HID_Device::spi_transfer(unsigned char value) {	// SPI transfer 
	unsigned char o_buf[MAX_STR];
	unsigned char i_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_spi_tran;
	o_buf[2] = value;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	Sleep(50);
	if (hid_read(device, i_buf, sizeof(i_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
	return i_buf[1];
}

//-----------------------------------------------------------------------------

void HID_Device::spi_cs(unsigned char select) {	// enable or disable SPI CS
	unsigned char o_buf[MAX_STR];
	o_buf[0] = 0x00;
	o_buf[1] = u_spi_cs;
	o_buf[2] = select;
	if (hid_write(device, o_buf, sizeof(o_buf)) == -1) { throw OPERATION_NOT_SUCCESSFULL; }
}

#endif
