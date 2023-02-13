package Java.Set;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class MyHashSet {
    public static void main(String[] args) {
        Set<Double> notas = new HashSet<>();
        notas.add(9.3);
        notas.add(7.0);
        notas.add(6.1);
        notas.add(4.4);
        notas.add(8.2);
        notas.add(3.8);
        notas.add(7.7);
        notas.add(6.4);
        System.out.println(notas);

        notas.remove(7.7);
        System.out.println(notas);

        System.out.println("Size: " + notas.size());

        Iterator<Double> iterator = notas.iterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }
        System.out.println("Is Empty: " + notas.isEmpty());
    }
}
