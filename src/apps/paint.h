#ifndef PAINT_H_INCLUDED
#define PAINT_H_INCLUDED

int paint_main(int argc, char *argv[]);

int execute(int acum_x, int acum_y, mouse_event_t m_event);

int get_action(int acum_x, int acum_y, mouse_event_t m_event); 

void print_menu();

void print_colors_menu();

void print_line(int acum_x, int acum_y, int selected_color, mouse_event_t m_event);

void print_line_aux(int fixed_x, int fixed_y, int acum_x, int acum_y, int type, int selected_color);

void print_square(int acum_x, int acum_y, int selected_color, mouse_event_t m_event);

void print_circle(int acum_x, int acum_y, int selected_color, mouse_event_t m_event);

void print_circle_aux(int fixed_x, int fixed_y, int acum_x, int acum_y, int radius, int center_x, int center_y, int selected_color, int type);

float distance(int p1_x, int p1_y, int p2_x, int p2_y);

int min_array(int * array, int len);

float sqrt(const float x);

void print_mouse(int curr_x, int curr_y, int prev_x, int prev_y);

void print_brush_color(int selected_color);
#endif