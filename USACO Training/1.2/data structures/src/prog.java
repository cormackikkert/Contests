public class prog {
    public static void main(String[] args) {
        DynamicArray a = new DynamicArray();
        a.append(1);
        a.append(2);
        a.pop();
        System.out.println(renderArray(a.getArray()));

        Heap test = new Heap();
        test.insert(4);
        test.insert(3);
        test.insert(1);
        test.insert(5);
        System.out.println(renderArray(test.getArray()));
        test.extractMin();
        System.out.println(renderArray(test.getArray()));
        test.extractMin();
        System.out.println(renderArray(test.getArray()));
        test.extractMin();

        System.out.println(renderArray(Heap.heapSort(new int[]{5, 2, 6, 1, 3, 6})));
    }
    public static String renderArray(int[] args) {
        String total = "";
        for (int x : args) {
            total += Integer.toString(x) + " ";
        }
        return total;
    }
}
