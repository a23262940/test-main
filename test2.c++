#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
template <typename T> vector<size_t> sort_indexes_e(vector<T> &v)
{
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
        [&v](size_t i1, size_t i2) {return v[i1] < v[i2]; });
    return idx;
}
int main(){
    int i=0;
    /*while(true){
        int a[100],b[11],c;
        for (int i = 0; i < 11;i++){
            b[i] = 0;
        }
        cin >> c;
        if (c <= 0){
            break;
        }
        for (i = 0; i < c; i++){
            cin >> a[i];
            if(a[i]<0 || a[i]>10)
                return 0;
        }
        int max1 = 0;
        int max2 = a[0];
        for(i=0; i<c; i++){
            if(a[i]>=max2){
                max1 = a[i];
            }
            if(a[i]>=0 && a[i]<=10)
                b[a[i]]++;
            else
                continue;
        }
        for (i = 0; i < 11;i++){
            if(b[i]!=0 && i != max1){
                cout << i << ":" << b[i] << " ";
            }else if(b[i]!=0 && i==max1){
                cout << i << ":" << b[i];
            }
        }
        cout << "\n";
    }*/
    while(true){
        int c;
        cin >> c;
        if (c <= 0){
            break;
        }
        vector<float> v;
        float f;
        for (i = 0; i < c; i++){
            cin >> f;
            if(f<0 || f>10)
                return 0;
            v.push_back(f);
        }
        vector<int> v1;
        int conut=0,j;
        for (i = 0;i<v.size();i++){
            float tmp = v[i];
            for (j = 0;j<v.size();j++){
                if(tmp==v[j])
                    conut++;
            }
            v1.push_back(conut);
            conut = 0;
        }
        vector<size_t> index = sort_indexes_e(v);
        for (i = 0;i<v.size();i++){
            if(v[index[i]]!=v[index[i]-1])
            cout << v[index[i]] << ":" << v1[index[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}