package Java.Set;

import java.util.LinkedHashSet;

public class MyLinkedHashSet {
    public static void main(String[] args) {
        LinkedHashSet<Integer> numbers = new LinkedHashSet<>();

        for (int i = 0; i < 10; i = i + 2) {
            numbers.add(i);
        }
        System.out.println(numbers);
        numbers.remove(4);
        System.out.println("Size: " + numbers.size());
        for (Integer i: numbers) {
            System.out.println(i);
        }
        numbers.clear();
        System.out.println("Is Empty: " + numbers.isEmpty());
    }
}
