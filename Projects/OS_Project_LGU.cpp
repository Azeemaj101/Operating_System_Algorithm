#include<iostream>
#include <windows.h> 
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
using namespace std;
sem_t lock; //globle
void * Main_Code(void *);
void findWaitingTime(int [], int, int [], int []);
void findTurnAroundTime(int [], int, int [], int [], int []);

// Random Funtion, Threads, Semaphores, 4 Departments 


int main()
{
	// Thread And semaphore variables
	int n[5]; 
	pthread_t T[5];

	// at a time more then one admin access the system
	int admins;
	
	//Use for Text Color
	system("color 87");
	
	//use random for choose random number
	srand(time(0));
	bool check = true;
	while(check)
	{	
		admins=(rand()%6)%4;
		cout<<"The total number of users who want to access the system (Total Admins = 3) (FCFS)\n";
		cout<<admins<<endl;
		system("PAUSE");
		if(admins>0 && admins<=3)
		{
			check = false;
		}
		else
		{
			cout<<"\n\n\t\tPlease enter positive number and less then or equal to three\n";
			system("PAUSE");
			system("CLS");
		}
	}
	
	// use concept of semaphore
	sem_init(&lock,0,1);
	
	// Create thread and join with parent process
	for(int i=0; i<admins; i++)
	{
		n[i]=i;
		pthread_create(&T[i],NULL,&Main_Code,(void *)&n[i]);
	}
	for(int i=0; i<admins; i++)
	{
		pthread_join(T[i],NULL);
	}
}

void *Main_Code(void *n)
{
	int ID=*(int *)n;
	sem_wait(&lock);
	//Login Vaiables
	string userName;
    int userPassword;
    int loginAttempt = 0;
    
    //Total number of patients 
    int num;
    
    int dep; //Department
	    
	//Use for Text Color & clear Screen
	system("color F4");
	system("CLS");
	
	//Display page
    cout<<"\n\n \t \t \t \t   ----------------------- Admin: "<<ID+1<<" ---------------------\n\n";
    cout<<"    \t \t \t \t                  Hospital Management System!\n\n";
	cout<<" \t \t \t \t \t \t    -----------------------\n\n";

	//login attempts total 5 there have 3 Admins
    while (loginAttempt < 5)
    {
        cout << "Please enter your Admin name: ";
        cin >> userName;
        cout << "Please enter your Admin password: ";
        cin >> userPassword;
        
        int ln = userName.length();
    	// Conversion according to ASCII values
    	for (int i = 0; i < ln; i++) {
        if (userName[i] >= 'A' && userName[i] <= 'Z')
            // Convert uppercase to lowercase
            userName[i] = userName[i] + 32;
    	}
    	
		cout << "Loading <";
		for (int i = 0; i <= 20; i++)
		{
			Sleep(100);
			cout << "|";
		}
		cout << ">100%\n\n";
		
        if (userName == "azeem" && userPassword == 1234)
        {
            cout << "Welcome To Admin Panal!\n";
            break;
        }
        else if (userName == "umer" && userPassword == 1234)
        {
            cout << " Welcome To Admin Panal!\n";
            break;
        }
        else if (userName == "muzammil" && userPassword == 1234)
        {
            cout << " Welcome To Admin Panal!\n";
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n\n";
            loginAttempt++;
            system("PAUSE");
            system("CLS");
        }
    }
    
    // this if use for terminate code because login password is wrong
    if (loginAttempt == 5)
    {
        cout << "Too many login attempts! The program will now terminate.";
		cout << "\t\t Thankyou for using program\n";
		cout << "\t\t\tAllah Hafiz\n";
		goto end; // use for terminate code 
    }

	userName[0] = userName[0]-32;
    cout << "\n\n    \t \t \t \t                  "<< userName <<" Thank you for logging in.\n\n\n";
	
	//Departmants
	cout<<"Press 1 for Outpatient Department (OPD)\n";
	cout<<"Press 2 for Injury Department\n";
	cout<<"Press 3 for Operation Department\n";
	cout<<"Press 4 for Pharmacy Department\n";
	cout<<"Press 5 for Exit\n";
	cin>>dep;
	if(dep != 5 && dep > 0)
	{	
	//Patients Data
	string patient[100];	
	int age[100];
	int bt[100];
	int patient_no[100];
	int inj[100];
	if(dep != 4)
	{
		//Total number of patients
		cout<<" \n \n   -> Enter the total number of Patient: ";
		cin>>num;
			
		cout<<"\n   Register Patients with their  ID, Name and Age\n\n";

		for(int i=0; i<num; i++)
		{
			cout<<"\n";
			patient_no[i]=i;
			cout<<"   Patient no "<<i+1<<"\n";
			cout<<"\n   Name    : ";
			cin>>patient[i];
			cout<<"\n   Age      : ";
			cin>>age[i];
			if(dep == 3)
			{
				cout<<"\n   Operation Time limit (BURST TIME): ";
				cin>>bt[i];	
			}
			else{
				cout<<"\n   Time limit (BURST TIME): ";
				cin>>bt[i];
			}
			if(dep == 2)
			{
				cout<<"\n   Injury in (%)    : "; 
				cin>>inj[i];
			}
			cout<<"   \n";
		}
	}
	int wt[num], tat[num], total_wt = 0, total_tat = 0;

	switch(dep)
	{
		case 1:
			{
				//Function to find waiting time of all processes
				findWaitingTime(patient_no, num, bt, wt);

				//Function to find turn around time for all processes
				findTurnAroundTime(patient_no, num, bt, wt, tat);
			
				//Display processes along with all details
				cout << "Patient ID  Patient Name  Age  Burst time  Waiting time  Turn around time\n";
			
				// Calculate total waiting time and total turn
				// around time
				for (int i=0; i<num; i++)
				{
					total_wt = total_wt + wt[i];
					total_tat = total_tat + tat[i];
					cout << "   " << patient_no[i]+1 << "\t\t" << patient[i] << "\t   " << age[i] << "\t   " << bt[i] <<"\t\t  "<< wt[i] <<"\t\t " << tat[i] <<endl;
				}
			
				cout << "Average waiting time = "<< (float)total_wt / (float)num;
				cout << "\nAverage turn around time = "<< (float)total_tat / (float)num<<endl;
				system("PAUSE");
				break;
				
			}
		case 2:
			{
				int temp;
				string tempS;
				cout<<"\n\n   -> Most injured patient get bed First (High priority)\n\n";
			    for(int i = 0; i<num-1; i++)
			    {
			       for (int j = 0; j < num-i-1; j++)  
			       {
			             if (inj[j] < inj[j+1])
			             {
			                temp = inj[j];
			                inj[j] = inj[j+1];
			                inj[j+1] = temp;
			                
			                temp = bt[j];
			                bt[j] = bt[j+1];
			                bt[j+1] = temp;
			                
			                temp = patient_no[j];
			                patient_no[j] = patient_no[j+1];
			                patient_no[j+1] = temp;
			                
			                tempS = patient[j];
			                patient[j] = patient[j+1];
			                patient[j+1] = tempS;
			                
			                temp = age[j];
			                age[j] = age[j+1];
			                age[j+1] = temp;
			            }
			        }
			    }
			    //Function to find waiting time of all processes
				findWaitingTime(patient_no, num, bt, wt);
			
				//Function to find turn around time for all processes
				findTurnAroundTime(patient_no, num, bt, wt, tat);
			
				//Display processes along with all details
				cout << "Patient ID  Patient Name  Age  Injury  Burst time  Waiting time  Turn around time\n";
			
				// Calculate total waiting time and total turn
				// around time
				for (int i=0; i<num; i++)
				{
					total_wt = total_wt + wt[i];
					total_tat = total_tat + tat[i];
					cout << "   " << patient_no[i]+1 << "\t\t" << patient[i] << "\t   " << age[i] << "\t " << inj[i] << "\t    " << bt[i] <<"\t\t  "<< wt[i] <<"\t\t " << tat[i] <<endl;
				}
			
				cout << "Average waiting time = "<< (float)total_wt / (float)num;
				cout << "\nAverage turn around time = "<< (float)total_tat / (float)num<<endl;
				system("PAUSE");
			    break;
			}
		case 3:
			{
				int temp;
				string tempS;
				cout<<"\n\n   -> Minor surgery patient get operate First (SJF)\n\n";
			    for(int i = 0; i<num-1; i++)
			    {
			       for (int j = 0; j < num-i-1; j++)  
			       {
			             if (bt[j] > bt[j+1])
			             {
			                temp = bt[j];
			                bt[j] = bt[j+1];
			                bt[j+1] = temp;
			                
			                temp = patient_no[j];
			                patient_no[j] = patient_no[j+1];
			                patient_no[j+1] = temp;
			                
			                tempS = patient[j];
			                patient[j] = patient[j+1];
			                patient[j+1] = tempS;
			                
			                temp = age[j];
			                age[j] = age[j+1];
			                age[j+1] = temp;
			            }
			        }
			    }
			    //Function to find waiting time of all processes
				findWaitingTime(patient_no, num, bt, wt);
			
				//Function to find turn around time for all processes
				findTurnAroundTime(patient_no, num, bt, wt, tat);
			
				//Display processes along with all details
				cout << "Patient ID  Patient Name  Age  Burst time  Waiting time  Turn around time\n";
			
				// Calculate total waiting time and total turn
				// around time
				for (int i=0; i<num; i++)
				{
					total_wt = total_wt + wt[i];
					total_tat = total_tat + tat[i];
					cout << "   " << patient_no[i]+1 << "\t\t" << patient[i] << "\t   " << age[i] << "\t    " << bt[i] <<"\t\t  "<< wt[i] <<"\t\t " << tat[i] <<endl;
				}
			
				cout << "Average waiting time = "<< (float)total_wt / (float)num;
				cout << "\nAverage turn around time = "<< (float)total_tat / (float)num<<endl;
				system("PAUSE");
			    break;
			}
			
		case 4:
			{
		string stock[100]={"Synthroid","Crestor","Ventolin","Nexium","Advair_Diskus","Lantus","Vyvanse","Lyrica","Spiriva","Januvia"};
				//cout<<stock[0]<<" "<<stock[9]<<endl;
				int empty=90;
				int full=10;
				int mutex=1;
				while(1)
				{
					cout<<"-------------------------------"<<endl<<endl;
					
					cout<<"Empty = "<<empty<<" , Full = "<<full<<" , Mutex = "<<mutex<<endl;
					
					cout<<"Enter your choice: \n1)ADD Medicine (Produce) \n2)Use Medicine (Consume) \n3)Display All \n4)Exit"<<endl;
					int x;
					cin>>x;
					if(x==1){
						if(empty != 0 && mutex==1)
						{
							cout<<"Enter Medicine Name: "<<endl;
							//wait()
							--empty;
							//wait()
							--mutex;
							cin>>stock[full];
							//signal()
							++mutex;
							//signal()
							++full;
						}
					else
						cout<<"Stock is full"<<endl;
					}
					
					else if(x==2){
						if(full>0 && mutex==1)
						{
							//wait()
							--full;
							//wait()
							--mutex;
							cout<<"Medicine is "<<stock[full]<<endl;
							//signal()
							++mutex;
							//signal()
							++empty;
						}
						else
						cout<<"Stock is empty"<<endl;
					}
					
					else if(x==3)
					{
						if(full > 0)
						{
							for(int i=0; i<full; i++)
							{
								cout<<"Medicine "<<i+1<<": "<< stock[i]<<endl;
							}
						}
						else
							cout<<"Stock is empty\n";
					}
					else if(x == 4)
					{
						goto end;
					}
					
					else 
					{
						cout<<"wrong input....\n";
						system("PAUSE");
					}
				}
				break;
			}
		default:
			{
				goto end;
			}
	}
	}end:
	sem_post(&lock);
	
}

void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
	// waiting time for first process is 0
	wt[0] = 0;
	// calculating waiting time
	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}

// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}
