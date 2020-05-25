public class Heap extends DynamicArray {

    public Heap() {}

    public void insert(int n) {
        int index = getLength();
        append(n);
        bubble_up(index);
    }

    public int extractMin() {
        int value = getItem(0);
        setItem(0, getItem(length - 1));
        pop();
        bubble_down(0);
        return value;
    }

    private void bubble_up(int index) {
        if (parent(index) == -1) return;

        if (getItem(index) < getItem(parent(index))) {
            swap(index, parent(index));
            bubble_up(parent(index));
        }
    }

    private void bubble_down(int index) {
        if (left_child(index) == -1) return;

        if (getItem(index) > getItem(left_child(index)) || getItem(index) > getItem(right_child(index))) {
            if (getItem(left_child(index)) < getItem(right_child(index))) {
                swap(index, left_child(index));
                bubble_down(left_child(index));
            } else {
                swap(index, right_child(index));
                bubble_down(right_child(index));
            }
        }
    }

    private void swap(int index1, int index2) {
        int temp = getItem(index1);
        setItem(index1, getItem(index2));
        setItem(index2, temp);
    }

    public int getItem(int n) {
        if (n == -1) {
            return 10000000;
        }
        return array[n];
    }

    private int parent(int n) {
        if (n == 0) {
            return -1;
        }
        return n / 2;
    }

    private int left_child(int n) {
        if (2 * n >= length) {
            return -1;
        }
        return (2 * n);
    }

    private int right_child(int n) {
        if (2 * n + 1 >= length) {
            return -1;
        }
        return (2 * n + 1);
    }

    public static int[] heapSort(int[] nums) {
        Heap a = new Heap();
        for (int n : nums) {
            a.append(n);
        }
        for (int i = a.length - 1; i >= 0; i--) {
            a.bubble_down(i);
        }
        return a.getArray();
    }
}