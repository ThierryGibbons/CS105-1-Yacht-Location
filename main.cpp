#include <iostream>
using namespace std;

class Location { //                                                                         Define Location class
    //                                                                              Step 1a: Declare member variables
    public:
        int degrees; //                                                                         Stores degrees, it's an integer because degrees are whole numbers (0 to 180 for latitude, 0 to 90 for longitude)
        float minutes; //                                                                       Stores minutes, it's a float because minutes can have decimal values (0 to 59.9999)
        char direction; //                                                                      Stores the direction letter (N, S, E, W), it's a char because it will only store one character
                                                                                // -----
        //                                                                          Step 1b: Implement the getpos() member function
    void getpos(bool lat) {
        // Declare local variables
        bool deg = true;
        bool min = true;
        bool dir = true;

    if (lat) {
            cout << "\nLatitude" << endl;
        } else {
            cout << "\nLongitude" << endl;
        }

        //                                                                                  Get Location from user
        while (deg) {
            cout << "Input degrees between 0 and 180: "; //                                         Get Degrees
            cin >> degrees;

            if (cin.fail() || degrees < 0 || degrees > 180) {
                cout << "Invalid input." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                deg = false;
            }
        }

        while (min) {
            cout << "Enter minutes between 0 and 60: "; //                                          Get Minutes
            cin >> minutes;

            if (cin.fail() || minutes < 0 || minutes >= 60) {
                cout << "Invalid input." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                min = false;
            }
        }

    //                                                                                              Get Direction
    if (lat) {
            while (dir) {
                cout << "Enter latitude (N/S): ";
                cin >> direction;

                if (cin.fail() || (toupper(direction) != 'N' && toupper(direction) != 'S')) {
                    cout << "Invalid input. Please enter either N or S." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    dir = false;
                    direction = toupper(direction);
                }
            }
        } else {
            while (dir) {
                cout << "Enter longitude (E/W): ";
                cin >> direction;

                if (cin.fail() || (toupper(direction) != 'E' && toupper(direction) != 'W')) {
                    cout << "Invalid input. Please enter either E or W." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    dir = false;
                    direction = toupper(direction);
                }
            }
        }
    }

                                                                                // -----
};

class Yacht {

    //                                                                              Step 2a: Declare static int and int for yacht count and serial number
    public:
    static int count;
    int serial_number;

    //                                                                              Step 2b: Declare two Location member variables for latitude and longitude
    Location latitude;
    Location longitude;

    //                                                                              Step 2c: Implement the Yacht constructor
    Yacht() {
        count++;
        serial_number = count;
    }

    //                                                                              Step 2d: Implement the get_pos() member function
    void get_pos() {
        cout << "*************************************" << endl;
        cout << "Enter the location of yacht " << serial_number << endl;
        latitude.getpos(true);
        longitude.getpos(false);
    }

    //                                                                              Step 2e: Implement the display() member function
    void display() {
        //                                                                              Display the yacht's serial number and location
        cout << "\nShip Serial Number: " << serial_number << endl;
        cout << "Position: " << latitude.degrees << "°" << latitude.minutes << " " << latitude.direction << " Latitude " << longitude.degrees << "°" << longitude.minutes << " " << longitude.direction << " Longitude" << endl;
    }

};

int Yacht::count = 0; //                                                                        Initialise the static count variable

//                                                                                          Main Function
int main() {
    //                                                                              Step 3a: Create three Yacht objects
    Yacht yacht1;
    Yacht yacht2;
    Yacht yacht3;

    //                                                                                  Display Title: Inputs
    cout << "**************Ocean Race 2021-22**************\n" << endl;

    //                                                                              Step 3b: Call get_pos() for each yacht to get user input for location
    yacht1.get_pos();
    yacht2.get_pos();
    yacht3.get_pos();

    //                                                                                  Display Seperator
    cout << "\n*************************************\n" << endl;

    //                                                                              Step 3c: Call display() for each yacht to display its number and location
    yacht1.display();
    yacht2.display();
    yacht3.display();

    //                                                                                  Display Title: Cuurent Results
    cout << "\n**************Welcome to Ocean Race 2021-22**************\n" << endl;

    return 0;
}
