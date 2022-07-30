#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator&it){
    char head = *it;
    ++it;
    if(head == 'b' || head == 'w')
        return string(1, head);
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(){
    int n;
    cin >> n;
    for (int i =0; i < n; i++ ) {
        string original;
        cin >> original;
        string::iterator it = original.begin();
        cout << reverse(it) << endl;
    }
}