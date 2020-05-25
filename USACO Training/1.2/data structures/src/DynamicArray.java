public class DynamicArray {
    int length = 0;
    int capacity = 1;
    int[] array = new int[capacity];

    public DynamicArray() {}

    public void append(int x) {
        if (this.length == this.capacity) {
            int[] tempArray = new int[this.capacity * 2];
            for (int i = 0; i < this.length; i++) {
                tempArray[i] = this.array[i];
            }
            this.array = tempArray;
            this.capacity *= 2;
        }
        this.array[length] = x;
        this.length++;
    }

    public int pop() {
        this.length--;
        return this.array[length];
    }

    public int[] getArray() {
        int[] tempArray = new int[length];
        for (int i=0; i<this.length; i++) {
            tempArray[i] = this.array[i];
        }
        return tempArray;
    }

    public int getLength() {
        return this.length;
    }

    public int getItem(int n) {
        return this.array[n];
    }

    public void setItem(int i, int n) {
        this.array[i] = n;
    }
}
