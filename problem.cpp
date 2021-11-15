#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

// PLEASE READ THESE INSTRUCTIONS CAREFULLY
// ALWAYS ENTER WITHDRAW OR CREDIT AMOUNTS IN xD space yC format
//WHERE X = DOLLARS & Y = CENTS YOU WANT TO DEPOSIT OR WITHDRAW
//IF YOU WANT TO DEPOSIT/WITHDRAW ONLY CENTS ENTER 0D yC AND NOT JUST yC

class bank_account{
    private :
    int amount_dollars = 0;
    int amount_cents = 0 ;
    public :
    void deposit(string s){
        // cout << s ;
        int d=0,c=0,i=0 ;
        if(s.find("D") != string::npos){
            string x = "" ;
            while(s[i] != 'D'){
                x.push_back(s[i]) ;
                i++ ;
            }
            d = stoi(x) ;
            i++ ;
        }
        if(s.find("C") != string::npos){
            // cout << "hello" ;
            string x = "" ;
            while(s[i] != 'C'){
                x.push_back(s[i]) ;
                i++ ;
            }
            c = stoi(x) ;
        }
        
        amount_dollars += d ;
        amount_cents += c ;

        if(amount_cents >= 100){
            amount_dollars += 1;
            amount_cents -= 100;
        }
        
    }
    void withdraw(string s){
        int d=0,c=0,i=0 ;
        if(s.find("D") != string::npos){
            string x = "" ;
            while(s[i] != 'D'){
                x.push_back(s[i]) ;
                i++ ;
            }
            d = stoi(x) ;
            i++ ;
        }
        if(s.find("C") != string::npos){
            // cout << "hello" ;
            string x = "" ;
            while(s[i] != 'C'){
                x.push_back(s[i]) ;
                i++ ;
            }
            c = stoi(x) ;
        }
        
        if(c > amount_cents){
            amount_cents += 100 ;
            amount_dollars -= 1 ;
        }
        amount_dollars -= d ;
        amount_cents -= c ;
    }
    void get_balance(){
        cout << "Your current account balance is "<< amount_dollars << "D "<< amount_cents <<"C" << endl ;
    }
} ;

int main() {
    int i=0 ;
    bank_account A ;
    while(1){
        cout << "Wha would you like to do ? \n 1. Deposit \n 2. Withdraw \n 3. Check Balance \n 4. Exit \n" << endl;
        cout<<"Please enter appropriate option"<<endl;
        int k ;
        cin >> k ;
        i = k ;
        if(i == 1){
            cout << "Enter the amount to be deposited in 'xD yC' format : " << " " ;
            string s = "", m = "" ;
            cin >> s ;
            cin >> m ;
            s = s+m ;
            A.deposit(s) ;
            cout << "Deposit Successful ! Enter 3 to check current balance." << endl ;
        }
        else if(i == 2){
            cout << "Enter the amount to be withdrawn in 'xD yC' format : " << " " ;
            string s = "", m = "" ;
            cin >> s ;
            cin >> m ;
            s = s+m ;
            A.withdraw(s) ;
            cout << "Withdrawl Successful ! Enter 3 to check current balance." << endl ;
        }
        else if(i == 3){
            A.get_balance() ;
        }
        else if(i == 4){
            return 0 ;
        }
        else {
            cout << "Please choose an existing option !"<< endl ;
        }
    }
    return 0;
}