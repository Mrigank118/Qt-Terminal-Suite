#include <iostream>
#include <cmath>
#include <cstdlib> // For rand() and srand()
#include <ctime>
#include <iomanip>
#include <chrono>
#include <vector>

#define PI 3.14159265
#define CLEAR_COMMAND "cls"

// ANSI color codes
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

using namespace std;


class HybridCalculator {
private:
    double a, b, x;
    double result; // Variable to store the result of operations

public:
    // Constructor to initialize result variable
    HybridCalculator() : result(0) {}

    void setvalue() {
        cout << "\nEnter The Value Of First Operand : " << endl;
        cin >> a;
        cout << "Enter The Value Of second Operand : " << endl;
        cin >> b;
    }

    void set_data() {
        cout << "\nEnter Any Number : ";
        cin >> x;
    }

    double Add() {
        result = a + b;
        return result;
    }

    double Sub() {
        result = a - b;
        return result;
    }

    double Mul() {
        result = a * b;
        return result;
    }

    double Div() {
        result = a / b;
        return result;
    }

    double Sqrt() {
        result = sqrt(x);
        return result;
    }

    double Cbrt() {
        result = cbrt(x);
        return result;
    }

    double Square() {
        result = x * x;
        return result;
    }

    double Cube() {
        result = x * x * x;
        return result;
    }

    double Sin() {
        result = sin(x * PI / 180);
        return result;
    }

    double Cos() {
        result = cos(x * PI / 180);
        return result;
    }

    double Tan() {
        result = tan(x * PI / 180);
        return result;
    }

    double Log() {
        result = log(x);
        return result;
    }

    // Function to print the stored result
    void printResult() {
        cout << "Result: " << result << endl;
    }
};


class BMIcalculator {
private:
    double weight; // Weight in kilograms
    double height; // Height in meters

public:
    // Constructor
    BMIcalculator(double w, double h)
    {
        weight = w;
        height = h;
    }

    // Function to calculate BMI
    double calculateBMI() {
        return weight / pow(height, 2);
    }

    // Function to get BMI category
    string getCategory() {
        double bmi = calculateBMI();
        if (bmi < 18.5) {
            return "Underweight";
        } else if (bmi >= 18.5 && bmi < 25) {
            return "Normal weight";
        } else if (bmi >= 25 && bmi < 30) {
            return "Overweight";
        } else {
            return "Obese";
        }
    }

    // Function to get personalized health tips based on BMI category
    string getHealthTips() {
        string category = getCategory();
        if (category == "Underweight") {
            return "Try to eat more nutrient-rich foods and consider consulting a dietitian.\n";
        } else if (category == "Normal weight") {
            return "Maintain your healthy lifestyle with regular exercise and balanced diet.\n";
        } else if (category == "Overweight") {
            return "Focus on portion control, increase physical activity, and avoid processed foods.\n";
        } else {
            return "Consult a health care professional for personalized advice and consider lifestyle changes.\n";
        }
    }
};

class Converter {
public:
    // Temperature conversion functions
    static double celsiusToFahrenheit(double celsius) {
        return (celsius * 9) / 5 + 32;
    }

    static double fahrenheitToCelsius(double fahrenheit) {
        return (fahrenheit - 32) * 5 / 9;
    }

    static double celsiusToKelvin(double celsius) {
        return celsius + 273.15;
    }

    static double kelvinToCelsius(double kelvin) {
        return kelvin - 273.15;
    }

    static double fahrenheitToKelvin(double fahrenheit) {
        return (fahrenheit + 459.67) * 5 / 9;
    }

    static double kelvinToFahrenheit(double kelvin) {
        return (kelvin * 9) / 5 - 459.67;
    }

    // Weight conversion functions
    static double kilogramsToGrams(double kilograms) {
        return kilograms * 1000;
    }

    static double gramsToKilograms(double grams) {
        return grams / 1000;
    }

    static double kilogramsToPounds(double kilograms) {
        return kilograms * 2.20462;
    }

    static double poundsToKilograms(double pounds) {
        return pounds / 2.20462;
    }

    static double kilogramsToTons(double kilograms) {
        return kilograms / 1000;
    }

    static double tonsToKilograms(double tons) {
        return tons * 1000;
    }

    // Currency conversion functions
    static double usdToEuro(double usd) {
        return usd * 0.82;
    }

    static double euroToUsd(double euro) {
        return euro / 0.82;
    }

    static double rupeeToUsd(double rupee) {
        return rupee * 0.013;
    }

    static double usdToRupee(double usd) {
        return usd / 0.013;
    }
};


int main()
{
    int choice;

    // Seed the random number generator
    srand(time(nullptr));

    do {
        system(CLEAR_COMMAND); // Clear screen

        cout << CYAN << " __________________________________ "<< RESET << endl;
        cout << CYAN << "|                                  |"<< RESET << endl;
        cout << CYAN << "|              Menu                |"<< RESET << endl;
        cout << CYAN << "|__________________________________|"<< RESET << endl;
        cout << CYAN << "|                                  |"<< RESET << endl;
        cout << CYAN << "| 1. BMI Calculator                |"<< RESET << endl;
        cout << CYAN << "| 2. Hybrid Calculator             |"<< RESET << endl;
        cout << CYAN << "| 3. Unit Converter                |"<< RESET << endl;
        cout << CYAN << "| 4. Exit                          |"<< RESET << endl;
        cout << CYAN << "|__________________________________|"<< RESET << endl;

        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    system(CLEAR_COMMAND); // Clear screen

                    double weight, height;

                    // Input weight and height
                    cout << "\nBMI Calculator\n";
                    cout << "\nEnter weight in kilograms: ";
                    cin >> weight;
                    cout << "\nEnter height in meters: ";
                    cin >> height;

                    // Create BMI calculator object
                    BMIcalculator bmiCalculator(weight, height);

                    // Calculate BMI and get category
                    double bmi = bmiCalculator.calculateBMI();
                    string category = bmiCalculator.getCategory();
                    string healthTips = bmiCalculator.getHealthTips();

                    // Display result
                    cout << "\nYour BMI is: " << bmi << endl;
                    cout << "\nBMI Category: " << category << endl;
                    cout << "\nHealth Tips: " << healthTips << endl;

                    cout << "\nPress Enter to continue...";
                    cin.ignore(); // Wait for Enter key
                    cin.get();
                    break;
            }


            case 2: {
                system(CLEAR_COMMAND); // Clear screen

                HybridCalculator obj1; // OperandType and ResultType are both double
                double result;
                int val;
                cout << GREEN  << " ___________________________________________"<< RESET << endl;
                cout << GREEN  << "|                                           |"<< RESET << endl;
                cout << GREEN  << "|                CALCULATOR                 |"<< RESET << endl;
                cout << GREEN  << "|___________________________________________|"<< RESET << endl;
                cout << GREEN  << "|     _________________________________     |"<< RESET << endl;
                cout << GREEN  << "|    |                                 |    |"<< RESET << endl;
                cout << GREEN  << "|    |   7   8   9   /   +   sin()     |    |"<< RESET << endl;
                cout << GREEN  << "|    |                                 |    |"<< RESET << endl;
                cout << GREEN  << "|    |   4   5   6   *   -   cos()     |    |"<< RESET << endl;
                cout << GREEN  << "|    |                                 |    |"<< RESET << endl;
                cout << GREEN  << "|    |   1   2   3   ^   x   tan()     |    |"<< RESET << endl;
                cout << GREEN  << "|    |                                 |    |"<< RESET << endl;
                cout << GREEN  << "|    |   .   0   =   log()   sqrt()    |    |"<< RESET << endl;
                cout << GREEN  << "|    |_________________________________|    |"<< RESET << endl;
                cout << GREEN  << "|___________________________________________|"<< RESET << endl;

                cout << "\nEnter : " << endl
                     << "\n 1 For Simple Calculator " << endl
                     << "\n 2 For Scientific Calculator \n"
                     << endl;
                cin >> val;
                switch (val) {
                    case 1:
                        obj1.setvalue();
                        int choose;
                        cout << "\nEnter:" << endl
                             << "1 --> Addition" << endl
                             << "2 --> Subtraction" << endl
                             << "3 --> Multiplication" << endl
                             << "4 --> Division" << endl;
                        cin >> choose;
                        switch (choose) {
                            case 1:
                                result = obj1.Add();
                                break;
                            case 2:
                                result = obj1.Sub();
                                break;
                            case 3:
                                result = obj1.Mul();
                                break;
                            case 4:
                                result = obj1.Div();
                                break;
                            default:
                                cout << "\nInvalid Output !!!" << endl;
                                break;
                        }
                        obj1.printResult();
                        break;
                    case 2:
                        obj1.set_data();
                        int Choice;
                        cout << "\nEnter : " << endl
                             << "1 --> Square Root" << endl
                             << "2 --> Cube Root"   << endl
                             << "3 --> Square"      <<endl
                             << "4 --> Cube"        <<endl
                             << "5 --> Sin()"       << endl
                             << "6 --> Cos()"       << endl
                             << "7 --> Tan()"       << endl
                             << "8 --> Log()"       << endl;
                        cin >> Choice;
                        switch (Choice) {
                            case 1:
                                result = obj1.Sqrt();
                                break;
                            case 2:
                                result = obj1.Cbrt();
                                break;
                            case 3:
                                result = obj1.Square();
                                break;
                            case 4:
                                result = obj1.Cube();
                                break;
                            case 5:
                                result = obj1.Sin();
                                break;
                            case 6:
                                result = obj1.Cos();
                                break;
                            case 7:
                                result = obj1.Tan();
                                break;
                            case 8:
                                result = obj1.Log();
                                break;
                            default:
                                cout << "\nInvalid Output!!!" << endl;
                                break;
                        }
                        obj1.printResult();
                        break;
                    default:
                        cout << "\nInvalid Output!!!" << endl;
                        break;
                }

                cout << "\nPress Enter to continue...";
                cin.ignore(); // Wait for Enter key
                cin.get();
                break;
            }

            case 3:
                {
                    system(CLEAR_COMMAND); // Clear screen
                    int choice;
    double value;

    cout << YELLOW << " __________________________" << RESET << endl;
    cout << YELLOW << "|                         |" << RESET << endl;
    cout << YELLOW << "|        CONVERTER        |" << RESET << endl;
    cout << YELLOW << "|_________________________|" << RESET << endl;
    cout << YELLOW << "|                         |" << RESET << endl;
    cout << YELLOW << "|     1. TEMPERATURE      |" << RESET << endl;
    cout << YELLOW << "|     2. WEIGHT           |" << RESET << endl;
    cout << YELLOW << "|     3. CURRENCY         |" << RESET << endl;
    cout << YELLOW << "|_________________________|" << RESET << endl;
    cout << YELLOW << "|_________________________|" << RESET << endl << endl;

    cout << "\nENTER CONVERSION TYPE (1/2/3) : ";
    cin >> choice;

    switch (choice) {
        system(CLEAR_COMMAND); // Clear screen
        case 1: {
            double temp;
            cout << "\nEnter temperature value : ";
            cin >> temp;

            int tempChoice;
            cout << MAGENTA << " ________________________________________" << RESET << endl;
            cout << MAGENTA << "|                                       |" << RESET << endl;
            cout << MAGENTA << "|         TEMPERATURE CONVERTER         |" << RESET << endl;
            cout << MAGENTA << "|_______________________________________|" << RESET << endl;
            cout << MAGENTA << "| |                                   | |" << RESET << endl;
            cout << MAGENTA << "| | 1. C to F | 2. F to C | 3. C to K | |" << RESET << endl;
            cout << MAGENTA << "| | 4. K to C | 5. F to K | 6. K to F | |" << RESET << endl;
            cout << MAGENTA << "| |___________________________________| |" << RESET << endl;
            cout << MAGENTA << "|_______________________________________|" << RESET << endl;
            cout << "\nENTER CONVERSION CHOICE : ";
            cin >> tempChoice;

            double result;
            switch (tempChoice) {
                case 1:
                    result = Converter::celsiusToFahrenheit(temp);
                    cout << "\nTemperature in Fahrenheit : " << result << endl;
                    break;
                case 2:
                    result = Converter::fahrenheitToCelsius(temp);
                    cout << "\nTemperature in Celsius : " << result << endl;
                    break;
                case 3:
                    result = Converter::celsiusToKelvin(temp);
                    cout << "\nTemperature in Kelvin : " << result << endl;
                    break;
                case 4:
                    result = Converter::kelvinToCelsius(temp);
                    cout << "\nTemperature in Celsius : " << result << endl;
                    break;
                case 5:
                    result = Converter::fahrenheitToKelvin(temp);
                    cout << "\nTemperature in Kelvin : " << result << endl;
                    break;
                case 6:
                    result = Converter::kelvinToFahrenheit(temp);
                    cout << "\nTemperature in Fahrenheit : " << result << endl;
                    break;
                default:
                    cout << "\nInvalid choice!!!" << endl;
                    break;
            }
             cout << "\nPress Enter to continue...";
                cin.ignore(); // Wait for Enter key
                cin.get();
                break;
        }
        case 2: {
            system(CLEAR_COMMAND); // Clear screen
            double weight;
            cout << "Enter weight value: ";
            cin >> weight;

            int weightChoice;
            cout << BLUE << " ___________________________________________________________" << RESET << endl;
            cout << BLUE << "|                                                          |" << RESET << endl;
            cout << BLUE << "|                     WEIGHT CONVERTER                     |" << RESET << endl;
            cout << BLUE << "|__________________________________________________________|" << RESET << endl;
            cout << BLUE << "| |                    |               |                 | |" << RESET << endl;
            cout << BLUE << "| |    1. KG to g      | 2. g to KG    | 3. KG to POUNDS | |" << RESET << endl;
            cout << BLUE << "| |    4. POUNDS to KG | 5. KG to TONS | 6. TONS to KG   | |" << RESET << endl;
            cout << BLUE << "| |____________________|_______________|_________________| |" << RESET << endl;
            cout << BLUE << "|__________________________________________________________|" << RESET << endl;
            cout << "ENTER CONVERSION CHOICE: ";
            cin >> weightChoice;

            double result;
            switch (weightChoice) {
                case 1:
                    result = Converter::kilogramsToGrams(weight);
                    cout << "Weight in grams: " << result << endl;
                    break;
                case 2:
                    result = Converter::gramsToKilograms(weight);
                    cout << "Weight in kilograms: " << result << endl;
                    break;
                case 3:
                    result = Converter::kilogramsToPounds(weight);
                    cout << "Weight in pounds: " << result << endl;
                    break;
                case 4:
                    result = Converter::poundsToKilograms(weight);
                    cout << "Weight in kilograms: " << result << endl;
                    break;
                case 5:
                    result = Converter::kilogramsToTons(weight);
                    cout << "Weight in tons: " << result << endl;
                    break;
                case 6:
                    result = Converter::tonsToKilograms(weight);
                    cout << "Weight in kilograms: " << result << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
             cout << "\nPress Enter to continue...";
                cin.ignore(); // Wait for Enter key
                cin.get();
                break;
        }
        case 3: {
            system(CLEAR_COMMAND); // Clear screen

            double amount;
            cout << "Enter currency amount: ";
            cin >> amount;

            int currencyChoice;
            cout << " ___________________________" << endl;
            cout << "|                          |" << endl;
            cout << "|     CURRENCY CONVERTER   |" << endl;
            cout << "|__________________________|" << endl;
            cout << "|                          |" << endl;
            cout << "|  1. USD to Euro          |" << endl;
            cout << "|  2. Euro to USD          |" << endl;
            cout << "|  3. Rupee to USD         |" << endl;
            cout << "|  4. USD to Rupee         |" << endl;
            cout << "|__________________________|" << endl;
            cout << "ENTER CONVERSION CHOICE : ";
            cin >> currencyChoice;

            double result;
            switch (currencyChoice) {
                case 1:
                    result = Converter::usdToEuro(amount);
                    cout << "Amount in Euro : " << result << endl;
                    break;
                case 2:
                    result = Converter::euroToUsd(amount);
                    cout << "Amount in USD : " << result << endl;
                    break;
                case 3:
                    result = Converter::rupeeToUsd(amount);
                    cout << "Amount in USD : " << result << endl;
                    break;
                case 4:
                    result = Converter::usdToRupee(amount);
                    cout << "Amount in Rupee: " << result << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
                    break;
            }
                default:
                cout << "Invalid Option!!" << endl;
                break;
    }
     cout << "\nPress Enter to continue...";
                cin.ignore(); // Wait for Enter key
                cin.get();
                break;
                }

            case 4:
                cout << "\nExiting...\n";
                break;
                default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 4);



}

