#include <iostream>
using namespace std;
#define MAX 5
int heap_size = 0;
int harr[MAX];
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return (2 * i + 1); }
int right(int i) { return (2 * i + 2); }
// ================= MIN HEAP INSERT =================
void insertKey_min(int k)
{
if (heap_size == MAX)
{
cout << "\nOverflow: Could not insertKey\n";
return;
}
heap_size++;
int i = heap_size - 1;
harr[i] = k;
// Fix min-heap property
while (i != 0 && harr[parent(i)] > harr[i])
{
int temp = harr[i];
harr[i] = harr[parent(i)];
harr[parent(i)] = temp;
i = parent(i);
}
}
// ================= MAX HEAP INSERT =================
void insertKey_max(int k)
{
if (heap_size == MAX)
{
cout << "\nOverflow: Could not insertKey\n";
return;
}
heap_size++;
int i = heap_size - 1;
harr[i] = k;
// Fix max-heap property
while (i != 0 && harr[parent(i)] < harr[i])
{
int temp = harr[i];
harr[i] = harr[parent(i)];
harr[parent(i)] = temp;
i = parent(i);
}
}
// ================= MIN HEAPIFY =================
void MinHeapify(int i)
{
int l = left(i);
int r = right(i);
int smallest = i;
if (l < heap_size && harr[l] < harr[i])
smallest = l;
if (r < heap_size && harr[r] < harr[i])
smallest = r;
if (smallest != i)
{
int temp = harr[i];
harr[i] = harr[smallest];
harr[smallest] = temp;
MinHeapify(smallest);
}
}
// ================= MAX HEAPIFY =================
void MaxHeapify(int i)
{
int l = left(i);
int r = right(i);
int largest = i;
if (l < heap_size && harr[l] > harr[i])
largest = l;
if (r < heap_size && harr[r] > harr[largest])
largest = r;
if (largest != i)
{
int temp = harr[i];
harr[i] = harr[largest];
harr[largest] = temp;
MaxHeapify(largest);
}
}
// ================= DELETE ROOT =================
int delete_key()
{
if (heap_size <= 0)
return 0;
if (heap_size == 1)
{
heap_size--;
return harr[0];
}
int root = harr[0];
harr[0] = harr[heap_size - 1];
heap_size--;
MaxHeapify(0);
// For Min-Heap use: MinHeapify(0);
return root;
}
// ================= DISPLAY HEAP =================
void display()
{
for (int i = 0; i < heap_size; i++)
{
cout << " " << harr[i] << " ,";
}
cout << "\b \b";
}
// ================= MAIN FUNCTION =================
int main()
{
// For Min Heap (uncomment to test)
/*
insertKey_min(3);
insertKey_min(2);
insertKey_min(1);
insertKey_min(15);
insertKey_min(5);
*/
// For Max Heap
insertKey_max(3);
insertKey_max(2);
insertKey_max(1);
insertKey_max(15);
insertKey_max(5);
cout << "Inserted!!\n";
display();
cout << endl;
int temp = delete_key();
if (temp == 0)
{
cout << "\nHeap is Empty!!" << endl;
}
else
{
cout << temp << " Deleted!!" << endl;
}
display();
return 0;
}