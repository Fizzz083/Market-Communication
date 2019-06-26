#include "Owner.H"
#include "worker.h"
#include "user.h"
#define pb push_back
#define ll long long

int main()
{

    cout<<"\n\t\t\t\t###############################################";
    cout<<"\n\t\t\t\t#.............................................#";
    cout<<"\n\t\t\t\t#...........Welcome to BUSYness PANDA.........#";
    cout<<"\n\t\t\t\t#.............................................#";
    cout<<"\n\t\t\t\t###############################################";

    cout<<"\n\n";
A:
    cout<<"\t\t\t1.Sign Up"<<endl;
    cout<<"\t\t\t2.Log in"<<endl;
    cout<<"\t\t\t3.Exit"<<endl;
    int cas;
    cin>>cas;

    if(cas==3)
    {
      cout<<"\n\t\t\t\t    ......Thank you for being with us......\n"<<endl;
        return 0;
    }
    if(cas==1)
    {
        cout<<"\t\t\t1.Owner sign up"<<endl;
        cout<<"\t\t\t2.Worker sign up"<<endl;
        cout<<"\t\t\t3.User sign up"<<endl;
        int n1;
        cin>>n1;
        if(n1==1)
        {
            int r=owner_sign();
            if(r==1)
            {
                goto A;
            }
            else
            {
                cout<<"\n\t\t\t\t    ......Thank you for being with us......\n"<<endl;
                return 0;
            }
        }
        if(n1==2)
        {
            int r=worker_sign();
            if(r==1)
            {
                goto A;
            }
            else
            {
                cout<<"\n\t\t\t\t    ......Thank you for being with us......\n"<<endl;
                return 0;

            }
        }
        else if(n1==3)
        {
            int r=user_sign();
            if(r==1)
            {

                goto A;
            }
            else
            {
               cout<<"\n\t\t\t\t    ......Thank you for being with us......\n"<<endl;
                return 0;

            }

        }

    }
    else if(cas==2)
    {
        cout<<"\t\t\t1.Owner Log in"<<endl;
        cout<<"\t\t\t2.Worker Log in"<<endl;
        cout<<"\t\t\t3.User Log in"<<endl;
        int n;
        cin>>n;
        if(n==1)
        {
            string owner_name, owner_org;
            int r=owner_login(&owner_name, &owner_org);
            if(r==0)
            {
                cout<<"\tFailed to log in.\n"<<endl;
                goto A;
            }
            else
            {
S:
                cout<<"\tEnter an option"<<endl;
                cout<<"\t\t1.My Profile\n\t\t2.My Products\n\t\t3.My workers\n\t\t4.Add Product\n\t\t5.Edit Product info"<<endl;
                cout<<"\t\t6.Organization Conversation\n\t\t7.Open Conversation\n\t\t8.Log Out"<<endl;
                int r;
                cin>>r;
                if(r==1)
                {
                    show_owner_profile(owner_name);
                    cout<<endl;
                    goto S;
                }
                else if(r==2)
                {
                    organization o;
                    o.show_goods(owner_org);
                    goto S;
                }
                else if(r==3)
                {
                    show_workers(owner_org);
                    goto S;
                }
                else if(r==4)
                {
                    organization o;
                    o.add_extra_goods(owner_org);
                    goto S;

                }
                else if(r==5)
                {
                    cout<<"\n\t\t1.Update Product\n\t\t2.Delete Product"<<endl;
                    int tt=0;
                    cin>>tt;

                    organization o;
                    if(tt==1)
                        o.edit_goods(owner_org);
                    else if(tt==2)
                        o.delete_goods(owner_org);

                    goto S;

                }
                else if(r==6)
                {
                    conversation con;
                    con.view_msg(owner_org,1);
                    cout<<"\tIf you want to reply?\n\t\t1.Yes\n\t\t2.No"<<endl;
                    int r;
                    cin>>r;
                    if(r==1)
                        con.org_to_org_conversation("Owner",owner_org);
                    goto S;


                }
                else if(r==7)
                {
                    conversation con;
                    con.view_msg(owner_org,2);
                    cout<<"\tIf you want to reply?\n\t\t1.Yes\n\t\t2.No"<<endl;
                    int r;
                    cin>>r;
                    if(r==1)
                        con.user_to_org_conversation("Owner",owner_org);
                    goto S;

                }
                else if(r==8)
                {
                    goto A;
                }


            }
        }
        if(n==2)
        {
            string worker_name, worker_org;
            int r=worker_login(&worker_name, &worker_org);
            if(r==0)
            {
                cout<<"\tFailed to log in.\n"<<endl;
                goto A;
            }
            else
            {
P:
                cout<<"\tEnter an option"<<endl;
                cout<<"\t\t1.My Profile\n\t\t2.My Company's Products"<<endl;
                cout<<"\t\t3.Organization Coversation\n\t\t4.Open Coversation\n\t\t5.Log Out"<<endl;
                int r;
                cin>>r;
                if(r==1)
                {
                    show_worker_profile(worker_name);
                    cout<<endl;
                    goto P;
                }
                else if(r==2)
                {
                    organization o;
                    o.show_goods(worker_org);
                    goto P;
                }
                else if(r==3)
                {
                    conversation con;
                    con.view_msg(worker_org,1);
                    cout<<"\tIf you want to reply?\n\t\t1.Yes\n\t\t2.No"<<endl;
                    int r;
                    cin>>r;
                    if(r==1)
                        con.org_to_org_conversation(worker_name,worker_org);
                    goto P;

                }
                else if(r==4)
                {
                    conversation con;
                    con.view_msg(worker_org,2);
                    cout<<"\tIf you want to reply?\n\t\t1.Yes\n\t\t2.No"<<endl;
                    int r;
                    cin>>r;
                    if(r==1)
                        con.user_to_org_conversation(worker_name,worker_org);
                    goto P;
                }
                else if(r==5)
                {
                    goto A;
                }

            }
        }
        else if(n==3)
        {
            string user_name;
            int r=user_login(&user_name);
            if(r==0)
            {
                cout<<"\tFailed to log in.\n"<<endl;
                goto A;
            }
            else
            {
Q:
                cout<<"\tEnter an option"<<endl;
                cout<<"\t\t1.My Profile\n\t\t2.Search Organization"<<endl;
                cout<<"\t\t3.Log Out"<<endl;
                int r;
                cin>>r;
                if(r==1)
                {
                    show_user_profile(user_name);
                    goto Q;
                }
                else if(r==2)
                {
                    bank b;
                    string bank_ac;
                    int taka=b.get_money(user_name,&bank_ac);
                    search_org(user_name, taka,bank_ac);
                    goto Q;
                }
                else if(r==3)
                {
                    goto A;
                }
            }
        }
    }
    return 0;
}
