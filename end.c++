#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
vector<string> out[100];
int createTable(string &a,int index){
    vector<string> table;
    a.erase(0, 12);
    stringstream ss(a);
    string tok;
    int flag = 0,c=2;
    while(getline(ss, tok,' ')){
        table.push_back(tok);
        if(tok == "INTEGER" || tok == "FLOATING" || tok == "STRING"){
            flag++;
        }
    }
    ss.str("");
    ss.clear();
    tok = table[1];
    int n = stoi(tok);
    string line = table[2];
    if(!out[index-1].empty() && index > 0){
        if(out[index-1][0] == table[0]){
            table.resize(0);
            table.clear();
            return 4;
        }
    }
    for(int i = 3; i < table.size();i+=2){
        if(table[i] != "INTEGER" && table[i] != "FLOATING" && table[i] != "STRING"){
            table.resize(0);
            table.clear();
            return 1;
        }
    }
    if(n != flag){
        table.resize(0);
        table.clear();
        return 2;
    }
    flag = 0;
    for(int j = 0; j < n;j++){
        for(int i = 0; i < table.size();i+=2){
            if(table[i] == line){
                flag++;
                if(flag>=2){
                    table.resize(0);
                    table.clear();
                    return 3;
                }
            }
        }
        flag = 0;
        line = table[c += 2];
    }
    for(int i = 0; i < table.size();i++){
        out[index].push_back(table[i]);
    }
    return 0;
}
int showTableList(int index,string tmp){
    if(tmp!="showTableList"){
        bool flag = false;
        int flag1;
        for(int i = 0; i < index; i++){
            if(out[i][0] == tmp){
                flag = true;
                flag1 = i;
                break;
            }
        }
        if(flag){
            int len = stoi(out[flag1][1]),o=0;
            for (int j = 2; j < out[flag1].size(); j++){
                if(out[flag1][j] == "INTEGER" || out[flag1][j] == "FLOATING" || out[flag1][j] == "STRING"){
                    continue;
                }else{
                    cout << out[flag1][j] << "\t";
                    o++;
                    if(o==len){
                        o = 0;
                        cout << "\n";
                    }
                }
            }
        }else{
            return -1;
        }
    }else{
        for(int i = 0; i < index; i++){
            int len = stoi(out[i][1]);
            for (int j = 0;j<len*2+2;j++){
                if(j==1){
                    continue;
                }
                if(j==0){
                    cout << out[i][j] << " [";
                }else if(j%2==0 && j!=0){
                    cout << "(" << out[i][j] << ", ";
                }else if(j%2==1){
                    cout << out[i][j] << ")";
                }
                if(j==len*2+1){
                    cout << "]\n";
                }
            }
        }
    }
    return 0;
}

int insertinto(string ins,int index){
    stringstream ss(ins);
    string tok;
    vector<string> tmp;
    bool found = false;
    int flag=0,flag1=0;
    while(getline(ss,tok,' ')){
        tmp.push_back(tok);
        flag1++;
    }
    ss.str("");
    ss.clear();
    for (int i = 0; i < index;i++){
        if(tmp[2]==out[i][0]){
            flag = i;
            found = true;
            break;
        }
    }
    if(found){
        int len = stoi(out[flag][1]),aa=3;
        if(len !=flag1-3){
            tmp.resize(0);
            tmp.clear();
            return 2;
        }
        for (int i = 0; i < len;i++){
            out[flag].push_back(tmp[aa++]);
        }
    }else{
        tmp.resize(0);
        tmp.clear();
        return -1;
    }
    return 0;
}

int main(){
    int ch = 0;
    while (true)
    {
        string a;
        int b;
        getline(cin, a);
        if (a == "exit")
        {
            return 0;
         }
        else if(a.find("createTable")!=string::npos){
            b=createTable(a,ch);
            if(b==1){
                cout << "Field type incorrect\n";
            }else if(b==2){
                cout << "Incorrect command\n";
            }else if(b==3){
                cout << "Field name duplicated\n";
            }else if(b==4){
                cout << "Table name duplicated\n";
            }else if(b==0){
                ch++;
            }
         }

        else if(a.find("showTableList")!=string::npos || a.find("showTableContent")!=string::npos){
            stringstream ss(a);
            string tok;
            while(getline(ss,tok,' '));
            ss.str("");
            ss.clear();
            b = showTableList(ch,tok);
            if(b==-1){
                cout << "Table does not exist\n";
            }
         }
        else if(a.find("insert into")!=string::npos){
            b = insertinto(a,ch);
            if(b==-1){
                cout << "Table does not exist\n";
            }else if(b==2){
                cout << "Number of fields is not consistent\n";
            }
         }
     }
}