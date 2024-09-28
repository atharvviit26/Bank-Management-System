#include<bits/stdc++.h>
using namespace std;





// -----------------------------------------------Class Account----------------------------------------------- //

class account{
    
    protected:
        string firstName;
        string lastName;
        string password;
        int balance;
        int accountNo;

    public:

        void createAcc(int cnt);
        void display();
        void addMoney();
        bool checkPassword();
        void withdrawMoney();

};

void account::createAcc(int cnt)
{
    string s1,s2,s3;
    int blnc;
    cout<<"Enter your First Name : ";
    cin>>s1;
    cout<<"Enter your Last Name : ";
    cin>>s2;
    cout<<"Enter a secure password for your account : ";
    cin>>s3;
    cout<<"Enter how much amount of balance you want to store : ";
    cin>>blnc;
    firstName=s1;
    lastName=s2;
    password=s3;
    balance=blnc;
    accountNo=cnt;
    cout<<"Your Account No is : "<<accountNo;
    cout<<"\n\n";
    return;
}


bool account::checkPassword()
{
    string temp;
    cout<<"Please Enter the Password first : ";
    cin>>temp;
    if(temp != password)
    {
        cout<<"You have entered the wrong password \n";
        cout<<"Sorry you can't access the account\n";
        return 0;
    }
    return 1;
}


void account:: display()
{
    if(!checkPassword()) return;
    cout<<"\nName : "<<firstName<<" "<<lastName<<"\n";
    cout<<"Account No : "<<accountNo<<'\n';
    cout<<"Available Balance : "<<balance<<'\n';
    cout<<"\n\n";
    return;
}


void account:: addMoney()
{
    if(!checkPassword()) return;
    int amt;
    cout<<"Enter the amount you want to add in account : ";
    cin>>amt;
    balance+=amt;
    cout<<"\nCongratulation "<<amt<<" amount has been successfully added to you account\n";
    return;
}



void account:: withdrawMoney()
{
    if(!checkPassword()) return;
    int amt;
    cout<<"Enter the amount you want to withdraw from account : ";
    cin>>amt;
    if(amt > balance)
    {
        cout<<"Sorry you can't withdraw "<<amt<<"Rs ,as your account balance is "<<balance<<"Rs \n";
        return;
    }
    balance-=amt;
    cout<<"Sucessfully debited "<<amt<<" from your account\n";
    cout<<"Account Balance : "<<balance<<"\n\n";
    return;
}

// -----------------------------------------------Class Account----------------------------------------------- //









// -----------------------------------------------Class Bank----------------------------------------------- //



class Bank : protected account
{
        static int cnt;
        map<int,account> mp;
    public:
        void option(int choice);
        pair<bool,int> isValidAccount();
};


int Bank::cnt=1;

pair<bool,int> Bank::isValidAccount()
{
    int AccNo;
    cout<<"Enter your Account Number : ";
    cin>>AccNo;
    if(mp.find(AccNo) == mp.end())
    {
        return {0,AccNo};
    }
    return {1,AccNo};
}

void Bank::option(int choice)
{
    if(choice==6) return;
    if(choice==1)
    {
        account a1;
        a1.createAcc(cnt);
        mp[cnt]=a1;
        cnt+=1;
        return;
    }
    if(choice==2)
    {
        pair<bool,int> b= isValidAccount();
        if(b.first)
        {
            mp[b.second].display();
        }
        else
        {
            cout<<"Please enter a valid Account No \n\n";
        }
    }
    if(choice==3)
    {
        pair<bool,int> b= isValidAccount();
        if(b.first)
        {
            mp[b.second].addMoney();
        }
        else
        {
            cout<<"Please enter a valid Account No \n\n";
        }
    }
    if(choice==4)
    {
        pair<bool,int> b= isValidAccount();
        if(b.first)
        {
            mp[b.second].withdrawMoney();
        }
        else
        {
            cout<<"Please enter a valid Account No \n\n";
        }
    }
    if(choice==5)
    {
        pair<bool,int> b= isValidAccount();
        if(b.first)
        {
            int key =b.second;
            bool correct = mp[key].checkPassword();
            if(!correct) return;
            auto it=mp.find(key);
            if(it != mp.end())
            {
                mp.erase(it);
            }
            // 
            cout<<"Sucessfully deleted your Account ";
            return;
        }
        else
        {
            cout<<"Please enter a valid Account No \n\n";
        }
    }
}



// -----------------------------------------------Class Bank----------------------------------------------- //


void validResponse()
{
    cout<<"Please Enter a valid option !!\n\n";
}


int main()
{
    Bank b;
    int choice;
    string s1;
    do {
        cout<<"Select the option number from below : \n";
        cout<<"1. Create Account \n";
        cout<<"2. Check Balance \n";
        cout<<"3. Add Money \n";
        cout<<"4. Withdraw Money \n";
        cout<<"5. Close Account \n";
        cout<<"6. Quit\n";
        cin>>s1;
        if(s1.size() > 1) validResponse();
        else
        {
            choice=stoi(s1);
            if(choice < 1 && choice > 6) validResponse();
            b.option(choice);
        }
    } while (choice != 6);
}