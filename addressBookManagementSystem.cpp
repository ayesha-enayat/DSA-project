#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Maximum number of contacts in the address book
#define Max 1000 // Maximum number of contacts

// Define a contact structure
struct Contacts
{
    string cName;      // Name
    int cGender = 1;   // Gender
    int cAge = 0;      // Age
    string cPhone;     // Phone number
    string cAdd;       // Address
};

// Define an address book structure
struct AddressBooks
{
    vector<Contacts> contactsArry[Max]; // Hash table to store contact information
    int aCount = 0;             // Number of contacts currently in the address book
};

// Hash function to map a name to an index
int hashFunction(const string &name)
{
    int hash = 0;
    for (char c : name)
    {
        hash = (hash * 31 + c) % Max;
    }
    return hash;
}

// Display the main menu
void showMenu()
{
    cout << "********************************" << endl;
    cout << "***** Address Book Management System *****" << endl;
    cout << "********************************" << endl;
    cout << "*****    1. Add Contact     *****" << endl;
    cout << "*****    2. Show Contacts     *****" << endl;
    cout << "*****    3. Delete Contact     *****" << endl;
    cout << "*****    4. Find Contact     *****" << endl;
    cout << "*****    5. Modify Contact     *****" << endl;
    cout << "*****    6. Clear Contacts     *****" << endl;
    cout << "*****    0. Exit Address Book     *****" << endl;
    cout << "********************************" << endl;
    cout << "***********        ***********" << endl;
    cout << "********************************" << endl;
}

// Add a contact
void AddContacts(AddressBooks *abs)
{
    // Check if the address book is full
    if (abs->aCount == Max)
    {
        cout << "The address book is full, cannot add more contacts!" << endl;
        return;
    }
    else
    {
        // Name
        string name;
        cout << "Please enter the name: " << endl;
        cin >> name;
        int index = hashFunction(name);

        Contacts newContact;
        newContact.cName = name;

        // Gender
        int gender;
        cout << "Please enter the gender: " << endl;
        cout << "1 ---- Male " << endl;
        cout << "2 ---- Female " << endl;

        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                newContact.cGender = gender;
                break;
            }
            cout << "Invalid input, please enter again!" << endl;
        }

        // Age
        int age;
        cout << "Please enter the age: " << endl;
        cin >> age;
        newContact.cAge = age;

        // Phone number
        string phone;
        cout << "Please enter the phone number: " << endl;
        cin >> phone;
        newContact.cPhone = phone;

        // Address
        string add;
        cout << "Please enter the address: " << endl;
        cin >> add;
        newContact.cAdd = add;

        // Add contact to hash table
        abs->contactsArry[index].push_back(newContact);
        abs->aCount += 1;
        cout << "Contact added successfully!" << endl;
        system("pause");
        // Clear screen
        system("cls");
    }
}

// Show contacts
void ShowContacts(AddressBooks *abs)
{
    if (abs->aCount == 0)
    {
        cout << "No contacts, please add some first!" << endl;
    }
    else
    {
        // Show all contacts
        for (int i = 0; i < Max; i++)
        {
            for (auto &contact : abs->contactsArry[i])
            {
                cout << "Name: " << contact.cName << " Gender: " << (contact.cGender != 2 ? "Male" : "Female") << " Age: " << contact.cAge << " Phone: " << contact.cPhone << " Address: " << contact.cAdd << endl;
            }
        }
    }
    system("pause");
    system("cls");
}

// Check if a contact exists
int IsExit(AddressBooks *abs, string name)
{
    int index = hashFunction(name);
    for (int i = 0; i < abs->contactsArry[index].size(); i++)
    {
        if (abs->contactsArry[index][i].cName == name)
        {
            return i;
        }
    }
    return -1;
}

// Delete a contact
void DeleteContacts(AddressBooks *abs)
{
    // Get the name from the user
    string name;
    cout << "Please enter the name of the contact you want to delete: " << endl;
    cin >> name;
    // Check if the contact exists
    int index = hashFunction(name);
    int pos = IsExit(abs, name);
    // If it exists
    if (pos > -1)
    {
        abs->contactsArry[index].erase(abs->contactsArry[index].begin() + pos);
        // Decrease the count
        abs->aCount--;
        cout << "Contact deleted successfully!" << endl;
    }
    else // If it doesn't exist
    {
        cout << "No such person found" << endl;
    }
    system("pause");
    system("cls");
}

// Find a contact
void GetContacts(AddressBooks *abs)
{
    // Get the name from the user
    string name;
    cout << "Please enter the name of the contact you want to find: " << endl;
    cin >> name;
    // Check if the contact exists
    int index = hashFunction(name);
    int pos = IsExit(abs, name);
    if (pos > -1)
    {
        // If it exists
        auto &contact = abs->contactsArry[index][pos];
        cout << "Name: " << contact.cName << endl;
        cout << "Gender: " << contact.cGender << endl;
        cout << "Age: " << contact.cAge << endl;
        cout << "Phone: " << contact.cPhone << endl;
        cout << "Address: " << contact.cAdd << endl;
    }
    else
    {
        // If it doesn't exist
        cout << "No such person found" << endl;
    }
    system("pause");
    system("cls");
}

// Modify a contact
void ModifyContacts(AddressBooks *abs)
{
    // Get the name from the user
    string name;
    cout << "Please enter the name of the contact you want to modify: " << endl;
    cin >> name;
    // Check if the contact exists
    int index = hashFunction(name);
    int pos = IsExit(abs, name);
    if (pos > -1)
    {
        // If it exists
        auto &contact = abs->contactsArry[index][pos];
        // Name
        string newName;
        cout << "Please enter the new name: " << endl;
        cin >> newName;
        contact.cName = newName;

        // Gender
        int gender;
        cout << "Please enter the new gender: " << endl;
        cout << "1 ---- Male " << endl;
        cout << "2 ---- Female " << endl;

        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                contact.cGender = gender;
                break;
            }
            cout << "Invalid input, please enter again!" << endl;
        }

        // Age
        int age;
        cout << "Please enter the new age: " << endl;
        cin >> age;
        contact.cAge = age;

        // Phone number
        string phone;
        cout << "Please enter the new phone number: " << endl;
        cin >> phone;
        contact.cPhone = phone;

        // Address
        string add;
        cout << "Please enter the new address: " << endl;
        cin >> add;
        contact.cAdd = add;
        cout << "Contact modified successfully!" << endl;
    }
    else
    {
        // If it doesn't exist
        cout << "No such person found" << endl;
    }
    system("pause");
    system("cls");
}

// Clear all contacts
void ClearContacts(AddressBooks *abs)
{
    string choose = "N";
    cout << "Are you sure you want to clear the address book? (Y to confirm / N to cancel)" << endl;

    while (true)
    {
        cin >> choose;
        if (choose == "Y" || choose == "N")
        {
            break;
        }
        else
        {
            cout << "Invalid input, please enter again!" << endl;
        }
    }

    if (choose == "Y")
    {
        for (int i = 0; i < Max; i++)
        {
            abs->contactsArry[i].clear();
        }
        abs->aCount = 0;
        cout << "Address book cleared successfully!" << endl;
    }
    else
    {
        cout << "Operation cancelled!" << endl;
    }
    system("pause");
    system("cls");
}

int main()
{
    // Record user input
    int select = 0;
    // Define an address book structure
    AddressBooks abs;
    // Set the current number of contacts to zero
    abs.aCount = 0;

    while (true)
    {
        // Display the main menu
        showMenu();

        cin >> select;
        switch (select)
        {
        case 1: // 1. Add contact
            AddContacts(&abs); // Pass by address
            break;
        case 2: // 2. Show contacts
            ShowContacts(&abs); // Pass by address
            break;
        case 3: // 3. Delete contact
            DeleteContacts(&abs);
            break;
        case 4: // 4. Find contact
            GetContacts(&abs);
            break;
        case 5: // 5. Modify contact
            ModifyContacts(&abs);
            break;
        case 6: // 6. Clear contacts
            ClearContacts(&abs);
            break;
        case 0: // 0. Exit address book
            cout << "Thank you for using the address book, goodbye!" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }

    system("pause"); // Press any key to continue
    return 0;
}
