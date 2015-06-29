#include <kernel.h>
#include "paint.h"

unsigned char cross[20 * 20] = {BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK};

unsigned char circle[20 * 20] = {BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,BLACK,
								BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,
								BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,
								BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,
								BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,
								BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,
								BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK};

unsigned char rectangle[20 * 20] = {BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK};

unsigned char line[20 * 20] =  {BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK};

unsigned char rubber[20*20] = {BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,WHITE,BLACK,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,BLACK,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,WHITE,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK};

unsigned char brush[20*20] = {	BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,RED,RED,RED,RED,RED,RED,RED,RED,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
								BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK};


int prev_acum_x, prev_acum_y, prev_radius, prev_center_x, prev_center_y, fixed_y, fixed_x = -1;


#define BACK_COLOR 0xFF
#define MOUSE_COLOR 0x00
enum actions { LINE, CIRCLE, SQUARE, ERRASE, PAINT, EXIT };
#define TRANSITORY 1
#define DEFINITIVE 2
#define abs(x) (x) < 0 ? (x) * -1: (x)

int selected_action, selected_color;


int
paint_main(int argc, char *argv[]) {
	int x, y;
	int acum_x=0,acum_y=0, prev_x = 0, prev_y = 0;
	bool cursor;
	bool exit=false;
	selected_action = PAINT;
	selected_color = BLACK;
	input_event_t event;

	mt_cons_clear();
	cursor = mt_cons_cursor(false);
	init_vga();
	fill_screen(WHITE);
	print_menu();

	while ( mt_input_get_cond(&event) )
		;

	while ( !exit )
	{
		mt_input_get(&event);
		switch ( event.type )
		{
			case KBD_EVENT:
				if ( event.kbd.scan_codes[0] == 0x81 ) //ESC
				{
					while ( getch_cond() != EOF )
						;					
					
					set_text_mode();
					mt_cons_clear();
					mt_cons_cursor(cursor);
					return 0;
				}
				break;
			case MOUSE_EVENT:
				x = event.mouse.x;
				if ( event.mouse.x_sign )
					x -= 256;
				y = event.mouse.y;
				if ( event.mouse.y_sign )
					y -= 256;
				prev_x = acum_x;
				prev_y = acum_y;
 				acum_x += x;
				acum_y -= y;
				if(acum_x>=WIDTH){
					acum_x=WIDTH-1;
				}
				if(acum_x<0){
					acum_x=0;
				}

				if(acum_y>=HEIGHT){
					acum_y=HEIGHT-1;
				}
				if(acum_y<0){
					acum_y=0;
				}
				
				print_mouse(acum_x, acum_y, prev_x, prev_y);
				exit = execute(acum_x,acum_y,event.mouse);
				break;
			default:
				break;
		}
	}
	set_text_mode();
	mt_cons_clear();
	mt_cons_cursor(cursor);

	return 0;
}

int
execute(int acum_x, int acum_y, mouse_event_t m_event) {

	int clicked = get_action(acum_x, acum_y, m_event);

	if (clicked == EXIT)
		return 1;

	if(!((acum_x >= 0 && acum_x <= 20) || 
				(acum_y >= 180 && acum_y <= 200))) {
		
		switch(clicked) {

			case LINE:
					print_line(acum_x, acum_y, selected_color, m_event);
				break;
			case CIRCLE:
					print_circle(acum_x, acum_y, selected_color, m_event);
				break;
			case SQUARE:
					print_square(acum_x, acum_y, selected_color, m_event);
				break;
			case ERRASE:
					if(m_event.left_button)
						print_px(acum_x, acum_y, WHITE);
					break;
			case PAINT:
					if(m_event.left_button)
						print_px(acum_x, acum_y, selected_color);
					break;		
		}
	}

	return 0;
}

int
get_action(int acum_x, int acum_y, mouse_event_t m_event) {
	
	if (m_event.left_button && acum_x >= (WIDTH-20)  && acum_x <= WIDTH //Checks if the user cliked on the exit button
		&& acum_y >= 0 && acum_y <= 20)
		selected_action = EXIT;
	else if(m_event.left_button && ((acum_x >= 0 && acum_x <= 20) ||  //Checks if the user cliked in the menu
		(acum_y >= (HEIGHT-20) && acum_y <= HEIGHT))) {

		if (acum_y >= 0 && acum_y <= (HEIGHT-20)){

			if (acum_y >= 0 && acum_y <= 20)
				selected_action = LINE;
			else if (acum_y >= 24 && acum_y <= 44)
				selected_action = CIRCLE;
			else if (acum_y >= 48 && acum_y <= 68)
				selected_action = SQUARE;
			else if (acum_y >= 72 && acum_y <= 92)
				selected_action = ERRASE;
			else if (acum_y >= 96 && acum_y <= 116)
				selected_action = PAINT;

		} else {

			if (acum_x >= 0  && acum_x <= 20)
				selected_color = 30;
			else if (acum_x >= 21  && acum_x <= 40)
				selected_color = BLACK;
			else if (acum_x >= 41  && acum_x <= 60)
				selected_color = 32;
			else if (acum_x >= 61  && acum_x <= 80)
				selected_color = 33;
			else if (acum_x >= 81  && acum_x <= 100)
				selected_color = 34;
			else if (acum_x >= 101  && acum_x <= 120)
				selected_color = 35;
			else if (acum_x >= 121  && acum_x <= 140)
				selected_color = 36;
			else if (acum_x >= 141  && acum_x <= 160)
				selected_color = 37;
			else if (acum_x >= 161  && acum_x <= 180)
				selected_color = 38;
			else if (acum_x >= 181  && acum_x <= 200)
				selected_color = 39;
			else if (acum_x >= 201  && acum_x <= 220)
				selected_color = 40;
			else if (acum_x >= 221  && acum_x <= 240)
				selected_color = 41;
			else if (acum_x >= 241  && acum_x <= 260)
				selected_color = 42;
			else if (acum_x >= 261  && acum_x <= 280)
				selected_color = 43;
			else if (acum_x >= 281  && acum_x <= 300)
				selected_color = 44;
			else
				selected_color = 45;

			print_current_color(selected_color);

		}
	}

	return selected_action;
} 

void
print_menu() {
	print_colors_menu();
	print_form(line, 0);
	print_form(rectangle, 48*WIDTH);
	print_form(circle, 24*WIDTH);
	print_form(cross, 300);
	print_form(rubber, 72*WIDTH);
	print_form(brush, 96*WIDTH);
	print_current_color(selected_color);
}

void
print_colors_menu(){
	int i,j;
	for(i=30,j=0;j<=300;i++){
		if(i == 31){
			print_color(BLACK,20);
		}
		else{
			print_color(i,j);
		}
		j+=20;
	}
}

// This function is base on Bresenham Line-Drawing Algorithm. http://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html
void
print_line(int acum_x, int acum_y, int selected_color, mouse_event_t m_event) {
	
	if(m_event.left_button){
		if (fixed_x == -1) {
			fixed_x = acum_x;
			fixed_y = acum_y;
			prev_acum_y = acum_y;
			prev_acum_x = acum_x;
		}
		print_line_aux(fixed_x, fixed_y, prev_acum_x, prev_acum_y, ERRASE, selected_color);
		print_line_aux(fixed_x, fixed_y, acum_x, acum_y, TRANSITORY, selected_color);
		prev_acum_x = acum_x;
		prev_acum_y = acum_y;
	} else if (fixed_x != -1){
		print_line_aux(fixed_x, fixed_y, acum_x, acum_y, DEFINITIVE, selected_color);
		fixed_x = -1;
	} 	

}

void
print_line_aux(int fixed_x, int fixed_y, int acum_x, int acum_y, int type, int selected_color){
	
	int dx = abs(acum_x - fixed_x), sx = fixed_x < acum_x ? 1 : -1;
	int dy = abs(acum_y - fixed_y), sy = fixed_y < acum_y ? 1 : -1; 
	int err = (dx > dy ? dx : -dy) / 2, e2;
	int i = fixed_x, j = fixed_y;
	for(;;) {
	    
	    if(type == ERRASE) 
			print_prev_px(i, j);
		else if(type == TRANSITORY)
			print_erasable_px(i, j, selected_color);
		else if(type == DEFINITIVE)
			print_px(i, j, selected_color);
	    
	    if (i == acum_x && j == acum_y) 
	    	break;
	    
	    e2 = err;
	    
	    if (e2 > -dx) {
	    	err -= dy; 
	    	i += sx; 
	    }
	    if (e2 < dy) { 
	    	err += dx; 
	    	j += sy; 
	    }
	}
}

void
print_square(int acum_x, int acum_y, int selected_color, mouse_event_t m_event) {
	int i;
	if (fixed_x == -1) {
		fixed_x = acum_x;
		fixed_y = acum_y;
		prev_acum_y = acum_y;
		prev_acum_x = acum_x;
	}
	
	if (fixed_x > acum_x){
		
		for(i = fixed_x; i > acum_x; i--)
			print_prev_px(i, prev_acum_y);

		for(i = fixed_x; i > acum_x; i--) {
			print_erasable_px(i, acum_y, selected_color);
			print_erasable_px(i, fixed_y, selected_color);
		}
	} else {
		for(i = fixed_x; i < acum_x; i++)
			print_prev_px(i, prev_acum_y);

		for(i = fixed_x; i < acum_x; i++) {
			print_erasable_px(i, acum_y, selected_color);
			print_erasable_px(i, fixed_y, selected_color);
		}
	}

	if (fixed_y > acum_y){

		for(i = fixed_y; i > acum_y; i--) {
			print_prev_px(prev_acum_x, i);
		}
		for(i = fixed_y; i > acum_y; i--) {
			print_erasable_px(acum_x, i, selected_color);
			print_erasable_px(fixed_x, i, selected_color);
		}
		
	} else {

		for(i = fixed_y; i < acum_y; i++) {
			print_prev_px(prev_acum_x, i);
		}
		for(i = fixed_y; i < acum_y; i++) {
			print_erasable_px(acum_x, i, selected_color);
			print_erasable_px(fixed_x, i, selected_color);
		}

	}

	prev_acum_x = acum_x;
	prev_acum_y = acum_y;

	if(!m_event.left_button) {

		if (fixed_x > acum_x){

			for(i = fixed_x; i > acum_x; i--) {
				print_px(i, acum_y, selected_color);
				print_px(i, fixed_y, selected_color);
			}

		} else {

			for(i = fixed_x; i < acum_x; i++) {
				print_px(i, acum_y, selected_color);
				print_px(i, fixed_y, selected_color);
			}

		}
		if (fixed_y > acum_y){ 

			for(i = fixed_y; i > acum_y; i--) {
				print_px(acum_x, i, selected_color);
				print_px(fixed_x, i, selected_color);
			}

		} else { 
			for(i = fixed_y; i < acum_y; i++) {
				print_px(acum_x, i, selected_color);
				print_px(fixed_x, i, selected_color);
			}

		}
		
		fixed_x = -1;
	}
		
}

//TODO: REFACTORIZAR FUNCIONES CON STRUCT DE POINT y mover la funcion sqrt a otro lado

void
print_circle(int acum_x, int acum_y, int selected_color, mouse_event_t m_event) {
	int radius, center_x, center_y;

	if (fixed_x == -1){
		fixed_x = acum_x;
		fixed_y = acum_y;
		prev_acum_x = acum_x;
		prev_acum_y = acum_y;

		if ( (acum_x - fixed_x) / 2 < (acum_y - fixed_y) / 2 )
			prev_radius = (acum_x - fixed_x) / 2;
		else 
			prev_radius = (acum_y - fixed_y) / 2;

		prev_center_x = (acum_x + fixed_x) / 2;
		prev_center_y = (acum_y + fixed_y) / 2;

	}

	if ( (acum_x - fixed_x) / 2 < (acum_y - fixed_y) / 2 )
		radius = (acum_x - fixed_x) / 2;
	else 
		radius = (acum_y - fixed_y) / 2;

	center_x = (acum_x + fixed_x) / 2;
	center_y = (acum_y + fixed_y) / 2;

	if (m_event.left_button) {
		
		print_circle_aux(fixed_x, fixed_y, prev_acum_x, prev_acum_y, prev_radius, prev_center_x, prev_center_y, selected_color, ERRASE);
		print_circle_aux(fixed_x, fixed_y, acum_x, acum_y, radius, center_x, center_y, selected_color, TRANSITORY);

		prev_acum_y = acum_y;
		prev_acum_x = acum_x;
		prev_center_y = center_y;
		prev_center_x = center_x;
		prev_radius = radius;
	} else {
		print_circle_aux(fixed_x, fixed_y, acum_x, acum_y, radius, center_x, center_y, selected_color, DEFINITIVE);
		fixed_x = -1;

	}
}

void
print_circle_aux(int fixed_x, int fixed_y, int acum_x, int acum_y, int radius, int center_x, int center_y, int selected_color, int type){
	int i,j;
	for(i = fixed_x; i < acum_x; i++){
		for(j = fixed_y; j < acum_y; j++){
			if ((int)distance(i, j, center_x, center_y) == radius){
				if(type == ERRASE)
					print_prev_px(i, j);
				else if(type == TRANSITORY)
					print_erasable_px(i, j, selected_color);
				else if(type == DEFINITIVE)
					print_px(i, j, selected_color);
			}

		}
	}
	

}

float
distance(int p1_x, int p1_y, int p2_x, int p2_y){

	return sqrt((p1_x - p2_x) * (p1_x - p2_x) + (p1_y-p2_y) *(p1_y-p2_y));

}
int
min_array(int * array, int len){
	int i = 0, curmin = array[0], j = 0;
	for(; i < len; i++){
		if(array[i] < curmin){
			curmin = array[i];
			j = i;
		}
	}
	return j;

}

// Code extrated from Reference: http://ilab.usc.edu/wiki/index.php/Fast_Square_Root
float sqrt(const float x)  
{
  union
  {
    int i;
    float x;
  } u;
  u.x = x;
  u.i = (1<<29) + (u.i >> 1) - (1<<22); 
  
  // Two Babylonian Steps (simplified from:)
  // u.x = 0.5f * (u.x + x/u.x);
  // u.x = 0.5f * (u.x + x/u.x);
  u.x =       u.x + x/u.x;
  u.x = 0.25f*u.x + x/u.x;

  return u.x;
} 

void
print_mouse(int curr_x, int curr_y, int prev_x, int prev_y) {

	print_prev_px(prev_x, prev_y);
	print_erasable_px(curr_x, curr_y, MOUSE_COLOR);
}

void
print_brush_color(int selected_color) {
	int i;
	int start = 107 * WIDTH + 6;
	int stop = 8;
	int rows = 4;
	for(i=0;i<stop;i++){
		print_pixel(start+i,selected_color);
		if(rows == 4 && i == 7){
			i = -1;
			stop = 6;
			start = start + WIDTH + 1;
			rows--;
		}
		if(rows == 3 && i == 5){
			i = -1;
			stop = 4;
			start = start + WIDTH + 1;
			rows--;
		}
		if(rows == 2 && i == 3){
			i = -1;
			stop = 2;
			start = start + WIDTH + 1;
		}
	}
}

void 
print_current_color(int selected_color){
	int i = 164*WIDTH + 4, k, j;
	for(k=0, j=0; k < 12*12; j++,k++,i++){
		if(j == 12){
			i += WIDTH - 12;
			j = 0;
		}
		print_pixel(i, selected_color);
	}
	print_brush_color(selected_color);
}