// Simple Bus Reservation System in C++
#include<bits/stdc++.h>
using namespace std;
int p = 0;
/* Here each of the bus is class type. we are using a array of class named `bus` where the size 25
means we can maximum add 25 buses. Each bus to be manually added. We used class because using class we
can easily use different method in bus and easily modify them plus retain OOPs property.
*/
class a
{
  //Note: Don't use space in input.
  //busPlateNum can store a input upto length 7 and so on for other attributes.
  //Here seatNumber is number of seats in a bus, seatNumber is matrix type char, means seatNumber[8][4] have 4 columns and 8 rows,
  //meaning 8*4=32 seats in total, while seatNumber[8][4][10] means each of the seatNumber can store a nameOfPassenger with 10 character each
  char busn[5], driver[10], arrival[10], depart[10], from[10], to[10], seat[8][4][10];

public:

  void add_new(); // Adds a New Bus with its details

  void allotmentOfSeatToPassenger(); // Used to allot seatNumber to passenger from availbale buses

  void empty();     // Used to intilialize all bus seats as vacent

  void showAvailableBusSeats();      //shows avialble bus seats from a bus

  void showAvailableBuses();     //shows all avialable buses

  void showReservedBusSeats(int i); //to get the all reserved bus seats from a bus

}

bus[25]; // Bus is an array of class with max size of 25 buses.
/* Dummy function used to add lines of `*` to separate and clean output*/
void vline(char ch)
{
	for (int i=75;i>0;i--)
	{
		cout<<ch;
	}
	cout<<endl;
}

void bus_rsadd_new()
{

  cout<<"Enter bus no: ";

  cin>>bus[p].busn;

  cout<<"\nEnter Driver's name: ";

  cin>>bus[p].driver;

  cout<<"\nArrival time : ";

  cin>>bus[p].arrival;

  cout<<"\nDeparture: ";

  cin>>bus[p].depart;

  cout<<"\nFrom: \t\t\t";

  cin>>bus[p].from;

  cout<<"\nTo: \t\t\t";

  cin>>bus[p].to;

  bus[p].empty(); // Fill all the seats with 'empty'

  p++; //Number of buses(index of array bus) increase

}

//Used to allocate seat in bus
void bus_rsallotmentOfSeatToPassenger()
{

  int seat;  // Enter seat number between 1 to 32

  char number[5]; //Bus number in which you want to reserve seat

  top:

  cout<<"Bus no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0) //Check if bus number exist or not, if exist n will be the index of array bus

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32) //Can't allocate as there are only 32 seats
    {

      cout<<"\nThere are only 32 seats available in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0) // used to break the seat number in row-column basis, If empty then allocate passenger

      {

        cout<<"Enter passanger's name: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];

        break;

      }

    else

      cout<<"The seat number is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"\t\t\tBus Not Found\n";
      //goto top;

    }

  }

//Makes all the seats empty
void bus_rsempty()
{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}


// Allows to check vacent seats in a bus
void bus_rsshowAvailableBusSeats()
{

  int n;

  char number[5];

  cout<<"\t\t\tEnter bus no: ";

  cin>>number;

//Finds the bus number matched with input bus number
  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0) // if matched the n will be the index of bus

    break;

  }

while(n<=p)

{

  vline('*'); // Prints a line with '*'
  cout<<"\n\t\t\tBus no: \t"<<bus[n].busn<<"\n\n\t\t\tDriver: \t"<<bus[n].driver<<"\n"
  <<"\t\t\tArrival time: \t"<<bus[n].arrival<<"\n"<<"\t\t\tDeparture time: "<<bus[n].depart<<"\n\n\n\n\t\t\tFrom "<<bus[n].from<<" To "<<bus[n].to<<"\n\n\n";

  vline('*');

  bus[0].showReservedBusSeats(n); //Checks for reserved seats in the current bus( nth bus)

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"\n\t\t\tBus Not Found";

}

//Helps create a table output with seats empty and reserved seats with passenger name
void bus_rsshowReservedBusSeats(int l)
{

  int s=0,h=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          h++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<h<<" seats empty in Bus No: "<<bus[l].busn;

  }

//Print all the buses added in the system
void bus_rsshowAvailableBuses()
{

  for(int n=0;n<p;n++)

  {

    vline('*');

    cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver

    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"

    <<bus[n].to<<"\n";

    vline('*');

    vline('_');

  }

}

//Main function
int main()
{

//system("cls");
  //Choice will be users input to use different functionality over system using switch
  int choice, count = 3;

  vline('-');

  cout<<"\t\t     ****SRM Bus Travel Committee****"<<endl<<endl;
  tag:
  cout<<"\n\t\t   *****Please Do Login To Proceed*****"<<endl;
  string pass;
  cout<<"\nEnter the Password below\n";
  getline(cin,pass);
  if(pass == "AP21110010521" || pass == "AP21110010567" || pass == "AP21110010568" || pass == "AP21110010579" || pass == "AP21110010583")
  {
  	vline('*');
	while(1)
	{


		    //system("cls");
		  cout<<endl;

		  vline('*');

		  cout<<"\n\n";

		  cout<<"\t\t\t1.Add new Bus Details:\n\t\t\t"<<"2.Reserve your seats:\n\t\t\t"
		  <<"3.Show the available seats in a bus:\n\t\t\t"<<"4.Buses Available Now: \n\t\t\t"<<"5.Exit"<<endl;

		  vline('*');

		  cout<<"\n\t\t\tEnter your choice:-> ";
		  cin>>choice;

		  vline('*');

		  switch(choice)

		  {

				case 1:  bus[p].add_new();
			      break;

			    case 2:  bus[p].allotmentOfSeatToPassenger();
			      break;

			    case 3:  bus[0].showAvailableBusSeats();
			      break;

			    case 4:  bus[0].showAvailableBuses();
			      break;

			    case 5:
				{
			      cout<<"\n\t\t\tSuccessfully Logged out from the Application. \n\t\t\t\t   Visit Again!"<<endl<<"\t\t\t\t  <Thanks You :)>"<<endl<<endl;
			      exit(0);
		    	};

		  }
		}
	}
	else
	{
		cout<<"\n";
		vline('X');
		if(count > 1)
		{

			cout<<"\n\t\t\tEntered Wrong Password ";
			count--;
			cout<<"\n\t\t\tStill "<<count<<" Attempts Left"<<endl<<endl;
			goto tag;
		}
		else
		{
			cout<<"\n\t\t\t Failed To Enter The Password"<<"\n\t\t\t\tTry Again Later"<<endl<<endl;
			vline('X');
		}

	}
return 0;

}
