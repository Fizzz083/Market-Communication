#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

class bank
{
protected:
    string b_user_name;
    string bank_ac_no;
    int amount;
public:
    bank()
    {
        bank_ac_no="";
        amount=0;
    }
    void open_bank_ac(string name)
    {
        this->b_user_name=name;
        cout<<"\tEnter Bank account number"<<endl;
        cin>>this->bank_ac_no;
        cout<<"\tEnter Amount"<<endl;
        cin>>this->amount;

        ofstream fout;
        fout.open("bank.txt", ios::out|ios::app);
        fout<<endl;
        fout<<"new ";
        fout<<this->b_user_name<<" "<<this->bank_ac_no<<" "<<this->amount;
        fout.close();
    }

    void show_bank(string name)
    {
        this->b_user_name=name;
        bool flag=0;
        vector<string>row;
        while(!flag)
        {
            flag=1;
            fstream fin;
            fin.open("bank.txt", ios::in);
            string line,tmp,word;
            while(fin>>tmp)
            {
                row.clear();
                getline(fin, line);
                stringstream ss(line);
                while(ss>>word)
                {
                    row.push_back(word);
                }


                if(this->b_user_name==row[0])
                {
                    string s=row[1];
                    int s1;
                    stringstream now(row[2]);
                    now>>s1;
                    this->bank_ac_no=s;
                    this->amount=s1;
                    flag=0;
                }

            }
            fin.close();
            if(!flag)
            {
                break ;
            }

        }
        if(flag==0)
        {
            cout<<"\tBank A/C no: "<<this->bank_ac_no<<"\n\tAmount: "<<this->amount<<endl;
        }
        else
        {
            cout<<"NO Bank A/C Exists"<<endl;
        }
    }
    int get_money(string name,string *bank_ac)
    {
        int ta=0;
        this->b_user_name=name;
        bool flag=0;
        vector<string>row;
        while(!flag)
        {
            flag=1;
            fstream fin;
            fin.open("bank.txt", ios::in);
            string line,tmp,word;
            while(fin>>tmp)
            {
                row.clear();
                getline(fin, line);
                stringstream ss(line);
                while(ss>>word)
                {
                    row.push_back(word);
                }


                if(this->b_user_name==row[0])
                {
                    int s1;
                    *bank_ac=row[1];
                    stringstream now(row[2]);
                    now>>s1;
                    ta=s1;
                    flag=0;
                    break;
                }

            }
            fin.close();
            if(!flag)
            {
                return ta;
            }

        }
        return 0;

    }

    virtual   void add_user(){}
};

void bank_update(string ac, int taka)
{
    vector<pair<string,pair<string, int> > > vp;

    fstream fin;
    fin.open("bank.txt", ios::in);
    string line,tmp,word;
    vector<string>row;
    while(fin>>tmp)
    {
        row.clear();
        getline(fin, line);
        stringstream ss(line);
        while(ss>>word)
        {
            row.push_back(word);
        }
        string s1=row[0];
        string s2=row[1];
        stringstream now(row[2]);
        int n;
        now>>n;
        if(row[1]==ac)
        {
            n=taka;
        }
        vp.push_back({s1,{s2,n}});
    }
    fin.close();

    ofstream fout;
    fout.open("bank.txt", ios::out);
    for(int i=0; i<(int)vp.size(); i++)
    {
        fout<<endl;
        fout<<"new ";
        fout<<vp[i].first<<" "<<vp[i].second.first<<" "<<vp[i].second.second;
    }
    fout.close();
}
string get_owner_name(string org)
{
    bool flag=false;
    string res="";
    while(!flag)
    {
        // cout<<" hi"<<endl;
        flag=true;
        fstream fin;
        fin.open("organization.txt", ios::in);
        string line,tmp,word;
        vector<string>row;
        while(fin>>tmp)
        {
            row.clear();
            getline(fin, line);
            stringstream ss(line);
            while(ss>>word)
            {
                row.push_back(word);
            }

            if(org==row[0])
            {
                res=row[1];
                flag=false;
            }

        }
        fin.close();
        if(!flag)
        {
            return res;
        }
    }
    return res;

}

int check_all_user(string name)
{
    bool flag=false;
    while(!flag)
    {
        //  cout<<" bye"<<endl;
        flag=true;
        fstream fin;
        fin.open("all_user_list.txt", ios::in);
        string line,tmp,word;
        vector<string>row;
        while(fin>>tmp)
        {
            //  cout<<" hi"<<endl;
            row.clear();
            getline(fin, line);
            stringstream ss(line);
            while(ss>>word)
            {
                row.push_back(word);
            }

            if(name==row[0])
            {
                flag=0;
            }
        }
        fin.close();
        if(!flag)
        {
            return 1;
        }
    }
    return 0;
}

void add_to_all_user(string name)
{
        //  this->user_name=user;
        ofstream fout;
        fout.open("all_user_list.txt", ios::out|ios::app);
        fout<<endl;
        fout<<"new ";
        fout<<name;
        fout.close();
}
