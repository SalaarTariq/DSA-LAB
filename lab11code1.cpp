#include <iostream>
using namespace std;
int tree[100];
int main() {
int n, value, index;
for(int i = 0; i < 100; i++)
tree[i] = -1;
cout << "How many nodes? ";
cin >> n;
for(int i = 0; i < n; i++) {
cout << "Enter value: ";
cin >> value;
cout << "Enter index: ";
cin >> index;
if(index < 1 || index >= 100) {
cout << "Invalid index\n";
} else if(tree[index] != -1) {
cout << "Position already occupied\n";
} else {
tree[index] = value;
}
}
cout << "\nTree (Index -> Value):\n";
for(int i = 1; i < 100; i++) {
if(tree[i] != -1)
cout << i << " -> " << tree[i] << endl;
}
cout << "\nSearch value: ";
cin >> value;
bool found = false;
for(int i = 1; i < 100; i++) {
if(tree[i] == value) {
cout << "Found at index " << i << endl;
found = true;
break;
}
}
if(!found)
cout << "Value not found\n";
return 0;
}