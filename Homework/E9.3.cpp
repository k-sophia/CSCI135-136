/**********
Simulate a circuit for controlling a hallway light
that has switched at both ends of the hallway.
- each switch can be up or down
- the light can be on or off

Toggling either switch turns the lamp on or off.

Provide and define functions:
-   int get_first_switch_state();
-   int get_second_switch_state();
-   int get_lamp_state();
-   void toggle_first_switch();
-   void toggle_second_switch();
**********/

#include <iostream>
#include <string>
using namespace std;

class Circuit {
	public:
		int get_first_switch_state();
		int get_second_switch_state();
		int get_lamp_state();
		void toggle_first_switch();
		void toggle_second_switch();
	private:
        //0 for down, 1 for up
		int first_switch = 0;
		int second_switch = 0;
        //0 for off, 1 for on
		int lamp_state = 0;
};

int Circuit::get_first_switch_state() {
    return first_switch;
}

int Circuit::get_second_switch_state() {
    return second_switch;
}

int Circuit::get_lamp_state() {
    return lamp_state;
}

void Circuit::toggle_first_switch() {
    if (first_switch == 0) {
        first_switch = 1;
    }
    else if (first_switch == 1) {
        first_switch = 0;
    }

    if (lamp_state == 0) {
        lamp_state = 1;
    }
    else if (lamp_state == 1) {
        lamp_state = 0;
    }
}

void Circuit::toggle_second_switch() {
    if (second_switch == 0) {
        second_switch = 1;
    }
    else if (second_switch == 1) {
        second_switch = 0;
    }

    if (lamp_state == 0) {
        lamp_state = 1;
    }
    else if (lamp_state == 1) {
        lamp_state = 0;
    }
}

int main() {
    Circuit c;

    cout << "Initial state:\n";
    cout << "First: " << c.get_first_switch_state() << ", ";
    cout << "Second: " << c.get_second_switch_state() << ", ";
    cout << "Lamp: " << c.get_lamp_state() << endl;

    c.toggle_first_switch();
    cout << "\nAfter toggling first switch:\n";
    cout << "First: " << c.get_first_switch_state() << ", ";
    cout << "Second: " << c.get_second_switch_state() << ", ";
    cout << "Lamp: " << c.get_lamp_state() << endl;

    c.toggle_second_switch();
    cout << "\nAfter toggling second switch:\n";
    cout << "First: " << c.get_first_switch_state() << ", ";
    cout << "Second: " << c.get_second_switch_state() << ", ";
    cout << "Lamp: " << c.get_lamp_state() << endl;
}