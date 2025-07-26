// TASK 1: CGPA Calculator
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// ------------------------- CGPA CALCULATOR -------------------------
void cgpaCalculator() {
    int n;
    float grade, credit, totalPoints = 0, totalCredits = 0;
    cout << "Enter number of courses: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter grade and credit hours for course " << i+1 << ": ";
        cin >> grade >> credit;
        totalPoints += grade * credit;
        totalCredits += credit;
    }

    float cgpa = totalPoints / totalCredits;
    cout << "\nYour CGPA is: " << cgpa << endl;
}

// ------------------------- LOGIN SYSTEM -------------------------
void registerUser() {
    string username, password;
    cout << "Register\nUsername: "; cin >> username;
    cout << "Password: "; cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password, u, p;
    cout << "Login\nUsername: "; cin >> username;
    cout << "Password: "; cin >> password;

    ifstream file("users.txt");
    bool success = false;
    while (file >> u >> p) {
        if (u == username && p == password) {
            success = true;
            break;
        }
    }
    file.close();
    if (success) cout << "Login successful!\n";
    else cout << "Login failed. Check your credentials.\n";
}

// ------------------------- SUDOKU SOLVER -------------------------
#define UNASSIGNED 0
#define N 9

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num || grid[x][col] == num ||
            grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num)
            return false;
    return true;
}

bool solveSudoku(int grid[N][N], int row = 0, int col = 0) {
    if (row == N - 1 && col == N) return true;
    if (col == N) { row++; col = 0; }
    if (grid[row][col] != UNASSIGNED) return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

void printSudoku(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++)
            cout << grid[r][d] << " ";
        cout << endl;
    }
}

// ------------------------- BANKING SYSTEM -------------------------
class Account {
public:
    string name;
    int accNumber;
    double balance;

    Account(string n, int num) : name(n), accNumber(num), balance(0.0) {}

    void deposit(double amt) {
        balance += amt;
        cout << "Deposited: " << amt << "\n";
    }

    void withdraw(double amt) {
        if (amt <= balance) {
            balance -= amt;
            cout << "Withdrawn: " << amt << "\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    void display() {
        cout << "Name: " << name << ", Account: " << accNumber << ", Balance: " << balance << "\n";
    }
};

// ------------------------- MAIN MENU -------------------------
int main() {
    int choice;
    Account myAcc("Muneeb Shah", 101);

    do {
        cout << "\n\nMENU:\n";
        cout << "1. CGPA Calculator\n";
        cout << "2. Register User\n";
        cout << "3. Login User\n";
        cout << "4. Sudoku Solver\n";
        cout << "5. Banking System (Deposit/Withdraw/Show Balance)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cgpaCalculator(); break;
            case 2: registerUser(); break;
            case 3: loginUser(); break;
            case 4: {
                int grid[N][N] = {
                    {5, 3, 0, 0, 7, 0, 0, 0, 0},
                    {6, 0, 0, 1, 9, 5, 0, 0, 0},
                    {0, 9, 8, 0, 0, 0, 0, 6, 0},
                    {8, 0, 0, 0, 6, 0, 0, 0, 3},
                    {4, 0, 0, 8, 0, 3, 0, 0, 1},
                    {7, 0, 0, 0, 2, 0, 0, 0, 6},
                    {0, 6, 0, 0, 0, 0, 2, 8, 0},
                    {0, 0, 0, 4, 1, 9, 0, 0, 5},
                    {0, 0, 0, 0, 8, 0, 0, 7, 9}
                };
                if (solveSudoku(grid)) printSudoku(grid);
                else cout << "No solution exists" << endl;
                break;
            }
            case 5: {
                int op;
                double amt;
                cout << "1. Deposit\n2. Withdraw\n3. Show Balance\nChoose: ";
                cin >> op;
                if (op == 1) { cout << "Amount: "; cin >> amt; myAcc.deposit(amt); }
                else if (op == 2) { cout << "Amount: "; cin >> amt; myAcc.withdraw(amt); }
                else myAcc.display();
                break;
            }
            case 0: cout << "Exiting..."; break;
            default: cout << "Invalid option. Try again."; break;
        }
    } while (choice != 0);

    return 0;
}


   

	

