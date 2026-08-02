// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    string id;
    vector<double> scores;
};

double calculateAverage(const Student &student) {
    double sum = 0;
    for (double score : student.scores) {
        sum += score;
    }
    return sum / student.scores.size();
}

void addStudent(vector<Student> &students) {
    Student student;

    cin.ignore();

    cout << "Enter student's name: ";
    getline(cin, student.name);

    cout << "Enter student's ID: ";
    getline(cin, student.id);

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        student.scores.push_back(score);
    }

    students.push_back(student);
    cout << "Student " << student.name << " added successfully.\n";
}

void displayStudents(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No students have been added yet.\n";
        return;
    }

    cout << "\nStudent Records\n";
    cout << "-------------------------------------------------------------\n";
    cout << left << setw(20) << "Name"
         << setw(15) << "ID"
         << setw(20) << "Scores"
         << "Average\n";
    cout << "-------------------------------------------------------------\n";

    for (const Student &student : students) {
        cout << left << setw(20) << student.name;
        cout << setw(15) << student.id;

        for (double score : student.scores) {
            cout << score << " ";
        }

        cout << "\t" << fixed << setprecision(2)
             << calculateAverage(student) << endl;
    }
}

void calculateStudentAverage(const vector<Student> &students) {
    string id;
    cout << "Enter student ID: ";
    cin >> id;

    for (const Student &student : students) {
        if (student.id == id) {
            cout << student.name << " average score: "
                 << fixed << setprecision(2)
                 << calculateAverage(student) << endl;
            return;
        }
    }

    cout << "Error: Student ID not found.\n";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Record System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Calculate Average Score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                calculateStudentAverage(students);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

