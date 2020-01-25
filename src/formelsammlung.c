#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#include <keyboard.hpp>
#include <string.h>
#include <sprite.h>
#include "menu.hpp"

int main(void) {
	Bdisp_EnableColor(1);
	Bdisp_Fill_VRAM(COLOR_RED, 1);
	
	
	static struct menu_tab Tab0 = {"Option", 7, {{1, "Text"}, {2, "Expression"}, {3, "Number Format"}, {4, "Clr Constraint"}, {5, "Show All"}, {6, "Hide"}, {7, "Area Calc"}}};
	static struct menu_tab Tab1 = {"Properties", 5, {{11, "to the front"}, {12, "to the back"}, {13, "All Text"}, {14, "Fade I/O"}, {15, "Store Picture"}}};
	static struct menu_tab Tab2 = {"File", 4, {{21, "New"}, {22, "Open"}, {23, "Save as"}, {24, "Key Help"}}};
	static struct menu_tab Tab3 = {"View", 6, {{31, "Zoom Box"}, {32, "Pan"}, {33, "Scroll"}, {34, "Zoom In"}, {35, "Zoom Out"}, {36, "Zoom to Fit"}}};
	static struct menu_tab Tab4 = {"Edit", 6, {{41, "Undo/Redo"}, {42, "Select All"}, {43, "Deselect All"}, {44, "Select Figure"}, {45, "Delete"}, {46, "Clear All"}}};
	static struct menu_tab Tab5 = {"Draw", 8, {{51, "Point"}, {52, "Line Segment"}, {53, "Infinite Line"}, {54, "Ray"}, {55, "Vector"}, {56, "Circle"}, {57, "Arc"}, {58, "SemiCirc(Diam)"}}};
	static struct menu_tab Tab6 = {"Draw Spec", 7, {{61, "Triangle"}, {62, "Isocs Triangle"}, {63, "Rectangle"}, {64, "Square"}, {65, "Polygon"}, {66, "Regular n-gon"}, {67, "Function f(x)"}}};
	static struct menu_tab Tab7 = {"Construct", 8, {{71, "Perp Bisector"}, {72, "Perpendicular"}, {73, "Midpoint"}, {74, "Intersection"}, {75, "Angle Bisector"}, {76, "Parallel"}, {77, "Tangent"}, {78, "Attached Angle"}}};
	static struct menu_tab Tab8 = {"Transform", 6, {{81, "Reflection"}, {82, "Translation"}, {83, "Trans(Sel Vec)"}, {84, "Rotation"}, {85, "Dilation"}, {86, "Symmetry"}}};
	static struct menu_tab Tab9 = {"Animate", 8, {{91, "Add Animation"}, {92, "Replace Anima"}, {93, "Trace"}, {94, "Edit Animation"}, {95, "Go(once)"}, {96, "Go(repeat)"}, {97, "Add Table"}, {98, "Display Table"}}};

	static struct menu_page Page0 = {"OPT", KEY_CTRL_OPTN, 2, {&Tab0, &Tab1}};
	static struct menu_page Page1 = {"F1", KEY_CTRL_F1, 2, {&Tab2, &Tab3}};
	static struct menu_page Page2 = {"F2", KEY_CTRL_F2, 1, {&Tab4}};
	static struct menu_page Page3 = {"F3", KEY_CTRL_F3, 2, {&Tab5, &Tab6}};
	static struct menu_page Page4 = {"F4", KEY_CTRL_F4, 1, {&Tab7}};
	static struct menu_page Page5 = {"F5", KEY_CTRL_F5, 1, {&Tab8}};
	static struct menu_page Page6 = {"F6", KEY_CTRL_F6, 1, {&Tab9}};

	static struct Tmenu geometry = {7, {&Page0,&Page1,&Page2,&Page3,&Page4,&Page5,&Page6}};
	
	int choice, key;	
	char buf[10]; buf[0]= ' '; buf[1] = ' ';
	
	PrintXY(1, 1, "xxPress [EXE] to launch the menu", 0x20, TEXT_COLOR_BLACK);
	PrintXY(1, 2, "xxthe menu", 0x20, TEXT_COLOR_BLACK);

	while(1){
		GetKey(&key);
		if(key==KEY_CTRL_EXE){
			choice = menu(&geometry, 3, 1);
			itoa(choice, buf+2);
			PrintXY(1, 4, "xxYour choice is:", 0x20, TEXT_COLOR_BLACK);
			PrintXY(1, 5, "xx          ", 0x01, TEXT_COLOR_RED);
			PrintXY(1, 5, buf, 0x20, TEXT_COLOR_BLACK);
		}
	}
	return 0;
}
