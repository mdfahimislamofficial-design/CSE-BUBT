#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Structure to hold criminal record information
struct Criminal
{
    int id;
    string name;
    int age;
    string crime;
    string sentence;
    string area;
};

// Function prototypes
void createAccount();
bool login();
void guestMenu();
void addCriminalRecord();
void viewAllRecords();
void searchRecord();
void updateRecord();
void deleteRecord();
void areaWiseCrimeRate();
void areaWiseRecords();
void displayPieChart();
void crimeStatisticsByAge();  // New feature: Crime Type Statistics by Age
void viewRecordsByAgeRange(); // New feature: View Records by Age Range
void menu();

// unique ID for each criminal
int uniqueID = 1;

int main()
{
    int choice;
    cout <<"\t \t \t \t" << "============================================" << endl;
    cout <<"\t \t \t \t" << "Welcome to Criminal Record Management System" << endl;
    cout <<"\t \t \t \t" << "============================================" << endl;

    while (true)
    {
        cout << "\n1. Create New Account\n2. Log In\n3. Guest Mode\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            createAccount();
        }
        else if (choice == 2)
        {
            if (login())
            {
                menu();
            }
            else
            {
                cout <<"\t \t \t \t \t" << "======================" << endl;
                cout <<"\t \t \t \t \t" << "Invalid login details!" << endl;
                cout <<"\t \t \t \t \t" << "======================" << endl;
            }
        }
        else if (choice == 3)
        {
            guestMenu(); // New guest mode function
        }
        else if (choice == 4)
        {
            exit(0);
        }
        else
        {
            cout <<"\t \t \t \t \t" << "Invalid choice. Try again!" << endl;
        }
    }
    return 0;
}

// Create a new account function
void createAccount()
{
    string username, password;
    ofstream accountsFile("accounts.txt", ios::app);

    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    accountsFile << username << " " << password << endl;
    accountsFile.close();

    cout <<"\t \t \t \t \t" << "============================" << endl;
    cout << "\t \t \t \t \t" <<"Account created successfully!" << endl;
    cout <<"\t \t \t \t \t" << "============================" << endl;
}

// Login function
bool login()
{
    string username, password, fileUsername, filePassword;
    ifstream accountsFile("accounts.txt");

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    while (accountsFile >> fileUsername >> filePassword)
    {
        if (username == fileUsername && password == filePassword)
        {
            return true;
        }
    }

    accountsFile.close();
    return false;
}

// Guest menu for viewing records without login
void guestMenu()
{
    int choice;
    while (true)
    {
        cout << "\n*Guest Mode - View Options:\n1. View All Records\n2. Search Record\n3. Area-wise Crime Rate\n4. Area-wise Records\n5. Crime Type Pie Chart\n6. Crime Statistics by Age\n7. View Records by Age Range\n8. Exit Guest Mode\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            viewAllRecords();
            break;
        case 2:
            searchRecord();
            break;
        case 3:
            areaWiseCrimeRate();
            break;
        case 4:
            areaWiseRecords();
            break;
        case 5:
            displayPieChart();
            break;
        case 6:
            crimeStatisticsByAge();
            break;
        case 7:
            viewRecordsByAgeRange();
            break;
        case 8:
            return;
        default:
            cout << "Invalid choice. Try again!" << endl;
        }
    }
}

// Menu for logged-in users with full access to criminal record operations
void menu()
{
    int choice;
    while (true)
    {
        cout << "\n1. Add Criminal Record\n2. View All Records\n3. Search Record\n4. Update Record\n5. Delete Record\n6. Area-wise Crime Rate\n7. Area-wise Records\n8. Crime Type Pie Chart\n9. Crime Statistics by Age\n10. View Records by Age Range\n11. Logout\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addCriminalRecord();
            break;
        case 2:
            viewAllRecords();
            break;
        case 3:
            searchRecord();
            break;
        case 4:
            updateRecord();
            break;
        case 5:
            deleteRecord();
            break;
        case 6:
            areaWiseCrimeRate();
            break;
        case 7:
            areaWiseRecords();
            break;
        case 8:
            displayPieChart();
            break;
        case 9:
            crimeStatisticsByAge();
            break;
        case 10:
            viewRecordsByAgeRange();
            break;
        case 11:
            return;
        default:
            cout << "Invalid choice. Try again!" << endl;
        }
    }
}

// Function to add a new criminal record
void addCriminalRecord()
{
    Criminal criminal;
    ofstream recordFile("records.txt", ios::app);

    criminal.id = uniqueID++; // Assign a unique ID to each criminal
    cout << "Enter criminal name: ";
    cin >> criminal.name;
    cout << "Enter criminal age: ";
    cin >> criminal.age;
    cout << "Enter crime committed: ";
    cin >> criminal.crime;
    cout << "Enter sentence: ";
    cin >> criminal.sentence;
    cout << "Enter area: ";
    cin >> criminal.area;

    recordFile << criminal.id << " " << criminal.name << " " << criminal.age << " " << criminal.crime << " " << criminal.sentence << " " << criminal.area << endl;
    recordFile.close();

    cout << "Record added successfully!" << endl;
}

// Function to view all records
void viewAllRecords()
{
    Criminal criminal;
    ifstream recordFile("records.txt");

    cout << "\n--- Criminal Records ---" << endl;
    while (recordFile >> criminal.id >> criminal.name >> criminal.age >> criminal.crime >> criminal.sentence >> criminal.area)
    {
        cout << "ID: " << criminal.id << "\nName: " << criminal.name << "\nAge: " << criminal.age << "\nCrime: " << criminal.crime << "\nSentence: " << criminal.sentence << "\nArea: " << criminal.area << "\n\n";
    }

    recordFile.close();
}

// Function to search for a specific record by ID
void searchRecord()
{
    Criminal criminal;
    ifstream recordFile("records.txt");
    int searchID;
    bool found = false;

    cout << "Enter criminal ID to search: ";
    cin >> searchID;

    while (recordFile >> criminal.id >> criminal.name >> criminal.age >> criminal.crime >> criminal.sentence >> criminal.area)
    {
        if (criminal.id == searchID)
        {
            found = true;
            cout << "ID: " << criminal.id << "\nName: " << criminal.name << "\nAge: " << criminal.age << "\nCrime: " << criminal.crime << "\nSentence: " << criminal.sentence << "\nArea: " << criminal.area << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Record not found!" << endl;
    }

    recordFile.close();
}

// Crime Type Statistics by Age
void crimeStatisticsByAge()
{
    ifstream recordFile("records.txt");
    Criminal criminal;
    map<int, map<string, int>> ageCrimeStats;

    while (recordFile >> criminal.id >> criminal.name >> criminal.age >> criminal.crime >> criminal.sentence >> criminal.area)
    {
        ageCrimeStats[criminal.age][criminal.crime]++;
    }

    cout << "\n--- Crime Type Statistics by Age ---" << endl;
    for (const auto &ageEntry : ageCrimeStats)
    {
        cout << "Age: " << ageEntry.first << endl;
        for (const auto &crimeEntry : ageEntry.second)
        {
            cout << "  Crime: " << crimeEntry.first << " | Count: " << crimeEntry.second << endl;
        }
        cout << endl;
    }

    recordFile.close();
}

// View Records by Age Range
void viewRecordsByAgeRange()
{
    int minAge, maxAge;
    Criminal criminal;
    ifstream recordFile("records.txt");

    cout << "Enter minimum age: ";
    cin >> minAge;
    cout << "Enter maximum age: ";
    cin >> maxAge;

    cout << "\n--- Criminal Records for Age Range " << minAge << "-" << maxAge << " ---" << endl;
    bool found = false;

    while (recordFile >> criminal.id >> criminal.name >> criminal.age >> criminal.crime >> criminal.sentence >> criminal.area)
    {
        if (criminal.age >= minAge && criminal.age <= maxAge)
        {
            cout << "ID: " << criminal.id << "\nName: " << criminal.name << "\nAge: " << criminal.age << "\nCrime: " << criminal.crime << "\nSentence: " << criminal.sentence << "\nArea: " << criminal.area << "\n\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No records found in this age range!" << endl;
    }

    recordFile.close();
}

// update a record by ID
void updateRecord()
{
    vector<Criminal> records; // Store records in a vector
    Criminal criminal;
    ifstream recordFile("records.txt");
    int searchID;
    bool found = false;

    cout << "Enter criminal ID to update: ";
    cin >> searchID;

    // Read all records into the vector
    while (recordFile >> criminal.id >> criminal.name >> criminal.age >> criminal.crime >> criminal.sentence >> criminal.area)
    {
        records.push_back(criminal);
    }

    // Close the input file
    recordFile.close();

    // Search for the record to update
    for (auto &rec : records)
    {
        if (rec.id == searchID)
        {
            found = true;
            cout << "Updating record for ID: " << rec.id << endl;
            cout << "Enter new age: ";
            cin >> rec.age;
            cout << "Enter new crime: ";
            cin >> rec.crime;
            cout << "Enter new sentence: ";
            cin >> rec.sentence;
            cout << "Enter new area: ";
            cin >> rec.area;
            break;
        }
    }

    if (found)
    {
        // Write all records back to the file
        ofstream recordFile("records.txt");
        for (const auto &rec : records)
        {
            recordFile << rec.id << " " << rec.name << " " << rec.age << " " << rec.crime << " " << rec.sentence << " " << rec.area << endl;
        }
        recordFile.close();
        cout << "Record updated successfully!" << endl;
    }
    else
    {
        cout << "Record not found!" << endl;
    }
}


// delete a record by ID
void deleteRecord()
{
    Criminal criminal;
    ifstream recordFile("records.txt");
    ofstream tempFile("temp.txt");
    int deleteID;
    bool found = false;

    cout << "Enter criminal ID to delete: ";
    cin >> deleteID;

    while (recordFile >> criminal.id >> criminal.name >> criminal.age >> criminal.crime >> criminal.sentence >> criminal.area)
    {
        if (criminal.id != deleteID)
        {
            tempFile << criminal.id << " " << criminal.name << " " << criminal.age << " " << criminal.crime << " " << criminal.sentence << " " << criminal.area << endl;
        }
        else
        {
            found = true;
        }
    }

    recordFile.close();
    tempFile.close();

    remove("records.txt");
    rename("temp.txt", "records.txt");

    if (found)
    {
        cout << "Record deleted successfully!" << endl;
    }
    else
    {
        cout << "Record not found!" << endl;
    }
}

// calculate area-wise crime rate
void areaWiseCrimeRate()
{
    ifstream recordFile("records.txt");
    Criminal criminal;
    map<string, int> areaCount;

    while (recordFile >> criminal.id >> criminal.name >> criminal.age >> criminal.crime >> criminal.sentence >> criminal.area)
    {
        areaCount[criminal.area]++;
    }

    cout << "\n--- Area-Wise Crime Rate ---" << endl;
    for (auto &entry : areaCount)
    {
        cout << "Area: " << entry.first << " | Crimes: " << entry.second << endl;
    }

    recordFile.close();
}

// display all records in a specific area
void areaWiseRecords()
{
    ifstream recordFile("records.txt");
    Criminal criminal;
    string searchArea;

    cout << "Enter area to view records: ";
    cin >> searchArea;

    cout << "\n--- Criminal Records in " << searchArea << " ---" << endl;
    bool found = false;
    while (recordFile >> criminal.id >> criminal.name >> criminal.age >> criminal.crime >> criminal.sentence >> criminal.area)
    {
        if (criminal.area == searchArea)
        {
            cout << "ID: " << criminal.id << "\nName: " << criminal.name << "\nAge: " << criminal.age << "\nCrime: " << criminal.crime << "\nSentence: " << criminal.sentence << "\nArea: " << criminal.area << "\n\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No records found in this area!" << endl;
    }

    recordFile.close();
}

// display a text-based pie chart for crime types
void displayPieChart()
{
    ifstream recordFile("records.txt");
    Criminal criminal;
    map<string, int> crimeCount;
    int totalCrimes = 0;

    while (recordFile >> criminal.id >> criminal.name >> criminal.age >> criminal.crime >> criminal.sentence >> criminal.area)
    {
        crimeCount[criminal.crime]++;
        totalCrimes++;
    }

    cout << "\n--- Crime Type Pie Chart ---" << endl;
    for (auto &entry : crimeCount)
    {
        cout << entry.first << ": " << fixed << setprecision(2) << (entry.second / (double)totalCrimes) * 100 << "%" << endl;
    }

    recordFile.close();

}
