#include<iostream>
using namespace std;

class Admin
{
private:
    string username;
    string password;
               
public:

    // default account
    Admin()
    {
        username = "admin";
        password = "1234";
    }

    void createAccount()
    {
        cout<<"Enter the username : "<<endl;
        cin>>username;

        cout<<"Enter the password : "<<endl;
        cin>>password;
    }

    void login(string user ,string pass)
    {
        if(user == username && pass == password)
        {
            cout<<"Login successful"<<endl;
        }
        else
        {
            cout<<"Invalid username or password"<<endl;
        }
    }
};

class Event
{
private:
    string eventName[50];
    string organiser[50];
    string date[50];
    string time[50];
    string venue[50];
    string winner[50];

    int count;

public:

    Event()
    {
        count = 0;
    }


// 1. Add Event
void addEvent()
{
    if(count >= 50)
    {
        cout<<"Event list is full\n";
        return;
    }

    cout<<"Enter Event Name: ";
    cin>>eventName[count];

    cout<<"Enter Organiser Name: ";
    cin>>organiser[count];

    cout<<"Enter Date: ";
    cin>>date[count];

    cout<<"Enter Time: ";
    cin>>time[count];

    cout<<"Enter Venue: ";
    cin>>venue[count];

    winner[count] = "NotDeclared";

    count++;

    cout<<"Event Added Successfully\n";
}


// 2. Delete Event
void deleteEvent()
{
    string name;
    int found = 0;

    cout<<"Enter Event Name to delete: ";
    cin>>name;

    for(int i=0;i<count;i++)
    {
        if(eventName[i] == name)
        {
            for(int j=i;j<count-1;j++)
            {
                eventName[j] = eventName[j+1];
                organiser[j] = organiser[j+1];
                date[j] = date[j+1];
                time[j] = time[j+1];
                venue[j] = venue[j+1];
                winner[j] = winner[j+1];
            }

            count--;
            found = 1;
            cout<<"Event Deleted Successfully\n";
            break;
        }
    }

    if(found == 0)
    {
        cout<<"Event not found\n";
    }
}


// 3. Update Date Time Venue
void addSchedule()
{
    string name;

    cout<<"Enter Event Name: ";
    cin>>name;

    for(int i=0;i<count;i++)
    {
        if(eventName[i] == name)
        {
            cout<<"Enter New Date: ";
            cin>>date[i];

            cout<<"Enter Time: ";
            cin>>time[i];

            cout<<"Enter Venue: ";
            cin>>venue[i];

            cout<<"Schedule Updated\n";
            return;
        }
    }

    cout<<"Event not found\n";
}


// 4. View Events
void viewEvents()
{
    if(count == 0)
    {
        cout<<"No events available\n";
        return;
    }

    for(int i=0;i<count;i++)
    {
        cout<<"\nEvent Name : "<<eventName[i];
        cout<<"\nOrganiser  : "<<organiser[i];
        cout<<"\nDate       : "<<date[i];
        cout<<"\nTime       : "<<time[i];
        cout<<"\nVenue      : "<<venue[i];
        cout<<"\nWinner     : "<<winner[i]<<endl;
    }
}


// 5. Declare Winner
void declareWinner()
{
    string name;

    cout<<"Enter Event Name: ";
    cin>>name;

    for(int i=0;i<count;i++)
    {
        if(eventName[i] == name)
        {
            cout<<"Enter Winner Name: ";
            cin>>winner[i];

            cout<<"Winner Declared Successfully\n";
            return;
        }
    }

    cout<<"Event not found\n";
}


// 6. Generate Report
void generateReport()
{
    cout<<"\n------ Event Report ------\n";

    for(int i=0;i<count;i++)
    {
        cout<<"\nEvent Name : "<<eventName[i];
        cout<<"\nOrganiser  : "<<organiser[i];
        cout<<"\nDate       : "<<date[i];
        cout<<"\nVenue      : "<<venue[i];
        cout<<"\nWinner     : "<<winner[i]<<endl;
    }
}


// 7. Search Event
void searchEvent()
{
    int choice;
    string key;

    cout<<"Search By\n";
    cout<<"1. Event Name\n";
    cout<<"2. Date\n";
    cout<<"3. Organiser\n";

    cin>>choice;

    cout<<"Enter value: ";
    cin>>key;

    for(int i=0;i<count;i++)
    {
        if((choice==1 && eventName[i]==key) ||
           (choice==2 && date[i]==key) ||
           (choice==3 && organiser[i]==key))
        {
            cout<<"\nEvent Name : "<<eventName[i];
            cout<<"\nOrganiser  : "<<organiser[i];
            cout<<"\nDate       : "<<date[i];
            cout<<"\nTime       : "<<time[i];
            cout<<"\nVenue      : "<<venue[i];
            cout<<"\nWinner     : "<<winner[i]<<endl;

            return;
        }
    }

    cout<<"Event not found\n";
}


// 8. Organiser Details
void organiserDetails()
{
    string name;

    cout<<"Enter Event Name: ";
    cin>>name;

    for(int i=0;i<count;i++)
    {
        if(eventName[i] == name)
        {
            cout<<"Organiser : "<<organiser[i]<<endl;
            return;
        }
    }

    cout<<"Event not found\n";
}
};

class Participants : public Event
{
private:
    string participantName[100];
    string eventForParticipant[100];
    int count = 0;
    int maxParticipants = 0;

public:

// 1️⃣ Add Maximum Participants for Event
void setMaxParticipants()
{
    cout<<"Enter Maximum Participants Allowed: ";
    cin>>maxParticipants;
}

};