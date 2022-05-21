#include<bits/stdc++.h>
using namespace std ;

class date
{
    public:
    int dd ;
    int mm ;
    int yy ;
    date &operator=(const date &d)
    {
        dd = d.dd ;
        mm = d.mm ;
        yy = d.yy ;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const date &d)
    {
         os<<d.dd<<"-"<<d.mm<<"-"<<d.yy ;
         return os ;
    }
    friend istream &operator>>(istream &is, date &d)
    {
         cout<<"Enter the day of birth : ";
         is>>d.dd ;
         cout<<"Enter the month of birth : ";
         is>>d.mm ;
         cout<<"Enter the year of birth : ";
         is>>d.yy ;
         return is ;
    }
};
class lender ;
class borrower
{
    public:
    string name ;
    string fname ;
    int age ;
    int income ;
    date DOB ;
    int id ;
    int due_amount ;
    borrower()
    {
        cout<<"Enter the borrower name : ";
        cin>>name;
        cout<<"Enter the  father's name  of borrower : ";
        cin>>fname;
        cout<<"Enter the  DOB of borrower : \n";
        cin>>DOB;
        cout<<"Enter the age of borrower : ";
        cin>>age;
        cout<<"Enter the income of borrower : ";
        cin>>income; 
    }
    void printborrower()
    {
        cout<<name<<" "<<fname<<" "<<age<<" "<<due_amount<<endl;
    }

};
class lender 
{
    private :
     string name ;
     int id;
     double interest_rate ;
     vector<borrower> list_borrowers ;
    public :
      lender()
      {
          cout<<"Enter the lender name : ";
          cin>>name;
          cout<<"Enter the the id of lender : ";
          cin>>id;
          cout<<"Enter the interest of lender : ";
          cin>>interest_rate;
      }
      int ispresent( borrower bw )
      {
          for( int i = 0 ; i < list_borrowers.size() ; i++ )
          {
              if( list_borrowers[i].id == bw.id )return i+1 ;
          }
          return 0 ;
      }
      void give_loan( borrower & bw , int amount , int time )
      {
          if( ispresent(bw) != 0 )
          {
              int total_amount = amount + time*amount*interest_rate/100 ; 
              bw.due_amount += total_amount ;
              list_borrowers[ispresent(bw)].due_amount += total_amount ;
          }
          else 
          {
              int total_amount = amount + time*amount*interest_rate/100 ; 
              bw.id = list_borrowers.size() + 1 ;
              list_borrowers.push_back(bw) ;
              list_borrowers[bw.id - 1 ].due_amount = total_amount ;
          }
      }
      void deposite_amount( borrower &bw , int amount )
      {
          list_borrowers[bw.id - 1].due_amount -= amount ;
          bw.due_amount -= amount ;
      }
      void print_details()
      {
          for( int i = 0 ; i < list_borrowers.size() ; i++ )
          {
              list_borrowers[i].printborrower();
          }
      }

};

int main()
{
    lender L ;
    // cout<<1;
    borrower B;
    int amount = 1000 ;
    int t = 2 ;
    L.give_loan(B , amount , t );
    L.print_details();
    // cout<<2 ;
}