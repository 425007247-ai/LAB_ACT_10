#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#include <string>
using namespace std;

// Scenario 02: Computer Laboratory Assets. Base equipment tag = 120000.
int linearSearch(const vector<int>& data, int target) {
    for (int i = 0; i < static_cast<int>(data.size()); i++)
        if (data[i] == target) return i;
    return -1;
}
int binarySearch(const vector<int>& data, int target) {
    int low = 0, high = static_cast<int>(data.size()) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (data[mid] == target) return mid;
        if (data[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int linearSearchProbes(const vector<int>& data, int target) {
    int probes = 0;
    for (int value : data) { probes++; if (value == target) return probes; }
    return probes;
}
int binarySearchProbes(const vector<int>& data, int target) {
    int low = 0, high = static_cast<int>(data.size()) - 1, probes = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2; probes++;
        if (data[mid] == target) return probes;
        if (data[mid] < target) low = mid + 1; else high = mid - 1;
    }
    return probes;
}
vector<int> createData(int n) {
    vector<int> data; data.reserve(n);
    for (int i = 0; i < n; i++) data.push_back(120000 + 2 * i);
    return data;
}
double medianOfThree(double a, double b, double c) {
    if (a > b) swap(a,b); if (b > c) swap(b,c); if (a > b) swap(a,b); return b;
}
double benchmark(const vector<int>& data, int target, bool useBinary) {
    double times[3]; volatile long long checksum = 0;
    for (int batch = 0; batch < 3; batch++) {
        auto start = chrono::steady_clock::now();
        for (int i = 0; i < 100; i++)
            checksum += useBinary ? binarySearch(data,target) : linearSearch(data,target);
        auto finish = chrono::steady_clock::now();
        times[batch] = chrono::duration_cast<chrono::nanoseconds>(finish-start).count()/100.0;
    }
    return medianOfThree(times[0],times[1],times[2]);
}
void showVerification(const vector<int>& d,int t,const string& label) {
    cout << label << " (Target: " << t << ")\n  Linear Search index: " << linearSearch(d,t)
         << "\n  Binary Search index: " << binarySearch(d,t) << endl;
}
void showLinearTrace(const vector<int>& d,int target) {
    cout << "\nLINEAR SEARCH TRACE for " << target << endl; int probes=0;
    for (int i=0;i<(int)d.size();i++) { probes++; cout << "Index " << i << ": " << d[i];
        if(d[i]==target){cout<<"  <-- FOUND\nTotal probes: "<<probes<<endl;return;} cout<<endl; }
    cout<<"Not found. Total probes: "<<probes<<endl;
}
void showBinaryTrace(const vector<int>& d,int target) {
    cout << "\nBINARY SEARCH TRACE for " << target << endl;
    int low=0,high=(int)d.size()-1,probes=0;
    while(low<=high){int mid=low+(high-low)/2;probes++;
        cout<<"Probe "<<probes<<": low="<<low<<", high="<<high<<", mid="<<mid<<", key="<<d[mid]<<endl;
        if(d[mid]==target){cout<<"FOUND at index "<<mid<<". Total probes: "<<probes<<endl;return;}
        if(d[mid]<target)low=mid+1;else high=mid-1;}
    cout<<"Not found. Total probes: "<<probes<<endl;
}
int main() {
    const int BASE_KEY=120000; vector<int> verifyData=createData(12);
    cout<<"============================================\n SCENARIO 02: COMPUTER LABORATORY ASSETS\n============================================\n";
    cout<<"Base key: "<<BASE_KEY<<"\n\n12 Verification Equipment Tags:\n";
    for(int x:verifyData)cout<<x<<" "; cout<<endl;
    cout<<"\n--- VERIFICATION TESTS ---\n";
    showVerification(verifyData,verifyData[0],"Key at index 0");
    showVerification(verifyData,verifyData[5],"Key at index 5");
    showVerification(verifyData,verifyData[11],"Key at index 11");
    showVerification(verifyData,BASE_KEY+1,"Absent key");
    vector<int> emptyData;
    cout<<"\nEmpty vector test:\n  Linear Search: "<<linearSearch(emptyData,BASE_KEY)
        <<"\n  Binary Search: "<<binarySearch(emptyData,BASE_KEY)<<endl;
    cout<<"\n--- SCENARIO 02 ADDITIONAL TEST ---\n";
    int retiringTag=120005, li=linearSearch(verifyData,retiringTag), bi=binarySearch(verifyData,retiringTag);
    cout<<"Trying to retire equipment tag: "<<retiringTag<<endl;
    if(li!=-1)cout<<"Result: Equipment tag exists at index "<<li<<".\n";
    else cout<<"Result: Equipment tag does not exist. Cannot retire it.\n";
    cout<<"Linear Search result: "<<li<<"\nBinary Search result: "<<bi<<endl;
    vector<int> shuffled=verifyData; mt19937 generator(42); shuffle(shuffled.begin(),shuffled.end(),generator);
    cout<<"\n--- SHUFFLED DATA TEST ---\nShuffled equipment tags: ";
    for(int x:shuffled)cout<<x<<" ";
    cout<<"\nLinear search for 120010 returned index "<<linearSearch(shuffled,120010)<<endl;
    showLinearTrace(verifyData,verifyData[11]); showBinaryTrace(verifyData,verifyData[11]);
    cout<<"\n--- BENCHMARK RESULTS ---\nTimes are median nanoseconds per search (3 batches x 100 searches).\n\n";
    int sizes[4]={1000,10000,100000,1000000};
    cout<<left<<setw(12)<<"Size"<<setw(15)<<"Target"<<setw(15)<<"Linear probes"<<setw(15)<<"Binary probes"
        <<setw(20)<<"Linear ns/search"<<setw(20)<<"Binary ns/search"<<endl;
    for(int n:sizes){
        vector<int>d=createData(n); int hit=BASE_KEY+2*(n-1),miss=BASE_KEY+1;
        cout<<left<<setw(12)<<n<<setw(15)<<"Last key (hit)"<<setw(15)<<linearSearchProbes(d,hit)
            <<setw(15)<<binarySearchProbes(d,hit)<<setw(20)<<fixed<<setprecision(2)<<benchmark(d,hit,false)
            <<setw(20)<<benchmark(d,hit,true)<<endl;
        cout<<left<<setw(12)<<n<<setw(15)<<"Missing (miss)"<<setw(15)<<linearSearchProbes(d,miss)
            <<setw(15)<<binarySearchProbes(d,miss)<<setw(20)<<benchmark(d,miss,false)
            <<setw(20)<<benchmark(d,miss,true)<<endl;
    }
    cout<<"\n--- COMPLEXITY ANALYSIS ---\nLinear Search: O(n) time, O(1) auxiliary space.\n"
        <<"Binary Search: O(log n) time, O(1) auxiliary space.\nBinary Search requires sorted data. Sorting cost is separate.\n";
    return 0;
}