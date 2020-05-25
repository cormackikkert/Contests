import java.util.*;

public class Prog {
    public static void main(String[] args) {
        int[] nums = {1, 2, 3};

        HashSet<int[]> set = new HashSet<>();

        set.add(nums);

        System.out.println(set.contains(new int[] {1, 2, 3})); // outputs false

        nums[2]++;

        System.out.println(set.contains(nums)); // outputs true
    }
}
