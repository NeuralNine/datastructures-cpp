#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
    private:
        vector<int> values;

        int get_parent(int i) {
            return (i - 1) / 2;
        }

        int get_left(int i) {
            return 2 * i + 1;
        }

        int get_right(int i) {
            return 2 * i + 2;
        }

        void heapify_down(int i) {
            int left = get_left(i);
            int right = get_right(i);

            int largest = i;

            if(left < values.size() && values[left] > values[i]) {
                largest = left;
            }

            if(right < values.size() && values[right] > values[largest]) {
                largest = right;
            }

            if(largest != i) {
                swap(values[i], values[largest]);
                heapify_down(largest);
            }
        }

        void heapify_up(int i) {
            if(i && values[get_parent(i)] < values[i]) {
                swap(values[i], values[get_parent(i)]);
                heapify_up(get_parent(i));
            }
        }

    public:
        void insert(int element) {
            values.push_back(element);
            int index = values.size() - 1;
            heapify_up(index);
        }

        void pop() {
            values[0] = values.back();
            values.pop_back();
            heapify_down(0);
        }

        int get_top() {
            return values.at(0);
        }

        void print_array() {
            for(int i = 0; i < values.size(); i++) {
                cout << values.at(i) << endl;
            }
        }

};

int main() {
    MaxHeap myheap = MaxHeap();

    myheap.insert(10);
    myheap.insert(20);
    myheap.insert(30);
    myheap.insert(12);
    myheap.insert(18);
    myheap.insert(22);

    myheap.print_array();

    return 0;
}