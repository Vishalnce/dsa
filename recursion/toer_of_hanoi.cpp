#include <iostream>
using namespace std;

void tower(int n, char src, char dest, char aux) {

    if (n == 1) {
        cout << "Move disk from " << src << " to " << dest << endl;
        return;
    }
    // recursive call 
    tower(n-1, src, aux, dest);


    // my calcualtion 
    // i)  so this i am moving 1 disk from a to c 
    cout << "Move disk from " << src << " to " << dest << endl;
    // ii) this i am moving form n-1 disk to b to c 
    tower(n-1, aux, dest, src);
}

int main() {
    tower(2, 'a', 'b', 'c');
    return 0;
}
