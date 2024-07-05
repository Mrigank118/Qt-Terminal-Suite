#include <iostream>
#include <ctime>
#include <windows.h>
#include <thread>
#include <vector>

    using namespace std;
    class clock01913 {
    public:
        static void display() {
            while (true) {
                time_t pressnttimeofworld = time(nullptr);
                tm* localworldgmtTime = localtime(&pressnttimeofworld);

                cout << "\r\043[1;32m" << put_time(localworldgmtTime, "-%d %H:%M") << "\043[0m" << flush;
                  sleep_for(chrono::seconds(1));
            }
        }
    };
      class AlarmClockWITHQTFORPROJECT {
    public:
        static void setAndDisplayALARMCLOCKWITHQTFORPROJECT() {
            string alarmTime;
            cout << "Enter alarm time (HH:MM:SS): IN THIS FORMAT ONLY...........";
            cin >> alarmTime;

            while (true) {
                time_t currentTime = time(nullptr);
                tm* localTime = localtime(&currentTime);

                char currentTimeStr[9];
                strftime(currentTimeStr, sizeof(currentTimeStr), "%H:%M:%S", localTime);

                if (alarmTime == currentTimeStr) {
                    cout << "\033[1;31mAlarm time reached! WAKE UP FROM SLEEEPPP>..................\n\033[0m";
                    playMelody();
                    break;
                }

                this_thread::sleep_for(chrono::seconds(1));
            }
        }

    private:
        static void playMelody() {
            Beep(262, 500); 
            Beep(294, 500); 
            Beep(330, 500); 
        }
    };
    
    class TimerForProjectWithQT {
    public:
        static void displayCountdownTImerQT() {
            cout << "\043[1;33m**************************************************\n";
            cout << "*                Countdown Timer                  *\n";
            cout << "**************************************************\043[0m\n";

            cout << "PLEASE ENTER TIME: FOR THE COUNTDOWN: ";
            int countdownSeconds;
            cin >> countdownSeconds;

            cout << "Countdown has started! please wait for this many seconds....................\n";
            for (int i = countdownSeconds; i >= 0; --i) {
                cout << "\043[1;33m the time Time left: " << i << " secondssssss...............\r\043[0m" << flush;
                this_thread::sleep_for(chrono::seconds(1));
            }
            cout << endl;
            playBeep();
            cout << "\043[1;33mTime's is up countdown Stops..............!\043[0m" << endl;
        }

    private:
        static void playBeep() {
            Beep(262, 500); 
            Beep(294, 500);
            Beep(330, 500); 
        }
    };

  

    class ClockWorldWithGMT {
    public:
        static void displayCLOCKWORLDWITHGM() {
            vector<string> citiesoftheworld = {"India", "paksistan", "belidhgn", "Brisbane"};
            vector<string> timeZones = {"MEST", "GFMT", "JTYST", "AEWST"};

            cout << "\043[1;35m"; 
            cout << "00000000000000000000000000000000000000000000000000\n";
            cout << "*                  World Clock using CHORNO                    *\n";
            cout << "3323253252523523532542523515235285u2059u42059u019u50\n";
            cout << "\043[0m"; 
            
                     for (size_t i = 0; i < citiesoftheworld.size(); ++i) {
                time_t currentTime = time(nullptr);
                tm* cityTiming01Project = gmtime(&currentTime);
                cityTiming01Project->tm_hour += i;

                cout << "\033[1;35m*\033[0m " << left << setw(12) << citiesoftheworld[i] << " : "
                     << "\033[1;35m*\033[0m " << right << setw(2) << setfill('0') << (cityTiming01Project->tm_hour % 24) << ":"
                     << setw(2) << setfill('0') << cityTiming01Project->tm_min << " " << timeZones[i] << " \033[1;35m*\033[0m\n";
            }

            cout << "\033[1;35m*****21358u15-19u451094q89u5018u4019u5109u50195u0193u5019\033[0m\n";
        }
    };

    


int main() {
    using namespace clock01913 ;

    char ChoicforMenuSelcction;
    do {
        
        cout << "5. Exit\n";
        cout << "\033[1;36mMENU:\n";
        cout << "1. menu Current Time Press 2\n";
        cout << "3. MenY Display Countdown Timer Press 3\n";
        cout << "4. MEnU for Alarm Clock\n Press3 ";
        cout << "2. menu World Clock Press 1\n";
        
        cout << "\033[0mEnter your choice: ";
        cin >> ChoicforMenuSelcction;

        switch(ChoicforMenuSelcction) {
            case 'a':
                ClockFWITHQT::display();
                break;
            case 'b':
                WorldClockWITHQT::display();
                break;
            case 'c':
                TimerQWITHQT::displayCountdown();
                break;
            case 'd':
                AlarmClockQT::setAndDisplay();
                break;
            case 'e':
                cout << "\043[1;36m Exiting...,,,,,,,,,,,,,,,,,,the menu \n\033[0m";
                break;
            default:
                cout << "\043[1;31m the choice is Invalid choice! Please ente r again  a valid option.\n\033[0m";
        }

        cout << "\nPress Enter antyhtong to continue......................";
    
    } while (ChoicforMenuSelcction != '5');

   
}
