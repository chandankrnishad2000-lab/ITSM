#include <iostream>
using namespace std;

class BusReservation {
     int seats;
    int booked;
    queue<string> waiting;
    string confirmed[100];

    public:
    BusReservation(int s){
        seats = s;
        booked = 0;
    }
    bool bookSeat(string name){
        if (booked < seats){
            confirmed[booked] = name;
            booked++;
            return true;
        }
        else {
            waiting.push(name);
            return false;
        }
    }

     void cancelTicket(string name) {
        bool found = false;
        for (int i = 0; i < booked; i++) {
            if (confirmed[i] == name) {
                found = true;
                confirmed[i] = confirmed[--booked];

                cout << name << " ticket cancelled.\n";

                if (!waiting.empty()) {
                    string next = waiting.front();
                    waiting.pop();
                    confirmed[booked++] = next;
                    cout << next << " moved from waiting to confirmed.\n";
                }
                break;
            }
        }
        if (!found) {
            cout << "Passenger not found.\n";
        }
    }

    void showConfirmed() {
        cout << "\nConfirmed List:\n";
        for (int i = 0; i < booked; i++)
            cout << confirmed[i] << endl;
    }

    void showWaiting() {
        cout << "\nWaiting List:\n";
        queue<string> temp = waiting;
        while (!temp.empty()) {
            cout << temp.front() << endl;
            temp.pop();
        }
    }
};


int main ()
{
BusReservation Bus(7);
    Bus.bookSeat("Alice");
    Bus.bookSeat("Bob");
    Bus.bookSeat("Charlie");
    Bus.bookSeat("David");
    Bus.bookSeat("Eve");
    Bus.bookSeat("Frank");
    Bus.bookSeat("Grace");
    Bus.bookSeat("Heidi");

    Bus.showConfirmed();
    Bus.showWaiting();

    Bus.cancelTicket("Charlie");
    Bus.cancelTicket("Eve");

    Bus.showConfirmed();
    Bus.showWaiting();  
}