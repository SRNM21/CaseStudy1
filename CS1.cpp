#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <string>
#include <sstream>

using namespace std;

// <-- Customer's Reservation Informations -->
vector<string> list_of_date_of_flight;
vector<string> list_of_fullname;
vector<string> list_of_gender;
vector<string> list_of_age;
vector<string> list_of_mobile_num;
vector<string> list_of_body_temp;
vector<string> list_of_exposure;
vector<string> list_of_room_type;

// <-- Total number of customers -->
int total_economy_customer = 0;
int total_deluxe_customer = 0;
int total_executive_customer = 0;

// <-- Total earnings -->
int total_economy_earnings = 0;
int total_deluxe_earnings = 0;
int total_executive_earnings = 0;

// <-- Total number of adult and minor -->
int total_number_of_adult = 0;
int total_number_of_minor = 0;

// <-- Total number of male and female -->
int total_number_of_male = 0;
int total_number_of_female = 0;

/*
    -=[ MACROS ]=-
*/

// <-- Null and Space -->
#define setspace(X) setw(X) << " "
#define _NULL_ ""

// <-- Colors and Designs -->
#define GREEN(WORD) design(WORD, 10)
#define YELLOW(WORD) design(WORD, 14)
#define RED(WORD) design(WORD, 12)
#define HEADER(WORD) design(WORD, 101)

// <-- Codes -->
#define fori(CONDITION) for (int i = 0; i < CONDITION; i++)
#define _DATABASE_ "group1_database.txt"
#define _INVALID_MONTH_ "invalid"
#define _INVALID_ invalid = true;

/*
    -=[ SYSTEM'S DATABASE ]=-
*/

// <-- Function to update the data in the text file -->
void updateDatabase()
{
    ofstream database_store;

    // Open the text file (database)
    database_store.open(_DATABASE_);

    // Store all data if the text file exist
    if (database_store.is_open())
    {
        database_store << total_economy_customer << endl;
        database_store << total_deluxe_customer << endl;
        database_store << total_executive_customer << endl;
        database_store << total_economy_earnings << endl;
        database_store << total_deluxe_earnings << endl;
        database_store << total_executive_earnings << endl;
        database_store << total_number_of_adult << endl;
        database_store << total_number_of_minor << endl;
        database_store << total_number_of_male << endl;
        database_store << total_number_of_female << endl;

        // mark x if the vectors is empty
        if (list_of_date_of_flight.empty())
        {
            fori(9)
            {
                database_store << "x" << endl;
            }
            
        // Otherwise, store all data from vectors into text file
        } 
        else 
        {
            fori(list_of_date_of_flight.size())
            {
                database_store << list_of_date_of_flight[i] << endl;
                database_store << list_of_fullname[i] << endl;
                database_store << list_of_gender[i] << endl;
                database_store << list_of_age[i] << endl;
                database_store << list_of_mobile_num[i] << endl;
                database_store << list_of_body_temp[i] << endl;
                database_store << list_of_exposure[i] << endl;
                database_store << list_of_room_type[i] << endl;

                // mark x in the end of file
                if (i == (list_of_date_of_flight.size() - 1))
                { 
                    database_store << "x"; 
                }
            }
        }

    // Otherwise, display not found
    } 
    else 
    {
        system("cls");
        cout << setspace(50) << "NO DATABASE HAS FOUND!" << endl;
    }

    // Close the text file (database)
    database_store.close();
}

// <-- Function to extract data from text file -->
void retrieveData()
{
    ifstream database_read;
    string retrieve_date_of_flight;
    string retrieve_fullname;
    string retrieve_gender;
    string retrieve_age;
    string retrieve_mobile_num;
    string retrieve_body_temp;
    string retrieve_exposure;
    string retrieve_room_type;
    string line;

    // Open the text file (database)
    database_read.open(_DATABASE_);

    // Retrieve all data if text file exist
    if (database_read.is_open())
    {
        database_read >> total_economy_customer;
        database_read >> total_deluxe_customer;
        database_read >> total_executive_customer;
        database_read >> total_economy_earnings;
        database_read >> total_deluxe_earnings;
        database_read >> total_executive_earnings;
        database_read >> total_number_of_adult;
        database_read >> total_number_of_minor;
        database_read >> total_number_of_male;
        database_read >> total_number_of_female;

        // Retrieve all data from text file into vectors
        while (getline(database_read, line))
        {

            // Check if the text file reached it's end
            getline(database_read, line);
            if (line == "x" ) 
            { 
                break; 
            } 
            else 
            { 
                retrieve_date_of_flight = line; 
            }

            getline(database_read, retrieve_fullname);
            database_read >> retrieve_gender;
            database_read >> retrieve_age;
            database_read >> retrieve_mobile_num;
            database_read >> retrieve_body_temp;
            database_read >> retrieve_exposure;
            database_read >> retrieve_room_type;

            list_of_date_of_flight.push_back(retrieve_date_of_flight);
            list_of_fullname.push_back(retrieve_fullname);
            list_of_gender.push_back(retrieve_gender);
            list_of_age.push_back(retrieve_age);
            list_of_mobile_num.push_back(retrieve_mobile_num);
            list_of_body_temp.push_back(retrieve_body_temp);
            list_of_exposure.push_back(retrieve_exposure);
            list_of_room_type.push_back(retrieve_room_type);
        }

    // Otherwise, create a new one
    } 
    else 
    {
        ofstream database_create(_DATABASE_);
    }

    // Close the text file
    database_read.close();
}

/*
    -=[ SYSTEM'S DESIGN ]=-
*/

// <-- Function to design the texts -->
string design(string word, int mod)
{
    HANDLE op = GetStdHandle(STD_OUTPUT_HANDLE);

    // Identify the modification of text
    if (mod == 101)
    {
        string display;
        string menu_header;

        // Identify the word if the modification is header
        if (word == "MAIN_MENU")
        {
            menu_header = ".oo=----------------------@}~~~~o>.!   FLIGHT RESERVATION SYSTEM  !>.o~~~~{@----------------------=oo";
        } 
        else if (word == "ADD_RESERVATION_MENU")
        {
            menu_header = ".oo=----------------------@}~~~~o>.!    ADD FLIGHT RESERVATION    !>.o~~~~{@----------------------=oo";
        } 
        else if (word == "DELETE_RESERVATION_MENU")
        {
            menu_header = ".oo=----------------------@}~~~~o>.!      DELETE RESERVATION      !>.o~~~~{@----------------------=oo";
        } 
        else if (word == "REPORT_MENU")
        {
            menu_header = ".oo=----------------------@}~~~~o>.! REPORT OF FLIGHT RESERVATION !>.o~~~~{@----------------------=oo";
        } 
        else if (word == "EXIT")
        {
            menu_header = ".oo=----------------------@}~~~~o>.!             EXIT             !>.o~~~~{@----------------------=oo";
        }

        // Build string header
        string line_1 = ". oo=-------------=o=------------------------=o=------=o=---=o=-------------=o=-----------=o=-----------=o=--@}~~~~=oo>";
        string line_2 = ". |                |                          |        |     |               |    Body     | Exposure to |           |>";
        string line_3 = ". | Date of Flight |        Fullname          | Gender | Age | Mobile Number | Temperature |  covid 19   | Room Type |>";
        string line_4 = ". |                |                          |        |     |               |             |  positive   |           |>";
        string line_5 = ". oo=~~~~{@-------=o=------------------------=o=------=o=---=o=-------------=o=-----------=o=-----------=o=--------=oo>";

        string ending_line_1 = "oo=---------------------------------------------------------------------=[ ~~~~{@ ";
        string ending_line_2 = "]=---------------------------------------------------------------------=oo";
        string seperator = "@}~~~~ ]=---------------------------=o=---------------------------=[ ~~~~{@";

        string report_table_header = line_1 + line_2 + line_3 + line_4 + line_5;
        string ending_line = ending_line_1 + ending_line_2;

        // Identify the text to display according to the first argument
        if (word == "REPORT_TABLE")
        { 
            display = report_table_header; 
        }
        else if (word == "REPORT_TABLE_END")
        { 
            display = line_1; 
        } 
        else if (word == "END_LINE")
        { 
            display = ending_line; 
        } 
        else if (word == "SEPERATOR")
        { 
            display = seperator; 
        } 
        else 
        { 
            display = menu_header; 
        }

        // Identify the color based on the characters of text to display
        fori(display.size())
        {
            if (display[i] == '=' || display[i] == '!')
            {
                SetConsoleTextAttribute(op, 6);
            } 
            else if (display[i] == '@')
            {
                SetConsoleTextAttribute(op, 4);
            } 
            else if (display[i] == '~' || display[i] == '{' || display[i] == '}')
            {
                SetConsoleTextAttribute(op, 10);
            } 
            else if (display[i] == '-' || display[i] == '|')
            {
                SetConsoleTextAttribute(op, 14);
            } 
            else 
            {
                SetConsoleTextAttribute(op, 15);
            }

            // Check and print the characters of text to display
            if (display[i] == '.')
            {
                display == menu_header ? cout << setspace(62) : cout << setspace(20);
            } 
            else if (display[i] == '>')
            {
                cout << endl;
            } 
            else 
            {
                cout << display[i];
            }
        }

        if (!(word == "REPORT_TABLE" || word == "SEPERATOR")) 
        { 
            cout << endl; 
        }
    } 
    else 
    {
        SetConsoleTextAttribute(op, mod);
        cout << word;
    }

    // Set color of texts to default (white)    
    SetConsoleTextAttribute(op, 15);
    return _NULL_;
}

// <-- Function to identify if the customer is allowed onboard -->
string validate(string word, string check, int index)
{
    HANDLE op = GetStdHandle(STD_OUTPUT_HANDLE);

    // Convert string value of body temp of current index into float value
    float temp_body_temp = stof(list_of_body_temp[index]);

    // Change the text color into color red if the customer is not allowed onboard
    if ((check == "CUSTOMER" || check == "COVID_EXPOSURE") && list_of_exposure[index] == "Yes")
    {
        SetConsoleTextAttribute(op, 12);
    } 
    else if ((check == "CUSTOMER" || check == "BODY_TEMP") && temp_body_temp > 37.5)
    {
        SetConsoleTextAttribute(op, 12);
    }

    cout << word;

    // Set color of texts to default (white)
    SetConsoleTextAttribute(op, 15);
    return _NULL_;
}

// <-- Functions to make line -->
void line()
{
    cout << endl << design("END_LINE", 101) << endl;
}

void seperator()
{
    cout << setspace(41) << design("SEPERATOR", 101) << endl;
}

/*
    -=[ SYSTEM'S ERROR HANDLERS ]=-
*/

// <-- Get user input -->
string getUserInput(string getter, string condition, char except_word)
{
    string input;
    bool invalid;

    do 
    {
        // Get user input
        getline(cin, input);
        invalid = false;

        string GETTER_ERROR;
        fori(getter.size())
        {
            GETTER_ERROR += toupper(getter[i]);
        }
        
        // Check if the input is blank/empty (accidentally press enter)
        string check_input;
        fori(input.size())
        {
            if (!isspace(input[i]))
            {
                check_input += input[i];
            }
        }
        
        if (check_input.empty())
        {
            cout << setspace(50) << RED("INVALID INPUT") << "," << endl;
            cout << setspace(50) << setw(45) << left << YELLOW("Please try again:");

            _INVALID_

        // Check if the input is alpha
        } 
        else if (condition == "ALPHA")
        {
            fori(input.size())
            {
                if (isalpha(input[i]) == 0 && input[i] != except_word)
                {
                    cout << setspace(50) << RED(GETTER_ERROR + " MUST CONTAIN LETTERS ONLY") << "," << endl;
                    cout << setspace(50) <<  setw(45) << left << YELLOW("Please enter " + getter + " again:");

                    _INVALID_
                    break;
                }
            }

        // Check if the input is numerical
        } 
        else if (condition == "NUMERICAL")
        {
            fori(input.size())
            {
                if (!isdigit(input[i]) && input[i] != except_word) 
                {
                    cout << setspace(50) << RED(GETTER_ERROR + " MUST BE NUMERICAL") << "," << endl;
                    cout << setspace(50) << setw(45) << left << YELLOW("Please enter " + getter + " again:");

                    _INVALID_
                    break;
                }
            }
        }

    // Loop while the input is invalid
    } 
    while (invalid);

    // Return Input
    return input;
}

// <-- Date Error Handler -->
string getDateOfFlight()
{
    string date_of_flight;
    bool invalid;

    do 
    {
        date_of_flight = getUserInput("Date of Flight", "NUMERICAL", '/');
        invalid = false;

        // Check the date format
        if (!(date_of_flight[2] == '/' && date_of_flight[5] == '/') || date_of_flight.size() != 10 ) 
        {
            cout << setspace(50) << RED("INVALID DATE FORMAT") << "," << endl;
            cout << setspace(50) << setw(45) << left << YELLOW("Please enter Date of flight again:");

            _INVALID_
        }
        
        // Check the date if the format is correct
        if (!invalid)
        {
            stringstream _month_;
            stringstream _day_;
            stringstream _year_;
            string month_name;

            // Seperate the month, day, and year,
            string month;
            _month_ << date_of_flight[0] << date_of_flight[1];
            _month_ >> month;

            string day;
            _day_ << date_of_flight[3] << date_of_flight[4];
            _day_ >> day;

            string year;
            _year_ << date_of_flight[6] << date_of_flight[7] << date_of_flight[8] << date_of_flight[9];
            _year_ >> year;

            // convert the date into integer values
            int temp_month = stoi(month);
            int temp_day = stoi(day);
            int temp_year = stoi(year);
            int feb_day;
            
            string month_names[] = 
            {
                _NULL_, "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", 
                "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"
            };

            (temp_month > 12 || temp_month == 0) ? month_name = _INVALID_MONTH_ : month_name = month_names[temp_month];

             // Check if the year is leap year
            if (temp_year % 4 == 0 && temp_month == 2) 
            {
                month_name.append(" (LEAP YEAR)");
                feb_day = 29;
            } 
            else 
            {
                feb_day = 28;
            }

            // Display if the year is below 2023
            if (temp_year < 2023)
            {
                cout << setspace(50) << RED("YEAR OF FLIGHT MUST BE AHEAD OF THE CURRENT") << endl
                    << setspace(50) << RED("DATE") << ", "
                    << setw(39) << left << YELLOW("Please enter Date of flight again:");

                _INVALID_

            // Display if the year is above 2028
            } 
            else if (temp_year > 2028)
            {
                cout << setspace(50) << RED("ONLY 5-YEAR ADVANCED RESERVATIONS ARE") << endl
                    << setspace(50) << RED("ACCEPTED") << ", "
                    << setw(35) << left << YELLOW("Please enter Date of flight again:");

                _INVALID_

            // Otherwise, check the month
            } 
            else 
            {

                // Check date for february
                if (temp_month == 2) 
                {
                    invalid = temp_day > feb_day || temp_day == 0 ? true : false;

                // Check the day for the months with 31 days
                } 
                else if (temp_month == 1 || temp_month == 3 || temp_month == 5 || temp_month == 7
                    || temp_month == 8 || temp_month == 10 || temp_month == 12) 
                {

                    invalid = temp_day > 31 || temp_day == 0 ? true : false;

                // Check the day for the months with 30 days
                } 
                else
                {
                    invalid = temp_day > 30 || temp_day == 0 ? true : false;
                }
                
                // Display the invalid input
                if (invalid && month_name == _INVALID_MONTH_)
                {
                    cout << setspace(50) << RED("DAY ") << "'" << GREEN(day) << "'" << RED(" AND MONTH ") 
                                        << "'" << GREEN(month) << "'" << RED(" IS INVALID") << "," << endl;
                    cout << setspace(50) << setw(45) << left << YELLOW("Please enter Date of flight again:");
                } 
                else if (invalid)
                {
                    cout << setspace(50) << RED("DAY ") << "'" << GREEN(day) << "'" << RED(" IN ") 
                                        << GREEN(month_name) << RED(" IS INVALID") << "," << endl;
                    cout << setspace(50) << setw(45) << left << YELLOW("Please enter Date of flight again:");
                } 
                else if (month_name == _INVALID_MONTH_) 
                {
                    cout << setspace(50) << RED("MONTH ") << "'" << GREEN(month) << "'" 
                                        << RED(" IS INVALID")<< "," << endl;
                    cout << setspace(50) << setw(45) << left << YELLOW("Please enter Date of flight again:");

                    _INVALID_
                } 
            }
        }

    // loop while the input is invalid
    } 
    while (invalid);

    // Return Date of Flight
    return date_of_flight;
}

// <-- Age Error Handler -->
int getAge()
{
    string temp_age;
    int age;
    bool invalid;

    do 
    {
        temp_age = getUserInput("Age", "NUMERICAL", ' ');
        invalid = false;

        // Check if the age is greater than 125
        age = stoi(temp_age);

        if (age > 125 || age == 0)
        {
            cout << setspace(50) << RED("INVALID AGE") << "," << endl;
            cout << setspace(50) << setw(45) << left << YELLOW("Please enter Age again:");

            _INVALID_
        }

    // Loop while the input is invalid
    } 
    while (invalid);

    // Return Age
    return age;
}

// <-- Mobile Number Error Handler -->
string getMobileNumber(bool add)
{
    string mobile_num;
    bool invalid;

    do 
    {
        mobile_num = getUserInput("Mobile Number", "NUMERICAL", ' ');
        invalid = false;

        // Check the the size of numbers if it's 11 digits
        if (mobile_num.size() != 11)
        {
            cout << setspace(50) << RED("MOBILE NUMBER MUST BE 11 DIGITS") << "," << endl;
            cout << setspace(50) << setw(45) << left << YELLOW("Please enter Mobile Number again:");

            _INVALID_
        
        
        // Check the format of phone number
        }
        else if (!(mobile_num[0] == '0' && mobile_num[1] == '9'))
        {
            cout << setspace(50) << RED("MOBILE NUMBER MUST BE BASED ON PHILIPPINES") << "," << endl;
            cout << setspace(50) << setw(45) << left << YELLOW("Please enter Mobile Number again:");

            _INVALID_
        }

        // Check if the mobile number has duplicates
        fori(list_of_mobile_num.size())
        {
            if (add && list_of_mobile_num[i] == mobile_num )
            {
                cout << setspace(50) << RED("MOBILE NUMBER HAS TAKEN") << "," << endl;
                cout << setspace(50) << setw(45) << left << YELLOW("Please enter another Mobile Number:");

                _INVALID_
                break;
            }
        }

    // loop while the input is invalid
    } 
    while (invalid);

    // Return Mobile Number
    return mobile_num;
}

// <-- Body Temperature Error Handler -->
float getBodyTemperature()
{
    string temp_body_temp;
    float body_temp;
    bool invalid;

    do 
    {
        temp_body_temp = getUserInput("Body Temperature", "NUMERICAL", '.');
        invalid = false;

        // Check if the body temperature is greater than 50 or less than 30
        body_temp = stof(temp_body_temp);

        if (body_temp > 50 || body_temp < 30)
        {
            cout << setspace(50) << RED("INVALID BODY TEMPERATURE") << "," << endl;
            cout << setspace(50) << setw(45) << left << YELLOW("Please enter Body Temperature again:");

            _INVALID_
        }

    // Loop while the input is invalid
    } 
    while (invalid);

    // Return Body Temperature
    return body_temp;
}

// <-- Room Type Error Handler -->
string getRoomType()
{
    string room_type;
    bool invalid;

    do 
    {
        room_type = getUserInput("Room Type", "ALPHA", ' ');
        invalid = false;

        // Display error if the input is not in the choices
        if  (!(room_type == "Economy" || room_type == "Deluxe" || room_type == "Executive"))
        {
            cout << setspace(50) << "\"" << GREEN(room_type) << "\"" << RED(" IS NOT IN THE SELECTION") << "," << endl;
            cout << setspace(50) << setw(45) << left << YELLOW("Please enter Room Type again:");

            _INVALID_
        }

    // Loop while the input is invalid
    } 
    while (invalid);

    // Return Rooom Type
    return room_type;
}

// <-- Selections Error Handler -->
int getSelection(string getter)
{
    string temp_selection;
    bool invalid;

    do 
    {
        temp_selection = getUserInput("Selection", "NUMERICAL", ' ');
        invalid = false;

        // Display error if the input was not in the selection ( MAIN MENU )
        if (getter == "MAIN_MENU")
        {
            if (!(temp_selection == "1" || temp_selection == "2" || temp_selection == "3" || temp_selection == "4"))
            {
                cout << setspace(50) << RED("INPUT MUST BE FROM ") << "'" << GREEN("1") << "'"
                                    << RED(" TO ") << "'" << GREEN("4") << "'," << endl;
                cout << setspace(50) << setw(45) << left << YELLOW("Please select again:");

                _INVALID_
            }

        // Display error if the input was not in the selection ( ADD RESERVATION MENU )    
        } 
        else if (getter == "ADD_RESERVATION_MENU")
        {
            if (!(temp_selection == "1" || temp_selection == "2"))
            {
                cout << setspace(50) << RED("INPUT MUST BE ") << "'" << GREEN("1") << "'"
                                    << RED(" OR ") << "'" << GREEN("2") << "'," << endl;
                cout << setspace(50) << setw(45) << left << YELLOW("Please select again:");

                _INVALID_
            }
        }

    // Loop while the input is invalid
    } 
    while (invalid);

    // Return selection
    return stoi(temp_selection);
}

// <-- Boolean Values Error Handler -->
bool getBoolean()
{
    string temp_bool_value;
    bool invalid;

    do 
    {
        temp_bool_value = getUserInput(_NULL_, _NULL_, ' ');
        invalid = false;

        // Display error if the input is not '0' or '1'
        if (!(temp_bool_value == "0" || temp_bool_value == "1"))
        {
            cout << setspace(50) << RED("INPUT MUST BE ") << "'" << GREEN("0") << "'"
                                << RED(" OR ") << "'" << GREEN("1") << "'," << endl;
            cout << setspace(50) << setw(45) << left << YELLOW("Please select again:");
            
            _INVALID_
        }

    // Loop while the input is invalid
    } 
    while (invalid);

    // Return boolean value
    return temp_bool_value == "1" ? true : false;
}

/*
    -=[ SYSTEM'S MENU ]=-
*/

// Save reservation ( ADD RESERVATION MENU )
void saveReservation(
    string save_date_of_flight, 
    string save_fullname, 
    bool save_gender, 
    int save_age,
    string save_mobile_num, 
    float save_body_temp, 
    bool save_exposure, 
    string save_room_type
){

    string new_gender;

    // increment genders and convert boolean value into string values
    if (save_gender)
    {
        new_gender = "Male";
        total_number_of_male++;
    } 
    else 
    {
        new_gender = "Female";
        total_number_of_female++;
    }

    // Convert non-string value into string value
    string new_body_temp;
    stringstream temp_body_temp;
    temp_body_temp << setprecision(3) << save_body_temp;
    temp_body_temp >> new_body_temp;

    string new_age = to_string(save_age);

    string new_exposure = save_exposure ? "Yes" : "No";

    // Increment the total number of minor/adult
    save_age < 18 ? total_number_of_minor++ : total_number_of_adult++;

    // Add rate and increment customer if the customer is allowed onboard
    if (new_exposure == "No" && save_body_temp <= 37.5)
    {

        // Identify the rate based on the customer's reservation information
        if (save_room_type == "Economy")
        {
            save_age < 18 ? total_economy_earnings += 700 : total_economy_earnings += 900;
            total_economy_customer++;
        } 
        else if (save_room_type == "Deluxe")
        {
            save_age < 18 ? total_deluxe_earnings += 1200 : total_deluxe_earnings += 1400;
            total_deluxe_customer++;
        } 
        else if (save_room_type == "Executive")
        {
            save_age < 18 ? total_executive_earnings += 1700 : total_executive_earnings += 1900;
            total_executive_customer++;
        }
    }

    // Store the customer's reservation information in to the database
    list_of_date_of_flight.push_back(save_date_of_flight);
    list_of_fullname.push_back(save_fullname);
    list_of_gender.push_back(new_gender);
    list_of_age.push_back(new_age);
    list_of_mobile_num.push_back(save_mobile_num);
    list_of_body_temp.push_back(new_body_temp);
    list_of_exposure.push_back(new_exposure);
    list_of_room_type.push_back(save_room_type);

    // Update the database
    updateDatabase();
}

/*
    -=[ ADD RESERVATION MENU ]=-
*/
void addReservation()
{
    bool book_again;
    bool duplicate;

    do 
    {
        book_again = false;
        duplicate = false;

        // Display the add reservation menu
        cout << HEADER("ADD_RESERVATION_MENU") << endl;

        // Ask customer for reservation information
        cout << setspace(95) << "(" << GREEN("mm/dd/yyyy") << ")" << endl;
        cout << setspace(50) << setw(45) << left << YELLOW("Date of Flight:");
        string date_of_flight = getDateOfFlight();

        seperator();
        cout << setspace(50) << setw(45) << left << YELLOW("Fullname:");
        string fullname = getUserInput("Fullname", "ALPHA", ' ');

        seperator();
        cout << setspace(95) << "[ " << GREEN("0") << " ] - Female" << endl;
        cout << setspace(95) << "[ " << GREEN("1") << " ] - Male" << endl;
        cout << setspace(50) << setw(45) << left << YELLOW("Gender:");
        bool gender = getBoolean();

        seperator();
        cout << setspace(50) << setw(45) << left << YELLOW("Age:");
        int age = getAge();

        seperator();
        cout << setspace(95) << "(e.g. " << GREEN("09123456789") << ")"  << endl;
        cout << setspace(50) << setw(45) << left << YELLOW("Mobile Number:");
        string mobile_num = getMobileNumber(true);

        seperator();
        cout << setspace(50) << setw(45) << left << YELLOW("Body Temperature:");
        float body_temp = getBodyTemperature();

        seperator();
        cout << setspace(95) << "[ " << GREEN("0") << " ] - No" << endl;
        cout << setspace(95) << "[ " << GREEN("1") << " ] - Yes" << endl;
        cout << setspace(50) << setw(45) << left << YELLOW("Exposure to covid-19 positive:");
        bool exposure = getBoolean();

        seperator();
        cout << setspace(95) << "(\"" << GREEN("Economy") << "\"|\"" << GREEN("Deluxe")
                            << "\"|\"" << GREEN("Executive") << "\")" << endl;
        cout << setspace(50) << setw(45) << left << YELLOW("Room Type:");
        string room_type = getRoomType();

        // Check if the Customer is already in a reservation
        fori(list_of_date_of_flight.size())
        {
            if (list_of_fullname[i] == fullname)
            {
                duplicate = true;

                cout << endl << setspace(54) << RED("THIS PERSON IS ALREADY IN THE LIST OF RESERVATION") << endl;
                cout << setspace(51) << YELLOW("Would you like to book a different reservation instead?") << endl; 
                cout << endl << setspace(95) << "[ " << GREEN("0") << " ] - No" << endl;
                cout << setspace(95) << "[ " << GREEN("1") << " ] - Yes"<< endl;
                cout << setspace(50) << setw(45) << left << YELLOW("Enter your selection:");
                book_again = getBoolean();
                
                break;
            }
        }

        if (!duplicate)
        {
            
            // Ask customer to save or cancel their reservation
            seperator();
            cout << setspace(95) << "[ " << GREEN("1") << " ] - Save" << endl;
            cout << setspace(95) << "[ " << GREEN("2") << " ] - Cancel" << endl;
            cout << setspace(50) << setw(45) << left << YELLOW("Enter your selection :");
            int selection = getSelection("ADD_RESERVATION_MENU");

            seperator();

            // Save reservation if they pick selection 1
            if (selection == 1)
            {
                saveReservation(
                    date_of_flight, 
                    fullname, 
                    gender, 
                    age, 
                    mobile_num, 
                    body_temp, 
                    exposure, 
                    room_type
                );

                cout << setspace(66) << "** -" << GREEN("Reservation Saved") << "- **" << endl;
            } 
            else 
            {
                cout << setspace(64) << "** -" << GREEN("Reservation Cancelled") << "- **" << endl;
            }
        }

        if (book_again) 
        { 
            system("cls"); 
        }

    } 
    while (book_again);
}

// Delete reservation ( DELETE RESERVATION MENU )
void confirmDeleteReservation(int index)
{

    // Convert string numerical values into integers
    int temp_age = stoi(list_of_age[index]);

    float temp_body_temp = stof(list_of_body_temp[index]);

    // Decrement the number of minor/adult
    temp_age < 18 ? total_number_of_minor-- : total_number_of_adult--;

    // Decrement the number of male/female
    list_of_gender[index] == "Male" ? total_number_of_male-- : total_number_of_female--;

    // Deduct earnings and number of Customers if the Customer is onboard
    if (list_of_exposure[index] == "No" && temp_body_temp <= 37.5)
    {

        // Deduct the value of Earnings and number of Customers
        if (list_of_room_type[index] == "Economy")
        {
            temp_age < 18 ? total_economy_earnings -= 700 : total_economy_earnings -= 900;
            total_economy_customer--;   
        } 
        else if (list_of_room_type[index] == "Deluxe")
        {
            temp_age < 18 ? total_deluxe_earnings -= 1200 : total_deluxe_earnings -= 1400;
            total_deluxe_customer--;
        } 
        else if (list_of_room_type[index] == "Executive")
        {
            temp_age < 18 ? total_executive_earnings -= 1700 : total_executive_earnings -= 1900;
            total_executive_customer--;
        }
    }

    // Delete the customer's reservation information
    list_of_date_of_flight.erase(list_of_date_of_flight.begin() + index);
    list_of_fullname.erase(list_of_fullname.begin() + index);
    list_of_gender.erase(list_of_gender.begin() + index);
    list_of_age.erase(list_of_age.begin() + index);
    list_of_mobile_num.erase(list_of_mobile_num.begin() + index);
    list_of_body_temp.erase(list_of_body_temp.begin() + index);
    list_of_exposure.erase(list_of_exposure.begin() + index);
    list_of_room_type.erase(list_of_room_type.begin() + index);

    // Update the database
    updateDatabase();
}

/*
    -=[ DELETE RESERVATION MENU ]=-
*/
void deleteReservation()
{
    bool found = false;
    bool find_again;

    // Display the delete reservation menu
    cout << HEADER("DELETE_RESERVATION_MENU") << endl;

    do 
    {
        find_again = false;

        // Ask user for the date of flight and mobile number
        cout << setspace(95) << "(" << GREEN("mm/dd/yyyy") << ")" << endl;
        cout << setspace(50) << setw(45) << left << YELLOW("Enter your Date of Flight:");
        string del_date_of_flight = getDateOfFlight();

        seperator();
        cout << setspace(95) << "(e.g: " << GREEN("09123456789") << ")"  << endl;
        cout << setspace(50) << setw(45) << left << YELLOW("Enter your Mobile Number:");
        string del_mobile_num = getMobileNumber(false);

        seperator();
        
        // Loop to searh the reservation
        fori(list_of_date_of_flight.size())
        {
            if (list_of_date_of_flight[i] == del_date_of_flight && list_of_mobile_num[i] == del_mobile_num)
            {  
                found = true;

                // Identify the customer's title based on their gender
                string title = list_of_gender[i] == "Male" ? "Sir " : "Ma'am ";

                // Ask user if they want to continue to delete their reservation
                cout << setspace(95) << "[ " << GREEN("0") << " ] - No" << endl;
                cout << setspace(95) << "[ " << GREEN("1") << " ] - Yes"<< endl;
                cout << setspace(50) << RED("ARE YOU SURE TO DELETE YOUR RESERVATION") << "," << endl;
                cout << setspace(50) << title << GREEN(list_of_fullname[i]) << "?" << endl;
                cout << setspace(50) << setw(45) << left << YELLOW("Enter your selection:");
                bool confirm = getBoolean();

                seperator();

                // Delete reservation if confirmed
                if (confirm)
                {
                    confirmDeleteReservation(i);
                    cout << setspace(57) << "** -" << GREEN("Reservation was Deleted Successfully") << "- **" << endl;
                } 
                else 
                {
                    cout << setspace(59) << "** -" << GREEN("Delete Reservation was Cancelled") << "- **" << endl;
                }
            }
        }

        // Diplay if the reservation is not in the list
        if (!found)
        {
            cout << setspace(95) << "[ " << GREEN("0") << " ] - No" << endl;
            cout << setspace(95) << "[ " << GREEN("1") << " ] - Yes"<< endl;
            cout << setspace(50) << RED("RESERVATION NOT FOUND") << endl;
            cout << setspace(50) << setw(45) << left << YELLOW("Do you want to try again?:");
            find_again = getBoolean();

            // Add line seperator 
            if (find_again) 
            { 
                seperator(); 
            }
        }

    // Loop if the user wants to search again
    } 
    while (find_again);
}

// Print table ( REPORT MENU )
void printTableReservationInfo()
{

    // Display the header of reservations information
    HEADER("REPORT_TABLE");

    // Loop to display all the customer's reservation information
    fori(list_of_date_of_flight.size())
    {
        string fullname_display = list_of_fullname[i];
        string fullname_extension;
        float temp_body_temp = stof(list_of_body_temp[i]);

        // Split fullname into two parts if it's more than 24 characters
        if (fullname_display.size() > 24)
        {

            // Store the first part of fullname in fullname_extension
            fori(fullname_display.size())
            {
                fullname_extension += fullname_display[i];

                // Stop building first part of fullname
                if (fullname_extension.size() > 8 && isspace(fullname_display[i]))
                { 
                    break; 
                }
            }

            // Erase the first part of fullname from the original 
            fullname_display.erase(0, fullname_extension.size());

            // Display the first part of fullname
            cout << setspace(20) << left
                << YELLOW(" | ") << setspace(14)
                << YELLOW(" | ") << setw(24) << validate(fullname_extension, "CUSTOMER", i)
                << YELLOW(" | ") << setspace(6)
                << YELLOW(" | ") << setspace(3)
                << YELLOW(" | ") << setspace(13)
                << YELLOW(" | ") << setspace(11)
                << YELLOW(" | ") << setspace(11)
                << YELLOW(" | ") << setspace(9)
                << YELLOW(" | ") << endl;
        }

        // Display all the customer's reservation information
        cout << setspace(20) << left
            << YELLOW(" | ") << setw(14) << list_of_date_of_flight[i]
            << YELLOW(" | ") << setw(24) << validate(fullname_display, "CUSTOMER", i)
            << YELLOW(" | ") << setw(6) << list_of_gender[i]
            << YELLOW(" | ") << setw(3) << list_of_age[i]
            << YELLOW(" | ") << setw(13) << list_of_mobile_num[i]
            << YELLOW(" | ") << setw(11) << validate(list_of_body_temp[i], "BODY_TEMP", i)
            << YELLOW(" | ") << setw(11) << validate(list_of_exposure[i], "COVID_EXPOSURE", i)
            << YELLOW(" | ") << setw(9) << list_of_room_type[i]
            << YELLOW(" | ") << endl;
    }

    HEADER("REPORT_TABLE_END");
}

/*
    -=[ REPORT MENU ]=-
*/
void report()
{

    // Display the report of flight reservation menu
    cout << HEADER("REPORT_MENU") << endl;

    // Display the total customers and earnings
    cout << setspace(29) << left << setw(26) << YELLOW("Total Economy Customer:") << setw(30) << total_economy_customer
            << setspace(15) << setw(26) << YELLOW("Total Economy Earnings:") << total_economy_earnings << endl;
    cout << setspace(29) << left << setw(26) << YELLOW("Total Deluxe Customer:") << setw(30) << total_deluxe_customer
        << setspace(15) << setw(26) << YELLOW("Total Deluxe Earnings:") << total_deluxe_earnings << endl;
    cout << setspace(29) << left << setw(26) << YELLOW("Total Executive Customer:") << setw(30) << total_executive_customer
            << setspace(15) << setw(26) << YELLOW("Total Executive Earnings:") << total_executive_earnings << endl;
    cout << endl;

    // Print table of reservations
    printTableReservationInfo();

    // Compute the grand total earnings
    int grand_total_earnings = total_economy_earnings + total_deluxe_earnings + total_executive_earnings;

    // Display the total number of male/female, minor/adult and the grand total earnings
    cout << setspace(29) << left << setw(23) << YELLOW("Total number of adult:") << setw(33) << total_number_of_adult
            << setspace(15) << setw(24) << YELLOW("Total number of male:") << total_number_of_male << endl;
    cout << setspace(29) << left << setw(23) << YELLOW("Total number of minor:") << setw(33) << total_number_of_minor
            << setspace(15) << setw(24) << YELLOW("Total number of female:") << total_number_of_female << endl;
    cout << endl << setspace(65) << YELLOW("Grand total earnings:") << grand_total_earnings << endl;
}

/*
    -=[ MAIN MENU ]=-
*/
int main()
{
    retrieveData();
    int selection;

    // Display main menu while the input is not '4'
    while (selection != 4)
    {
        cout << HEADER("MAIN_MENU") << endl;
        
        cout << setspace(67) << "[ " << GREEN("1") << " ] - Add Reservation" << endl;
        cout << setspace(67) << "[ " << GREEN("2") << " ] - Delete" << endl;
        cout << setspace(67) << "[ " << GREEN("3") << " ] - Report" << endl;
        cout << setspace(67) << "[ " << GREEN("4") << " ] - Exit" << endl;
        cout << endl << setspace(50) << setw(45) << left << YELLOW("Enter your selection:");
        selection = getSelection("MAIN_MENU");
        
        system("cls");

        // Go to selected menu
        if (selection == 1)
        { 
            addReservation(); 
        } 
        else if (selection == 2)
        { 
            deleteReservation(); 
        } 
        else if (selection == 3)
        { 
            report(); 
        }   

        if (selection != 4)
        {
            line();
            system("pause");
        }   
        
        system("cls");
    }

    // Display on exit
    cout << HEADER("EXIT") << endl;
    cout << setspace(72) << YELLOW("Thank you :)") << endl;
    line();

    return 0;
}   