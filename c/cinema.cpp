#include <iostream>
using namespace std;

class Cinema {
private:
  int seats[10][7];

public:
  Cinema() {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 7; j++) {
        seats[i][j] = 1;
      }
    }
  }

  void displaySeats() {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 7; j++) {
        if (seats[i][j] == 1) {
          cout << "S" << i << j << " ";
        }
        
      }cout<<endl;
    }
    cout << endl;
  }

  void bookSeat(int row, int col) {
    if (row >= 0 && row < 10 && col >= 0 && col < 7 && seats[row][col] == 1) {
      seats[row][col] = 0;
      cout << "Seat booked successfully!" << endl;
    } else {
      cout << "Invalid seat or seat is already booked!" << endl;
    }
  }

  void cancelSeat(int row, int col) {
    if (row >= 0 && row < 10 && col >= 0 && col < 7 && seats[row][col] == 0) {
      seats[row][col] = 1;
      cout << "Booking cancelled successfully!" << endl;
    } else {
      cout << "Invalid seat or seat is not booked!" << endl;
    }
  }
};

int main() {
  Cinema seating;

  int choice, row, col;

  do {
    cout << "Menu:\n";
    cout << "1. Display available seats\n";
    cout << "2. Book a seat\n";
    cout << "3. Cancel a booking\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        seating.displaySeats();
        break;
      case 2:
        cout << "Enter row number: ";
        cin >> row;
        cout << "Enter column number: ";
        cin >> col;
        seating.bookSeat(row, col);
        break;
      case 3:
        cout << "Enter row number to cancel booking: ";
        cin >> row;
        cout << "Enter column number to cancel booking: ";
        cin >> col;
        seating.cancelSeat(row, col);
        break;
      case 4:
        cout << "Exiting the program. Goodbye!\n";
        break;
      default:
        cout << "Invalid choice. Please try again.\n";
        break;
    }

    if (choice != 4) {
      cout << "---------------------------------\n";
    }
  } while (choice != 4);

  return 0;
}
