package Java.Set;

import java.util.TreeSet;

public class MyTreeSet {
    public static void main(String[] args) {
        TreeSet<Integer> tree = new TreeSet<>();
        for (int i = 1; i < 3000; i = i * 3) {
            tree.add(i);
        }
        System.out.println(tree);
        System.out.println("First: " + tree.first());
        System.out.println("Last: " + tree.last());
        System.out.println("Lower: " + tree.lower(27));
        System.out.println("Higher: " + tree.higher(81));
        System.out.println("Remove top first: " + tree.pollFirst());
        System.out.println("Remove bottom first: " + tree.pollLast());
        System.out.println(tree);
    }
}
