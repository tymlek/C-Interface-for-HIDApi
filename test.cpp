// Tymoteusz Lekszycki
// 26.11.2015

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <exception>
#include <string>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Group.H>

#include "hid_device.h"

class My_Window : public Fl_Window {
private:
	// Variables:
	HID_Device* board = nullptr;

	// Methods:
	template<typename T>
	std::string to_str(T value)
	{
		std::ostringstream os;
		os << value;
		return os.str();
	}

	/*template<typename T>
	unsigned int to_uint(T value)
	{
		std::istringstream is(value);
		unsigned int i;

		is >> i;

		if (!is)
			return 0;
		else
			return i;
	}*/

	double to_voltage(unsigned int value)
	{
		return (value * (3.3 / 1024));
	}

	// Widgets:
	Fl_Group* grpMainGroup;
	Fl_Group* grpGPIO;
	Fl_Output* lblRd_4;
	Fl_Output* lblRd_5;
	Fl_Output* lblRd_6;
	Fl_Output* lblRd_7;
	Fl_Button* btnRd_4_Input;
	Fl_Button* btnRd_5_Input;
	Fl_Button* btnRd_6_Input;
	Fl_Button* btnRd_7_Input;
	Fl_Button* btnRd_4_Output;
	Fl_Button* btnRd_5_Output;
	Fl_Button* btnRd_6_Output;
	Fl_Button* btnRd_7_Output;
	Fl_Button* btnRd_4_Set;
	Fl_Button* btnRd_5_Set;
	Fl_Button* btnRd_6_Set;
	Fl_Button* btnRd_7_Set;
	Fl_Button* btnRd_4_Clear;
	Fl_Button* btnRd_5_Clear;
	Fl_Button* btnRd_6_Clear;
	Fl_Button* btnRd_7_Clear;
	Fl_Button* btnRd_4_Read;
	Fl_Button* btnRd_5_Read;
	Fl_Button* btnRd_6_Read;
	Fl_Button* btnRd_7_Read;
	Fl_Group* grpAnalog;
	Fl_Output* lblRa_0;
	Fl_Output* lblRa_1;
	Fl_Button* btnRa_0_Read;
	Fl_Button* btnRa_1_Read;
	Fl_Group* grpRegisters;
	Fl_Input* txtSetReg;
	Fl_Output* lblGetReg;
	Fl_Button* btnSetReg;
	Fl_Button* btnSetRegBit;
	Fl_Button* btnGetReg;
	Fl_Button* btnGetRegBit;
	Fl_Group* grpOnBoard;
	Fl_Output* lblButton;
	Fl_Button* btnToggleLed;
	Fl_Output* lblLed;
	Fl_Button* btnReadButton;
	Fl_Button* btnQuit;

	// Events:
	void rd_4_input(Fl_Widget* w);
	void rd_5_input(Fl_Widget* w);
	void rd_6_input(Fl_Widget* w);
	void rd_7_input(Fl_Widget* w);

	void rd_4_output(Fl_Widget* w);
	void rd_5_output(Fl_Widget* w);
	void rd_6_output(Fl_Widget* w);
	void rd_7_output(Fl_Widget* w);

	void rd_4_set(Fl_Widget* w);
	void rd_5_set(Fl_Widget* w);
	void rd_6_set(Fl_Widget* w);
	void rd_7_set(Fl_Widget* w);

	void rd_4_clear(Fl_Widget* w);
	void rd_5_clear(Fl_Widget* w);
	void rd_6_clear(Fl_Widget* w);
	void rd_7_clear(Fl_Widget* w);

	void rd_4_read(Fl_Widget* w);
	void rd_5_read(Fl_Widget* w);
	void rd_6_read(Fl_Widget* w);
	void rd_7_read(Fl_Widget* w);

	void analog_ra_0(Fl_Widget* w);
	void analog_ra_1(Fl_Widget* w);

	void reg_get(Fl_Widget* w);
	void reg_set(Fl_Widget* w);
	void reg_get_bit(Fl_Widget* w);
	void reg_set_bit(Fl_Widget* w);

	void toggle_led(Fl_Widget* w);
	void read_switch(Fl_Widget* w);

	void quit(Fl_Widget* w);

	// Callbacks
	static void cb_rd_4_input(Fl_Widget* w, void* f);
	static void cb_rd_5_input(Fl_Widget* w, void* f);
	static void cb_rd_6_input(Fl_Widget* w, void* f);
	static void cb_rd_7_input(Fl_Widget* w, void* f);

	static void cb_rd_4_output(Fl_Widget* w, void* f);
	static void cb_rd_5_output(Fl_Widget* w, void* f);
	static void cb_rd_6_output(Fl_Widget* w, void* f);
	static void cb_rd_7_output(Fl_Widget* w, void* f);

	static void cb_rd_4_set(Fl_Widget* w, void* f);
	static void cb_rd_5_set(Fl_Widget* w, void* f);
	static void cb_rd_6_set(Fl_Widget* w, void* f);
	static void cb_rd_7_set(Fl_Widget* w, void* f);

	static void cb_rd_4_clear(Fl_Widget* w, void* f);
	static void cb_rd_5_clear(Fl_Widget* w, void* f);
	static void cb_rd_6_clear(Fl_Widget* w, void* f);
	static void cb_rd_7_clear(Fl_Widget* w, void* f);

	static void cb_rd_4_read(Fl_Widget* w, void* f);
	static void cb_rd_5_read(Fl_Widget* w, void* f);
	static void cb_rd_6_read(Fl_Widget* w, void* f);
	static void cb_rd_7_read(Fl_Widget* w, void* f);

	static void cb_analog_ra_0(Fl_Widget* w, void* f);
	static void cb_analog_ra_1(Fl_Widget* w, void* f);

	static void cb_reg_set(Fl_Widget* w, void* f);
	static void cb_reg_set_bit(Fl_Widget* w, void* f);
	static void cb_reg_get(Fl_Widget* w, void* f);
	static void cb_reg_get_bit(Fl_Widget* w, void* f);

	static void cb_toggle_led(Fl_Widget* w, void* f);
	static void cb_read_button(Fl_Widget* w, void* f);

	static void cb_quit(Fl_Widget* w, void* f);
public:
	My_Window()
		: Fl_Window(555,300,"I/O Board Interface") 
	{
		try {
			board = new HID_Device();
		} catch (std::exception& e) {
			board = nullptr;
			std::cerr << e.what();
			std::cin.get();
			exit(1);
		}

		if (board) {
			try {
				board->gpio_out(rd4, 0);
				board->gpio_out(rd5, 0);
				board->gpio_out(rd6, 0);
				board->gpio_out(rd7, 0);
			}
			catch (std::exception& e) {
				std::cerr << e.what();
				std::cin.get();
				exit(1);
			}
		}
		else {
			exit(1);
		}

		// Attach
		{ grpMainGroup = new Fl_Group(0, 0, 555, 335);
			{ grpGPIO = new Fl_Group(10, 20, 520, 110, "GPIO");
				{
					lblRd_4 = new Fl_Output(50, 35, 65, 20, "Rd 4");
				} // Fl_Output* lblRd_4
				{
					lblRd_5 = new Fl_Output(50, 55, 65, 20, "Rd 5");
				} // Fl_Output* lblRd_5
				{
					lblRd_6 = new Fl_Output(50, 75, 65, 20, "Rd 6");
				} // Fl_Output* lblRd_6
				{
					lblRd_7 = new Fl_Output(50, 95, 65, 20, "Rd 7");
				} // Fl_Output* lblRd_7
				
				{
					btnRd_4_Input = new Fl_Button(130, 35, 70, 20, "Input");
					btnRd_4_Input->callback(cb_rd_4_input,(void*)this);
				} // Fl_Button* btnRd_4_Input
				{
					btnRd_5_Input = new Fl_Button(130, 55, 70, 20, "Input");
					btnRd_5_Input->callback(cb_rd_5_input,(void*)this);
				} // Fl_Button* btnRd_5_Input
				{
					btnRd_6_Input = new Fl_Button(130, 75, 70, 20, "Input");
					btnRd_6_Input->callback(cb_rd_6_input,(void*)this);
				} // Fl_Button* btnRd_6_Input
				{
					btnRd_7_Input = new Fl_Button(130, 95, 70, 20, "Input");
					btnRd_7_Input->callback(cb_rd_7_input,(void*)this);
				} // Fl_Button* btnRd_7_Input
				
				{
					btnRd_4_Output = new Fl_Button(210, 35, 70, 20, "Output");
					btnRd_4_Output->callback(cb_rd_4_output,(void*)this);
				} // Fl_Button* btnRd_4_Output
				{
					btnRd_5_Output = new Fl_Button(210, 55, 70, 20, "Output");
					btnRd_5_Output->callback(cb_rd_5_output,(void*)this);
				} // Fl_Button* btnRd_5_Output
				{
					btnRd_6_Output = new Fl_Button(210, 75, 70, 20, "Output");
					btnRd_6_Output->callback(cb_rd_6_output,(void*)this);
				} // Fl_Button* btnRd_6_Output
				{
					btnRd_7_Output = new Fl_Button(210, 95, 70, 20, "Output");
					btnRd_7_Output->callback(cb_rd_7_output,(void*)this);
				} // Fl_Button* btnRd_7_Output
				
				{
					btnRd_4_Set = new Fl_Button(290, 35, 70, 20, "Set");
					btnRd_4_Set->callback(cb_rd_4_set,(void*)this);
				} // Fl_Button* btnRd_4_Set
				{
					btnRd_5_Set = new Fl_Button(290, 55, 70, 20, "Set");
					btnRd_5_Set->callback(cb_rd_5_set,(void*)this);
				} // Fl_Button* btnRd_5_Set
				{
					btnRd_6_Set = new Fl_Button(290, 75, 70, 20, "Set");
					btnRd_6_Set->callback(cb_rd_6_set,(void*)this);
				} // Fl_Button* btnRd_6_Set
				{
					btnRd_7_Set = new Fl_Button(290, 95, 70, 20, "Set");
					btnRd_7_Set->callback(cb_rd_7_set,(void*)this);
				} // Fl_Button* btnRd_7_Set
				
				{
					btnRd_4_Clear = new Fl_Button(370, 35, 70, 20, "Clear");
					btnRd_4_Clear->callback(cb_rd_4_clear,(void*)this);
				} // Fl_Button* btnRd_4_Clear
				{
					btnRd_5_Clear = new Fl_Button(370, 55, 70, 20, "Clear");
					btnRd_5_Clear->callback(cb_rd_5_clear,(void*)this);
				} // Fl_Button* btnRd_5_Clear
				{
					btnRd_6_Clear = new Fl_Button(370, 75, 70, 20, "Clear");
					btnRd_6_Clear->callback(cb_rd_6_clear,(void*)this);
				} // Fl_Button* btnRd_6_Clear
				{
					btnRd_7_Clear = new Fl_Button(370, 95, 70, 20, "Clear");
					btnRd_7_Clear->callback(cb_rd_7_clear,(void*)this);
				} // Fl_Button* btnRd_7_Clear
				
				{
					btnRd_4_Read = new Fl_Button(450, 35, 70, 20, "Read");
					btnRd_4_Read->callback(cb_rd_4_read,(void*)this);
				} // Fl_Button* btnRd_4_Read
				{
					btnRd_5_Read = new Fl_Button(450, 55, 70, 20, "Read");
					btnRd_5_Read->callback(cb_rd_5_read,(void*)this);
				} // Fl_Button* btnRd_5_Read
				{
					btnRd_6_Read = new Fl_Button(450, 75, 70, 20, "Read");
					btnRd_6_Read->callback(cb_rd_6_read,(void*)this);
				} // Fl_Button* btnRd_6_Read
				{
					btnRd_7_Read = new Fl_Button(450, 95, 70, 20, "Read");
					btnRd_7_Read->callback(cb_rd_7_read,(void*)this);
				} // Fl_Button* btnRd_7_Read
				grpGPIO->end();
			} // Fl_Group* grpGPIO
			
			{ grpAnalog = new Fl_Group(10, 155, 200, 70, "Analog");
				{
					lblRa_0 = new Fl_Output(50, 170, 65, 20, "Ra 0");
				} // Fl_Output* lblRa_0
				{
					lblRa_1 = new Fl_Output(50, 190, 65, 20, "Ra 1");
				} // Fl_Output* lblRa_1
				{
					btnRa_0_Read = new Fl_Button(130, 170, 70, 20, "Read");
					btnRa_0_Read->callback(cb_analog_ra_0,(void*)this);
				} // Fl_Button* btnRa_0_Read
				{
					btnRa_1_Read = new Fl_Button(130, 190, 70, 20, "Read");
					btnRa_1_Read->callback(cb_analog_ra_1,(void*)this);
				} // Fl_Button* btnRa_1_Read
				grpAnalog->end();
			} // Fl_Group* grpAnalog
			
			{ grpRegisters = new Fl_Group(220, 155, 310, 70, "Registers");
				{
					txtSetReg = new Fl_Input(240, 170, 120, 20, "In");
				} // Fl_Input* txtSetReg
				{
					lblGetReg = new Fl_Output(255, 190, 65, 20, "Out");
				} // Fl_Output* lblGetReg
				{
					btnSetReg = new Fl_Button(370, 170, 70, 20, "Set Reg");
					btnSetReg->callback(cb_reg_set,(void*)this);
				} // Fl_Button* btnSetReg
				{
					btnSetRegBit = new Fl_Button(370, 190, 70, 20, "Set Bit");
					btnSetRegBit->callback(cb_reg_set_bit,(void*)this);
				} // Fl_Button* btnSetRegBit
				{
					btnGetReg = new Fl_Button(450, 170, 70, 20, "Get Reg");
					btnGetReg->callback(cb_reg_get,(void*)this);
				} // Fl_Button* btnGetReg
				{
					btnGetRegBit = new Fl_Button(450, 190, 70, 20, "Get Bit");
					btnGetRegBit->callback(cb_reg_get_bit,(void*)this);
				} // Fl_Button* btnGetRegBit
				grpRegisters->end();
			} // Fl_Group* grpRegisters

			{ grpOnBoard = new Fl_Group(10, 235, 520, 35, "On Board");
				{
					lblButton = new Fl_Output(50, 250, 65, 20, "Stat");
				} // Fl_Output* lblButton
				{
					btnReadButton = new Fl_Button(130, 250, 70, 20, "Read Btn");
					btnReadButton->callback(cb_read_button,(void*)this);
				} // Fl_Button* btnReadButton
				{
					lblLed = new Fl_Output(370, 250, 65, 20, "Stat");
				} // Fl_Output* lblLed
				{
					btnToggleLed = new Fl_Button(450, 250, 70, 20, "Tog LED");
					btnToggleLed->callback(cb_toggle_led,(void*)this);
				} // Fl_Button* btnToggleLed
				grpOnBoard->end();

				btnQuit = new Fl_Button(240, 270, 70, 20, "Quit");
				btnQuit->callback(cb_quit,(void*)this);
			} // Fl_Group* grpOnBoard
			grpMainGroup->end();
		} // Fl_Group* grpMainGroup

		btnRd_4_Read->deactivate();
		btnRd_4_Set->deactivate();
		btnRd_4_Clear->deactivate();
		btnRd_5_Read->deactivate();
		btnRd_5_Set->deactivate();
		btnRd_5_Clear->deactivate();
		btnRd_6_Read->deactivate();
		btnRd_6_Set->deactivate();
		btnRd_6_Clear->deactivate();
		btnRd_7_Read->deactivate();
		btnRd_7_Set->deactivate();
		btnRd_7_Clear->deactivate();

		if (board->sfr_get_regbit(PORTC,2))
			lblLed->value("ON");
		else
			lblLed->value("OFF");

		if (board->read_switch())
			lblButton->value("1");
		else
			lblButton->value("0");
	}

	~My_Window()
	{
		board->gpio_out(rd4,0);
		board->gpio_out(rd5,0);
		board->gpio_out(rd6,0);
		board->gpio_out(rd7,0);
		
		delete board;
	}
};

//-------------------------------------------------------------------

void My_Window::rd_4_input(Fl_Widget* w)
{
	board->gpio_out(rd4,0);
	board->gpio_init(rd4,dir_input);

	lblRd_4->value("");
	
	w->deactivate();
	btnRd_4_Set->deactivate();
	btnRd_4_Clear->deactivate();

	btnRd_4_Read->activate();
	btnRd_4_Output->activate();
}

//-------------------------------------------------------------------

void My_Window::cb_rd_4_input(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_4_input(w);
}

//-------------------------------------------------------------------

void My_Window::rd_5_input(Fl_Widget* w)
{
	board->gpio_out(rd5,0);
	board->gpio_init(rd5,dir_input);

	lblRd_5->value("");

	w->deactivate();
	btnRd_5_Set->deactivate();
	btnRd_5_Clear->deactivate();

	btnRd_5_Read->activate();
	btnRd_5_Output->activate();
}

//-------------------------------------------------------------------

void My_Window::cb_rd_5_input(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_5_input(w);
}

//-------------------------------------------------------------------

void My_Window::rd_6_input(Fl_Widget* w)
{
	board->gpio_out(rd6,0);
	board->gpio_init(rd6,dir_input);

	lblRd_6->value("");

	w->deactivate();
	btnRd_6_Set->deactivate();
	btnRd_6_Clear->deactivate();

	btnRd_6_Read->activate();
	btnRd_6_Output->activate();
}

//-------------------------------------------------------------------

void My_Window::cb_rd_6_input(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_6_input(w);
}

//-------------------------------------------------------------------

void My_Window::rd_7_input(Fl_Widget* w)
{
	board->gpio_out(rd7,0);
	board->gpio_init(rd7,dir_input);

	lblRd_7->value("");

	w->deactivate();
	btnRd_7_Set->deactivate();
	btnRd_7_Clear->deactivate();

	btnRd_7_Read->activate();
	btnRd_7_Output->activate();
}

//-------------------------------------------------------------------

void My_Window::cb_rd_7_input(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_7_input(w);
}

//-------------------------------------------------------------------

void My_Window::rd_4_output(Fl_Widget* w)
{
	board->gpio_out(rd4,0);
	board->gpio_init(rd4,dir_output);

	lblRd_4->value("");

	w->deactivate();
	btnRd_4_Read->deactivate();

	btnRd_4_Set->activate();
	btnRd_4_Clear->activate();
	btnRd_4_Input->activate();
}

//-------------------------------------------------------------------

void My_Window::cb_rd_4_output(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_4_output(w);
}

//-------------------------------------------------------------------

void My_Window::rd_5_output(Fl_Widget* w)
{
	board->gpio_out(rd5,0);
	board->gpio_init(rd5,dir_output);

	lblRd_5->value("");

	w->deactivate();
	btnRd_5_Read->deactivate();

	btnRd_5_Set->activate();
	btnRd_5_Clear->activate();
	btnRd_5_Input->activate();
}

//-------------------------------------------------------------------

void My_Window::cb_rd_5_output(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_5_output(w);
}

//-------------------------------------------------------------------

void My_Window::rd_6_output(Fl_Widget* w)
{
	board->gpio_out(rd6,0);
	board->gpio_init(rd6,dir_output);

	lblRd_6->value("");

	w->deactivate();
	btnRd_6_Read->deactivate();

	btnRd_6_Set->activate();
	btnRd_6_Clear->activate();
	btnRd_6_Input->activate();
}

//-------------------------------------------------------------------

void My_Window::cb_rd_6_output(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_6_output(w);
}

//-------------------------------------------------------------------

void My_Window::rd_7_output(Fl_Widget* w)
{
	board->gpio_out(rd7,0);
	board->gpio_init(rd7,dir_output);

	lblRd_7->value("");

	w->deactivate();
	btnRd_7_Read->deactivate();

	btnRd_7_Set->activate();
	btnRd_7_Clear->activate();
	btnRd_7_Input->activate();
}

//-------------------------------------------------------------------

void My_Window::cb_rd_7_output(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_7_output(w);
}

//-------------------------------------------------------------------

void My_Window::rd_4_set(Fl_Widget* w)
{
	board->gpio_out(rd4,1);
	
	lblRd_4->value("1");
}

//-------------------------------------------------------------------

void My_Window::cb_rd_4_set(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_4_set(w);
}

//-------------------------------------------------------------------

void My_Window::rd_5_set(Fl_Widget* w)
{
	board->gpio_out(rd5,1);

	lblRd_5->value("1");
}

//-------------------------------------------------------------------

void My_Window::cb_rd_5_set(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_5_set(w);
}

//-------------------------------------------------------------------

void My_Window::rd_6_set(Fl_Widget* w)
{
	board->gpio_out(rd6,1);

	lblRd_6->value("1");
}

//-------------------------------------------------------------------

void My_Window::cb_rd_6_set(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_6_set(w);
}

//-------------------------------------------------------------------

void My_Window::rd_7_set(Fl_Widget* w)
{
	board->gpio_out(rd7,1);

	lblRd_7->value("1");
}

//-------------------------------------------------------------------

void My_Window::cb_rd_7_set(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_7_set(w);
}

//-------------------------------------------------------------------

void My_Window::rd_4_clear(Fl_Widget* w)
{
	board->gpio_out(rd4,0);

	lblRd_4->value("0");
}

//-------------------------------------------------------------------

void My_Window::cb_rd_4_clear(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_4_clear(w);
}

//-------------------------------------------------------------------

void My_Window::rd_5_clear(Fl_Widget* w)
{
	board->gpio_out(rd5,0);

	lblRd_5->value("0");
}

//-------------------------------------------------------------------

void My_Window::cb_rd_5_clear(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_5_clear(w);
}

//-------------------------------------------------------------------

void My_Window::rd_6_clear(Fl_Widget* w)
{
	board->gpio_out(rd6,0);

	lblRd_6->value("0");
}

//-------------------------------------------------------------------

void My_Window::cb_rd_6_clear(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_6_clear(w);
}

//-------------------------------------------------------------------

void My_Window::rd_7_clear(Fl_Widget* w)
{
	board->gpio_out(rd7,0);

	lblRd_7->value("0");
}

//-------------------------------------------------------------------

void My_Window::cb_rd_7_clear(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_7_clear(w);
}

//-------------------------------------------------------------------

void My_Window::rd_4_read(Fl_Widget* w)
{
	lblRd_4->value(to_str((unsigned int)board->gpio_in(rd4)).c_str());
}

//-------------------------------------------------------------------

void My_Window::cb_rd_4_read(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_4_read(w);
}

//-------------------------------------------------------------------

void My_Window::rd_5_read(Fl_Widget* w)
{
	lblRd_5->value(to_str((unsigned int)board->gpio_in(rd5)).c_str());
}

//-------------------------------------------------------------------

void My_Window::cb_rd_5_read(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_5_read(w);
}

//-------------------------------------------------------------------

void My_Window::rd_6_read(Fl_Widget* w)
{
	lblRd_6->value(to_str((unsigned int)board->gpio_in(rd6)).c_str());
}

//-------------------------------------------------------------------

void My_Window::cb_rd_6_read(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_6_read(w);
}

//-------------------------------------------------------------------

void My_Window::rd_7_read(Fl_Widget* w)
{
	lblRd_7->value(to_str((unsigned int)board->gpio_in(rd7)).c_str());
}

//-------------------------------------------------------------------

void My_Window::cb_rd_7_read(Fl_Widget* w, void* f)
{
	((My_Window*)f)->rd_7_read(w);
}

//-------------------------------------------------------------------

void My_Window::analog_ra_0(Fl_Widget* w)
{
	lblRa_0->value(to_str(to_voltage(board->adc_ra0())).c_str());
}

//-------------------------------------------------------------------

void My_Window::cb_analog_ra_0(Fl_Widget* w, void* f)
{
	((My_Window*)f)->analog_ra_0(w);
}

//-------------------------------------------------------------------

void My_Window::analog_ra_1(Fl_Widget* w)
{
	lblRa_1->value(to_str(to_voltage(board->adc_ra1())).c_str());
}

//-------------------------------------------------------------------

void My_Window::cb_analog_ra_1(Fl_Widget* w, void* f)
{
	((My_Window*)f)->analog_ra_1(w);
}

//-------------------------------------------------------------------

void My_Window::reg_set(Fl_Widget* w)
{
	std::istringstream is(to_str(txtSetReg->value()));
	unsigned short reg;
	unsigned short rval;

	is >> reg;
	is >> rval;

	unsigned char result;
	
	result = board->sfr_set_reg((unsigned char)reg,(unsigned char)rval);

	lblGetReg->value(to_str(result).c_str());
}

//-------------------------------------------------------------------

void My_Window::cb_reg_set(Fl_Widget* w, void* f)
{
	((My_Window*)f)->reg_set(w);
}

//-------------------------------------------------------------------

void My_Window::reg_set_bit(Fl_Widget* w)
{
	std::istringstream is(to_str(txtSetReg->value()));
	unsigned short reg;
	unsigned short rbit;
	unsigned short bval;

	is >> reg;
	is >> rbit;
	is >> bval;

	unsigned char result;
	
	result = board->sfr_set_regbit((unsigned char)reg,(unsigned char)rbit,(unsigned char)bval);

	lblGetReg->value(to_str(result).c_str());
}

//-------------------------------------------------------------------

void My_Window::cb_reg_set_bit(Fl_Widget* w, void* f)
{
	((My_Window*)f)->reg_set_bit(w);
}

//-------------------------------------------------------------------

void My_Window::reg_get(Fl_Widget* w)
{
	std::istringstream is(to_str(txtSetReg->value()));
	unsigned short reg;

	is >> reg;

	unsigned char result;
	
	result = board->sfr_get_reg((unsigned char)reg);

	lblGetReg->value(to_str(result).c_str());
}

//-------------------------------------------------------------------

void My_Window::cb_reg_get(Fl_Widget* w, void* f)
{
	((My_Window*)f)->reg_get(w);
}

//-------------------------------------------------------------------

void My_Window::reg_get_bit(Fl_Widget* w)
{
	std::istringstream is(to_str(txtSetReg->value()));
	unsigned short reg;
	unsigned short rbit;

	is >> reg;
	is >> rbit;

	unsigned char result;
	
	result = board->sfr_get_regbit((unsigned char)reg,(unsigned char)rbit);

	lblGetReg->value(to_str(result).c_str());
}

//-------------------------------------------------------------------

void My_Window::cb_reg_get_bit(Fl_Widget* w, void* f)
{
	((My_Window*)f)->reg_get_bit(w);
}

//-------------------------------------------------------------------

void My_Window::toggle_led(Fl_Widget* w)
{
	board->toggle_led();

	if (board->sfr_get_regbit(PORTC,2))
		lblLed->value("ON");
	else
		lblLed->value("OFF");
}

//-------------------------------------------------------------------

void My_Window::cb_toggle_led(Fl_Widget* w, void* f)
{
	((My_Window*)f)->toggle_led(w);
}

//-------------------------------------------------------------------

void My_Window::read_switch(Fl_Widget* w)
{
	if (board->read_switch())
		lblButton->value("1");
	else
		lblButton->value("0");
}

//-------------------------------------------------------------------

void My_Window::cb_read_button(Fl_Widget* w, void* f)
{
	((My_Window*)f)->read_switch(w);
}

//-------------------------------------------------------------------

void My_Window::quit(Fl_Widget* w)
{
	board->gpio_out(rd4,0);
	board->gpio_out(rd5,0);
	board->gpio_out(rd6,0);
	board->gpio_out(rd7,0);

	board->sfr_set_regbit(PORTC,2,0);
		
	delete board;

	this->hide();
}

//-------------------------------------------------------------------

void My_Window::cb_quit(Fl_Widget* w, void* f)
{
	((My_Window*)f)->quit(w);
}

//-------------------------------------------------------------------

int main(int argc, char** argv)
{
	My_Window* win = new My_Window();
	win->show(argc,argv);

	return Fl::run();
}
