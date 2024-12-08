#include "library.h"


const int buttons[4][4] =
{
    { L'7', L'8', L'9', L'+' },
    { L'4', L'5', L'6', L'-' },
    { L'1', L'2', L'3', L'×' },
    { L'c', L'0', L'=', L'÷' }
};

void draw_calc()
{
	set_pen_color(color::grey);
	fill_rectangle(0,95,300,400);
	int button_row = 0;
	while(button_row < 4)
	{
		int button_column = 0;
		while(button_column < 4)
		{
			move_to(40 + button_column * 75, 135 + button_row * 75);
            set_pen_width(60);
			set_pen_color(color::black);
			draw_point();
			set_pen_width(55);
			set_pen_color(color::pink);
			draw_point();
            button_column = button_column + 1;
		}
		button_row = button_row + 1;
	}
    int row = 0;
	set_pen_color(color::black);
	set_font("Arial", 45);
    while (row < 4)
    {
        int column = 0;
        while (column < 4)
        {
            move_to(30 + column * 75, 150 + row * 75);
            write_char(buttons[row][column]);
            column = column + 1;
        }
        row = row + 1;
    }
}

double num_grabber()
{
	int number = 0;
	while(true)
	{
		wait_for_mouse_click();
		int x = get_click_x();
		int y = get_click_y();
		if(x >= 22 && x <= 61 && y >= 115 && y <= 156)
		{
			number = number * 10 + 7;
		}
		else if(x >= 93 && x <= 138 && y >= 115 && y <= 156)
		{
			number = number * 10 + 8;
		}
		else if(x >= 166 && x <= 214 && y >= 115 && y <= 156)
		{
			number = number * 10 + 9;
		}
		else if(x >= 15 && x <= 62 && y >= 194 && y <= 229)
		{
			number = number * 10 + 4;
		}
		else if(x >= 94 && x <= 135 && y >= 194 && y <= 229)
		{
			number = number * 10 + 5;
		}
		else if(x >= 168 && x <= 210 && y >= 194 && y <= 229)
		{
			number = number * 10 + 6;
		}
		else if(x >= 15 && x <= 65 && y >= 270 && y <= 308)
		{
			number = number * 10 + 1;
		}
		else if(x >= 97 && x <= 140 && y >= 270 && y <= 308)
		{
			number = number * 10 + 2;
		}
		else if(x >= 167 && x <= 215 && y >= 270 && y <= 308)
		{
			number = number * 10 + 3;
		}
		else if(x >= 97 && x <= 135 && y >= 338 && y <= 380)
		{
			number = number * 10;
		}
		else if(x >= 160 && x <= 220 && y >= 330 && y <= 390)
		{
			return number;
		}
	}
}


void calc(double results)
{
	while(true)
	{	
		double result = results;
		double num1 = 0;
		if(result == 0)
		{
			num1 = num_grabber();
			set_pen_color(color::yellow);
			move_to(20,80);
			write_string(num1);
		}
		double num2 = 0;

		
		wait_for_mouse_click();
	    int x = get_click_x();
		int y = get_click_y();

		if(x >= 235 && x <= 290 && y >= 105 && y <= 165)
		{
			num2 = num_grabber();
			result = num1 + num2 + result;
			set_pen_color(color::black);
			fill_rectangle(0,0,300,100);
			set_pen_color(color::yellow);
			move_to(20,80);
			write_string(num2);
			calc(result);
		}
		else if(x >= 235 && x <= 290 && y >= 185 && y <= 236)
		{
			num2 = num_grabber();
			result = (num1 + result) - num2;
			set_pen_color(color::black);
			fill_rectangle(0,0,300,100);
			set_pen_color(color::yellow);
			move_to(20,80);
			write_string(num2);
			calc(result);
		}
		else if(x >= 235 && x <= 290 && y >= 260 && y <= 320)
		{
			num2 = num_grabber();
			result = (num1 + result) * num2;
			set_pen_color(color::black);
			fill_rectangle(0,0,300,100);
			set_pen_color(color::yellow);
			move_to(20,80);
			write_string(num2);
			calc(result);
		}
		else if(x >= 235 && x <= 290 && y >= 330 && y <= 390)
		{
			num2 = num_grabber();
			result = (num1 + result) / num2;
			set_pen_color(color::black);
			fill_rectangle(0,0,300,100);
			set_pen_color(color::yellow);
			move_to(20,80);
			write_string(num2);
			calc(result);
		}
		else if(x >= 160 && x <= 220 && y >= 330 && y <= 390)
		{
			set_pen_color(color::black);
			fill_rectangle(0,0,300,100);
			set_pen_color(color::yellow);
			move_to(20,80);
			write_string(result);
		}
		else if(x >= 15 && x <= 70 && y >= 330 && y <= 390)
		{
			num1 = 0;
			num2 = 0;
			result = 0;
			set_pen_color(color::black);
			fill_rectangle(0,0,300,100);
			calc(result);
		}
	}
}

void main()
{
    make_window(300, 400);
	draw_calc();
	set_pen_color(color::black);
	fill_rectangle(0,0,300,100);
	set_font("Arial", 60);
	calc(0);

}
