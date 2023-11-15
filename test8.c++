#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
using namespace std;
template <typename T> vector<size_t> sort_indexes_e(vector<T> &v)
{
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
        [&v](size_t i1, size_t i2) {return v[i1] > v[i2]; });
    return idx;
}
int main(){
    int a, b, f;
    string e;

    while(true){
        cin >> a >> b;
        if(a<1 || b<1){
            break;
        }
        vector<string> d[a];
        static vector<double> tmp;
        for(int i=0; i<a; i++){
            double sum = 0.0;
            cin >> e;
            d[i].push_back(e);
            for(int j=0; j<b; j++){
                cin >> f;
                d[i].push_back(to_string(f));
                sum += double(f);
            }
            sum /= b;
            d[i].push_back(to_string(sum));
            if(sum-int(sum)>=0.05)
                sum += 0.05;
            tmp.push_back(sum);
        }
        static vector<size_t> index;
        index = sort_indexes_e(tmp);
        cout << a << " " << b << endl;
        for (int i = 0; i != index.size(); i++)
        {
            for (int j = 0; j < d[index[i]].size(); j++)
            {
                if(j==d[index[i]].size()-1)
                    break;
                cout << d[index[i]][j] << " ";
            }
            printf("%.1f\n", tmp[index[i]]);
        }
        index.clear();
        tmp.clear();
    }
    return 0;
}
