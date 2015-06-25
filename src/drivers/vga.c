#include <kernel.h>

unsigned char * display = 0xA0000;
unsigned char display2[HEIGHT * WIDTH];
int prev_acum_x, prev_acum_y, prev_radius, prev_center_x, prev_center_y, fixed_y, fixed_x = -1;




void
init_vga() {
	set_graphics_mode();
}

void 
fill_screen(unsigned char color){
	int i=0;
	for(;i<HEIGHT * WIDTH;i++){
		display[i] = color;
		display2[i] = color;
	}
}


void
print_mouse(int curr_x, int curr_y, int prev_x, int prev_y) {

	print_prev_px(prev_x, prev_y);
	print_erasable_px(curr_x, curr_y, MOUSE_COLOR);
}

void
print_px(int curr_x, int curr_y, int selected_color) {

	print_erasable_px(curr_x, curr_y, selected_color);

	display2[getPos(curr_x, curr_y)] = selected_color;
	display2[getPos(curr_x + 1, curr_y)] = selected_color;
	display2[getPos(curr_x, curr_y + 1)] = selected_color;
	display2[getPos(curr_x + 1, curr_y + 1)] = selected_color;

}
void
print_erasable_px(int curr_x, int curr_y, int selected_color) {
	display[getPos(curr_x, curr_y)] = selected_color;
	display[getPos(curr_x + 1, curr_y)] = selected_color;
	display[getPos(curr_x, curr_y + 1)] = selected_color;
	display[getPos(curr_x + 1, curr_y + 1)] = selected_color;
}

void
print_prev_px(int prev_x, int prev_y) {

	display[getPos(prev_x, prev_y)] = display2[getPos(prev_x, prev_y)];
	display[getPos(prev_x + 1, prev_y)] = display2[getPos(prev_x + 1, prev_y)];
	display[getPos(prev_x, prev_y + 1)] = display2[getPos(prev_x, prev_y + 1)];
	display[getPos(prev_x + 1, prev_y + 1)] = display2[getPos(prev_x + 1, prev_y + 1)];

}

void
print_from(unsigned char * form, int length) {
	int i=0,j=0,z = 0;

	for(i = length; j < 20*20; j++, i++, z++) {
		if(z == 20){
			i += WIDTH - 20;
			z = 0;
		}
		display2[i] = form[j];
		display[i] = form[j];
	}
}

void
print_color(int color, int pos){
	int i=0, z=0, j=0; 
	for(i = 180*WIDTH + pos, j=0, z = 0; j < 20*20; i++, j++, z++) {
		if(z == 20){
			i += WIDTH - 20;
			z = 0;
		}
		display2[i] = color;
		display[i] = color;
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
		display2[i] = selected_color;
		display[i] = selected_color;
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