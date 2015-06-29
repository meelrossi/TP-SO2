#include <kernel.h>

unsigned char * display = (unsigned char*) 0xA0000;
unsigned char display2[HEIGHT * WIDTH];

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
print_form(unsigned char * form, int length) {
	int i=0,j=0,z = 0;

	for(i = length; j < 20*20; j++, i++, z++) {
		if(z == 20){
			i += WIDTH - 20;
			z = 0;
		}
		print_pixel(i, form[j]);
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
		print_pixel(i, color);
	}
}

void
print_pixel(int pos, int color) {
	display2[pos] = color;
	display[pos] = color;
}
