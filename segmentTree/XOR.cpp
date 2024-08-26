#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>

using namespace std;


int main() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for(int i=1;i<n;i++){
        v[i] ^= v[i-1];
    }

    while(q>0){
        q--;
        int a,b;
        cin>>a>>b;

        a--;
        b--;
        if(a==0)
        cout<<v[b]<<endl;
        else{
            int ans = v[b]^v[a-1];
            cout<<ans<<endl;
        }
    }

    return 0;
}
