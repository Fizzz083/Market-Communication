
#include <bits/stdc++.h>

using namespace std;

template<class T>
class str
{
public:
   T s;
    T friend operator+(str p, str q)
    {
        T x=p.s+q.s;
        return x;
    }
  //  friend class conversation;
};

class conversation : public str<string>
{
    string file_name;
public:

    void user_to_org_conversation(string name, string org)
    {
        string s2;

        str<string> ss,ss1,ss2,ss3;

        s2="client_conversation\\";

        ss.s=s2;

        string s="conversation\\";
        ss1.s=s;

        ss2.s=ss1+ss;

        string file=ss2.s+org+".txt";

        ofstream fout;
        fout.open(file, ios::in|ios::app);

        cout<<"\tEnter message"<<endl;
        char msg[10000];
        getchar();
        cin.getline(msg,10000);
        fout<<endl;
        fout<<"new ";
        fout<<name<<" "<<msg;
        fout.close();
    }

    void org_to_org_conversation(string name, string org)
    {
        string s2;

        s2="org_conversation\\";

        str<string> ss,ss1,ss2,ss3;

       // s2="client_conversation\\";

        ss.s=s2;

        string s="conversation\\";
        ss1.s=s;

        ss2.s=ss1+ss;

        string file=ss2.s+org+".txt";

        ofstream fout;
        fout.open(file, ios::out|ios::app);
        string word;
        cout<<"\tEnter message: ";
        char msg[10000];
        getchar();
        cin.getline(msg,10000);

        fout<<endl;
        fout<<"new ";
        fout<<name;
        fout<<" "<<msg;
        fout.close();
    }

    void view_msg(string org, int r)
    {
        cout<<"\t\t\tPrevious Messages.."<<endl;
        string s2;
        if(r==1)
            s2="org_conversation\\";
        else
            s2="client_conversation\\";
        string s="conversation\\";

        string file=s+s2+org+".txt";

        fstream fin;
        fin.open(file, ios::in);
        vector<string>row;
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

            cout<<"\tSender: "<<row[0];
            cout<<"\n\t\t : ";
            for(int i=1; i<(int)row.size(); i++)
            {
                cout<<row[i]<<" ";
            }
            cout<<endl;

        }
        fin.close();
        cout<<endl;
    }
};
