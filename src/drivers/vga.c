#include <kernel.h>


unsigned char * display=0xA0000;

void
init_vga() {
	set_graphics_mode();
}

void 
fill_screen(unsigned char color){
	int i=0;
	for(;i<HEIGHT * WIDTH;i++){
		display[i] = color;
	}
}