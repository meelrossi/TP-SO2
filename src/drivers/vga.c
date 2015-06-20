#include <kernel.h>


unsigned char * display = 0xA0000;
unsigned char display2[HEIGHT * WIDTH];
int selected_color = WHITE;

void
init_vga() {
	set_graphics_mode();
}

void 
fill_screen(unsigned char color){
	int i=0;
	for(;i<HEIGHT * WIDTH;i++){
		display[i] = BACK_COLOR;
		display2[i] = BACK_COLOR;
	}
}




/*
void
print_menu(){
int i=0;

filePtr = fopen("./images.bmp","rb");
if (filePtr == NULL)
return NULL;

//read the bitmap file header
fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER),1,filePtr);

//verify that this is a bmp file by check bitmap id
if (bitmapFileHeader.bfType !=0x4D42)
{
fclose(filePtr);
return NULL;
}

//read the bitmap info header
fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER),1,filePtr);

//move file point to the begging of bitmap data
fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);

//allocate enough memory for the bitmap image data
bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);

//verify memory allocation
if (!bitmapImage)
{
free(bitmapImage);
fclose(filePtr);
return NULL;
}

//read in the bitmap image data
fread(bitmapImage,bitmapInfoHeader->biSizeImage,filePtr);

//make sure bitmap image data was read
if (bitmapImage == NULL)
{
fclose(filePtr);
return NULL;
}

//swap the r and b values to get RGB (bitmap is BGR)
for (imageIdx = 0,imageIdx < bitmapInfoHeader->biSizeImage;imageIdx+=3)
{
tempRGB = bitmapImage[imageIdx];
bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
bitmapImage[imageIdx + 2] = tempRGB;
}

//close file and return bitmap iamge data
fclose(filePtr);
return bitmapImage;

for(;i<HEIGHT * WIDTH;i++){
	display[i] = bitmapImage[i];
	display2[i] = bitmapImage[i];
}
}
*/
void
print_mouse(int curr_x, int curr_y, int prev_x, int prev_y) {

	display[getPos(prev_x, prev_y)] = display2[getPos(prev_x, prev_y)];
	display[getPos(prev_x + 1, prev_y)] = display2[getPos(prev_x + 1, prev_y)];
	display[getPos(prev_x, prev_y + 1)] = display2[getPos(prev_x, prev_y + 1)];
	display[getPos(prev_x + 1, prev_y + 1)] = display2[getPos(prev_x + 1, prev_y + 1)];

	display[getPos(curr_x, curr_y)] = WHITE;
	display[getPos(curr_x + 1, curr_y)] = WHITE;
	display[getPos(curr_x, curr_y + 1)] = WHITE;
	display[getPos(curr_x + 1, curr_y + 1)] = WHITE;
}

void
print_line(int curr_x, int curr_y) {

	display[getPos(curr_x, curr_y)] = selected_color;
	display[getPos(curr_x + 1, curr_y)] = selected_color;
	display[getPos(curr_x, curr_y + 1)] = selected_color;
	display[getPos(curr_x + 1, curr_y + 1)] = selected_color;

	display2[getPos(curr_x, curr_y)] = selected_color;
	display2[getPos(curr_x + 1, curr_y)] = selected_color;
	display2[getPos(curr_x, curr_y + 1)] = selected_color;
	display2[getPos(curr_x + 1, curr_y + 1)] = selected_color;

}

void
print_from(unsigned char * form, int length) {
	int i,j,z = 0;

	for(i = length; j < 20*20; j++, i++, z++) {
		if(z == 20){
			i += WIDTH - 20;
			z = 0;
		}
		display2[i] = form[j];
		display[i] = form[j];
	}
}